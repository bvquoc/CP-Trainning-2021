#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define lam_tron cout<<fixed <<setprecision(2);
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*----------------------------------------------*/
int doc() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
const int M=4e5+5;
const int mod=1e6+3;
const double esp=1e-1;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
int n,m;
ll giaithua[M];
ll f[M],c[M];
int a[M];
ll mm(ll x,int y)
{
    if(y==0) return 1;
    ll tg=mm(x,y/2)%mod;
    if(y%2==0) return (tg*tg)%mod;
    return (x*((tg*tg)%mod))%mod;
}
void khoitao()
{
    giaithua[1]=1;
    for(int i=2;i<=M-5;i++) giaithua[i]=(giaithua[i-1]*i)%mod;
    for(int i=2;i<=M-5;i+=2)
    {
        ll tu=giaithua[i]%mod;
        ll mau=(giaithua[i/2]*giaithua[i/2])%mod;
        mau=(mau*(i/2+1))%mod;
        mau=mm(mau,mod-2);
        c[i]=(tu*mau)%mod;
    }
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios_base::sync_with_stdio(false);
    khoitao();
    cin>>n>>m;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    if(n<=2000)
    {
        f[0]=1;
        for(int i=2;i<=2*n;i+=2)
        {
            f[i]=0;
            int vt=lower_bound(a+1,a+i,a[i]-m)-a;
            for(int j=vt;j<i;j++)
                if((i-j-1)%2==0)
                {
                    int k=max(2,i-j-1);
                    f[i]=(f[i]+(f[j-1]*c[k])%mod)%mod;
                }
        }
        cout<<f[2*n]%mod;
    }
    else cout<<c[2*n]%mod;
    return 0;
}
