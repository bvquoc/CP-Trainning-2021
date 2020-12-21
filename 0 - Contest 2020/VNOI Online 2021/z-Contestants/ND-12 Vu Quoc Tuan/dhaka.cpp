#include <bits/stdc++.h>

using namespace std;
long long n,m,d[100005][(1<<5)+5],k,l,tt[100005];
bool kt[100005][(1<<5)+5];
vector<pair<long long,int> > a[100005];
priority_queue<pair<long long,pair<int,int> >, vector<pair<long long,pair<int,int> > >, greater<pair<long long,pair<int,int> > > > q;
long long ditcha()
{
    for (int i=1;i<=n;++i)
     for (int j=0;j<(1<<k);++j) d[i][j]=1e18;
    d[1][0]=0;
    q.push({0,{1,0}});
    while (!q.empty())
    {
        int u=q.top().second.first;
        int x=q.top().second.second;
        q.pop();
        if (u==n && __builtin_popcount(x)>=l) return d[u][x];
        if (kt[u][x]) continue;
        kt[u][x]=true;

        int nx=(x|tt[u]);
        if (d[u][nx]>d[u][x])
        {
            d[u][nx]=d[u][x];
            q.push({d[u][nx],{u,nx}});
        }

        for (int i=0;i<a[u].size();++i)
        {
            int v=a[u][i].second;
            long long w=a[u][i].first;
            if (d[v][x]>d[u][x]+w)
            {
                d[v][x]=d[u][x]+w;
                q.push({d[v][x],{v,x}});
            }
        }

    }
    return -1;
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;++i)
    {
        int sl;
        cin>>sl;
        while (sl--)
        {
            int x;
            cin>>x;
            --x;
            tt[i]|=(1<<x);
        }
    }
    for (int i=1;i<=m;++i)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    cout<<ditcha();

    return 0;
}
