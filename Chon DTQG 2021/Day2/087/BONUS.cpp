#include <bits/stdc++.h>;

using namespace std;
int n,r,k,a[1000][1000],b[1000][1000],x[100005],y[100005];
int main()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin>>n>>r>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=k;i++) cin>>x[i]>>y[i];

        for(int p=1;p<=k;p++)
            for(int i=x[p]; i<=x[p]+r-1; i++)
            for(int j=y[p]; j<=y[p]+r-1; j++)
            b[i][j]=1;

        long long tong=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(b[i][j]==1) tong=tong+a[i][j];
        cout<<tong;

    return 0;
}
