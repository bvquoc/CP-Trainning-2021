#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const int MAXN = 100010 ;

const int MAXL = 100000 ;

const int INF = 1000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;

typedef pair < int , ii > iii ;

inline int scan( int &a )
{
    bool minus = false ;

    int res = 0 ;

    char c ;

    c = getchar() ;

    while( true )
    {
        if( c == '-' ) break ;

        if( c >= '0' && c <= '9' ) break ;

        c = getchar() ;
    }

    if( c == '-' ) minus = true ;
    else res = c - '0' ;

    while( true )
    {
        c = getchar() ;

        if( c < '0' || c > '9' ) break ;

        res = res * 10 + ( c - '0' ) ;
    }
    if( minus ) a = -res ;
    else a = res ;

    return 0 ;
}

inline ll scanll( ll &a )
{
    bool minus = false ;

    ll res = 0 ;

    char c ;

    c = getchar() ;

    while( true )
    {
        if( c == '-' ) break ;

        if( c >= '0' && c <= '9' ) break ;

        c = getchar() ;
    }

    if( c == '-' ) minus = true ;
    else res = c - '0' ;

    while( true )
    {
        c = getchar() ;

        if( c < '0' || c > '9' ) break ;

        res = res * 10 + ( c - '0' ) ;
    }
    if( minus ) a = -res ;
    else a = res ;

    return 0 ;
}

inline void printll( ll n )
{
    if( n < 0 ) putchar( '-' ) , n = -n ;

    ll N = n, rev , count = 0 ;

    rev = N ;

    if( N == 0 )
    {
        putchar( '0' ) ;

        return ;
    }

    while( ( rev % 10 ) == 0 )
    {
        count ++ ;

        rev /= 10 ;
    }

    rev = 0 ;

    while( N != 0 )
    {
        rev = ( rev << 3 ) + ( rev << 1 ) + N % 10 ;

        N /= 10 ;
    }

    while( rev != 0 )
    {
        putchar( rev % 10 + '0' ) ;

        rev /= 10 ;
    }

    while( count -- ) putchar('0') ;
}

//**********************************************************RHYMASTER*********************************************************

int n , m ;

ll a[MAXN] ;
ll f[MAXN] ;

//**********************************************************RHYMASTER*********************************************************

ll xet( int l , int r )
{
    ll res = a[l] ;

    ll Min = a[l] ;
    ll Max = a[l] ;

    FOR( i , l , r )
    {
        if( a[i] >= Max ) Max = a[i] ;
        else
        {
            res += Max - Min ;

            Min = a[i] ;
            Max = a[i] ;
        }
    }

    res += Max - Min ;

    return res ;
}

void fixarray( int r )
{
    FOR( i , 1 , r ) if( f[i] > 0 )
    {
        a[i] += f[i] ;

        f[i + 1] += f[i] ;

        f[i] = 0 ;
    }
}

void trau()
{
    while( m -- )
    {
        int type ;

        scan( type ) ;

        if( type == 1 )
        {
            int l , r ;
            ll val ;

            scan( l ) ;
            scan( r ) ;
            scanll( val ) ;

            f[l] += val ;
            f[r + 1] -= val ;
        }
        else
        {
            int l , r ;

            scan( l ) ;
            scan( r ) ;

            fixarray( r ) ;

            printll( xet( l , r ) ) ;
            putchar( '\n' ) ;
        }
    }
}

//**********************************************************RHYMASTER*********************************************************

void tinhte()
{
    trau() ;
}

//**********************************************************RHYMASTER*********************************************************

void Solve()
{
    scan( n ) ;
    scan( m ) ;

    FOR( i , 1 , n ) scanll( a[i] ) ;

    FOR( i , 1 , n ) f[i] = 0 ;

    trau() ;
}

//**********************************************************RHYMASTER*********************************************************

main()
{
    #define FILE "CONSTRUCT"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    /*ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;*/

    int querry ;

    scan( querry ) ;

    while( querry -- ) Solve() ;
}
