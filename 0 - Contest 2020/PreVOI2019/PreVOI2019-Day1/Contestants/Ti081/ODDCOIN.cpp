#include<bits/stdc++.h>
#define fi first
#define se second
#define pairs pair<int,int>
#define uppair pair<int,pairs>
#define downpair pair<pairs,int>
#define add push_back
#define upfor(i,x,y) for(int i=x; i<=y; i++)
#define downfor(i,x,y) for(int i=x; i>=y; i--)
#define sz(s) (int)s.size()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define maxm 200001
#define maxn 100010
using namespace std;

int q;
long long res;
long long c[20], f[maxn];

void online_judge()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
}

void solve1(long long x, long long t, long long cost)
{
    if(t<0) return;
    if(t == 0)
    {
        res = min(res,cost);
        return;
    }
    if(t>=x and cost+1<res) solve1(x,t-x,cost+1);
    if(t>=10 and cost+1<res) solve1(x,t-10,cost+1);
    if(t>=5 and cost+1<res) solve1(x,t-5,cost+1);
    if(t>=3 and cost+1<res) solve1(x,t-3,cost+1);
    if(t>=1 and cost+1<res) solve1(x,t-1,cost+1);
}

void makecoin()
{
    c[1]=1; c[2]=3; c[3]=5; c[4]=10; c[5]=30;
    c[6]=50; c[7]=100; c[8]=300; c[9]=500; c[10]=1000;
    c[11]=3000; c[12]=5000; c[13]=10000; c[14]=30000; c[15]=50000;
}

void solve2(long long x, long long t)
{
    makecoin();
    upfor(i,0,t) f[i] = 1e18;
    f[0] = 0;
    c[16]=x;
    sort(c+1,c+16+1);
    int n, j;
    upfor(i,1,t)
    {
        n = lower_bound(c+1,c+16+1,i) - c;
        j = 1;
        while(j<n)
        {
            f[i] = min(f[i],f[i-c[j]]+1);
            j++;
        }
        if(c[n]<=i) f[i] = min(f[i],f[i-c[n]]+1);
    }
    cout<<f[t]<<'\n';
}

void solve()
{
    cin>>q;
    long long x, t;
    while(q>0)
    {
        cin>>x>>t;
        if(x<=20 and t<=20)
        {
            res = 1e18;
            solve1(x,t,0);
            cout<<res<<'\n';
            q--;
            continue;
        }
        if(x<=100000 and t<=100000)
        {
            solve2(x,t);
            q--;
            continue;
        }
        else
        {
            cout<<1<<'\n';
            q--;
            continue;
        }
    }
}

int main()
{
    fastread
    online_judge();
    solve();
    return 0;
}
