#include <bits/stdc++.h>
using namespace std;
#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define pb push_back;
int mod=1e6+3;
int dp[4010],n,m,a[4010];
int gt[1000000];
int igt[1000000];
int po(int a,int b)
{
    if(b==0)return 1;
    int t=po(a,b/2);
    if(b&1)return t*t%mod*a%mod;
    else return t*t%mod;
}
void solve()
{
    dp[0]=1;
    for(int i=2;i<=2*n;i+=2)
    {
        dp[i]=0;
        if(a[i]-a[i-1]<=m)dp[i]=dp[i-2];
        for(int j=i-4;j>=0;j-=2)
        {
            if(a[i]-a[j+1]>m)break;
            if(a[j+3]-a[j+2]<=m)dp[i]+=dp[j];
        }
        dp[i]%=mod;
    }
    cout<<dp[2*n];
}
void sub5()
{
    cout<<(po(2,n-1)+mod)%mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
    //int test;cin>>test;while(test--)
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)cin>>a[i];
    if(n<=2000)solve();
    else sub5();
    return 0;
}
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/
