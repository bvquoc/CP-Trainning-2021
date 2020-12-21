#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,l,k,d[10005],a[10005];
vector <pii> adj[10005];
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i=1; i<=n; i++)
        d[i]=INT_MAX;
    d[1]=0;
    pq.push(pii(0,1));
    while (pq.size())
    {
        int u=pq.top().second;
        int du= pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].second;
            int uv=adj[u][i].first;
            if (d[v] > du+ uv)
            {
                d[v]=du+uv;
                pq.push(pii(d[v],v));
            }
        }
    }
}
int main()
{
    freopen("DHAKA.inp","r",stdin);
   freopen("DHAKA.out","w",stdout);
    cin >>n>>m>>k>>l;
    for (int i=1; i<=n; i++)
        cin >>a[i];
    for (int i=1; i<=m; i++)
    {
        int u,v,w;
        cin >>u>>v>>w;
        adj[u].push_back(pii(w,v));
        adj[v].push_back(pii(w,u));
    }
    if (l==0)
    {
        dijkstra();
        cout <<d[n];
    }
    else
        cout <<"-1";
    return 0;
}
