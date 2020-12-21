#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void file()
{
    freopen ( "SOCKS.inp", "r", stdin );
    freopen ( "SOCKS.out", "w", stdout );
}

const int maxn = 5e5 + 7;

int n, q;
int sl = 0;
int ON[maxn];
int path[maxn];
int light[maxn];
vector<vector<int>> dsk;

void dfs ( int u, int p, int c )
{
    for ( int j = 0; j < dsk[u].size(); ++j )
        if ( dsk[u][j] != p )
        {
            int v = dsk[u][j];
            path[v] = c;
            dfs ( v, u, c );
        }
    return ;
}

signed main()
{
    faster
    file();
    cin >> n >> q;
    for ( int i = 1; i <= n; ++i )
    {
        cin >> ON[i];
        sl += ON[i];
    }
    dsk.assign ( n + 1, vector<int>() );
    for ( int i = 1; i < n; ++i )
    {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back ( v );
        dsk[v].push_back ( u );
    }
    bool sub1 = true;
    int sub2 = 0;
    int vt = 1;
    for ( int i = 1; i <= n; ++i )
    {
        if ( dsk[i].size() >= 3 )
            ++sub2, vt = i, sub1 = false;
    }
    if ( sub2 == 1 )
    {
        path[vt] = -1;
        for ( int i = 0; i < 3; ++i )
        {
            path[dsk[vt][i]] = i;
            dfs ( dsk[vt][i], vt, i );
        }

        for ( int i = 1; i <= n; ++i )
            if ( ON[i] )
            {
                light[path[i]]++;
            }
        int cnt = 0;
        for ( int i = 0; i < 3; ++i )
            if ( light[i] )
                ++cnt;
        int xuatra = ( cnt + 1 ) / 2;
        if ( xuatra == 0 )
            xuatra += ON[vt];
        cout << xuatra << '\n';
        while ( q-- )
        {
            int x;
            cin >> x;
            if ( ON[x] )
            {
                ON[x] = 0;
                light[path[x]]--;
                cnt = 0;
                for ( int i = 0; i < 3; ++i )
                    if ( light[i] )
                        ++cnt;
            }
            else
            {
                ON[x] = 1;
                light[path[x]]++;
                cnt = 0;
                for ( int i = 0; i < 3; ++i )
                    if ( light[i] )
                        ++cnt;
            }
            xuatra = ( cnt + 1 ) / 2;
            if ( xuatra == 0 )
                xuatra += ON[vt];
            cout << xuatra << '\n';
        }
    }
    else if ( sub1 )
    {
        for ( int i = 1; i <= n; ++i )
            path[i] = 1;
        cout << ( sl > 0 ? 1 : 0 ) << '\n';
        while ( q-- )
        {
            int x;
            cin >> x;
            if ( ON[x] )
                --sl, ON[x] = 0;
            else
                ++sl, ON[x] = 1;
            cout << ( sl > 0 ? 1 : 0 ) << '\n';
        }
    }
}
