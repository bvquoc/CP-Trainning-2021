#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 102;

struct edge {
    int u, v, w;
};

int par[N], rnk[N];

int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] < rnk[v]) par[u] = v;
    else par[v]=u;
    return true;
}

int n, c[5], d[N][N];
vector <edge> edges;

signed main(void) {
    FastIO;
    freopen("BUILD.INP","r",stdin);
    freopen("BUILD.OUT","w",stdout);
    { // Read Input
        cin >> n;
        FOR(i,1,4) cin >> c[i];
        int u, v, w;
        while (cin >> u >> v >> w) {
            edges.push_back({u,v,w});
            d[u][v] = w;
            d[v][u] = w;
        }
        
    }

    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.w < b.w;
    });

    for (int i=1; i<=n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }

    int T[n+5];

    for (edge &e: edges) {
        if (join(e.u, e.v)) {
            T[e.v] = e.u;
        }
    }

    set <ii> ans;
    FOR(i,1,4) {
        int x = c[i];
        while (T[x]!=0) {
            int u = x, v = T[x];
            if (u>v) swap(u,v); 
            ans.insert({u,v});
            cout << "{" << u << ',' << v << "} "; 
            x = T[x];
        }
        cout << endl;
    }

    
    return 0;
}