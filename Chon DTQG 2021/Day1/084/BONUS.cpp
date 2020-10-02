#include <bits/stdc++.h>

using namespace std;
long long s;
int a[505][505],i,j,z,kt[505][505],n,r,k,g,h,x[100005],y[100005];
int main()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin>>n>>r>>k;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        cin>>a[i][j];
    for (i=1;i<=k;i++)
        cin>>x[i]>>y[i];
    for (i=1;i<=k;i++)
    {
        if (x[i]+r-1>n)
            h=n;
        else h=x[i]+r-1;
        if (y[i]+r-1>n)
            g=n;
        else g=y[i]+r-1;
        for (j=x[i];j<=h;j++)
            for (z=y[i];z<=g;z++)
            if (kt[j][z]==0)
        {
            s=s+a[j][z];
            kt[j][z]=1;
        }
    }
    cout<<s;
    return 0;
}
