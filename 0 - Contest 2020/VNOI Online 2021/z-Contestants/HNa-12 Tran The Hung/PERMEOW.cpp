//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "PERMEOW"
#define memset(f,a) memset(f,(a),sizeof(f))
#define forr(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define F first
#define S second
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)

using namespace std;

typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> ii ;

const int maxn=2e5+5;
const ll maxc=1e9+7;
const int mod=1e9+7 ;
void add(int &x,int y)
{
    x+=y ;
    if(x>=mod)
        x-=mod ;
}
int n,a[maxn],b[maxn] ;
int bit[maxn] ;
void up(int x)
{
    for(; x<=n; x+=x& -x)
        bit[x]++ ;
}
int get(int x)
{
    int res=0 ;
    for(; x>0; x-=x& -x)
        res+=bit[x] ;
    return res ;
}

int sub1()
{
    int ans=0 ;
    fill(bit,bit+n+1,0) ;
    forr(i,1,n)
    {
        up(a[i]) ;
        add(ans,get(n)-get(a[i])) ;
    }
    return ans ;
}
int gt[maxn] ;
int id[maxn] ;
int C2(int n)
{
    return (1LL*n*(n-1)/2)%mod;
}
void sub2()
{
    int ans=0 ;
    forr(i,1,n)
    if(n-2>=0)
    {
        int tmp=1LL*gt[n-2]*(n-i)%mod ;
        tmp=1LL*tmp*C2(n)%mod ;
        add(ans,tmp) ;
    }
    cout<<ans <<"\n" ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    bool ok1=true,ok2=true ;
    cin>>n  ;
    forr(i,1,n)
    {
        cin>>a[i] ;
        if(a[i]!=i)
            ok2=false ;
    }
    forr(i,1,n)
    {
        cin>>b[i] ;
        if(b[i]!=n-i+1)
            ok2=false ;
    }
    forr(i,1,n)
    if(a[i]!=b[i])
        ok1=false ;
    gt[0]=1 ;
    forr(i,1,n)
    gt[i]=1LL*gt[i-1]*i%mod ;

    if(ok1==true)
        return cout<<sub1(),0 ;
    if(ok2==true)
        return sub2(),0 ;
    int ans=0 ;
    while(true)
    {
        bool stop=true ;
        forr(i,1,n)
        if(a[i]!=b[i]) stop=false ;
        add(ans,sub1()) ;
        if(stop==true) break ;
        next_permutation(a+1,a+n+1) ;
    }
    cout<<ans ;

    return 0;
}
//-----------CODE MY DREAM------------
