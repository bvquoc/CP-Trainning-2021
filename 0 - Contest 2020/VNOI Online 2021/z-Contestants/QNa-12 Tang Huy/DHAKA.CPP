#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long oo=1e18;
int n,m,k,l,p[N];
long long d[N],dist[N][7];
typedef pair<long long,long long>ii;
typedef pair<long long,ii>iii;
vector<ii>a[N];
void dijkstra()
{
    priority_queue< ii , vector<ii> , greater<ii> > q;
    for (int i=1;i<=n;i++)
        d[i]=oo;
    q.push(ii(0,1));
    d[1]=0;
    while (!q.empty())
    {
        int u=q.top().second;
        long long du=q.top().first;
        q.pop();
        if (du!=d[u]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first;
            long long c=a[u][i].second;
            if (d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                q.push(ii(d[v],v));
            }
        }
    }
    if (d[n]==oo) cout<<-1;
    else cout<<d[n];
}
void dijkstra2()
{
     priority_queue< iii , vector<iii> , greater<iii> > q;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
        dist[i][j]=oo;
    int dem=__builtin_popcount(p[1]);
    q.push(iii(0,ii(1,p[1])));
    dist[1][dem]=0;
    while (!q.empty())
    {
        int u=q.top().second.first;
        long long du=q.top().first;
        int pr=q.top().second.second;
        q.pop();
        int Kpre=__builtin_popcount(pr);
        if (du!=dist[u][Kpre]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first;
            long long c=a[u][i].second;
            int K=__builtin_popcount(p[v]|pr);
            if (dist[v][K]>dist[u][Kpre]+c)
            {
                dist[v][K]=dist[u][Kpre]+c;
                q.push(iii(dist[v][K],ii(v,p[v]|pr)));
            }
        }
    }
    long long res=oo;
    for (int i=l;i<=k;i++)
        res=min(res,dist[n][i]);
    if (res==oo) cout<<-1;
    else cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for (int j=1;j<=x;j++)
            {
                int c;
                cin>>c;
                p[i]=p[i]|(1<<(c-1));
            }
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    if (l==0) dijkstra();
    else dijkstra2();
}

