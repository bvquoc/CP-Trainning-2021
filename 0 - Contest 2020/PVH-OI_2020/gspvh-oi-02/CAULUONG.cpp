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
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
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

const int N = 1502, M = 5003;
const int INF = INT_MAX, MOD = 998244353;
struct Edge { int u, v, w; };
int n, m, min_path[N][N];
Edge e[M];
vector <int> adj[N];
int ans[M];

vector <int> idEdges;
void dijkstra(const int &st, int d[]){
    priority_queue <ii, vector<ii>, greater<ii> > pq;

    for (int i=1; i<=n; i++) d[i] = INF;
    d[st] = 0;
    pq.push(ii(0, st));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        
        if (du!=d[u]) continue;

        for (int i: adj[u]) {
            int v = e[i].v, uv = e[i].w;
            if (minimize(d[v], du + uv)) {
                pq.push(ii(d[v], v));
                idEdges.push_back(i);
            }
        }
    }
}

vector <int> ke[N];
int f[N], g[N];

int calc_g(int u) {
    if (ke[u].empty()) return g[u] = 1;
    g[u] = 1;
    for (int i: ke[u]) g[u] += calc_g(e[i].v);
    return g[u];
}
int calc_f(int u) {
    for (int i: ke[u]) {
        f[e[i].v] += f[u];
        calc_f(e[i].v);
    }
    return f[u];
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("CAULUONG.INP","r",stdin);
    freopen("CAULUONG.OUT","w",stdout);
    #endif
    
    int subtask; Read(subtask);
    Read(n); Read(m);
    FOR(i,1,m) {
        int u, v, w;
        Read(u); Read(v); Read(w);
        e[i] = {u, v, w};
        adj[u].push_back(i);
    }

    FOR(u,1,n) {
        idEdges.clear();
        dijkstra(u, min_path[u]);
        FOR(i,1,n) {
            ke[i].clear();
            f[i] = g[i] = 0;
        }

        for (int i: idEdges) ke[e[i].u].push_back(i);
        f[u] = 1;
        calc_f(u);
        calc_g(u);

        cout << u << ": \n";
        FOR(i,1,n) cout << f[i] << ' ' << g[i] << endl;
        cout << endl;
        for (int i: idEdges) (ans[i] += 1LL * f[e[i].u] * g[e[i].v]) % MOD;
    }

    FOR(i,1,m) {
        Write(ans[i]);
        putchar(endl);
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}