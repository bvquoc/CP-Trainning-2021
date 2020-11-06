#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

stack <string> st;
string s; int n;
int res = 0;

signed main(void) {
    FastIO;
    freopen("STRALT.INP","r",stdin);
    freopen("STRALT.OUT","w",stdout);
    cin >> s; n = s.size();
    s = ' ' + s;
    FOR(i,1,n) {
        if (s[i] == ')') {
            res++;
            string str1 = "";
            while (st.top() != "(") {
                str1 = st.top() + str1;
                st.pop();
            }
            st.pop();
            int num = 1, now = 0;
            while (!st.empty() && st.top().size() == 1 && '0' <= st.top()[0] && st.top()[0] <= '9') {
                now += num * (st.top()[0] - '0');
                num *= 10;
                st.pop();
            }
            string str2 = "";
            while (now--) str2 += str1;
            st.push(str2);
            continue;
        }
        if (s[i] == ']' && s[i - 1] != '*') {
            res++;
            string str1 = "";
            while (st.top() != "[") {
                str1 = st.top() + str1;
                st.pop();
            }
            st.pop();
            str1.erase(0, 1);
            string str2 = str1;
            reverse(ALL(str2));
            str1 += str2;
            st.push(str1);
            continue;
        }
        if (s[i] == ']') {
            res++;
            string str1 = "";
            while (st.top() != "[") {
                str1 = st.top() + str1;
                st.pop();
            }
            st.pop();
            str1.erase(str1.size() - 1, 1);
            string str2 = str1;
            reverse(ALL(str2));
            str2.erase(0, 1);
            str1 += str2;
            st.push(str1);
            continue;
        }
        string str = "";
        str.push_back(s[i]);
        st.push(str);
    }

    string str = "";
    while (!st.empty()) {
        str = st.top() + str;
        st.pop();
    }
    cout << res << endl << str;
    return 0;
}