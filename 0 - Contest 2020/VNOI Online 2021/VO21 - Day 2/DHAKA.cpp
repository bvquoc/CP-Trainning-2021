/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
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
        x = (x << 3) + (x << 1) + (c - '0');
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

const int N = 100005, INF = 1e18;
int n, m, k, l, f[N];
vector <ii> adj[N];
int g[N][64];

struct State {
    int u, w, mask;
    State (int _u = 0, int _w = INF, int _mask = 0) {
        u = _u; w = _w; mask = _mask;
    }
    bool operator< (const State& other) const { 
        return w > other.w || (w == other.w && cntBit(mask) < cntBit(other.mask)); 
    }
};

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    #endif
    
    Read(n); Read(m); Read(k); Read(l);
    FOR(i, 1, n) {
        int x, d; Read(d);
        f[i] = 0;
        REP(j, d) {
            Read(x);
            f[i] = turnON(f[i], x-1);
        }
    }
    FOR(i,1,m) {
        int u, v, w;
        Read(u); Read(v); Read(w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    if (l == 0) {
        priority_queue <ii, vector<ii>, greater<ii> > pq;

        for (int i=1; i<=n; i++) f[i] = INF;
        f[1] = 0; pq.push(ii(0, 1));

        while (pq.size()) {
            int u = pq.top().second, du = pq.top().first; pq.pop();
            if (du != f[u]) continue;
            for (ii e: adj[u]) {
                int v = e.first, uv = e.second;
                if (minimize(f[v], du + uv)) pq.push(ii(f[v], v));
            }
        }

        if (f[n] == INF) f[n] = -1;
        Write(f[n]);
        exit(0);
    }


    priority_queue <State> pq;
    for (int i=1; i<=n; i++) REP(j, 64) g[i][j] = INF;
    g[1][f[1]] = 0; pq.push(State(1, 0, f[1]));

    while (pq.size()) {
        int u = pq.top().u, du = pq.top().w;
        int mask = pq.top().mask; pq.pop();

        if (g[u][mask] != du) continue;

        for (ii e: adj[u]) {
            int v = e.first, uv = e.second;
            int newMask = mask | f[v];
            if (minimize(g[v][newMask], du + uv)) pq.push(State(v, g[v][newMask], newMask));
        }

    }

    int res = INF;
    REP(mask, 64) if (cntBit(mask) >= l && g[n][mask] < INF) minimize(res, g[n][mask]);
    if (res == INF) res = -1;
    Write(res);

    return 0;
}