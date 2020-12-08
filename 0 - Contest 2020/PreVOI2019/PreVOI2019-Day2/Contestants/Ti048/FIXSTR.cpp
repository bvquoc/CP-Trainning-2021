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

//**********************************************************RHYMASTER*********************************************************

int n , m ;

string s ;

int a[MAXN] ;

int STmax[4 * MAXN] ;
int STmin[4 * MAXN] ;

int lazy[4 * MAXN] ;

//**********************************************************RHYMASTER*********************************************************

int f[1010][1010] ;

void fixarray( int u , int v )
{
    FOR( i , 1 , n ) f[u][i] = f[v][i] ;
}

int calc( int u , int l , int r )
{
    int sum = 0 ;

    int res = 0 ;

    FOR( i , l , r )
    {
        if( sum < 0 && f[u][i] == 1 )
        {
            res += abs( sum ) ;

            sum = 1 ;
        }
        else sum += f[u][i] ;
    }

    res += abs( sum ) ;

    return res ;
}

void trau()
{
    FOR( i , 0 , n - 1 )
    {
        if( s[i] == '(' ) f[0][i + 1] = 1 ;
        else f[0][i + 1] = -1 ;
    }

    char type ;

    FOR( i , 1 , m )
    {
        cin >> type ;

        if( type == 'C' )
        {
            int pos ;

            cin >> pos ;

            fixarray( i , i - 1 ) ;

            f[i][pos] *= -1 ;
        }

        if( type == 'Q' )
        {
            int l , r ;

            cin >> l >> r ;

            fixarray( i , i - 1 ) ;

            cout << calc( i , l , r ) << '\n' ;
        }

        if( type == 'U' )
        {
            int pos ;

            cin >> pos ;

            fixarray( i , pos - 1 ) ;
        }

        //FOR( j , 1 , n ) if( f[i][j] == 1 ) cout << '(' ; else cout << ')' ; cout << endl ;
    }
}

//**********************************************************RHYMASTER*********************************************************

void build( int id , int l , int r )
{
    if( l < 1 || l > n || r < 1 || r > n || l > r ) return ;

    if( l == r )
    {
        STmax[id] = l ;
        STmin[id] = l ;

        return ;
    }

    int mid = ( l + r ) / 2 ;

    build( id * 2 , l , mid ) ;
    build( id * 2 + 1 , mid + 1 , r ) ;

    if( a[STmax[id * 2]] >= a[STmax[id * 2 + 1]] ) STmax[id] = STmax[id * 2] ;
    else STmax[id] = STmax[id * 2 + 1] ;

    if( a[STmin[id * 2]] <= a[STmin[id * 2 + 1]] ) STmin[id] = STmin[id * 2] ;
    else STmin[id] = STmin[id * 2 + 1] ;
}

void down( int id )
{
    int t = lazy[id] ;

    lazy[id] = 0 ;

    if( STmax[id * 2] == STmin[id * 2] )
    {
        if( STmax[id * 2] != STmax[id] && STmax[id * 2] != STmin[id] ) a[STmax[id * 2]] += t ;
    }
    else
    {
        if( STmax[id * 2] != STmax[id] ) a[STmax[id * 2]] += t ;
        if( STmin[id * 2] != STmin[id] ) a[STmin[id * 2]] += t ;
    }

    lazy[id * 2] += t ;

    if( STmax[id * 2 + 1] == STmin[id * 2 + 1] )
    {
        if( STmax[id * 2 + 1] != STmax[id] && STmax[id * 2 + 1] != STmin[id] ) a[STmax[id * 2 + 1]] += t ;
    }
    else
    {
        if( STmax[id * 2 + 1] != STmax[id] ) a[STmax[id * 2 + 1]] += t ;
        if( STmin[id * 2 + 1] != STmin[id] ) a[STmin[id * 2 + 1]] += t ;
    }

    lazy[id * 2 + 1] += t ;
}

void update( int id , int l , int r , int u , int v , int val )
{
    if( l < 1 || l > n || r < 1 || r > n || l > r ) return ;

    if( l > u || r < v ) return ;

    if( u <= l && r <= v )
    {
        a[STmax[id]] += val ;
        if( STmin[id] != STmax[id] ) a[STmin[id]] += val ;
        lazy[id] += val ;

        return ;
    }

    down( id ) ;

    int mid = ( l + r ) / 2 ;

    update( id * 2 , l , mid , u , v , val ) ;
    update( id * 2 + 1 , mid + 1 , r , u , v , val ) ;

    if( a[STmax[id * 2]] >= a[STmax[id * 2 + 1]] ) STmax[id] = STmax[id * 2] ;
    else STmax[id] = STmax[id * 2 + 1] ;

    if( a[STmin[id * 2]] <= a[STmin[id * 2 + 1]] ) STmin[id] = STmin[id * 2] ;
    else STmin[id] = STmin[id * 2 + 1] ;
}

