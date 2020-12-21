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

const int maxn = 1e5 + 10;
int f[(1<<5)+2][maxn],n,m,k,l,u,v,c;
vector<ii> ke[maxn];
vector<int> ad[maxn];

void dij(int s)
{
    int ma = (1<<k)-1;
    priority_queue<pair<int,ii>,vector<pair<int,ii> >,greater<pair<int,ii> > > h;
    int tt = 0;
    forv(v,ad[1]) tt = batbit(tt,v);
    fori(tt,0,ma) fori(i,1,n) f[tt][i] = 1e15;

    h.push({0,{s,tt}}),f[tt][s] = 0;

    while(!h.empty())
    {
        auto u = h.top();
        h.pop();
        int umin = u.se.fi;
        int tt = u.se.se;
        int dmin = u.fi;
        if(f[tt][umin] < dmin) continue;

        forv(v,ke[umin])
        {
            int z = tt;
            forv(j,ad[v.fi]) z = batbit(z,j);
            if(f[z][v.fi] > dmin + v.se)
            {
                f[z][v.fi] = dmin + v.se;
                h.push({f[z][v.fi],{v.fi,z}});
            }
        }
    }

    int kq = 1e15;
    fori(tt,0,ma) if(__builtin_popcount(tt)>=l)
    kq = min(kq,f[tt][n]);
    if(kq==1e15) cout<<-1;
    else cout<<kq;
}

void nhap()
{
    fasty;
    #define task "dhaka"
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
main()
{
    nhap();
    cin>>n>>m>>k>>l;
    fori(i,1,n)
    {
        int sl;
        cin>>sl;
        while(sl--) cin>>u,ad[i].pb(u);
    }
    fori(i,1,m)
    {
        cin>>u>>v>>c;
        ke[u].pb({v,c}),ke[v].pb({u,c});
    }
    dij(1);
}
