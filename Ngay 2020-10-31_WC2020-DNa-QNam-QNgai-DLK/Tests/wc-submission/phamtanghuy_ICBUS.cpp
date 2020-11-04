#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long>ii;
const int N=1e4+5;
int n,k,c[N],d[N];
bool dd[N];
int dist[N];
long long f[N];
vector<int>adj[N];
vector<ii>a[N];
void BFS(int s)
{
    for (int i=1;i<=n;i++)
        dd[i]=true;
    for (int i=1;i<=n;i++)
    dist[i]=10000000000009;
    queue<int>q;
    q.push(s);
    dist[s]=0;
    dd[s]=false;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if (dist[u]<=d[s] && dist[u]!=0)
        {
            a[s].push_back(ii(u,c[s]));
        //    a[u].push_back(ii(s,c[s]));
      //      cout<<s<<" "<<u<<" "<<dist[u]<<endl;
        }
        for (int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if (dd[v]==true )
            {
                dist[v]=dist[u]+1;
                dd[v]=false;
                q.push(v);
            }
        }
    }
}
void dijkstra()
{
    priority_queue< ii , vector<ii> , greater<ii> > qq;
    for (int i=1;i<=n;i++)
        f[i]=10000000000009;
    qq.push(ii(0,1));
    f[1]=0;
    while (!qq.empty())
    {
        int u=qq.top().second;
        int du=qq.top().first;
        qq.pop();
        if (du!=f[u]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first;
            int c=a[u][i].second;
     //       cout<<u<<" "<<v<<" "<<c<<endl;
            if (f[v]>f[u]+c)
            {
                f[v]=f[u]+c;
                qq.push(ii(f[v],v));
            }
        }
    }
cout<<f[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i];
    }
    for (int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 //   cout<<endl;
    for (int i=1;i<=n;i++)
        {
            BFS(i);
        }
    dijkstra();
}
