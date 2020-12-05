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
using List = set <int>;

/*
(\_/)
( •_•)
/ >?? */

struct Edge {
    int u, v, w;
    Edge() { u = 0; v = 0; w = 0;}
    Edge(int _u, int _v, int _w) { u = _u; v = _v; w = _w;}
}; bool operator < (const Edge &p, const Edge &b) {return p.w < b.w;}

struct Disjoint_Set {
    vector<int> par, rank;
    Disjoint_Set(int n) {
        par.resize(n+1);
        rank.resize(n+1,0);
        for (int i=1; i<=n; i++) par[i] = i;
    }
    int find(int u) {
        if (par[u] != u) par[u] = find(par[u]);
        return par[u];
    }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] > rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

vector <int> p;
vector <ii> res;
vector <List> b;
vector<Edge> e;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("GALAXY.INP","r",stdin);
    freopen("GALAXY.OUT","w",stdout);
    #endif
    
    int n, m;
    cin >> n >> m; p.resize(n+1);
    FOR(i,1,n) cin >> p[i];
	int x, u, v; b.resize(n+1);
    while (m--) {
		cin >> x >> u >> v;
		if (v < u) swap(u, v);
        FOR(j,u,v) {
			b[x].insert(j);
			b[j].insert(x);
		}
	}
	FOR(i,1,n) FORE(it, b[i]) {
        e.push_back(Edge(i, *it, p[i] + p[*it]));
        e.push_back(Edge(*it, i, p[i] + p[*it]));
    }

    m = sz(e); sort(ALL(e));

    Disjoint_Set DSU(n);
    int result = 0;
    REP(i, m) if (DSU.join(e[i].u, e[i].v)) result += e[i].w;
	cout << result;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}