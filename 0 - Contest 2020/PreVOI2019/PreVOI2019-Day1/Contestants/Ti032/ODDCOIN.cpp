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
const int M=1e7+5;
const int mod=1e9+7;
const double esp=1e-1;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
int a[20];
int f[50005];
ll g[M];
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    a[1]=1;a[2]=3;a[3]=5;
    int base=10;
    for(int i=2;i<=5;i++)
    {
        a[(i-1)*3+1]=a[(i-2)*3+1]*base;
        a[(i-1)*3+2]=a[(i-2)*3+2]*base;
        a[(i-1)*3+3]=a[(i-2)*3+3]*base;
    }
    f[0]=0;
    for(int i=1;i<=50000;i++)
    {
        f[i]=mod;
        for(int j=1;j<=15;j++)
            if(i>=a[j]) f[i]=min(f[i],f[i-a[j]]+1);
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll x,t;
        cin>>x>>t;
        ll k=t/x;
        if(k<=10000000)
        {
            ll ans=1ll*mod*mod;
            for(int i=0;i<=k;i++)
            {
                ll du=t-1ll*x*i;
                ans=min(ans,f[du%50000]+du/50000+i);
            }
            cout<<ans<<"\n";
        }
        else
        {
            g[0]=0;
            a[16]=x;
            for(int i=1;i<=t;i++)
            {
                 g[i]=1ll*mod*mod;
                for(int j=1;j<=16;j++)
                    if(i>=a[j]) g[i]=min(g[i],g[i-a[j]]+1);
            }
            cout<<g[t]<<"\n";
        }
    }
    return 0;
}
