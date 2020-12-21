//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "DECOR"
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

const int maxn=5e5+5;
const ll maxc=1e9+7 ;
int n,m,k ;
int sum[maxn] ;
string s ;
void sub2()
{
    int ans=0,resL,resR ;
    forr(i,1,n)
    {
        int l=i-1,r=n+1 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(sum[mid]-sum[i-1]<=k)
                l=mid ;
            else
                r=mid ;
        }
        if(ans<l-i+1)
        {
            ans=l ;
            resL=i,resR=l;
        }
    }
    if(ans==0)
        return cout<<-1,void() ;
    cout<<resL<<" "<<resR<<"\n" ;

}
struct dsu
{
    vector< vector<int> > Light ;
    vector<int> root ;
    int n ;
    dsu(int n)
    {
        this->n=n ;
        root.assign(n+5,0) ;
        Light.assign(n+5,vector<int>()) ;
    }
    int Root(int u)
    {
        return root[u]?root[u]=Root(root[u]):u ;
    }
    bool Union(int u,int v)
    {
        int p=Root(u) ;
        int q=Root(v) ;
        if(p==q) return false ;
        root[p]=q ;
        return true ;
    }
    void TurnOn(int u)
    {
        Light[Root(u)].push_back(u) ;
    }
    void TurnOff(int u)
    {
        Light[Root(u)].pop_back() ;
    }
    bool IsOn(int u)
    {
        return Light[Root(u)].size()>0 ;
    }
} ;
void sub3()
{
    dsu global(n) ;
    forr(LOVE,1,m)
    {
        int u,v ;
        cin>>u >>v ;
        global.Union(u,v) ;
    }
    forr(i,1,n)
    if(s[i]=='1')
    {
        global.TurnOn(i) ;
    }
    int ans=0,resL=0,resR=0 ;
    forr(i,1,n)
    {
        int j=i-1,cnt=k ;
        dsu tmp=global ;
        while(j+1<=n)
        {
            if(tmp.IsOn(j+1)==true)
            {
                tmp.TurnOff(j+1) ;
                ++j ;
            }
            else if(cnt>0) --cnt,++j ;
            else break ;
        }
        if(ans<j-i+1)
        {
            ans=j-i+1 ;
            resL=i ;
            resR=j ;
        }
    }
    if(ans==0) cout<<-1 ;
    else cout<<resL<<" "<<resR<<"\n" ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    cin>>n >>m >>k ;
    cin>>s ;
    s=' '+s ;
    forr(i,1,n)
    {
        sum[i]=sum[i-1]+(s[i]=='0') ;
    }
    if(m==0)
        return sub2(),0 ;
    sub3() ;
    return 0;
}
//-----------CODE MY DREAM------------
