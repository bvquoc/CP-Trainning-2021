//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "DHAKA"
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


const int maxn=1e5+5;
const ll maxc=(ll)1e18+7;
struct Data
{
    ll du ;
    int u,mask ;
    friend bool operator <(const Data &a,const Data &b)
    {
        return a.du<b.du ;
    }
    friend bool operator >(const Data &a,const Data &b)
    {
        return a.du>b.du ;
    }
};
int n,m,k,l ;
vector<ii> adj[maxn] ;
ll d[maxn][MASK(5)] ;
int c[maxn] ;
void dijkstra()
{
    priority_queue<Data,vector<Data>,greater<Data> > q ;
    forr(i,1,n)
    forr(mask,0,MASK(k)-1)
    d[i][mask]=maxc ;

    d[1][c[1]]=0 ;
    q.push({0,1,c[1]}) ;
    ll ans=maxc ;
    while(!q.empty())
    {
        int u=q.top().u ;
        ll du=q.top().du ;
        int mask=q.top().mask ;
        if(u==n && __builtin_popcount(mask)>=l)
            ans=min(ans,du) ;
        q.pop() ;
        if(du!=d[u][mask]) continue ;
        fore(it,adj[u])
        {
            if(d[it->F][mask|c[it->F]]>du+it->S)
            {
                d[it->F][mask|c[it->F]]=du+it->S ;
                q.push({d[it->F][mask|c[it->F]],it->F,mask|c[it->F]}) ;
            }
        }
    }
    cout<<(ans>=maxc?-1:ans) ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);

    cin>>n >>m >>k >>l ;
    forr(i,1,n)
    {
        int s ; cin>>s ;
        int mask=0 ;
        forr(LOVE,1,s)
        {
            int x ;cin>>x ;
            mask|=MASK(x-1) ;
        }
        c[i]=mask ;
    }
    forr(LOVE,1,m)
    {
        int u,v,w ;
        cin>>u >>v >>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }
    dijkstra() ;

    return 0;
}
//-----------CODE MY DREAM------------
