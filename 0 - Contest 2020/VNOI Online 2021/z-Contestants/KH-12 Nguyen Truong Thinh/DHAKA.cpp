#include<bits/stdc++.h>
#define int long long
using namespace std;
int shift;
int d[100009][33];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<ii> b[100009];
int gt[100009];
int n,m,k,l;
const int oo=1e17;
void dijktra(int s)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=shift;j++) {
        d[i][j]=oo;
        }
    }
    int u=gt[s];
    d[1][u]=0;
    priority_queue <iii, vector<iii>, greater<iii> > qu;
    qu.push(iii(0,ii(s,u)));
    while (qu.empty()==0)
    {
        iii top=qu.top();
        qu.pop();
        int z1=top.second.first;
        int z2=top.second.second;
        if (d[z1][z2]!=top.first)
        {
            continue;
        }
        for (int i=0;i<b[z1].size();i++)
        {
            ii v=b[z1][i];
            int o=gt[v.second];
            int o1=o|z2;
            if (d[v.second][o1]>d[z1][z2]+v.first)
            {
                d[v.second][o1]=d[z1][z2]+v.first;
                qu.push(iii(d[v.second][o1],ii(v.second,o1)));
            }
        }
    }
}
 main()
{
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        int s;
        cin>>s;
        int o=0;
        for (int j=1;j<=s;j++)
        {
            int v;
            cin>>v;
            //a[i].push_back(v);
            int tam=1LL<<(v-1);
            o=o|tam;
        }
        gt[i]=o;
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        b[u].push_back(ii(w,v));
        b[v].push_back(ii(w,u));
    }
    shift=(1LL<<k)-1;
    dijktra(1);
    int mi=oo;
    for (int i=0;i<=shift;i++)
    {
        int tam=0;
        for (int j=0;j<k;j++)
        {
            int o=1LL<<j;
            int kt=o&i;
            if (kt!=0)
            {
                tam++;
            }
        }
        if (tam>=l)
        {
            mi=min(mi,d[n][i]);
        }
    }
    if (mi==oo)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<mi<<endl;
    }
    return 0;
}
