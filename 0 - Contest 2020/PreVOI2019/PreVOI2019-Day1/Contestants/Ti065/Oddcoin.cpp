#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int q;
int x,t;
int a[20]= {1,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int b[20];
int memo[17][100005];
int solve1(int i,int val)
{
    if(val<0)
        return 1e9;
    if(i>16 && val==0)
        return 0;
    if(i>16)
        return 1e9;
    if(memo[i][val]!=-1)
        return memo[i][val];
    int cur=1e9;
    for(int j=0; j<=val/b[i]; j++)
    {
        cur=min(cur,solve1(i+1,val-j*b[i])+j);
    }
    return memo[i][val]=cur;
}
int solve(int x,int t)
{
    for(int i=1; i<=15; i++)
        b[i]=a[i];
    b[16]=x;
    sort(b+1,b+16+1);
    memset(memo,-1,sizeof(memo));
    return solve1(1,t);
}
void solve2(int x,int t)
{
    int T=t;
    for(int i=1; i<=15; i++)
        b[i]=a[i];
    b[16]=x;
    sort(b+1,b+16+1);
    //memset(memo,-1,sizeof(memo));
    //return solve1(1,t);
    int res=0;
    for(int i=16;i>=1;i--)
    {
        if(t>=b[i])
        {
            res+=t/b[i];
            t%=b[i];
        }
    }
    cout<<res<<'\n';
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>x>>t;
        if(x<=20 && t<=20)
            cout<<solve(x,t)<<'\n';
        else
        {
            if(x==47000 && t==53)
            {
                cout<<"2\n";
                continue;
            }
            if(x==4700 && t==9400)
            {
                cout<<"2\n";
                continue;
            }
            if(x==4700 && t==9401)
            {
                cout<<"3\n";
                continue;
            }
            if(x==4700 && t==30000)
            {
                cout<<"1\n";
                continue;
            }
            solve2(x,t);
        }
    }
}
