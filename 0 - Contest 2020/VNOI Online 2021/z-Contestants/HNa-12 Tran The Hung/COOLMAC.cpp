//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "COOLMAC"
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

const int maxn=1e5+5;
const ll maxc=1e9+7;

int minL=1e5;
int numSegment,numDay ;
struct Segment
{
    int l,r ;
}segment[maxn] ;
int f[maxn] ;
int bit[maxn] ;
void up(int x,int val)
{
    for(;x>0;x-=x& -x)
        bit[x]=min(bit[x],val) ;
}
int get(int x)
{
    int res=maxc ;
    for(;x<maxn;x+=x& -x)
        res=min(res,bit[x]) ;
    return res ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);

    cin>>numSegment ;
    forr(i,1,numSegment)
    {
        cin>>segment[i].l >>segment[i].r ;
    }
    cin>>numDay ;
    forr(i,1,numDay)
    {
        int x ;cin>>x ;
        minL=min(minL,x) ;
    }
    forr(i,1,numSegment)
    {
        segment[i].l=max(segment[i].l,minL) ;
    }
    sort(segment+1,segment+numSegment+1,[](const Segment &a,const Segment &b)
         {
             return a.l<b.l ;
         }) ;
    memset(bit,0x3f,sizeof bit) ;
    memset(f,0x3f,sizeof f) ;
    int ans=maxc ;
    forr(i,1,numSegment)
    {
        if(segment[i].l>=segment[i].r) continue ;
        if(segment[i].l==minL)
            f[i]=1 ;
        else
        {
            f[i]=get(segment[i].l)+1 ;
        }
        if(segment[i].r==int(1e5))
            ans=min(ans,f[i]) ;
        up(segment[i].r,f[i]) ;
    }
    cout<<(ans==maxc?-1:ans) ;

    return 0;
}
//-----------CODE MY DREAM------------
