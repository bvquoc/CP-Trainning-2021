#include <bits/stdc++.h>
#define ft first
#define sc second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int N=100005;
const int oo=1000000000;
int n,m,k,l,tt,dd;
int a[N];
int d[N],f[N],vi[N];
int ans=oo;
vector<ii> g[N];
int sobit(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
void dijsktra()
{
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii{0,1});
    while(!pq.empty())
    {
        int u=pq.top().sc;
        int du=pq.top().ft;
        pq.pop();
        if(du>d[u]) continue;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].ft;
            int dv=du+g[u][i].sc;
            if(dv<d[v])
            {
                d[v]=dv;
                pq.push(ii{d[v],v});
            }
        }
    }
    cout<<d[n];
}
void dfs(int u)
{
    vi[u]=1;
    int au=tt;
    tt=tt|a[u];
    if(sobit(tt)>=l&&u==n) ans=min(ans,dd);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].ft;
        if(!vi[v])
        {
            dd+=g[u][i].sc;
            dfs(v);
            dd-=g[u][i].sc;
        }
    }
    tt=au;
    vi[u]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)
        {
            int u;
            cin>>u;
            a[i]|=u;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(ii{v,w});
        g[v].push_back(ii{u,w});
    }
    for(int i=1;i<=n;i++) d[i]=oo;
    d[1]=0;
    tt=0;
    dd=0;
    if(n<=100)
    {
        dfs(1);
        cout<<(ans==oo? -1: ans);
    }
    else if(l==0) dijsktra();
    return 0;
}
