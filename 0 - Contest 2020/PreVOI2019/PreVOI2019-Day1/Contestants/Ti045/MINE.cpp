#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)#define onbit(x,i) (x|(1<<(i-1)))#define offbit(x,i) (x&~(1<<(i-1)))
const int N=400010,mod=1e6+3;
int n,m,a[N];
ll pw(int a,int b)
{
    if(!b) return 1;
    ll tg=pw(a,b/2);
    tg=tg*tg%mod;
    if(b%2) return tg*a%mod;
    return tg;
}
ll M[N],D[N],f[N];
ll C(int n,int k)
{
    return M[n]*D[k]*D[n-k]%mod;
}
ll CTL(int n)
{
    if(n%2) return 0;
    if(!n) return 1;
    return (C(n,n/2)-C(n,n/2-1))%mod;
}
int main()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    n=in,m=in;
    forinc(i,1,2*n) a[i]=in;
    M[0]=1;
    forinc(i,1,2*n) M[i]=M[i-1]*i%mod;
    D[2*n]=pw(M[2*n],mod-2);
    fordec(i,2*n,1) D[i-1]=D[i]*i%mod;
    if(m==1000000) return cout<<(CTL(2*n)+mod)%mod,0;
    f[0]=1;
    forinc(i,1,2*n) if(f[i-1]) forinc(j,i+1,2*n)
    {
        if(a[j]-a[i]>m) break;
        f[j]=(f[j]+f[i-1]*CTL(j-i-1))%mod;
    }
    cout<<(f[2*n]+mod)%mod;
}
