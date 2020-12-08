#include <bits/stdc++.h>
#define PII pair<int,int>
#define LL long long
#define F first
#define S second
using namespace std;
const int N=4003;
const int mod=1e6+3;
int f[N][N],dp[N],a[N],n,m;
void sub1()
{
    f[1][1]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<=i;j++) f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%mod;
        for (int j=0;j<2;j++) f[i][j]=f[i-1][j+1];
    }
    dp[0]=1;
    for (int i=2;i<=n;i+=2)
    for (int j=0;j<i;j+=2)
    if (a[i]-a[j+1]<=m)
        dp[i]=(dp[i]+(LL)dp[j]*f[i-j][0]%mod)%mod;
    cout<<dp[n];
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>n>>m;n*=2;
    for (int i=1;i<=n;i++) cin>>a[i];
    sub1();
    return 0;
}
