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
#define int ll

const int N=1e5+5;
int f[N];
vector<int> c;
ll t,x;

void COIN()
{
    FOR(i,0,4)
    {
        int res=1;
        FOR(j,1,i) res*=10;
        c.pb(1*res);
        c.pb(3*res);
        c.pb(5*res);
    }
    reverse(c.begin(),c.end());
}
ll THAM(ll x)
{
    ll res=0;
    VEC(i,c) if(x>=i)
    {
        res+=x/i;
        x%=i;
    }
    return res;
}
void MAIN()
{
    ll res=LLONG_MAX;
    x=in,t=in;
    FOR(i,0,1e5) if(t-x*i>=0) Min(res,i+THAM(t-x*i));
    FOR(i,1,1e5)
    {
        f[i]=LLONG_MAX;
        VEC(j,c) if(i>=j) Min(f[i],f[i-j]+1);
        if(i>=x) Min(f[i],f[i-x]+1);
    }
    FOR(i,1,1e5) if(t>=i) Min(res,(t/i)*f[i]+f[t%i]);
    cout<<res<<"\n";
}
main()
{
    OPEN("oddcoin.inp");
    SHUT("oddcoin.out");

    COIN();
    FOR(i,1,in) MAIN();
}
