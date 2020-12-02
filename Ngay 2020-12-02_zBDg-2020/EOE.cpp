/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
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
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

string s, x, y;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("EOE.INP","r",stdin);
    freopen("EOE.OUT","w",stdout);
    #endif

    cin >> s >> x >> y;
    s.push_back('+');

    bool isOdd = 0, cur = 0, tmp = 1;    
    for (char ch: s)  {
        if (ch == '+' || ch == '-')  {
            tmp *= cur;
            isOdd = isOdd xor tmp;
            tmp = 1;
            continue;
        } 
        if (ch == '*') {
            tmp *= cur; 
            cur = 0;
            continue;
        }
        
        if (ch == 'x' || ch == 'y')  {
            if (ch == 'x') cur = bool(x == "Odd");
            else cur = bool(y == "Odd");
            continue;
        }
        
        cur = (ch-'0') % 2;
    }

    cout << (isOdd ? "Odd" : "Even");

    cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}