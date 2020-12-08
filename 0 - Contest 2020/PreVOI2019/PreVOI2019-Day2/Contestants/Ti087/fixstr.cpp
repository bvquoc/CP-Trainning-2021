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
#define in ({int x=0;cin>>x;x;})
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

const int N=1e6+5;
int n,m;
string sgiven;

int node[N],Node=1;
vector<pi> e[N];
vector<pair<int,pair<int,int>> > q[N];

int ans[N];


#define Slef S*2,l,MID(l,r)
#define Srig S*2+1,MID(l,r)+1,r
#define SEGFIRST int S=1,int l=1,int r=sgiven.size()
pi s[4*N];
pi CAL(pi a,pi b)
{
    int x=min(a.x,b.y);
    a.x-=x,b.y-=x;
    return {a.x+b.x,a.y+b.y};
}
void BIL(SEGFIRST)
{
	if(l==r)
	{
		if(sgiven[r-1]=='(') s[S]={1,0};
		else s[S]={0,1};
		return;
	}
	BIL(Slef);BIL(Srig);
	s[S]=CAL(s[S*2],s[S*2+1]);
}
void ATE(int x,SEGFIRST)
{
	if(x<l||r<x) return;
	if(l==r)
	{
        swap(s[S].x,s[S].y);
		return;
	}
	ATE(x,Slef);ATE(x,Srig);
	s[S]=CAL(s[S*2],s[S*2+1]);
}
pi GET(int u,int v,SEGFIRST)
{
	if(u<=l&&r<=v) return s[S];
	if(MID(l,r)<u) return GET(u,v,Srig);
	if(v<MID(l,r)+1) return GET(u,v,Slef);
	return CAL(GET(u,v,Slef),GET(u,v,Srig));
}



void DFS(int x)
{
    VEC(i,q[x])
    {
        pi res=GET(i.y.x,i.y.y);
        ans[i.x]=res.x+res.y;
    }
    VEC(i,e[x])
    {
        ATE(i.y);
        DFS(i.x);
        ATE(i.y);
    }
}
main()
{
    OPEN("fixstr.inp");
    SHUT("fixstr.out");
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>sgiven;MEMSET(ans,-1);

    node[0]=1;
    FOR(i,1,m=in)
    {

        char c;cin>>c;

        if(c=='C') e[node[i-1]].pb({node[i]=++Node,in});
        if(c=='Q') q[node[i]=node[i-1]].pb({i,{in,in}});
        if(c=='U') node[i]=node[in-1];
    }
    BIL();
    DFS(1);

    FOR(i,1,m) if(ans[i]>=0) cout<<ans[i]<<"\n";
}
