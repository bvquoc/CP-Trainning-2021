#include<bits/stdc++.h>
using namespace std;
int n, m;
int P[20][500005];
int onl[500005], level[500005], child[500005];
int ans;
vector<int> G[500005];
void DFS( int u, int p )
{
    level[u] = level[p] + 1;
    if( onl[u] ) child[u] = 1;
    for( int v : G[u] ) if( !level[v] && v != p )
    {
        DFS( v, u );
        child[u] += ( child[v] > 0 );
    }
    if( onl[u] == child[u] && onl[u] ) ++ans;
}
void DFS_( int u, int p )
{
    if( child[u] == onl[u] && onl[u] )
    {
        --ans;
        return;
    }
    if( child[u] )
    {
        ++ans;
        return;
    }
    for( int v : G[u] ) if( v != p )
    {
        DFS_( v, u );
        child[u] += ( child[v] > 0 );
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Socks.inp", "r", stdin );
    freopen( "Socks.out", "w", stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; ++i ) cin >> onl[i];
    for( int i = 1; i < n; ++i )
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS( 1, 1 ); ++ans; cout << ans / 2 + ( ans % 2 ) << endl;
    while( m-- )
    {
        int p;
        cin >> p;
        if( child[p] )
        {
            cout << ans / 2 + ( ans % 2 ) << endl;
            continue;
        }
        DFS_( p, p );
        ++onl[p];
        cout << ans / 2 + ( ans % 2 ) << endl;
    }
}
/**
6 4
0 0 0 1 0 1
1 3
3 2
3 4
4 5
4 6
1
2
3
5
*/
