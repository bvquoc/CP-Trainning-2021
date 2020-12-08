                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "oddcoin"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
const int n=15;
int a[18]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int cnt[18];
int dp[100005];
void make_bang()
{
    for(int i=0;i<=100000;i++)
    {
        dp[i]=i;
    }
    for(int i=0;i<=15;i++)
    {
        cnt[a[i]]++;
    }
    dp[0]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=100000;j>=a[i];j--)
        {
            for(int k=1;k<=10;k++)
            {
                if(j-a[i]*k<0) break;
                dp[j]=min(dp[j],dp[j-a[i]*k]+k);
            }
        }
    }
}
int trau(int kq,int x)
{
    int dem=0;
    int flag=0;
    int j=15;
    while(kq>0&&j>=1)
    {
        if(x>a[j]&&flag==0)
        {
            flag=1;
            dem+=kq/x;
            kq=kq%x;
        }
        else
        {
            dem+=kq/x;
            kq=kq%x;
            j--;
        }
    }
    return dem;
}
void nhap()
{
    int x,kq;
    int res=INT_MAX;
    cin>>x>>kq;
    if(kq>100000)
    {
        cout<<trau(kq,x);
        return ;
    }
    if(x<=100000&&cnt[x]==1)
    {
        cout<<dp[kq];
        return ;
    }
    for(int k=0;k<=kq/x;k++)
        {
            res=min(res,dp[kq-x*k]+k);
        }
    cout<<res<<'\n';
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    make_bang();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        nhap();
}
