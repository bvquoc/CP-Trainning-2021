#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+12;
long long n,k;
struct request
{
    long long s;
    long long e;
    long long r;
    request(){};
    request(long long _s, long long _e, long long _r)
    {
        s=_s;
        e=_e;
        r=_r;
    }
}a[N];
long long dp[N];
bool cmp(request a, request b)
{
    return (a.e<b.e);
}
int main()
{
    //freopen("FACILITY.INP","r",stdin);
    cin>>n>>k;
    for(long long i=1; i<=n; i++)
    {
        long long start, day, en, revenue;
        cin>>start>>day>>revenue;
        en=start+day;
        a[i]=request(start,en,revenue);
    }
    sort(a+1,a+n+1,cmp);
    dp[1]=a[1].r;
    for(long long i=2; i<=n; i++)
    {
        long long l=1, r=i-1;
        long long vt=0;
        while (l<=r)
        {
            long long m=(l+r)/2;
            if (a[m].e<=a[i].s-k)
            {
                vt=m;
                l=m+1;
            }
            else r=m-1;
        }
        dp[i]=max(dp[i-1],dp[vt]+a[i].r);
    }
    cout<<dp[n];
}
