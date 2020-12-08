//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define  HUNGPOGBA "paint"
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

const int maxn=1e6+5;
const ll maxc=1e9+7;
inline int ReadInt()
{
    char c ;
    for(c=getchar(); c>'9' ||c<'0'; c=getchar()) ;
    int x=c-'0' ;
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())
        x=x*10+c-'0' ;
    return x ;
}

inline char Readchar()
{
    char c ;
    for(c=getchar(); c>'z' || c<'a'; c=getchar()) ;
    return c ;
}
int n ;
int a[maxn],color[150] ;


void sub1()
{
    int dem=0 ;
    forr(i,1,n)
    {
        int type ;
        char c ;
        type =ReadInt(),c=Readchar() ;
        if(type==1)
            a[++dem]=c ;
        else
        {
            char d=Readchar() ;
            forr(i,1,dem)
            if(a[i]==c)
                a[i]=d ;
        }
    }
    forr(i,1,dem)
    if(a[i]!=0)
        cout<<char(a[i]) ;
    else break ;
}
int root[26*maxn+maxn] ;
int in[26*maxn+maxn] ;
int getroot(int u)
{
    if(root[u]==0)
    {
        if(u>n) return u ;
        else return 0 ;
    }
    return root[u]=getroot(root[u]) ;
}
void sub2()
{
    int dem=0,cnt=n ;
    forr(i,'a','z')
    {
        color[i]=++cnt ;
        in[cnt]=i ;
    }
    forr(i,1,n)
    {
        int type ;
        char c ;
        type=ReadInt(),c=Readchar() ;
        if(type==1)
            root[++dem]=color[c] ;
        else
        {
            char d ;
            d=Readchar() ;
            int p=getroot(color[c]) ;
            int q=getroot(color[d]) ;
            root[p]=q ;
            color[c]=++cnt ;
            in[cnt]=c ;
        }
    }
    forr(i,1,dem)
    {
        int u=getroot(i) ;
        cout<<char(in[u]) ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    n=ReadInt() ;
     if(n<=1e3)
      sub1() ;
      else
    sub2() ;
    return 0;
}
