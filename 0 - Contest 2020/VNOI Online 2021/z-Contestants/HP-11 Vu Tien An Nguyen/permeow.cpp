#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fori(x,a,b) for (int x=a;x<=b;x++)
#define ford(x,a,b) for (int x=a;x>=b;x--)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define mp make_pair
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define getbit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define tatbit(x,i) (x&~(1<<(i-1)))
#define gg exit(0);

const int maxn = 2e5+10;
const int mod = 1e9+7;
int n,a[maxn],b[maxn];
void sub1()
{
    int kq=0;
	fori(i,1,n-1)
	{
       fori(j,i+1,n) if(a[i]>a[j]) ++kq;
	}
	cout<<kq;
}
void nhap()
{
   #define task "permeow"
   if(fopen(task".inp","r"))
   {
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
   }
}
main()
{
    nhap();
    cin>>n;
    fori(i,1,n) cin>>a[i];
    fori(i,1,n) cin>>b[i];
    int ok1=0;
    fori(i,1,n) if(a[i]!=b[i]) {ok1=1;break;}
    if(!ok1) sub1(),gg;

    int gt=1,ok2=0;
    fori(i,1,n)
    {
        gt = gt*i;
        if(!ok2 && gt%4==0) gt/=4,ok2=1;
        else if(gt>=mod) gt%=mod;
    }
    gt = gt*n%mod*(n-1)%mod;
    if(n<=3) cout<<gt/4;
    else cout<<gt;
}
// kq la so nghich the
//n!*n*(n-1)/4;
