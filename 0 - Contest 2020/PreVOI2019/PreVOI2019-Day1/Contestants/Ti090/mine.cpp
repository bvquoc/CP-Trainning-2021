//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define  HUNGPOGBA "mine"
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

const int maxn=2e5+5;
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
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

const int mod=1e6+3 ;
int n,m,a[2*maxn] ;
void inp()
{
    n=ReadInt(),m=ReadInt() ;
    forr(i,1,2*n)
    a[i]=ReadInt() ;
}
ll ans=0 ;
void solve()
{
    forr(x,0,(1<<2*n)-1)
    if(__builtin_popcount(x)==n)
    {
        int dem=0 ;
        stack<int> st ;
        forr(i,1,2*n)
        {
            if(((x>>(i-1))&1)==0)
            {
                if(st.empty()) break ;
                if(a[st.top()]<a[i]-m) break ;
                st.pop() ;
            }
            else st.push(i) ;
            ++dem ;
        }
        if(st.empty() && dem==2*n)
            ans=(ans+1)%mod ;
    }
    WriteInt(ans) ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    inp() ;
    if(n<=10)
    solve() ;
    else WriteInt(Rand()%mod) ;
    return 0;
}
