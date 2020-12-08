#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define pb push_back
int dp[1000010],x,t;
int a[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
void sub2()
{
    vector<int>v;
    int sub=0;
    int max_val=max(50000,x);
    for(int i=0;i<15;i++)v.pb(a[i]);
    if(x<=1000000)v.pb(x);
    else
    {
        while(t>=x)
        {
            t-=x;
            ++sub;
        }
    }
    if(t>=1000000)
    {
        int dist=(t-1000000);
        int res=dist/max_val+(dist%max_val!=0);
        sub+=res;
        t-=res*max_val;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=1;i<=1000000;i++)dp[i]=1e9;
    dp[0]=0;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=0;j<v.size();j++)
            if(i-v[j]>=0)dp[i]=min(dp[i],dp[i-v[j]]+1);
        if(v.size()>1&&i>v[v.size()-1]*10)v.pop_back();
    }
    cout<<dp[t]+sub<<'\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("oddcoin.inp", "r", stdin);
    freopen("oddcoin.out", "w", stdout);
    int test;cin>>test;while(test--)
    {
        cin>>x>>t;
        sub2();
    }
    return 0;
}
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/
