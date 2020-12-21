#include <bits/stdc++.h>
#define maxn 500005
#define oo 2000000000

using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;

int n, q;
vector<int> g[maxn];
int a[maxn], d[maxn], deg[maxn], nhanh[maxn], sl[5];
int root;
int id = 0;

void sub1()
{
    int sl = 0;
    for(int i=1; i<=n; ++i) if(a[i] == 1) ++sl;
    if(sl <= 1) cout<<0<<'\n';
    else cout<<1<<'\n';

    for(int i=1; i<=q; ++i)
    {
        int u;
        cin>>u;

        if(a[u] == 1)
        {
            --sl;
            a[u] = 0;
        }
        else
        {
            ++sl;
            a[u] = 0;
        }

        if(sl <= 1) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
}

void DFS(int u)
{
    d[u] = 1;
    nhanh[u] = id;
    for(auto &v : g[u])
    {
        if(d[v] == 0) DFS(v);
    }
}

void sub2()
{
    for(auto &u : g[root])
    {
        ++id;
        DFS(u);
    }

    for(int i=1; i<=n; ++i) if(a[i] == 1) ++sl[nhanh[i]];

    if(sl[1] > 0 && sl[2] > 0 && sl[3] > 0) cout<<2;
    else if(sl[1] == 0 && sl[2] == 0 && sl[3] == 0) cout<<0;

    else if(sl[1] == 0 && sl[2] > 0 && sl[3] > 0) cout<<1;
    else if(sl[1] > 0 && sl[2] == 0 && sl[3] > 0) cout<<1;
    else if(sl[1] > 0 && sl[2] > 0 && sl[3] == 0) cout<<1;

    else if(sl[1] == 1 && sl[2] == 0 && sl[3] == 0) cout<<0;
    else if(sl[1] == 0 && sl[2] == 1 && sl[3] == 0) cout<<0;
    else if(sl[1] == 0 && sl[2] == 0 && sl[3] == 1) cout<<0;

    else if(sl[1] > 1 && sl[2] == 0 && sl[3] == 0) cout<<1;
    else if(sl[1] == 0 && sl[2] > 1 && sl[3] == 0) cout<<1;
    else if(sl[1] == 0 && sl[2] == 0 && sl[3] > 1) cout<<1;
    cout<<'\n';

    for(int i=1; i<=q; ++i)
    {
        int u;
        cin>>u;

        if(a[u] == 0)
        {
            a[u] = 1;
            ++sl[nhanh[u]];
        }
        else
        {
            a[u] = 0;
            --sl[nhanh[u]];
        }

        if(sl[1] > 0 && sl[2] > 0 && sl[3] > 0) cout<<2;
        else if(sl[1] == 0 && sl[2] == 0 && sl[3] == 0) cout<<0;

        else if(sl[1] == 0 && sl[2] > 0 && sl[3] > 0) cout<<1;
        else if(sl[1] > 0 && sl[2] == 0 && sl[3] > 0) cout<<1;
        else if(sl[1] > 0 && sl[2] > 0 && sl[3] == 0) cout<<1;

        else if(sl[1] == 1 && sl[2] == 0 && sl[3] == 0) cout<<0;
        else if(sl[1] == 0 && sl[2] == 1 && sl[3] == 0) cout<<0;
        else if(sl[1] == 0 && sl[2] == 0 && sl[3] == 1) cout<<0;

        else if(sl[1] > 1 && sl[2] == 0 && sl[3] == 0) cout<<1;
        else if(sl[1] == 0 && sl[2] > 1 && sl[3] == 0) cout<<1;
        else if(sl[1] == 0 && sl[2] == 0 && sl[3] > 1) cout<<1;

        cout<<'\n';
    }
}

void sub3()
{
    for(int i=1;i<=q;++i) cout<<1<<'\n';
}

int main()
{
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<n; ++i)
    {
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);

        ++deg[u];
        ++deg[v];
    }

    int check = 0;
    for(int u=1; u<=n; ++u)
    {
        if(deg[u] == 3)
        {
            root = u;
            sub2();
            return 0;
        }
        else if(deg[u] == 1) ++check;
    }

    if(check == 2) sub1();
    else sub3();
}
