#include <bits/stdc++.h>

using namespace std;
long long kq,mod,gt[200005],dp[200005],n,a[200005],bit[200005],g[200005];
long long tong(long long x)
{
    long long ans=x*(x+1)/2;
    ans%=mod;
    return ans;
}
void up(int x)
{
    for (;x<=n;x+=(x&(-x)))
     ++bit[x];
}
long long get(int x)
{
    long long ans=0;
    for (;x>0;x-=(x&(-x))) ans+=bit[x];
    return ans;
}
long long solve()
{
    memset(bit,0,sizeof(bit));
    g[n+1]=1;
    for (int i=n;i>0;--i)
    {
        up(a[i]);
        long long x=get(a[i])-1;
        g[i]=(x*gt[n-i]%mod+g[i+1])%mod;
    }
    memset(bit,0,sizeof(bit));
    long long ans=0;
    for (int i=1;i<=n;++i)
    {
        up(a[i]);
        long long x=a[i]-get(a[i]);
        ans=(ans+x*g[i+1])%mod;
        ans=(ans+x*dp[n-i]%mod+tong(x-1)*gt[n-i]%mod)%mod;


    }
    return ans;
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    mod=1e9+7;
    gt[0]=1;
    for (int i=1;i<=n;++i) gt[i]=gt[i-1]*i%mod;
    for (long long i=1;i<=n;++i)
    {
        dp[i]=i*dp[i-1]%mod;

        dp[i]=(dp[i]+tong(i-1)*gt[i-1])%mod;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        up(a[i]);
        kq=(kq+a[i]-get(a[i]))%mod;
    }
    kq=(kq-solve()+mod)%mod;

    for (int i=1;i<=n;++i) cin>>a[i];
    kq=(kq+solve())%mod;

    cout<<kq;

    return 0;
}
