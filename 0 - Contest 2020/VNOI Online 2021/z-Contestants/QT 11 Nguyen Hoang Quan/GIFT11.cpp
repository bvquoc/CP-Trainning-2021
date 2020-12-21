#include <bits/stdc++.h>

using namespace std;
const int nmax= 2002;
const int mod= 998244353;

int n, a[ nmax ];


void add( int m, vector< int > &kq )
{
    vector< int > X; while( m != 0 )
    {
        X.push_back( m % 10 );
        m/= 10;
    }
    reverse( X.begin(), X.end() );

    for( int cs: X ) kq.push_back( cs );
}
void hv()
{
    int X[11]; for( int i= 1; i<= n; ++i ) X[i]= i;

    int cnt= 0;
    while( true )
    {
        vector< int > kq; kq.push_back( 0 );
        for( int i= 1; i<= n; ++i )
        add( a[ X[i] ], kq );

        int tl= 0, tc= 0;
        for( int i= 1; i< kq.size(); i+= 2 ) tl+= kq[i];
        for( int i= 2; i< kq.size(); i+= 2 ) tc+= kq[i];

        if( abs(tl-tc) % 11 == 0 ) cnt++;

        if( next_permutation( X+1, X+n+1 ) == false ) break;
    }

    cout << cnt <<'\n';
}


int check()
{
    vector< int > lcs; lcs.push_back( 0 );
    for( int i= 1; i<= n; ++i )
    {
        int m= a[i];
        int dem= 0; while( m != 0 ) { dem++; lcs.push_back( m%10 ); m/= 10; }
        if( dem % 2 == 1 ) return 0;
    }

    long long tc= 0, tl= 0;
    for( int i= 1; i< lcs.size(); i+= 2 ) tl+= lcs[i];
    for( int i= 2; i< lcs.size(); i+= 2 ) tc+= lcs[i];
    if( abs(tl-tc) % 11 == 0 ) return 1;
    else return -1;
}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);

    int T; cin >> T;
    for( int t= 1; t<= T; ++t )
    {
        cin >> n; for( int i= 1; i<= n; ++i ) cin >> a[i];

        if( check() == 0 ) hv();
        else if( check() != 0 )
        {
            long long gt= 1;
            for( int i= 1; i<= n; ++i ) gt= ( gt*i )%mod;
            if( check() == 1 ) cout << gt <<'\n';
            else cout << 0 <<'\n';
        }
    }

    return 0;
}
