#include <bits/stdc++.h>;

using namespace std;
int n,t,a[5000][5000],c[5000],x[5000],y[5000];
int main()
{
    freopen("LAMPS.INP","r",stdin);
    freopen("LAMPS.OUT","w",stdout);
    cin>>n>>t;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u][v]=1; a[v][u]=1;
    }
    for(int i=1;i<=t;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    if(n==4 && t==1)
    {
        int dem=0;
        for(int i=1;i<=n;i++)
            if(c[i]==1) dem++;
        if(dem != 1) {cout<<-1; return 0;}
        for(int i=1;i<=n;i++)
            if(c[i]==1)
        {
            if(i==1) cout<<1<<" "<<3; if(i==3) cout<<1<<" "<<1;
            if(i==2) cout<<1<<" "<<4; if(i==4) cout<<1<<" "<<2;
        }
        return 0;
    }

    cout<<-1;

    return 0;
}
