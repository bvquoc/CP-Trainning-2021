#include <bits/stdc++.h>

using namespace std;

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;

/// Shortcut

#define TASK "TEST2"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, l, r) for (type i = l; i >= r; i--)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define FORAUTO(i, a) for (auto i : a)

/// Functions

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))
#define fillV(v, x) fill(v.begin(), v.end(), x)
#define fillArr(arr, n, x) fill(arr, arr + n, x)
#define fillA(a, n, x) fill(a + 1, a + n + 1, x)
#define all(x) (x).begin(), (x).end()

/// Data Structure

#define um unordered_map
#define us unordered_set
#define pq priority_queue

/// BIT

#define GetMask ((x >> i) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

/// EDIT

const ll MAX = 100005;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;

/// ================================ - MAIN - ================================

string s, tmp, num;
char cur;
int cnt;
stack <char> st, open;
string res;
deque<string> S;
deque<char> B;
deque<int> V;

string F(int n, string st){
    string res;
    while (n--)
        res += st;
    return res;
}
string SS(string st){
    string res = st;
    reverse(st.begin(), st.end());
    res += st;
    return res;
}
string T(string st){
    string res = "";
//    res[res.size() - 1] = "";
    FOR(i, 0, st.size() - 2)
        res += st[i];
    reverse(st.begin(), st.end());
    res += st;
    return res;
}

int convert(string s){
    stringstream str2num(s);
    int x = 0;
    str2num >> x;
    return x;
}

string standardized(string st){
    string res;
    FOR(i, 0, st.size() - 1)
        if (st[i] == '*') continue;
            else res += st[i];
    return res;
}
//void
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//        freopen(TASK".INP","r",stdin);
//        freopen(TASK".OUT","w",stdout);
//    #endif
    cin >> s;
    FOR(i, 0, s.size() - 1)
        if (s[i] == '(' || s[i] == '[') cnt++;
    cout << cnt << '\n';
    if (!cnt){
        cout << s;
        return 0;
    }
    S.push_back("");
    V.push_back(0);
    FOR(i, 0, s.size() - 1){
        char c = s[i];
        if (c == '('){
            B.push_back('(');
            S.push_back("");
            V.push_back(0);
            continue;
        }

        if (c == '['){
            B.push_back('[');
            S.push_back("");
            V.push_back(0);
            continue;
        }

        if ('0' <= c && c <= '9')
        {
            V.back() = (V.back() << 3) + (V.back() << 1) + (c - '0');
            continue;
        }

        if (c == ')')
        {
            V.pop_back();
            string tmp;
            while (V.back() --> 0) tmp += S.back();
            S.back() = tmp;
            V.back() = 0;
            S.pop_back();

            S.back() += tmp;
            B.pop_back();
            if (B.empty())
            {
                res += S.back();
                S.back() = "";
            }
            continue;
        }

        if (c == ']')
        {
            string tmp;
            for (char c : S.back()) if (c != '*') tmp += c;
            if (S.back().back() == '*') tmp.pop_back();
            reverse(all(S.back()));
            for (char c : S.back()) if (c != '*') tmp += c;
            S.pop_back();
            S.back() += tmp;

            B.pop_back();
            V.pop_back();
            if (B.empty())
            {
                res += S.back();
                S.back() = "";
            }
            continue;
        }

        S.back() += c;
    }
    for (; S.size(); S.pop_back())
        res += S.back();
    FOR(i, 0, res.size() - 1)
        cout << res[i];
//    for (auto c : s){
//        st.push(s[i]);
//        if (c == ')'){
//            string comp = "";
//            while (1){
//                int ch = st.pop();
//                if (ch == '(') break;
//                comp += st.pop();
//            }
//            reverse(comp.begin(), comp.end());
//
//        }
//    }
//    for (char c : res) putchar(c);
//    FOD(i, s.size() - 1, 0)
//        st.push(s[i]);
////    checker = 0;
//    tmp = "";
//    while (!st.empty()){
//        cur = st.top();
//        if (cur >= '0' && cur <= '9'){
//            num += cur;
//            st.pop();
//            continue;
//        }
//        if (cur == '(' || cur == '['){
//            tmp = "";
//            st.pop();
//            continue;
//        }
//        if (cur == ')' || cur == ')'){
//            if (cur == ')'){
//                    res += F(convert(num), tmp);
////                    cerr << convert(num) << ' ' << tmp << '\n';
//                    num = "";
//            } else {
//                    if (tmp[0] == '*')
//                        res += S(standardized(tmp));
//                    else res += T(standardized(tmp));
//                }
//           tmp = "";
//           st.pop();
//           continue;
//        }
//        tmp += cur;
////        if (cur != '(' && )
////        if (checker){
////            tmp += st.top();
////        }
////        checker = false;
//        st.pop();
//    }
//    cout << res;
////    st.push('2');
////    cout << st.top();
    return 0;
}
