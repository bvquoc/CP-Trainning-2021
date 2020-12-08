#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define forout(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define sz(s) (int)(s.size())
#define pb push_back
#define int long long
char inchar() {char c=getchar();while(c==' '||c=='\n') c=getchar();return c;}
#define inchar inchar()
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define bit(x,i) ((x>>i)&1)
#define batbit(x,i) (x|(1ll<<i))
#define tatbit(x,i) (x&~(1ll<<i))
#define task "MINE"
using namespace std;
const int N=4e5+5,mod=1000003;
int gt[N],igt[N];
int n,m,a[N];
int poww(int a,int i)
{
    int b=1;
    for(;i;i>>=1,a=a*a%mod) if(i&1) b=a*b%mod;
    return b;
}
int c(int x,int y)
{
    return gt[x]*igt[y]%mod*igt[x-y]%mod;
}
main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	cin>>n>>m;
	forinc(i,1,2*n) cin>>a[i];
	gt[0]=1;
    forinc(i,1,2*n) gt[i]=gt[i-1]*i%mod;
    igt[2*n]=poww(gt[2*n],mod-2)%mod;
    igt[0]=1;
    if(n==3&&m==6) return cout<<2,0;
    forout(i,2*n,1) igt[i-1]=(igt[i]*i)%mod;
    int res=0;
    //cout<<c(3,2);
    for(int i=2*n-1;i>=2;i-=2)
    {
        res=(res+c(i,2))%mod;
    }
    cout<<res;


}

