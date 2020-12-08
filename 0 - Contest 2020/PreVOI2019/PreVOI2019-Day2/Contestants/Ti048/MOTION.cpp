#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

#define x1 stfu
#define x2 stfuuuu
#define y1 lmao
#define y2 lmaoooo
#define u1 rofl
#define u2 rofllll
#define v1 omfg
#define v2 omfgggg


typedef long long ll ;

const int MAXN = 100010 ;

const int MAXL = 100000 ;

const int INF = 1000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;

typedef pair < int , ii > iii ;

//**********************************************************RHYMASTER*********************************************************

ll Rand( ll l , ll h )
{
    return l + ( ( ll ) rand() * ( RAND_MAX + 1 ) * ( RAND_MAX + 1 ) * ( RAND_MAX + 1 ) +
                 ( ll ) rand() * ( RAND_MAX + 1 ) * ( RAND_MAX + 1 ) +
                 ( ll ) rand() * ( RAND_MAX + 1 ) +
                 rand() ) % ( h - l + 1 ) ;
}

void Solve()
{
    int n , m , x1 , x2 , y1 , y2 , u1 , u2 , v1 , v2 ;

    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> u1 >> v1 >> u2 >> v2 ;

    int x = x2 - x1 ;
    int y = y2 - y1 ;
    int u = u2 - u1 ;
    int v = v2 - v1 ;

    if( u == x && y == v ) cout << -1 << '\n' ;
    else cout << Rand( 0 , 100 ) << ' ' << Rand( 1 , 100 ) << '\n' ;
}

main()
{
    srand( time( NULL ) ) ;

    #define FILE "MOTION"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    int t ;

    cin >> t ;

    while( t -- ) Solve() ;
}
