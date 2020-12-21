#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
using namespace std;

void file()
{
    freopen ( "DHAKA.inp", "r", stdin );
    freopen ( "DHAKA.out", "w", stdout );
}

typedef long long ll;
typedef pair<int, int> ii;;

const int maxn = 1e5 + 7;

ll n, m, k, l;
ll res = 2e18 + 7;
vector<vector<ii>> dsk;
vector<vector<int>> melon;
int mau[maxn];

vector<ll> dijkstra ( int s )
{
    vector<ll> dist ( n + 1, 2e18 + 7 );
    dist[s] = 0;
    set<ii> qu;
    qu.insert ( {0, s} );
    while ( !qu.empty() )
    {
        ii top = *qu.begin();
        qu.erase ( qu.begin() );
        ll d = top.ff, u = top.ss;
        if ( dist[u] != d )
            continue;
        for ( int i = 0; i < dsk[u].size(); ++i )
        {
            ii v = dsk[u][i];
            if ( dist[u] + v.ss < dist[v.ff] )
            {
                dist[v.ff] = dist[u] + v.ss;
                qu.insert ( {dist[v.ff], v.ff} );
            }
        }
    }
    return dist;
}

void sub2()
{
    vector<ll> tmp = dijkstra ( 1 );
    res = tmp[n];
    if ( res < 2e15 )
        cout << res;
    else
        cout << -1;
}

vector<ll> toN;
void dfs ( int u, int mask, int cnt, ll W )
{
    if ( cnt >= k )
    {
        res = min ( res, W + toN[u] );
        return;
    }
    mau[u] = 1;
    for ( int j = 0 ; j < dsk[u].size(); ++j )
    {
        if ( mau[dsk[u][j].ff] == 0 )
        {
            int v = dsk[u][j].ff;
            int n_mask = mask;
            int n_cnt = cnt;
            for ( int j = 0; j < melon[v].size(); ++j )
            {
                if ( ( ( n_mask >> ( melon[v][j] - 1 ) ) & 1 ) == 0 )
                {
                    ++n_cnt;
                    n_mask |= ( 1 << ( melon[v][j] - 1 ) );
                }
            }
            dfs ( v, n_mask, n_cnt, W + dsk[u][j].ss );
        }
    }
    mau[u] = 0;
    return;
}

void sub1()
{
    toN = dijkstra ( n );
    int n_mask = 0;
    int n_cnt = 0;
    for ( int j = 0; j < melon[1].size(); ++j )
    {
        if ( ( ( n_mask >> ( melon[1][j] - 1 ) ) & 1 ) == 0 )
        {
            ++n_cnt;
            n_mask |= ( 1 << ( melon[1][j] - 1 ) );
        }
    }
    dfs ( 1, n_mask, n_cnt, 0 );
    if ( res < 2e15 )
        cout << res;
    else
        cout << -1;
}

signed main()
{
    faster
    file();
    cin >> n >> m >> k >> l;
    dsk.assign ( n + 1, vector<ii>() );
    melon.assign ( n + 1, vector<int>() );
    for ( int i = 1; i <= n; ++i )
    {
        int s;
        cin >> s;
        for ( int j = 0; j < s; ++j )
        {
            int x;
            cin >> x;
            melon[i].push_back ( x );
        }
    }
    for ( int i = 1; i <= m; ++i )
    {
        int u, v, c;
        cin >> u >> v >> c;
        dsk[u].push_back ( {v, c} );
        dsk[v].push_back ( {u, c} );
    }
    if ( l == 0 )
        sub2();
    else
        sub1();
}
