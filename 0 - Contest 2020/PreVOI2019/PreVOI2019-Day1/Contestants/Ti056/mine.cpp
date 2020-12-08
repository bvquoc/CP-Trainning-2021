#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=4005;
const int M=1e6+5;
const int mod=1e6+3;
int n,a[N],dp[N],m,f[N][N];

int calc(int l,int r)
{
    if(f[l][r]!=-1) return f[l][r];
    if(r==l+1)
    {
        if(a[r]-a[l]>m) return 0;
        return 1;
    }
    int &res=f[l][r];
    res=0;
    if(a[r]-a[l]<=m) res=(res+calc(l+1,r-1))%mod;
    if(a[r]-a[r-1]<=m) res=(res+calc(l,r-2))%mod;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MINE.INP","r",stdin);
    freopen("MINE.OUT","w",stdout);
    memset(f,-1,sizeof f);
    cin>>n>>m;
    for(int i=1;i<=n*2;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    dp[0]=1;
    for(int i=1;i<=n*2;i++)
    {
        for(int j=1;j<i;j++)
        {
            if((i-j+1)%2) continue;
            if(a[i]-a[j]>m) continue;
            if(j!=i-1) dp[i]=(dp[i]+calc(j+1,i-1)*dp[j-1])%mod;
            else dp[i]=(dp[i]+dp[j-1])%mod;
        }
        //cout<<i<<' '<<dp[i]<<'\n';
    }
    cout<<dp[2*n];
}
