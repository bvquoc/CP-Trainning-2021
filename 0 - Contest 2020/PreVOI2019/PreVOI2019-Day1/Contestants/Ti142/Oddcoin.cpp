#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,x,q;
int f[19][13100005];
int a[18]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    cin>>q;
    while (q--)
    {
        cin>>t;
        a[16]=t;
        cin>>x;
        for (int i=0;i<=17;i++)
            for (int j=0;j<=x+1;j++)
                f[i][j]=1e9;
        for (int i=1;i<=16;i++)
        {
            for (int j=1;j<=x;j++)
            {
                if (j<a[i]) f[i][j]=f[i-1][j];
                else if (j==a[i]) f[i][j]=1;
                else f[i][j]=min(f[i-1][j],f[i][j-a[i]]+1);
            }
        }
        cout<<f[16][x]<<'\n';
    }
}
