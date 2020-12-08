#include <bits/stdc++.h>
#define tmax3 50000000
#define coinmax 15
#define oo 2000000001
using namespace std;
const int coins[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int x,t,dp[tmax3+10];
void in()
{
    cin>>x>>t;
}
void sub3()
{
    dp[0]=0;
    for(int i=1;i<=t;i++){
      dp[i]=oo;
      for(int j=0;j<coinmax;j++) if(coins[j]<=i)
        dp[i]=min(dp[i],dp[i-coins[j]]+1);
      if(x<=i)
        dp[i]=min(dp[i],dp[i-x]+1);
    }
    cout<<dp[t]<<'\n';
}
void run()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
      in();
      sub3();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    run();
    return 0;
}
