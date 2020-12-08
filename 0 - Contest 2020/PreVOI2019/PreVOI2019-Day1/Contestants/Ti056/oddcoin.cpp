#include<bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int coin[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int dp[N],n;
bool vis[50005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    for(int i=1;i<=N-5;i++)
    {
        dp[i]=i;
        for(int j=0;j<15;j++)
        {
            vis[coin[j]]=true;
            if(i>=coin[j]) dp[i]=min(dp[i],dp[i-coin[j]]+1);
            else break;
        }
    }
    int T;
    cin>>T;
    while(T--)
    {
        int x,t;
        cin>>x>>t;
        if(vis[x]||x>t)
        {
            cout<<dp[t]<<'\n';
            continue;
        }
        if(x<N&&t<N)
        {
            int res=t;
            for(int i=0;i*x<=t;i++) res=min(res,dp[t-i*x]+i);
            cout<<res<<'\n';
        }
        else
        {
            coin[15]=x;
            sort(coin,coin+16);
            int res=0;
            for(int i=15;i>=0;i--)
            {
                int cur=t/coin[i];
                res=res+cur;
                t-=coin[i]*cur;
            }
            cout<<res<<'\n';
        }
    }
}
