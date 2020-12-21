#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long LL;
const int MAXN=1+3e5;
const LL inf=1+1e18;
const LL mod=1e9+7;
int n,m,k,l;
LL d[MAXN][50];
vector<pair<LL,LL> > g[MAXN];
vector<int> a[MAXN];
LL ans=inf;
void dijk()
{
    for(int i=1; i<=n; ++i)
    {
        for(int mask=0; mask<(1<<k); ++mask) d[i][mask]=inf;
    }
    set<pair<pair<LL,LL>,LL> > q;
    d[1][0]=0;
    q.insert({{0,1},0});
    int mask1=0;
    for(int i=0; i<a[1].size(); ++i)
    {
        int x=a[1][i];
        d[1][mask1|(1<<x)]=0;
        mask1=mask1|(1<<x);
        d[1][1<<x]=0;
        q.insert({{0,1},(1<<x)});
        q.insert({{0,1},mask1});
    }
    while(!q.empty())
    {
        LL u=q.begin()->fi.se,du=q.begin()->fi.fi,mask=q.begin()->se;
        //cout<<u<<' '<<du<<' '<<mask<<'\n';
        q.erase(q.begin());
        for(int i=0; i<g[u].size(); ++i)
        {
            LL v=g[u][i].fi,l=g[u][i].se;
            LL mask1=mask,mask2=mask;
            //cout<<u<<' '<<v<<' '<<l<<' '<<mask1<<'\n';
            if(d[v][mask1]>du+l)
            {
                q.insert({{d[v][mask1]=du+l,v},mask1});
            }

            for(int j=0; j<a[v].size(); ++j)
            {
                int x=a[v][j];
                if(d[v][mask2|(1<<x)]>du+l)
                {
                    q.insert({{d[v][mask2|(1<<x)]=du+l,v},mask2|(1<<x)});
                    mask2=mask2|(1<<x);
                }
                if(d[v][mask1|(1<<x)]>du+l)
                {
                    q.insert({{d[v][mask1|(1<<x)]=du+l,v},mask1|(1<<x)});
                }
            }
        }
    }
    return;
}
int main()
{
#define TASK "DHAKA"
    if(fopen(TASK ".inp","r"))
    {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; ++i)
    {
        int s;
        cin>>s;
        for(int j=1; j<=s; ++j)
        {
            int x;
            cin>>x;
            a[i].push_back(x-1);
        }
    }
    for(int i=1; i<=m; ++i)
    {
        LL u,v,l;
        cin>>u>>v>>l;
        g[u].push_back({v,l});
        g[v].push_back({u,l});
    }
    dijk();
    for(int mask=0; mask<(1<<k); ++mask)
    {
        if(__builtin_popcount(mask)>=l) ans=min(ans,d[n][mask]);
    }
    if(ans==inf) ans=-1;
    cout<<ans;
    return 0;
}
