#define taskname "ODDCOIN"
#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e6+2;
int q, x, t, dp[maxn], a[15]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000}, ans;

void Enter()
{
    for(int i=1;i<=1e6;i++)
    {
        dp[i]=1e9;
        for(int j=0;j<15;j++)
        {
            if(a[j]>i)break;
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>t;
        ans=1e9;
        for(int i=(t-1)/1000000;1ll*i*x<=t;i++)
            ans=min(ans,i+dp[t-i*x]);
        cout<<ans<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    Enter();
}
