#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int nmax= 1e5+9;

int n, m, K, L;
set< int > S[ nmax ];
vector< pair< int, int > > adj[ nmax ];


//{ HOAN VI
void hv()
{
    long long c[11][11];
    memset( c, 0, sizeof(c) );
    for( int i= 1; i<= n; ++i ) for( int j= 1; j<= n; ++j ) c[i][j]= 1e15+9;
    for( int i= 1; i<= n; ++i )
    {
        for( auto pp: adj[i] )
        {
            int v= pp.fi, w= pp.se; c[i][v]= c[v][i]= w;
        }
    }


    long long kq= 1e15+9;
    int X[11]; for( int i= 1; i<= n; ++i ) X[i]= i;
    while( true )
    {
        long long d= 0, d2= 0; set< int > ST= S[1]; bool batdau= false;
        for( int i= 2; i<= n; ++i )
        {
            int u= X[i-1], v= X[i];
            if( batdau == false ) d+= c[u][v]; else d2+= c[u][v];
            for( auto it= S[v].begin(); it != S[v].end(); ++it ) ST.insert( *it );

            if( v == n ) batdau= true;
            if( ST.size() >= L && batdau == true ) kq= min( kq, d + d2 + d2 );
        }

        if( next_permutation( X+2, X+n+1 ) == false ) break;
    }

    if( kq >= 1e15+9 ) cout << -1; else cout << kq;
}
//}


//{ DIJKSTRA
const long long oo= 1e15+9;
long long d[5][ nmax ];
void dijkstra( int s, int t )
{
    priority_queue< pair< long long, int > > MO;
    for( int i= 1; i<= n; ++i ) d[t][i]= oo;

    d[t][s]= 0;
    MO.push({ 0, s });

    while( !MO.empty() )
    {
        int u= MO.top().se; MO.pop();

        for( auto pp: adj[u] )
        {
            int v= pp.fi, w= pp.se;
            if( d[t][u] + w < d[t][v] )
            {
                d[t][v]= d[t][u] + w;
                MO.push({ -d[t][v], v });
            }
        }
    }
}
void subnho()
{
    if( L == 0 )
    {
        dijkstra( 1, 1 );
        cout << d[1][n];
    }
    else
    {
        dijkstra( 1, 1 );
        dijkstra( n, 2 );

        long long kq= oo;
        for( int i= 1; i<= n; ++i ) if( S[i].size() >= 1 )
            kq= min( kq, d[1][i] + d[2][i] );

        if( kq >= oo ) cout << -1; else cout << kq;
    }
}
//}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);


    cin >> n >> m >> K >> L;
    for( int i= 1; i<= n; ++i )
    {
        int sl; cin >> sl;
        for( int j= 1; j<= sl; ++j )
        {
            int x; cin >> x;
            S[i].insert( x );
        }
    }
    for( int i= 1; i<= m; ++i )
    {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }


    if( L == 0 || L == 1 ) subnho();
    else if( n <= 10 ) hv();
    else cout << -1;

    return 0;
}
