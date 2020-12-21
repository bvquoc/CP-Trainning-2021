#include <bits/stdc++.h>
using namespace std;
long long d[1000],MINC=INT_MAX,k,dem=0,ch[1000],Dem[1000],y[1009],s[1000],l,q[1000][1000],c[1000][1000],t[1000],u,minc,ans,v,w,kt[1000],n,m,S,f;
void khoitao()
{
    for(int u=1;u<=n;u++)
        d[u]=c[S][u];
    d[S]=0;
}
void dijkstra()
{
    int u,minc;
    do
    {
        u=0;
        minc=1000000000;
        for (int i=1;i<=n;i++)
            if (kt[i]==0 && minc>d[i])
            {
                u=i;
                minc=d[i];
            }
        kt[u]=1;
        for (int v=1;v<=n;v++)
            if (kt[v]==0 && d[v]>d[u]+c[u][v])
                d[v]=d[u]+c[u][v];
    }
    while(u!=0 && u!=f);
}
int main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
        for (int j=1;j<=s[i];j++)
        {
            cin>>q[i][j];
            Dem[q[i][j]]++;
        }
    }
    for (int i=1;i<=5;i++)
        if (Dem[i]!=0)
            dem++;
    if (dem<l)
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        c[u][v]=w;
        c[v][u]=w;
    }
    for(int u=1;u<=n;u++)
        for(int v=1;v<=n;v++)
            if(u!=v && c[u][v]==0)
                c[u][v]=1000000000;
    minc=INT_MAX;
    if (l==0)
    {
        S=1;
        f=n;
        khoitao();
        dijkstra();
        if (d[n]==1000000000)
            cout<<-1;
        else
        cout<<d[n];
        return 0;
    }
    if (k==1)
    {
        if (s[1]!=0 || s[n]!=0)
        {
            S=1;
            f=n;
            khoitao();
            dijkstra();
            if (d[n]==1000000000)
            cout<<-1;
        else
        cout<<d[n];
            return 0;
        }
        else {
            for (int i=2;i<n;i++)
            {
                if (s[i]!=0)
                {
                    S=1;
                    f=i;ans=0;
                    khoitao();
                    dijkstra();
                    ans+=d[i];
                    S=i;
                    f=n;
                    khoitao();
                    dijkstra();
                    ans+=d[n];
                    minc=min(minc,ans);
                }
            }
            cout<<minc;
            return 0;
        }
    }cout<<-1;
    return 0;
}
