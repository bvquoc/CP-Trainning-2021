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
int n,m;
#define Slef S*2,l,MID(l,r)
#define Srig S*2+1,MID(l,r)+1,r
#define SEGFIRST int S=1,int l=1,int r=n
#define Snow S,l,r
struct seg
{
    ll vl,vr,vm;
    ll ans;
} s[4*N];
int lz[4*N];



seg CAL(seg u,seg v)
{
    seg w;

    w.vm=min(u.vm,v.vm);u.vm-=w.vm,v.vm-=w.vm;
    w.vl=u.vl+u.vm;
    w.vr=v.vr+v.vm;
    w.ans=u.ans+v.ans+max(u.vr,v.vl);

    return w;
}
void LAZY(SEGFIRST)
{
	int x=lz[S];lz[S]=0;

	s[S].vm+=x;
	if(l!=r)
    {
		lz[S*2]+=x,
		lz[S*2+1]+=x;
    }
}
void BIL(SEGFIRST)
{
	if(l==r)
	{
		s[S].vl=0;
		s[S].vr=0;
		s[S].vm=in;
		s[S].ans=0;
		return;
	}
	BIL(Slef);BIL(Srig);
	s[S]=CAL(s[S*2],s[S*2+1]);
}
void ATE(int u,int v,int d,SEGFIRST)
{
	LAZY(Snow);
	if(r<u||v<l) return;
	if(u<=l&&r<=v)
	{
		lz[S]=d;
		LAZY(Snow);
		return;
	}
	ATE(u,v,d,Slef);ATE(u,v,d,Srig);
	s[S]=CAL(s[S*2],s[S*2+1]);
}
seg GET(int u,int v,SEGFIRST)
{
	LAZY(Snow);
	if(u<=l&&r<=v) return s[S];
	if(MID(l,r)<u) return GET(u,v,Srig);
	if(v<MID(l,r)+1) return GET(u,v,Slef);
	return CAL(GET(u,v,Slef),GET(u,v,Srig));
}
void MAIN()
{
    n=in,m=in;
    BIL();
    FOR(i,1,m)
    {
        int t=in,x=in,y=in;
        if(t==1) ATE(x,y,in);
        else
        {
            seg res=GET(x,y);
            cout<<res.ans+res.vl+res.vr+res.vm<<"\n";
        }
    }
}
main()
{
    OPEN("construct.inp");
    SHUT("construct.out");
    FOR(i,1,in) MAIN();
}
