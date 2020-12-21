#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pii;

struct canh
{
    long long u,v,w;
}c[200005];

const long long maxN=100005,infi=1e18+10;
vector<pii> xuoi[maxN],dao[maxN];
long long k,l,res=infi,dis,n,m,v,u,w;
long long f[maxN],g[maxN],s[maxN],a[maxN][10];

void dijkstra(long long s, long long d[maxN], vector<pii> adj[maxN])
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (long long i=1;i<=n;i++) d[i]=infi;
    d[s]=0;
    pq.push(pii(0,s));

    while (!pq.empty())
    {
        long long u=pq.top().second, du=pq.top().first;
        pq.pop();
        if (du>d[u]) continue;

        for (long long i=0;i<adj[u].size();i++)
        {
            long long v=adj[u][i].second,dv=adj[u][i].first;
            if (d[v]>du+dv)
            {
                d[v]=du+dv;
                pq.push(pii(d[v],v));
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin >>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        cin >>s[i];
        for (int j=1;j<=s[i];j++) cin >>a[i][j];
    }
    for (long long i=1;i<=m;i++)
    {
        cin >>u>>v>>w;
        c[i].u=u;   c[i].v=v;   c[i].w=w;

        xuoi[u].push_back(pii(w,v));
        dao[v].push_back(pii(w,u));
    }
    dijkstra(1,f,xuoi);
    dijkstra(n,g,dao);

    for (long long i=1;i<=m;i++)
    {
        dis=f[c[i].u]+g[c[i].v]+c[i].w;
        res=min(res,dis);
    }
    if (res==infi)
    {
        cout <<-1;
        return 0;
    }
    cout <<res;

    return 0;
}
