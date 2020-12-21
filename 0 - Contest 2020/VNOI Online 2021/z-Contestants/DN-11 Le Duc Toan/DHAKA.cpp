#include<bits/stdc++.h>

using namespace std;

#define task "DHAKA"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

struct three
{
    int u,mask;
    ll len;

    bool operator < (const three &other) const
    {
        return len>other.len;
    }
};

int n,m,k,l,s[N];
vector<pii> adj[N];
ll f[N][35];


void dijkstra()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<(1<<k);++j)
        {
            f[i][j]=1e17;
        }
    }

    f[1][s[1]]=0;

    priority_queue<three> q;

    q.push({1,s[1],0});

    while(zs(q))
    {
        int u=q.top().u, mask=q.top().mask;
        ll len=q.top().len;

        q.pop();

        if(f[u][mask]<len) continue;

        for(int i=0;i<zs(adj[u]);++i)
        {
            int v=adj[u][i].fi, w=adj[u][i].se;
            int nmask=(mask|s[v]);

            if(f[v][nmask]>f[u][mask]+w)
            {
                f[v][nmask]=f[u][mask]+w;
                q.push({v,nmask,f[v][nmask]});
            }
        }
    }
}
void gogo()
{
    cin>>n>>m>>k>>l;

    for(int i=1;i<=n;++i)
    {
        int num;
        cin>>num;
        for(int j=1;j<=num;++j)
        {
            int x;
            cin>>x;
            --x;
            s[i]|=(1<<x);
        }
    }

    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    dijkstra();

    ll ans=1e18;

    for(int mask=0;mask<(1<<k);++mask)
    {
        if(CNTBIT(mask)>=l) ans=min(ans,f[n][mask]);
    }

    if(ans>=1e17) cout<<-1;
    else cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    gogo();
}






