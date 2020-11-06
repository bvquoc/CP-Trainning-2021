#include<bits/stdc++.h>
using namespace std;
long long n,m,p,l,k,d[10009];
typedef pair<long long,long long>ii;
vector<ii>a[20009];
void dijkstra()
{
    priority_queue< ii , vector<ii> , greater<ii> > q;
    for (int i=1;i<=n;i++)
        d[i]=10000000000009;
    q.push(ii(0,1));
    d[1]=0;
    while (!q.empty())
    {
        int u=q.top().second;
        int du=q.top().first;
        q.pop();
        if (du!=d[u]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first;
            int c=a[u][i].second;
            if (d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                q.push(ii(d[v],v));
            }
        }
    }

    if (d[n]==10000000000009) cout<<-1;
    else
    cout<<d[n];
}
int main()
{
    cin>>n>>m>>p>>l>>k;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    dijkstra();
}
