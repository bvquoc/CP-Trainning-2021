#include <bits/stdc++.h>
#define task "DHAKA"
#define ll long long
#define FOR( i, l, r) for(int i = (l), _r = (r); i <= _r; ++i)
#define FOD( i, l, r) for(int i = (l), _r = (r); i >= _r; --i)
#define REP( i, n)    for(int i = 0, _n = (n); i < _n; ++i)
#define pii pair<int, ll>
#define fi  first
#define se  second
#define MASK(x)  (1ll << (x))
#define BIT(x,k) (((x) >> (k)) & 1ll)
#define OFF(x,k) ((x) & ~(1ll << (k)))
#define ON(x,k)  ((1ll << (k)) | (x))
#define endl '\n'
#define __builtin_popcount __builtin_popcountll
using namespace std;
int const N = 1e5 + 11;
ll const INF = 1e18 + 7;
ll d[N][MASK(5)];
int numNode, numEdge, l, k;
vector<pii> adj[N];
int a[N];
struct Data
{
    int u, mask;
    ll w;
    Data(int _u = 0, ll _w = 0, int _mask = 0)
    {
        u = _u, w = _w, mask = _mask;
    }
};
struct cmp
{
    bool operator ()(Data const &x, Data const &y)
    {
        return x.w > y.w;
    }
};
ll ans = INF;
priority_queue<Data, vector<Data>, cmp> pq;
void Dijkstra(void)
{
    FOR(i, 1, numNode) REP(j, MASK(k)) d[i][j] = INF;
    d[1][a[1]] = 0;
    pq.push(Data( 1, 0, a[1]));
    while(!pq.empty())
    {
        int u = pq.top().u;
        ll w = pq.top().w;
        int mask = pq.top().mask;
        pq.pop();
        if(d[u][mask] != w) continue;
        for(pii &i : adj[u])
        {
            int v = i.fi;
            ll c = i.se;
            if(d[v][mask | a[v]] > d[u][mask] + c)
            {
                d[v][mask | a[v]] = d[u][mask] + c;
                pq.push(Data( v, d[v][mask | a[v]], (mask | a[v])));
            }
        }
    }
    REP(mask, MASK(k)) if(__builtin_popcount(mask) >= l) ans = min( ans, d[numNode][mask]);
}
void inp(void)
{
    cin >> numNode >> numEdge >> k >> l;
    FOR( i, 1, numNode)
    {
        int s;
        cin >> s;
        FOR( j, 1, s)
        {
            int val;
            cin >> val;
            a[i] = ON(a[i], val - 1);
        }
    }
    FOR( i, 1, numEdge)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back(pii( v, w));
        adj[v].push_back(pii( u, w));
    }
}
void solve(void)
{
    Dijkstra();
    if(ans == INF) ans = -1;
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    inp();
    solve();
    return 0;
}
