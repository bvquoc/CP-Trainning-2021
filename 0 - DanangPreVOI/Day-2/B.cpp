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

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
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

#define NMAX 500005
#define NMOD 998244353

struct edge {
    int u, v, X, Y;
};

int fact[NMAX];
int n, m, res = 0;
vector <int> adj[NMAX];
edge e[NMAX];

bool mark[NMAX];

void DFS(int u, int d) {
    mark[u] = true;
    int cnt = 0;
    for (int v: adj[u]) if (!mark[v]) {
        DFS(v, d + 1);
        cnt++;
    }
    if (cnt == 0) {
        res += fact[d];
        res %= NMOD;
    }
}

// #define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif
    /* prepare */ {
        fact [0] = fact[1] = 1;
        FOR(i, 2, NMAX - 5) fact[i] = (1LL * fact[i-1] * i) % NMOD;
    }

    int T; Read(T);
    Read(n); Read(m);

    FOR(i,1,m) {
        Read(e[i].u); Read(e[i].v);
        Read(e[i].X); Read(e[i].Y);
    }

    FOR(u,1,m) FOR(v,1,m) if (e[u].X < e[v].X && e[u].Y < e[v].Y) adj[u].push_back(v);

    FOR(i,1,m) if (!mark[i]) DFS(i,1);
    while (res > NMOD) res -= NMOD;
    cout << res;

    // cerr << "Time: " << (double) clock() / 1000.0;
    return 0;
}
