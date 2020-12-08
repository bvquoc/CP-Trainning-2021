//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define  HUNGPOGBA "oddcoin"
#define ii pair<int,int>
#define memset(f, a) memset(f, 0, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)
#define ford(i, a, b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define ll long long
#define pub push_back
#define pob pop_back
#define llu unsigned long long
#define mp make_pair
#define ld long double
#define sz(s) int(s.size())

using namespace std;
mt19937 Rand(time(0));

const int maxn=1e5+5;
const ll maxc=2e9+7;
inline int ReadInt()
{
    char c ;
    for(c=getchar(); c>'9' ||c<'0'; c=getchar()) ;
    int x=c-'0' ;
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())
        x=x*10+c-'0' ;
    return x ;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int a[20]= {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000} ;
int ma ;
ii b[55] ;
const int maxt=2e7 ;
int f[maxt+5] ;
void solve()
{
    forr(i,1,min(maxt,ma))
    f[i]=maxc ;
    f[0]=0 ;
    forr(i,0,14)
    f[a[i]]=1;
    forr(i,1,min(maxt,ma))
    forr(j,0,14)
    if(i>=a[j])
    f[i]=min(f[i],f[i-a[j]]+1) ;
}
void calc(int x,int t)
{
    if(t<maxt)
    {
        forr(i,1,maxt)
        if(1ll*x*i<=t)
            f[t]=min(f[t],f[t-x*i]+i) ;
        else break ;
        WriteInt(f[t]) ;
        putchar('\n') ;
    }
    else
    {
        int ans=maxc ;
        forr(i,1,maxt)
        if(1ll*x*i<=t)
        {
            if(t-x*i<=maxt)
                ans=min(ans,f[t-x*i]+i) ;
        }
        else break ;
        forr(i,1,maxt)
        if(t-i<=maxt)
          ans=min(ans,f[i]+f[t-i]) ;
       WriteInt(ans) ;
       putchar('\n') ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    int q ;
    q=ReadInt() ;
    forr(i,1,q)
    {
        b[i].F=ReadInt(),b[i].S=ReadInt() ;
        ma=max(ma,b[i].S) ;
    }
    solve() ;
    forr(i,1,q)
    calc(b[i].F,b[i].S) ;
    return 0;
}
