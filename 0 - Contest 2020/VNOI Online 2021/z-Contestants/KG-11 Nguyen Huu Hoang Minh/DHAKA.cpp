#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define iii pair< int, ii >
#define vi vector<int>
#define vii vector< ii >
#define viii vector< iii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "DHAKA"
#define int long long

using namespace std;

typedef long double ld;
const int inf = 1e10;

int n,m,k,l;
int dua[N];
vector<ii> a[N];
int d[N][(1<<5)+5];

int gbit(int val, int pos)
{
    return (val >> pos) & 1;
}

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> n >> m >> k >> l;
    for(int i=1; i<=n; i++)
    {
        int si;
        cin >> si;
        for(int j=1; j<=si; j++)
        {
            int x;
            cin >> x;
            dua[i] |= (1 << x);
        }
    }
    for(int i=1; i<=m; i++)
    {
        int u,v,z;
        cin >> u >> v >> z;
        a[u].pb(ii(v,z));
        a[v].pb(ii(u,z));
    }
}

void dijkstra()
{
    priority_queue<iii, viii, greater<iii>> q;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<(1<<5)+5; j++) d[i][j] = inf;
    }
    int state = dua[1];
    d[1][state] = 0;
    q.push(iii(0,ii(1,state)));
    while (q.size())
    {
        int u = q.top().se.fi;
        int sta = q.top().se.se;
        int du = q.top().fi;
        q.pop();
        if (du != d[u][sta]) continue;
        for(int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i].fi;
            int uv = a[u][i].se;
            int vsta = sta | dua[v];
            if (d[v][vsta] > d[u][sta]+uv)
            {
                d[v][vsta] = d[u][sta] + uv;
                q.push(iii(d[v][vsta],ii(v,vsta)));
            }
        }
    }
}

void proc()
{
    dijkstra();
    int res = inf;
    for(int i=0; i<(1<<5); i++)
    {
        if (__builtin_popcount(i) >= l) res = min(res,d[n][i]);
    }
    if (res==inf) cout << -1;
    else cout << res;
}

signed main()
{
    readfile();
    proc();
    return 0;
}
