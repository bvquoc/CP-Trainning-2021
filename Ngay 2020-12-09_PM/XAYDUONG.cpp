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

const int N = 100005;
const ll LINF = LLONG_MAX;

struct TQuery { int type, u, v, w; } q[N];
int n, q_sz;
int maxIndex_q1 = INT_MIN, minIndex_q2 = INT_MAX;
vector <ii> adj[N];

struct DisjointSet {
    int n; vector <int> father, height;
    void assign(int sz) {
        n = sz;
        father.resize(n+1);
        height.resize(n+1);
        for (int i=1; i<=n; i++) {
            father[i] = i;
            height[i] = 0;
        }
    }
    DisjointSet () { assign(1e5); }
    DisjointSet (int sz) { assign(sz); }
    int find(int node) {
        if (father[node] != node) {
            father[node] = find(father[node]);
        }
        return father[node];
    }
    bool unite(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rootA == rootB) return false;

        if (rand() % 2) father[rootB] = rootA;
        else father[rootA] = rootB;

        return true;
    }
} DSU;

ll d[N], ans[N];
void dijkstra(const int &st) {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    FOR(i,1,n) d[i] = LINF;
    d[st] = 0;
    pq.push(ii(0, st));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du!=d[u]) continue;

        for (ii e: adj[u]) {
            int v = e.first, uv = e.second;
            if (minimize(d[v], du + uv)) pq.push(ii(d[v], v));
        }
    }

    FOR(i,1,n) if (d[i] != LINF) maximize(ans[st], d[i]);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("XAYDUONG.INP","r",stdin);
    freopen("XAYDUONG.OUT","w",stdout);
    #endif
    Read(n); Read(q_sz);
    FOR(i,1,q_sz) {
        Read(q[i].type);
        Read(q[i].u);
        if (q[i].type == 1) {
            Read(q[i].v);
            Read(q[i].w);
            maximize(maxIndex_q1, i);
        } else minimize(minIndex_q2, i);
    }

    #define minTask (maxIndex_q1 < minIndex_q2)
    #define EXIT exit(0);
    #define ENDL putchar('\n')

    DSU.assign(n);

    if (minTask) {
        FOR(id, 1, maxIndex_q1) {
            int u = q[id].u, v = q[id].v;
            if (DSU.unite(u, v)) {
                adj[u].emplace_back(ii(v, q[id].w));
                adj[v].emplace_back(ii(u, q[id].w));
            }
        }

        FOR(i,1,n) ans[i] = -1;

        FOR(id, minIndex_q2, q_sz) {
            int u = q[id].u;
            if (ans[u] == -1) dijkstra(u);
            Write(ans[u]);
            ENDL;
        }
        EXIT;
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}