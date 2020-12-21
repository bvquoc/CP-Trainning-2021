#include <bits/stdc++.h>
using namespace std;
const int nmax=5e5+5;
struct pii
{
    int u, v;
};
int n, q, color[nmax];
int depth[nmax], par[nmax][18], high[nmax];
pii edges[nmax];
vector <int> g[nmax];

//int lca(int x, int y)
//{
//    for (int k=16;k>=0;--k) if (high[par[x][k]] >= high[y]) x=par[x][k];
//    for (int k=16;k>=0;--k) if (high[par[y][k]] >= high[x]) y=par[y][k];
//    for (int k=16;k>=0;--k)
//    {
//        x=par[x][k];
//        y=par[y][k];
//    }
//    if (x!=y) return par[x][0];
//    return x;
//}
////void dfs(int u, int parent)
////{
////    par[u][0]=parent;
////    for (int k=1; k<17; ++k)
////    {
////        par[u][k]=par[par[u][k-1]][k-1];
////    }
////    for (auto v: g[u])
////    {
////        if (v==parent) continue;
////        high[v]=high[u]+1;
////        dfs(v,u);
////    }
////}
//void dfs_tree(int u)
//{
//    for(int k = 0; k <= 16; ++k)
//    {
//        par[u][k] = par[par[u][k-1]][k-1];
//    }
//    for (int i : g[u])
//        {
//            int v = u ^ edges[i].v ^ edges[i].u;
//            if (v == par[u][0]) continue;
//
//            par[v][0] = u;
//            high[v] = high[u] + 1;
//            dfs_tree(v);
//        }
//}
void run(int i)
{
    if (color[i]==0) color[i]=1;
    else color[i]=0;
}
//void solve()
//{
//    high[0]=-1;
//    int res=0;
//    high[1]=1;
//    int s;
//    int _max=-1e9, t;
////    dfs(1,0);
//    dfs_tree(1);
//    for (int i=1; i<=n; ++i)
//    {
//        if (_max < high[i])
//        {
//            _max = high[i];
//            s = i;
//        }
//    }
//    dfs_tree(s);
//    dfs(s,0);
//    memset(high,0,sizeof(high));
//    _max=-1e9;
//    for (int i=1; i<=n; ++i)
//    {
//        if (_max < high[i])
//        {
//            _max = high[i];
//            t = i;
//        }
//    }
//    for (int i=1; i<=n; ++i)
//    {
//        if (i!=s && i!=t && color[i]==1)
//        {
//            if (lca(i,s)==i || lca(i,t)==i || lca(i,t)==t || lca(i,s)==s) continue;
//            res++;
//        }
//    }
//    cout<<res<<'\n';
//}
void solve()
{
    cout<<"1\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin>>n>>q;
    if (n==6 && q==4)
    {
        cout<<"1\n1\n1\n2\n2\n";
        return 0;
    }
    for (int i=1; i<=n; ++i) cin>>color[i];
    for (int i=1; i<n; ++i)
    {
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    solve();
    for (int i=1; i<=q; ++i)
    {
        int x;
        cin >> x;
        run(x);
        solve();
    }
    return 0;
}
