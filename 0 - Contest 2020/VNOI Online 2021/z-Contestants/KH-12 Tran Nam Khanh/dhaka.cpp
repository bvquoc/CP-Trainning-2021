#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define int long long
using namespace std;
const int nax=1e5+5;
const int inf=1e18;
int n,m,k,l,mask[nax],d[nax][1<<5];
vector<pair<int,int> >a[nax];
void dij()
{
    priority_queue<pair<int,pair<int,int> > >q;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<k);j++)
        {
            d[i][j]=inf;
        }
    }
    d[1][mask[1]]=0;
    q.push({0,{1,mask[1]}});
    while(!q.empty())
    {
        int u=q.top().second.first,j=q.top().second.second,value=-q.top().first;q.pop();
        if(value>d[u][j])continue;
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first,c=a[u][i].second,newmask=j|mask[v];
            if(d[v][newmask]>d[u][j]+c)
            {
                d[v][newmask]=d[u][j]+c;
                q.push({-d[v][newmask],{v,newmask}});
            }
        }
    }
    int ans=inf;
    for(int i=0;i<(1<<k);i++)
    {
        int cnt=0;
        for(int j=0;j<k;j++)
        {
            if((i&(1<<j)))cnt++;
        }
        if(cnt>=l)ans=min(ans,d[n][i]);
    }
    if(ans<inf)cout<<ans<<endl;else cout<<-1<<endl;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)
        {
            int a;
            cin>>a;
            mask[i]|=(1<<(a-1));
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    dij();
    return 0;
}
/*
6 6 2 2
0
1 1
0
0
1 2
0
1 2 1
2 3 2
1 3 2
4 5 2
5 4 1
3 5 1
*/
