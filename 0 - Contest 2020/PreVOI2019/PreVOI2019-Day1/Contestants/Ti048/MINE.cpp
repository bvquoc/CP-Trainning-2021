#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( int i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( int i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const int MAXN = 400010 ;

const int MAXL = 400000 ;

const int INF = 1000000000 ;

const int MOD = 1000000007 ;

typedef pair < int , int > ii ;

typedef pair < int , ii > iii ;

//**********************************************************RHYMASTER*********************************************************

int n , m ;

int a[MAXN] ;

int f[MAXN] ;

vector < int > v ;

int res = 0 ;

void calc()
{
    int k = true ;

    FOR( i , 1 , n * 2 - 1 ) FOR( j , i + 1 , n * 2 ) if( f[i] == f[j] )
    {
        if( ( ( j - i + 1 ) % 2 == 1 ) || ( a[j] - a[i] > m ) ) k = false ;
    }

    if( k ) res ++ ;
}

void lam( int id )
{
    if( id > n )
    {
        calc() ;

        return ;
    }

    FOR( i , 0 , v.size() - 1 )
    {
        int tmp = v[i] ;

        f[tmp] = id ;

        v[i] = INF ;

        sort( v.begin() , v.end() ) ;

        v.pop_back() ;

        FOR( j , 0 , v.size() - 1 )
        {
            int tmp2 = v[j] ;

            if( a[tmp2] - a[tmp] > m || tmp2 <= tmp ) break ;

            f[tmp2] = id ;

            v[j] = INF ;

            sort( v.begin() , v.end() ) ;

            v.pop_back() ;

            lam( id + 1 ) ;

            v.push_back( tmp2 ) ;

            sort( v.begin() , v.end() ) ;
        }

        v.push_back( tmp ) ;

        sort( v.begin() , v.end() ) ;
    }
}

main()
{
    #define FILE "MINE"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> n >> m ;

    FOR( i , 1 , n * 2 ) cin >> a[i] ;

    sort( a + 1 , a + n * 2 + 1 ) ;

    FOR( i , 2 , n * 2 ) v.push_back( i ) ;

    f[1] = 1 ;

    FOR( i , 0 , v.size() - 1 )
    {
        int tmp = v[i] ;

        if( a[tmp] - a[1] > m ) break ;

        f[tmp] = 1 ;

        v[i] = INF ;

        sort( v.begin() , v.end() ) ;

        v.pop_back() ;

        lam( 2 ) ;

        v.push_back( tmp ) ;

        sort( v.begin() , v.end() ) ;
    }

    cout << res ;
}
