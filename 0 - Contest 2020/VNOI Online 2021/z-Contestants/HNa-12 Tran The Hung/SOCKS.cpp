//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define HUNGPOGBA "SOCKS"
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
const ll maxc=1e9+7;
const int LOG=19 ;

int n,q ;
int color[maxn] ;
int child[maxn] ;
int p[maxn][LOG+5],h[maxn] ;
vector<int> adj[maxn] ;
int res=maxc;
int numRed=0 ;
int f[maxn],deg[maxn] ;

void dfs(int u,int par=-1)
{
    forr(x,1,LOG) p[u][x]=p[p[u][x-1]][x-1] ;
    for(auto v: adj[u])
    {
        if(v==par)
            continue ;
        h[v]=h[u]+1 ;
        p[v][0]=u ;
        dfs(v,u) ;
    }
}
int root ;
void out()
{
    int res=0 ;
    for(auto v: adj[root])
        res+=(child[v]>0) ;
    if(numRed<=1)
        cout<<0<<"\n" ;
    else if(res<=2)
        cout<<1<<"\n" ;
    else
        cout<<2<<"\n" ;
}
void sub2()
{
    dfs(root) ;
    forr(i,1,n)
    if(color[i]==1)
    {
        int u=i,d=h[u]-1 ;
        if(u==root)
            continue ;
        forr(i,1,d)
        if(BIT(d,i))
            u=p[u][i] ;
        child[u]++ ;
    }


    out() ;
    forr(LOVE,1,q)
    {
        int u ;
        cin>>u ;
        color[u]^=1 ;
        if(color[u]==1)
            ++numRed ;
        else --numRed ;

        int val=0 ;
        if(color[u]==1)
            val=1 ;
        else
            val=-1 ;

        if(u!=root)
        {
            int d=h[u]-1 ;
            forr(i,1,d)
            if(BIT(d,i))
                u=p[u][i] ;
            child[u]+=val ;
        }
        out() ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    cin>>n >>q ;
    forr(i,1,n) cin>>color[i],numRed+=color[i] ;
    forr(LOVE,1,n-1)
    {
        int u,v ;
        cin>>u >>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
        deg[u]++ ,deg[v]++ ;

    }

    root=0 ;
    forr(u,1,n)
    if(deg[u]==3)
        root=u ;
    forr(u,1,n)
    if(deg[u]==2 && root==0)
        root=u ;
    sub2() ;





    return 0;
}
//-----------CODE MY DREAM------------
