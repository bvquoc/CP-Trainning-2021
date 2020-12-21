#include <bits/stdc++.h>
#define int long long
#define pii pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = (int)1e5+1;
const int INF = (int)1e18;
int n , m , k , l;
int d[N][33];
vector<pii> f[N];
int t[N];
struct Data
{
    int u , w , mask;
    bool operator > (const Data &x) const
    {
        return w > x.w;
    }
    Data(int _u = 0 , int _w = 0 , int _mask = 0)
    {
        u = _u , w = _w , mask = _mask;
    }
};
priority_queue<Data , vector<Data> , greater<Data> >pq;
void dijkstra()
{
    for(int i=1 ; i<=n ; ++i) for(int j=0 ; j<(1<<k) ; ++j) d[i][j] = INF;
    d[1][t[1]] = 0;
    pq.push(Data(1 , 0 , t[1]));
    while(pq.size())
    {
        int u = pq.top().u;
        int w = pq.top().w;
        int mask = pq.top().mask;
        pq.pop();
        if(d[u][mask] != w) continue;
        for(int i=0 ; i<(int)f[u].size() ; ++i)
        {
            int v = f[u][i].fi;
            int newMask = (mask|t[v]);
            if(d[v][newMask] > w + f[u][i].se)
            {
                d[v][newMask] = w+f[u][i].se;
                pq.push(Data(v , d[v][newMask] , newMask));
            }
        }
    }
}
void inp()
{
    cin >> n >> m >> k >> l;
    int cnt , tmp;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> cnt;
        for(int j=1 ; j<=cnt ; ++j)
        {
            cin >> tmp;
            t[i]|=(1<<(tmp-1));
        }
    }
    int u , v , l;
    for(int i=1 ; i<=m ; ++i)
    {
        cin >> u >> v >> l;
        f[u].push_back(make_pair(v , l));
        f[v].push_back(make_pair(u , l));
    }
}
void solve()
{
    int res = INF;
    dijkstra();
    for(int mask=0 ; mask<(1<<k) ; ++mask)
    {
        if(__builtin_popcountll(mask) >= l)
        {
            res = min(res , d[n][mask]);
        }
    }
    if(res == INF) cout << -1;
    else cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP" , "r" , stdin);
    freopen("DHAKA.OUT" , "w" , stdout);
    inp();
    solve();
    return 0;
}
