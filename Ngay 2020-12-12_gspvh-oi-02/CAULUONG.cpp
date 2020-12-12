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
            if (minimize(d[v], du + uv)) pq.push(ii(d[v], v));
        }
    }
}

bool mark[N];
ii trace[N];

void get_path(int x) {
    while (trace[x] != ii(-1, -1)) {
        ans[trace[x].second]++;
        if (ans[trace[x].second] >= MOD) ans[trace[x].second] -= MOD;
        x = trace[x].first;
    }
}

int root;
void dfs(const int &u, const int &d) {
    for (int i: adj[u]) if (!mark[e[i].v]) {
        int v = e[i].v;

        mark[v] = true;
        trace[v] = ii(u, i);
        if (d + e[i].w == min_path[root][v]) get_path(v);
        dfs(v, d + e[i].w);
        trace[v] = ii(-1,-1);
        mark[v] = false;
    }
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

    FOR(i,1,n) dijkstra(i, min_path[i]);

    FOR(i,1,n) {
        FOR(j,1,n) mark[j] = false;
        FOR(j,1,n) trace[j] = ii(-1, -1);
        root = i;
        dfs(i, 0);
    }

    FOR(i,1,m) {
        Write(ans[i]);
        putchar(endl);
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}