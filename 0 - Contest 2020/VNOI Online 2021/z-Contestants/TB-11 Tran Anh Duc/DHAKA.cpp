#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
#define int long long
using namespace std;
const int oo=1e18;
const int MAXN=1e5+1;
int n,m,k,l;
vector<pii> adj[MAXN];
vector<pii> v[MAXN];
int d[MAXN],d1[MAXN],mark[MAXN],dp[MAXN][5];
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        d[i]=oo;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    d[1]=0;
    while(pq.size())
    {
        int u=pq.top().se;
        int du=pq.top().fi;
        pq.pop();
        if(d[u]!=du)
        {
            continue;
        }
        for(pii h : adj[u])
        {
            int v=h.fi;
            int uv=h.se;
            if(d[v]>du+uv)
            {
                d[v]=du+uv;
                pq.push({d[v],v});
            }
        }
    }
}
void dijkstra_reverse()
{
    for(int i=1;i<=n;i++)
    {
        d1[i]=oo;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,n});
    d1[n]=0;
    while(pq.size())
    {
        int u=pq.top().se;
        int du=pq.top().fi;
        pq.pop();
        if(d1[u]!=du)
        {
            continue;
        }
        for(pii h : adj[u])
        {
            int v=h.fi;
            int uv=h.se;
            if(d1[v]>du+uv)
            {
                d1[v]=du+uv;
                pq.push({d1[v],v});
            }
        }
    }
}
void sub2()
{
    dijkstra();
    cout<<d[n];
}
void sub3()
{
    dijkstra();
    dijkstra_reverse();
    int mi=oo;
    for(int i=1;i<=n;i++)
    {
        for(pii h : v[i])
        {
            int tmp=h.fi;
            if(tmp==1)
            {
                mi=min(mi,d[i]+d1[i]);
                break;
            }
        }
    }
    cout<<mi;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP" , "r" , stdin);
    freopen("DHAKA.OUT" , "w" , stdout);
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        for(int j=1;j<=tmp;j++)
        {
            int temp;
            cin>>temp;
            v[i].push_back({tmp,temp});
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    if(l==0)
    {
        sub2();
        return 0;
    }
    if(k==1)
    {
        sub3();
        return 0;
    }
    return 0;
}