int getmax( int id , int l , int r , int u , int v )
{
    if( l < 1 || l > n || r < 1 || r > n || l > r ) return 0 ;

    if( l > u || r < v ) return 0 ;

    if( u <= l && r <= v ) return STmax[id] ;

    down( id ) ;

    int mid = ( l + r ) / 2 ;

    int tmp1 = getmax( id * 2 , l , mid , u , v ) ;
    int tmp2 = getmax( id * 2 + 1 , mid + 1 , r , u , v ) ;

    if( a[STmax[id * 2]] >= a[STmax[id * 2 + 1]] ) STmax[id] = STmax[id * 2] ;
    else STmax[id] = STmax[id * 2 + 1] ;

    if( a[STmin[id * 2]] <= a[STmin[id * 2 + 1]] ) STmin[id] = STmin[id * 2] ;
    else STmin[id] = STmin[id * 2 + 1] ;

    if( tmp1 == 0 ) return tmp2 ;
    if( tmp2 == 0 ) return tmp1 ;

    if( a[tmp1] >= a[tmp2] ) return tmp1 ;
    else return tmp2 ;
}

int getmin( int id , int l , int r , int u , int v )
{
    if( l < 1 || l > n || r < 1 || r > n || l > r ) return INF ;

    if( l > u || r < v ) return INF ;

    if( u <= l && r <= v ) return STmin[id] ;

    down( id ) ;

    int mid = ( l + r ) / 2 ;

    int tmp1 = getmax( id * 2 , l , mid , u , v ) ;
    int tmp2 = getmax( id * 2 + 1 , mid + 1 , r , u , v ) ;

    if( a[STmax[id * 2]] >= a[STmax[id * 2 + 1]] ) STmax[id] = STmax[id * 2] ;
    else STmax[id] = STmax[id * 2 + 1] ;

    if( a[STmin[id * 2]] <= a[STmin[id * 2 + 1]] ) STmin[id] = STmin[id * 2] ;
    else STmin[id] = STmin[id * 2 + 1] ;

    if( tmp1 == 0 ) return tmp2 ;
    if( tmp2 == 0 ) return tmp1 ;

    if( a[tmp1] <= a[tmp2] ) return tmp1 ;
    else return tmp2 ;
}

void tinhte()
{
    FOR( i , 0 , n - 1 )
    {
        if( s[i] == '(' ) a[i + 1] = 1 ;
        else a[i + 1] = -1 ;
    }

    FOR( i , 1 , n ) a[i] += a[i - 1] ;

    build( 1 , 1 , n ) ;

    char type ;

    int pos , l , r ;

    int tmp ;

    FOR( i , 1 , m )
    {
        cin >> type ;

        if( type == 'C' )
        {
            cin >> pos ;

            if( s[pos - 1] == '(' ) tmp = -2 ;
            else tmp = 2 ;

            update( 1 , 1 , n , pos , n , tmp ) ;
        }

        if( type == 'Q' )
        {
            cin >> l >> r ;

            int res = 0 ;

            int posmin = getmin( 1 , 1 , n , l , r ) ;

            int posmax = -1 ;

            posmax = getmax( 1 , 1 , n , l - 1 , l - 1 ) ;

            posmax = -1 ;

            int Min = a[posmin] - a[l - 1] ;

            int Max = 0 ;

            if( Min < 0 )
            {
                if( posmin < r ) posmax = getmax( 1 , 1 , n , posmin + 1 , r ) ;

                res += abs( Min ) ;

                if( posmax != -1 )
                {
                    Max = a[posmax] - a[posmin] ;

                    res += abs( Max ) ;
                }

                cout << res << '\n' ;
            }
            else
            {
                posmax = getmax( 1 , 1 , n , r , r ) ;

                cout << abs( a[r] - a[l - 1] ) << '\n' ;
            }
        }
    }
}

//**********************************************************RHYMASTER*********************************************************

main()
{
    #define FILE "FIXSTR"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    cin >> s ;

    n = s.length() ;

    cin >> m ;

    if( n <= 1000 && m <= 1000 ) trau() ;
    else tinhte() ;
}
