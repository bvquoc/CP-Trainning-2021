#include <bits/stdc++.h>

#define task "socks"
#define endl '\n'
#define int long long
#define ii pair<int,int>

using namespace std;

const int oo=1e9 + 7;

int lv[600000],vis[600000],pa[600000],n,q,l[600000],p[600000][20];
set<int> s,S;
vector<int> e[600000];

void dfs(int id,int lev,int pre)
{
    lv[id] = lev;
    vis[id] = 1;
    pa[id] = pre;
    for (int i = 0;i < e[id].size();i++)
    {
        if (vis[e[id][i]] == 0)
            dfs(e[id][i],lev + 1,id);
    }
}

void pre()
{
    for (int i = 1;i<=n;i++)
        p[i][0] = pa[i];
    for (int k = 1;k <= 19;k++)
        for (int i = 1;i <= n;i++)
            p[i][k] = p[p[i][k - 1]][k - 1];
}

int lca(int x,int y)
{
    for (int i = 19;i >= 0;i--)
        if (lv[p[x][i]] >= lv[y])
            x = p[x][i];
    for (int i = 19;i >= 0;i--)
        if (p[x][i] != p[y][i])
        {
            x = p[x][i];
            y = p[y][i];
        }
    x = pa[x];
    return x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>q;
    for (int i = 1;i <= n;i++)
        {
            cin>>l[i];
            if (l[i] == 1)
                s.insert(i);
        }
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (s.size() > 1)
        cout<<1<<endl;
    else cout<<0<<endl;
    for (int i = 1;i <= q;i++)
    {
        int c;
        cin>>c;
        if (l[c] == 1)
        {
            s.erase(c);
            l[c] = 0;
        }
        else
        {
            s.insert(c);
            l[c] = 1;
        }
        if (s.size() > 1)
            cout<<1<<endl;
                else cout<<0<<endl;
    }
}
