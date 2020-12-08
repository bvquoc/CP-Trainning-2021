#include<bits/stdc++.h>
//{ HEZ
using namespace std;
#define ll long long
#define db double
#define pi pair<int,int>
#define x first
#define y second

template<typename A,typename B>bool Min(A &a,B b){if(a<=b) return 0;a=b;return 1;}
template<typename A,typename B>bool Max(A &a,B b){if(a>=b) return 0;a=b;return 1;}
#define in ({ll x=0;int o=0,c=char(),t=0;for(;!isdigit(c)&&t<1000;c=getchar(),t++) o=c=='-';for(;isdigit(c);c=getchar()) x=x*10+c-'0';o?-x:x;})
#define inchar ({char c=getchar();while(c==' '||c=='\n') c=getchar();c;})

#define FOR(i,a,b) for(int i=a,ENDFOR=b;i<=ENDFOR;i++)
#define ROF(i,a,b) for(int i=b,ENDFOR=a;ENDFOR<=i;i--)
#define RR(x,a,b) {cout<<#x<<": ";FOR(_,a,b) cout<<x[_]<<" ";cout<<"\n";}
#define rr(x) " "<<#x<<'='<<(x)<<" "

#define VEC(i,a) for(auto&i:a)
#define pb push_back
#define fiv(a) (int)a.size()-1
#define vl(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin()-1)
#define vr(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())

#define bit(x,i) ((x>>(i-1))&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define mu2(x) (1ll<<x)
#define bitnum(x) __builtin_popcountll(x)

#define DIS(a,b) (abs(a-b)+1)
#define MID(a,b) (a+(b-(a))/2)
#define MEMSET(x,a) memset(x,a,sizeof x)
#define OPEN(a) freopen(a,"r",stdin);
#define SHUT(b) freopen(b,"w",stdout);
//}///////////////////////////////////////////////////// END OF DEFINE

#define false(x) if(!(x))
const int N=4e5+5;
const int MOD=1000003;


int n,m,n2;
int a[N];

ll f[4005][4005];
ll F(int l,int r)
{
    ll &res=f[l][r];
    if(res>=0) return res;res=0;
    false(l<=r) return res=1;

    for(int i=l+1;i<=r;i+=2)
    {
        if(a[i]-a[l]<=m) res+=F(l+1,i-1)*F(i+1,r)%MOD,res%=MOD;
        else break;
    }
    return res;
}
void SUB1()
{
    MEMSET(f,-1);
    cout<<F(1,n2);
}


ll gt[N],rgt[N];
ll POW(ll x,int y)
{
    ll res=1;
    for(;y>0;y>>=1,x=(x*x)%MOD) if(y&1) res=(res*x)%MOD;
    return res;
}
void BIL_GT(int fin)
{
    gt[0]=1;
    FOR(i,1,fin) gt[i]=i*gt[i-1]%MOD;
    ROF(i,0,fin)
    {
        if(i==fin||gt[i+1]==0) rgt[i]=POW(gt[i],MOD-2);
        else rgt[i]=rgt[i+1]*(i+1)%MOD;
    }
}
ll C(int n,int k){return gt[n]*rgt[n-k]%MOD*rgt[k]%MOD;}
ll WALK(ll x){return C(n2,(n2-x)/2);}
void SUB2()
{
    BIL_GT(n2);
    ll res=WALK(0)-WALK(-2);
    res=(res%MOD+MOD)%MOD;
    cout<<res;
}
main()
{
    OPEN("mine.inp");
    SHUT("mine.out");
    n=in,m=in;n2=n*2;
    FOR(i,1,n2) a[i]=in;

    if(m<a[n2]-a[1]) SUB1();
    else SUB2();
}
