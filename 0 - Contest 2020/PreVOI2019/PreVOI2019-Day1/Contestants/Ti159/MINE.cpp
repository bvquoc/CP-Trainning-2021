#include <bits/stdc++.h>
#define nmax 200000
#define mmax 1000000
#define mod 1000003
using namespace std;
int n,m,dd[mmax+10],t[nmax*2+20],cnt;
long long dp[300];
void in()
{
    cin>>n>>m;
    for(int i=1;i<=n+n;i++)
      cin>>t[i];
}
void bktrk(int x)
{
    for(int i=1;i<=n<<1;i++)
    if(dd[i]==0){
      dd[i]=1;
      for(int j=i+1;j<=n+n&&t[j]-t[i]<=m;j+=2){
          dd[j]=1;
          if(x==n){
            cnt++;
            if(cnt>mod) cnt-=mod;
          }
          else bktrk(x+1);
          dd[j]=0;
          if(dd[j+1]==1) break;
      }
      dd[i]=0;
      break;
    }
}
void sub1()
{
    cnt=0;
    bktrk(1);
    cout<<cnt;
}
void sub2()
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
      for(int j=i-1;j>=0;j--)
        dp[i]=(dp[i]+dp[j]*dp[i-1-j])%mod;
    cout<<dp[n];
}
void sub5()
{

}
void run()
{
    in();
    //if(n<=10) sub1();else
     if(n<=200&&m==1000000) sub2();else
    if(n<=2000000&&m==1000000) sub5();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    run();
    return 0;
}
