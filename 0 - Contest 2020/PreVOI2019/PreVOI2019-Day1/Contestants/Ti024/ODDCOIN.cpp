/// !! Killian !! ///

#include <bits/stdc++.h>
#define Killian "ODDCOIN"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int b[17]= {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int a[17];
int dp[17][1000005];
int T,x,t;
int n=16;
void del()
{
    memset(dp,64,sizeof(dp));
    for (int i=1; i<=n; i++)
        dp[i][0]=0;
}
void sub12()
{
    del();
    for (int i=1; i<=n; i++)
        for (int j=1; j<=t; j++)
            dp[i][j]=min(dp[i-1][j],1+dp[i][j-a[i]]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>x>>t;
        for (int i=1; i<=n-1; i++)
            a[i]=b[i];
        a[n]=x;
        if (t<=1e6)
        {
            sub12();
            cout<<dp[n][t]<<endl;
        }
        else
        {
            sort(a+1,a+1+n);
            int i=n,res=0;
            while (t>0 && i>=1)
            {
                while (t>=a[i])
                {
                    t-=a[i];
                    res++;
                }
                i--;
            }
            cout<<res<<endl;
        }
    }
}
