#include <bits/stdc++.h>
#define fort(i,a,b) for(long i=a;i<=b;i++)
#define pb push_back
using namespace std;
const long N=5e5+5;
long n,m,k,rs,l,r,sum[N],bit[N],lx,rx;
char s[N];
vector<vector<long> >a;
void sub1()
{
    fort(i,1,n)
     {
         sum[i]=sum[i-1]+(s[i]=='0');
         long d=lower_bound(sum,sum+1+i,sum[i]-k)-sum;
         if (rs<i-d)
         {
             rs=i-d;
             l=d+1;r=i;
         }
     }
    if (l==0) cout<<"-1\n";else
        cout<<l<<' '<<r<<'\n';
}
long day(long x)
{
    long rs;
    if (s[x]=='0') rs=x;else rs=n+1;
    for(long i:a[x])
        if (i<x) rs=min(rs,day(i));
    return rs;
}
long up(long x)
{
    long rs=n+1;
    if (s[x]=='0') return x;
    for(long i:a[x])
        if (i>x) rs=min(rs,up(i));
    return rs;
}
void upd(long i,long val)
{
    for(;i<=n;i+=i&-i) bit[i]+=val;
}
long gts(long i)
{
    long rs=0;
    for(;i>=1;i-=i&-i) rs+=bit[i];
    return rs;
}
bool ok(long l,long r)
{
    return (gts(r)-gts(l-1)<=k);
}
void sub2()
{
    fort(i,1,m)
    {
        long u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    //fort(i,1,n) sort(a[i].begin(),a[i].end());
    fort(i,1,n)
     if (s[i]=='1')
     {
         long tt=day(i);
         if (tt<=n) swap(s[tt],s[i]);
     }
    fort(i,1,n)
     if (s[i]=='0') upd(i,1);
    fort(i,1,n)
     {
         l=i-1;r=n;
         while (l<r)
         {
             long mid=(l+r+1)/2;
             if (ok(i,mid)) l=mid;else r=mid-1;
         }
         if (l-i+1>rs)
         {
             rs=l-i+1;
             lx=i;rx=l;
         }
         if (s[i]=='1')
         {
             long tt=up(i);
             if (tt<=n)
             {
                 upd(i,1);upd(tt,-1);
                 swap(s[i],s[tt]);
             }
         }
     }
     if (lx==0) cout<<"-1\n";else
     cout<<lx<<' '<<rx<<'\n';
}
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    a.resize(n+1);
    fort(i,1,n) cin>>s[i];
    if (m==0) sub1();else sub2();
    return 0;
}
