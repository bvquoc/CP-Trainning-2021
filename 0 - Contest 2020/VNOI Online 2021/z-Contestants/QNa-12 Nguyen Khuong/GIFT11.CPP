#include <bits/stdc++.h>
using namespace std;
int a[2012],n;
int sz[2012];
const int MOD=998244353;
int calc(string x)
{
    int ans=0;
    for(int i=0; i<x.size(); i++)
    {
        int cs=x[i]-'0';
        ans+=((i&1)?-cs:cs);
    }
    return ans;
}
int f[(1<<20)][12];
long long opt(int cur, int bitmask, int exc, int pos)
{
    if (f[bitmask][exc]>-1) return f[bitmask][exc];
    if (__builtin_popcount(bitmask)==n)
    {
        return (exc==0);
    }
    long long ans=0;
    for(int next=1; next<=n; next++)
    {
        if (cur==next) continue;
        if ((bitmask>>(next-1))&1) continue;
        int newmask=bitmask|(1<<(next-1));
        int add=((pos&1)?-a[next]:a[next]);
        ans=(ans+opt(next,newmask,(exc+add+11)%11,pos+sz[next]))%MOD;
    }
    return f[bitmask][exc]=ans;
}
long long gt(int n)
{
    if (n==1) return n;
    return (gt(n-1)*n)%MOD;
}
int main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        bool alleven=1, allodd=1;
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            string x;
            cin>>x;
            sz[i]=x.size();
            if (sz[i]&1) alleven=0; else allodd=0;
            a[i]=calc(x);
            sum+=a[i];
        }
        memset(f,-1,sizeof(f));
        if (n<=200)
        {
            long long temp=opt(0,0,0,0);
            cout<<((temp)?temp:0)<<endl;
            continue;
        }
        if (alleven)
        {
            long long res=((sum+22)%11)?0:gt(n);
            cout<<res<<endl;
            continue;
        }
    }
}
