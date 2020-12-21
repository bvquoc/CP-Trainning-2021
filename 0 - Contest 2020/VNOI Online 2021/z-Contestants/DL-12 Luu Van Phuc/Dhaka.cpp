#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair< int, long long > ii;
typedef pair< long long, ii > iii;
int n, m, l, k, tmp;
long long ans = 2e15;
int melon[100005];
long long D[100005][40];
vector<ii> G[100005];
void DJ()
{
    for( int i = 1; i <= n; ++i )
        for( int mask = 0; mask < ( 1 << k ); ++mask ) D[i][mask] = 2e15;
    priority_queue< iii, vector<iii>, greater<iii> > pq;
    D[1][melon[1]] = 0;
    pq.push( iii( 0, ii( 1, melon[1] ) ) );
    while( pq.size() )
    {
        int u = pq.top().Y.X;
        long long du = pq.top().X;
        int mask = pq.top().Y.Y;
        pq.pop();
        if( du != D[u][mask] ) continue;
        for( int i = 0; i < G[u].size(); ++i )
        {
            int v = G[u][i].X;
            long long uv = G[u][i].Y;
            int _mask = mask | melon[v];
            if( D[v][_mask] > du + uv )
            {
                D[v][_mask] = du + uv;
                pq.push( iii( D[v][_mask], ii( v, _mask ) ) );
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Dhaka.inp", "r", stdin );
    freopen( "Dhaka.out", "w", stdout );
    cin >> n >> m >> k >> l;
    for( int i = 1; i <= n; ++i )
    {
        int S;
        cin >> S;
        for( int _i = 1; _i <= S; ++_i )
        {
            int X;
            cin >> X; --X;
            melon[i] |= ( 1 << X );
        }
    }
    for( int i = 1; i <= n; ++i ) tmp |= melon[i];
    if( __builtin_popcount( tmp ) < l )
    {
        cout << -1;
        return 0;
    }
    for( int i = 1; i <= m; ++i )
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        G[u].push_back( ii( v, w ) );
        G[v].push_back( ii( u, w ) );
    }
    DJ();
    for( int mask = 0; mask < ( 1 << k ); ++mask ) if( __builtin_popcount( mask ) >= l ) ans = min( ans, D[n][mask] );
    if( ans == 2e15 ) cout << -1; else cout << ans;
}
/**
6 6 2 2
0 1 1 0 0 1 2 0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
*/
