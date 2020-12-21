#include <bits/stdc++.h>
#define task "SOCKS"
#define ll long long
#define FOR( i, l, r) for(int i = (l), _r = (r); i <= _r; ++i)
#define FOD( i, l, r) for(int i = (l), _r = (r); i >= _r; ++i)
#define REP( i, n)    for(int i = 0, _n = (n); i < _n; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1ll << (x))
#define BIT(x, k) (1ll & ((x) >> (k)))
#define ON(x, k)  ((x) | (1ll << (k)))
#define OFF(x, k) ((x) & ~(1ll << (k)))
#define endl '\n'
#define __builtin_popcount __builtin_popcountll
using namespace std;
int const N = 5e5 + 11;
int numNode, q;
vector<int> adj[N];
int color[N], sta[N], order[N << 1], times, f[N], ans, h[N];
int par[N][22];
set<int> redNode;
int deg[N];
int numRed, child[N];
void inp(void)
{
    cin >> numNode >> q;
    FOR( i, 1, numNode) cin >> color[i], numRed += color[i];
    FOR( i, 2, numNode)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}
void sub1(void)
{
    if(numRed >= 2)
        ans = 1;
    cout << ans << endl;
    while(q--)
    {
        int u;
        cin >> u;
        if(color[u] == 0)
            numRed++;
        else
            numRed--;
        color[u] ^= 1;
        ans = (numRed >= 2);
        cout << ans << endl;
    }
}
//void dfs(int u, int p)
//{
//    sta[u] = ++times;
//    par[u][0] = p;
//    FOR( i, 1, 20)
//    {
//        if(par[u][i - 1] == -1)
//            break;
//        par[u][i] = par[par[u][i - 1]][i - 1];
//    }
//    for(auto &v : adj[u])
//    {
//        if(v == p)
//            continue;
//        h[v] = h[u] + 1;
//        dfs(v, u);
//    }
//}
//int go( int u, int d)
//{
//    FOR( i, 0, 20) if(bit( d, i))
//        u = par[u][i];
//    return u;
//}
//int lca( int u, int v)
//{
//    if(h[u] < h[v])
//        swap( u, v);
//    u = go( u, h[u] - h[v]);
//    if( u == v)
//        return u;
//    FOD( i, 20, 0) if(par[u][i] != par[v][i])
//    {
//        u = par[u][i];
//        v = par[v][i];
//    }
//    return par[u][0];
//}
void DFS(int u, int p = 0)
{
    if(color[u])
        child[u]++;
    for(int &v : adj[u])
        if(v != p)
        {
            DFS(v, u);
            child[u] += child[v];
            f[u] += (f[v] == 1);
        }
    if(f[u] > 1)
        ans += (f[u] + 1) / 2;
    if(f[u] == 0 && child[u]) f[u] = 1;
}
void sub3(void)
{
    int root = 1;
    FOR( i, 1, numNode) child[i] = 0, f[i] = 0, root = (deg[root] > deg[i] ? root : i);
    DFS(root, 0);
    if(f[root] == 1)
        ans++;
    cout << ans << endl;
    while(q--)
    {
        ans = 0;
        int u;
        cin >> u;
        color[u] ^= 1;
        int root = 1;
        FOR( i, 1, numNode) child[i] = 0, f[i] = 0, root = (deg[root] > deg[i] ? root : i);
        DFS( root, 0);
        if(f[root] == 1)
            ans++;
        cout << ans << endl;
    }
}
void solve(void)
{
    int maxDeg = 0;
    FOR( i, 1, numNode) maxDeg = max(maxDeg, deg[i]);
    if(maxDeg <= 2)
        sub1();
    sub3();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    inp();
    solve();
    return 0;
}
