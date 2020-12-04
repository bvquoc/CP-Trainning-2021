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
#define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = (x << 3) + (x << 1) + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

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

/*
(\_/)
( •_•)
/ >?? */

const int N = 1000006, INF = 1e18;
int n, a[N];

ld f[N][2];
bool solved[N][2];

ld dp(int i, bool t) {
    if (solved[i][t]) return f[i][t];
    ld &ans = f[i][t];
    if (t == 0) {
        maximize(ans, max(a[i+1] + dp(i+1,0), dp(i+1,1)));
    } else {
        maximize(ans, max(ld(a[i-1]+a[i+1])/2.0 + dp(i+1,0), a[i-1] + dp(i+1,1)));
    }
    solved[i][t] = true;
    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("RGAME.INP","r",stdin);
    freopen("RGAME.OUT","w",stdout);
    #endif

    auto printAns = [&](const ld &res) {
        Write(ll(res));
        putchar('.');
        putchar((trunc(res) == res) ? '0' : '5');
        putchar(endl);
    };

    int T; Read(T);
    while (T--) {
        Read(n);
        FOR(i,1,n) Read(a[i]);
        FOR(i,1,n) {
            solved[i][0] = solved[i][1] = false;
            f[i][0] = f[i][1] = 0;
        }
        f[n][0] = 0; f[n][1] = a[n-1];
        solved[n][0] = solved[n][1] = true;
        printAns(dp(1,0));
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}