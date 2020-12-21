#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1e5+10;
int d[mn][40],n,m,l,k;
vector<int> cnt[mn];
vector<pii> ke[mn];

void dis(int u)
{
    forinc(j,0,(1ll<<k)-1) forinc(i,1,n)
    {
        d[i][j]=1e15;
    }
    int bett=0;
    forv(i,cnt[u]) bett=batbit(i,bett);
    d[u][bett]=0;
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> q;
    q.push({{0,bett},u});
    while(!q.empty())
    {
        auto f=q.top();
        q.pop();
        int umin=f.se;
        int dmin=f.fi.fi;
        int tt=f.fi.se;
        if(dmin>d[umin][tt]) continue;
        forv(v,ke[umin])
        {
            int tt2=tt;
            forv(i,cnt[v.fi]) tt2=batbit(i,tt2);
            if(d[v.fi][tt2]>dmin+v.se)
            {
                d[v.fi][tt2]=dmin+v.se;
                q.push({{d[v.fi][tt2],tt2},v.fi});
            }
        }
    }
}

main()
{
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> l;
    forinc(i,1,n)
    {
        int t;
        cin >> t;
        forinc(j,1,t)
        {
            int x;
            cin >> x;
            cnt[i].push_back(x-1);
        }
    }
    forinc(i,1,m)
    {
        int u,v,c;
        cin >> u >> v >> c;
        ke[u].push_back({v,c});
        ke[v].push_back({u,c});
    }
    dis(1);
    int res=1e15;
    forinc(tt,0,(1ll<<k)-1)
    {
        int dem=0;
        forinc(i,0,k-1) if(getbit(i,tt)) dem++;
        if(dem>=l)
        {
            res=min(res,d[n][tt]);
        }
    }
    if(res==1e15) return cout << -1,0;
    cout << res;
}
