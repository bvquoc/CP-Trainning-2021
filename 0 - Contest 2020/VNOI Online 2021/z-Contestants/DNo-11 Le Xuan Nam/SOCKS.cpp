#include <bits/stdc++.h>

using namespace std;
long long c[100009],a[1009][1009],dem,x,y,n,m,i,j;
int main()
{
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>c[i];
    for (i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for (i=1;i<=n;i++)
        if (c[i]==1)
            dem++;
    if (dem>=2)
        cout<<1<<endl;
    else cout<<0<<endl;
    for (i=1;i<=m;i++)
    {
        cin>>x;
        if (c[x]==0)
            c[x]=1;
        else c[x]=0;
        dem=0;
        for (j=1;j<=n;j++)
            if (c[j]>0)
                dem++;
        if (dem>=2)
            cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
