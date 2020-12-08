#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const int MAXN = 1000010 ;

const int MAXL = 1000000 ;

const int INF = 1000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;

typedef pair < int , ii > iii ;

void print( int u )
{
    if( u == 0 ) putchar( 'a' ) ;
    if( u == 1 ) putchar( 'b' ) ;
    if( u == 2 ) putchar( 'c' ) ;
    if( u == 3 ) putchar( 'd' ) ;
    if( u == 4 ) putchar( 'e' ) ;
    if( u == 5 ) putchar( 'f' ) ;
    if( u == 6 ) putchar( 'g' ) ;
    if( u == 7 ) putchar( 'h' ) ;
    if( u == 8 ) putchar( 'i' ) ;
    if( u == 9 ) putchar( 'j' ) ;
    if( u == 10 ) putchar( 'k' ) ;
    if( u == 11 ) putchar( 'l' ) ;
    if( u == 12 ) putchar( 'm' ) ;
    if( u == 13 ) putchar( 'n' ) ;
    if( u == 14 ) putchar( 'o' ) ;
    if( u == 15 ) putchar( 'p' ) ;
    if( u == 16 ) putchar( 'q' ) ;
    if( u == 17 ) putchar( 'r' ) ;
    if( u == 18 ) putchar( 's' ) ;
    if( u == 19 ) putchar( 't' ) ;
    if( u == 20 ) putchar( 'u' ) ;
    if( u == 21 ) putchar( 'v' ) ;
    if( u == 22 ) putchar( 'w' ) ;
    if( u == 23 ) putchar( 'x' ) ;
    if( u == 24 ) putchar( 'y' ) ;
    if( u == 25 ) putchar( 'z' ) ;
}

//**********************************************************RHYMASTER*********************************************************

int q ;

int n = 0 ;

int root[MAXN] ;

int boss[26] ;

int res[MAXN] ;

int getroot( int u )
{
    if( root[u] == u ) return u ;

    root[u] = getroot( root[u] ) ;

    return root[u] ;
}

void join( int u , int v )
{
    if( u == v ) return ;

    root[u] = getroot( u ) ;
    root[v] = getroot( v ) ;

    if( root[u] == root[v] ) return ;

    root[v] = root[u] ;
}

void change( int x , int y )
{
    if( boss[x] == 0 ) return ;

    if( ( boss[x] == 0 && boss[y] == 0 ) || ( x == y ) ) return ;

    if( boss[y] == 0 )
    {
        swap( boss[x] , boss[y] ) ;

        boss[x] = 0 ;

        return ;
    }

    root[boss[x]] = getroot( root[boss[x]] ) ;

    root[boss[x]] = boss[y] ;

    boss[x] = 0 ;
}

main()
{
    #define FILE "PAINT"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> q ;

    FOR( i , 1 , q ) root[i] = i ;

    int type ;

    char c , c1 , c2 ;

    int tmp , tmp1 , tmp2 ;

    FOR( i , 1 , q )
    {
        cin >> type ;

        if( type == 1 )
        {
            cin >> c ;

            tmp = c - 'a' ;

            n ++ ;

            if( boss[tmp] == 0 ) boss[tmp] = n ;
            else join( boss[tmp] , n ) ;
        }
        else
        {
            cin >> c1 >> c2 ;

            tmp1 = c1 - 'a' ;
            tmp2 = c2 - 'a' ;

            change( tmp1 , tmp2 ) ;
        }
    }

    FOR( i , 1 , n ) root[i] = getroot( i ) ;

    FOR( i , 1 , n )
    {
        FOR( j , 0 , 25 ) if( root[i] == boss[j] )
        {
            res[i] = j ;

            break ;
        }
    }

    FOR( i , 1 , n ) print( res[i] ) ;
}
