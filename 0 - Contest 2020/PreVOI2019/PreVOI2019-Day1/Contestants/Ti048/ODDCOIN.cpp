#include<bits/stdc++.h>

using namespace std ;


#define FOR( i , a , b ) for( ll i = a , _b = b ; i <= _b ; i ++ )

#define FOD( i , a , b ) for( ll i = a , _b = b ; i >= _b ; i -- )

#define fi first

#define se second

typedef long long ll ;

const ll MAXN = 100010 ;

const ll MAXL = 100000 ;

const ll INF = 1000000000 ;

const ll MOD = 1000000007 ;

typedef pair < ll , ll > ii ;

typedef pair < ll , ii > iii ;

//**********************************************************RHYMASTER*********************************************************

ll a[15] = { 1 , 3 , 5 , 10 , 30 , 50 , 100 , 300 , 500 , 1000 , 3000 , 5000 , 10000 , 30000 , 50000 } ;

ll calc( ll x )
{
    ll res = 0 ;

    if( x == 0 ) return 0 ;

    FOD( i , 14 , 0 )
    {
        res += x / a[i] ;

        x %= a[i] ;
    }

    return res ;
}

void Solve()
{
    ll x , n ;

    cin >> x >> n ;

    ll res = calc( n ) ;

    FOR( i , 1 , 200000 )
    {
        if( i * x > n ) break ;

        ll tmp = calc( n - i * x ) + i ;

        if( tmp > res + 15 ) break ;

        res = min( res , tmp ) ;
    }

    cout << res << '\n' ;
}

main()
{
    #define FILE "ODDCOIN"

    freopen( FILE".inp" , "r" , stdin ) ;
    freopen( FILE".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    ll querry ;

    cin >> querry ;

    while( querry -- ) Solve() ;
}
