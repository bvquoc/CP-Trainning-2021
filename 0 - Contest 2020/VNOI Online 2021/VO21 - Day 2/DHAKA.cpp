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

const int N = 100005, INF = 2e18;
int n, m, k, l, f[N];
vector <int> s[N];
vector <ii> adj[N];

int g[N][64];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    #endif
    
    Read(n); Read(m); Read(k); Read(l);
    FOR(i, 1, n) {
        int x; Read(x);
        s[i].push_back(x);
        f[i] = 0;
        REP(j, s[i][0]) {
            Read(x);
            s[i].push_back(x);
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

    struct State {
        int u, w, mask;
        State (int _u = 0, int _w = INF, int _mask = 0) {
            u = _u; w = _w; mask = _mask;
        }
        bool operator< (const State& other) const { return w > other.w || (w == other.w && cntBit(mask) < cntBit(other.mask)); }
    };

    priority_queue <State> pq;
    for (int i=1; i<=n; i++) REP(j, 64) g[i][j] = INF;
    g[1][f[1]] = 0; pq.push(State(1, 0, f[1]));

    while (pq.size()) {
        int u = pq.top().u, du = pq.top().w;
        int mask = pq.top().mask; pq.pop();

        if (g[u][mask] != du) continue;

        for (ii e: adj[u]) {
            int v = e.first, uv = e.second;
            if (minimize(g[v][mask | f[v]], du + uv)) pq.push(State(v, g[v][mask | f[v]], mask | f[v]));
        }

    }

    int res = INF;
    REP(j, 64) if (cntBit(j) >= l && g[n][j] < INF) minimize(res, g[n][j]);
    if (res == INF) res = -1;
    Write(res);

    return 0;
}


// if (k == 1) { // Subtask 3
//         struct State {
//             int u, w; bool ok;
//             State (int _u = 0, int _w = INF, bool _ok = 0) {
//                 u = _u; w = _w; ok = _ok;
//             }
//             bool operator< (const State& other) const { return w > other.w || (w == other.w && ok < other.ok); }
//         };

//         priority_queue <State> pq;
//         for (int i=1; i<=n; i++) {
//             d[i] = INF;
//             f[i] = INF;
//         }

//         d[1] = 0; pq.push(State(1, 0, 0));
//         if (s[1][0]) {
//             f[1] = 0;
//             pq.push(State(1, 0, 1));
//         }

//         while (pq.size()) {
//             int u = pq.top().u, du = pq.top().w; 
//             bool ok = pq.top().ok; pq.pop();

//             if (!ok) {
//                 if (du != d[u]) continue;
//                 for (ii e: adj[u]) {
//                     int v = e.first, uv = e.second;
//                     if (s[v][0]) {
//                         if (minimize(f[v], du + uv)) pq.push(State(v, f[v], 1));
//                     } else {
//                         if (minimize(d[v], du + uv)) pq.push(State(v, d[v], 0));
//                     }
//                 }
//             } else {
//                 if (du != f[u]) continue;
//                 for (ii e: adj[u]) {
//                     int v = e.first, uv = e.second;
//                     if (minimize(f[v], du + uv)) pq.push(State(v, f[v], ok));
//                 }
//             }
//         }

//         if (f[n] == INF) f[n] = -1;
//         Write(f[n]);
//         exit(0);
//     }