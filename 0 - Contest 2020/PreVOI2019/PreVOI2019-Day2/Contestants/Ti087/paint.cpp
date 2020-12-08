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


vector<int> v,dsu,ans;
int c[30];

int num(){return inchar-'a'+1;}
int r(int x){return dsu[x]==-1?x:dsu[x]=r(dsu[x]);}
void CREATE(int x)
{
    if(c[x]>=0) return;
    dsu.pb(-1);ans.pb(x);
    c[x]=fiv(dsu);
}
main()
{
    OPEN("paint.inp");
    SHUT("paint.out");
    MEMSET(c,-1);
    FOR(i,1,in)
    {
        int t=in;
        if(t==1)
        {
            int x=num();
            CREATE(x);
            v.pb(c[x]);
        }
        if(t==2)
        {
            int x=num(),y=num();
            if(c[x]==-1) continue;
            if(x==y) continue;
            CREATE(y);

            dsu[c[x]]=c[y];c[x]=-1;
        }
    }
    VEC(i,v) cout<<char(ans[r(i)]+'a'-1);
}
