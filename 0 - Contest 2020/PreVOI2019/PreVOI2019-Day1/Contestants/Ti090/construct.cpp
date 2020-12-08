//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define  HUNGPOGBA "construct"
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
const ll maxc=1e15+7;
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
int n,m ;
ll a[maxn] ;
void inp()
{
    n=ReadInt(),m=ReadInt() ;
    forr(i,1,n)
    a[i]=ReadInt() ;
}
void solve()
{
    while(m--)
    {
        int type,l,r ;
        type=ReadInt(),l=ReadInt(),r=ReadInt() ;
        if(type==1)
        {
            int k ;
            k=ReadInt() ;
            forr(i,l,r)
            a[i]+=k ;
        }
        else
        {
            int ans=0 ;
            int l1=l,r1=r ;
            int sl=r1-l1+1 ;
            ll b[maxn] ;
            forr(i,l,r)
            b[i]=a[i] ;
            b[r+1]=0 ;
            while(sl>0)
            {
                ll x=maxc ;
                int pos ;
                ford(i,r,l)
                if(b[i]!=0)
                {
                          pos=i ;
                          break ;
                }
                r=pos ;
                forr(i,l,r)
                if(b[i]!=0)
                {
                    pos=i ;
                    break ;
                }
                l=pos ;
                sl=r1-l1+1 ;
                forr(i,l,r+1)
                {
                    if(b[i]==0 && pos!=0)
                    {
                       //  if(l1==1 && r1==5) cerr<<i<<" "<<pos<<"\n" ;
                        forr(j,pos,i-1)
                        {
                                  b[j]-=x ;
                        }
                        pos=i+1 ;
                        ans+=x ;
                        x=maxc ;
                    }
                    else
                        x=min(x,b[i]) ;
                }
                forr(i,l1,r1)
                if(b[i]==0) sl-- ;
            }
            WriteInt(ans) ;
            putchar('\n') ;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    int t ;
    t=ReadInt() ;
    while(t--)
    {
        inp() ;
        solve() ;
    }
    return 0;
}
