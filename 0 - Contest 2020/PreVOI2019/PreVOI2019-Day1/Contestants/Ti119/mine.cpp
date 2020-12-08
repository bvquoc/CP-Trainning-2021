#include<bits/stdc++.h>
#define name "mine"
#define input  freopen(name".inp","r",stdin)
#define output freopen(name".out","w",stdout)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rev(i,a,b) for(int i=a;i>=b;--i)
#define wipe(x) memset(x,0,sizeof(x))
#define sqr(x) ((x)*(x))
#define sz(x) (x.size())
#define pb push_back
#define pp pair<int,int>
#define x first
#define y second
#define ll int64_t
#define ld double
using namespace std;

const int maxn=2e5+5, mod=1e6+3;
int n,m,res=0;
int a[25], d[25], start[25], f[maxn];

int cal(int k)
{
    if(f[k]) return f[k];
    if(k==0) return f[k]=1;
    int tmp=0;
    rep(i,0,k-1) tmp=((ll)cal(i)*cal(k-i-1)%mod+tmp)%mod;
    return f[k]=tmp;
}

bool check(int k)
{
    rep(i,k+1,n) if(d[i]==1) return 0;
    return 1;
}

void bt(int i)
{
    rep(j,1,n) if(d[j-1]>0 && d[j]<2 && check(j))
    {
        if(!d[j]) start[j]=a[i];
        else if(a[i]-m>start[j]) continue;
        ++d[j];
        if(i<2*n) bt(i+1);
        else res=(res+1)%mod;
        --d[j];
    }
}

void sub1()
{
    rep(i,1,2*n) scanf("%d",a+i);
    d[0]=2;
    bt(1);
    printf("%d",res);
}

int main()
{
    input; output;
    scanf("%d %d",&n,&m);
    if(m==1e6) printf("%d",cal(n));
    else sub1();
}