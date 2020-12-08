#include <bits/stdc++.h>
using namespace std;
long long gt[800002],f[400002],a[400002],ng[800002],n,m,i,j;
const long long mod=round(1e6)+3;
long long ngoac(long long n)
{
    return gt[2*n]*(ng[n]*ng[n]%mod-ng[n-1]*ng[n+1]%mod+mod)%mod;
}
void sub1()
{
    f[0]=1;
    for(i=2;i<=2*n;i+=2)
    {
        for(j=i-2;j>=0;j-=2)
        {
            if(a[i]-a[j+1]>m) break;
            f[i]=(f[i]+f[j]*ngoac((i-j)/2-1)%mod)%mod;
        }
    }
    cout<<f[2*n];
}
long long lt(long long a,long long b)
{
    if(b==0) return 1;
    long long tg=lt(a,b/2);
    if(b%2==0) return tg*tg%mod;
    return tg*tg%mod*a%mod;
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin>>n>>m;
    if(n<=2000) for(i=1;i<=2*n;i++) scanf("%lld",&a[i]);
    gt[0]=1;
    for(i=1;i<=2*n;i++) gt[i]=gt[i-1]*i%mod;
    ng[n+1]=lt(gt[n+1],mod-2);
    for(i=n;i>=0;i--) ng[i]=ng[i+1]*(i+1)%mod;
    if(n>2000) cout<<ngoac(n);
    else sub1();
}
