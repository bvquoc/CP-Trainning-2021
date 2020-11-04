#include <bits/stdc++.h>
#define fname "STRALT"
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr <<(#a)<< ": ["; REP0(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define ARR1(a, n) {cerr <<(#a)<< ": ["; REP1(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define LB lower_bound
#define UB upper_bound
#define X first
#define Y second

using namespace std;
template<typename T, typename V>
inline void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
inline void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    string str;
    cin >> str;
    stack<char> st;
    int cnt = 0;
    REP0(i, str.size()) {
        if(('a' <= str[i] && str[i] <= 'z') || ('0' <= str[i] && str[i] <= '9') || str[i] == '[') st.push(str[i]);
        else if(str[i] == ')') {
            ++cnt;
            string s;
            while(st.size() && 'a' <= st.top() && st.top() <= 'z') {
                s.pb(st.top());
                st.pop();
            }
            reverse(s.begin(), s.end());
            string num;
            while(st.size() && '0' <= st.top() && st.top() <= '9') {
                num.pb(st.top());
                st.pop();
            }
            reverse(num.begin(), num.end());
            int n = stoi(num);
            REP0(t, n) REP0(j, s.size()) st.push(s[j]);
        }
        else if(str[i] == ']') {
            ++cnt;
            string s;
            while(st.size() && st.top() != '[') {
                s.pb(st.top());
                st.pop();
            }
            st.pop();
            reverse(s.begin(), s.end());
            REP0(j, s.size()) st.push(s[j]);
            if(str[i - 1] == '*') s.popb();
            reverse(s.begin(), s.end());
            REP0(j, s.size()) st.push(s[j]);
        }
    }
    string ans;
    while(st.size()) {
        ans.pb(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << cnt << '\n' << ans;
	return 0;
}
