#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int nmax= 5e5+9;

int n, m, k; char a[ nmax ];


//{ SUB1
int f[ nmax ];
void sub1()
{
    if( a[n] == '1' ) f[n]= 1; else f[n]= 0; int kq= f[n];
    for( int i= n-1; i>= 1; --i )
    {
        if( a[i] == '1' && a[i+1] == '1' ) f[i]= f[i+1] + 1;
        else
        {
            if( a[i] == '1' ) f[i]= 1; else f[i]= 0;
        }
        kq= max( kq, f[i] );
    }


    if( kq == 0 ) cout << -1; else
    for( int i= 1; i<= n; ++i ) if( f[i] == kq )
    {
        cout << i <<" "<< i+f[i]-1; return;
    }
}
//}


//{ SUB2
void sub2()
{
    int beg= 1; int d= 0; vector< pair< int, int > > kq;
    for( int i= 1; i<= n; ++i )
    {
        if( a[i] == '0' ) d++;

        while( d > k )
        {
            if( a[beg] == '0' ) d--;
            beg++;
        }

        if( beg <= i ) kq.push_back({ beg, i });
    }

    int maxx= 0;
    for( auto pp: kq ) maxx= max( maxx, pp.se-pp.fi+1 );

    if( maxx == 0 ) cout << -1; else
    for( auto pp: kq ) if( pp.se-pp.fi+1 == maxx ) { cout << pp.fi <<" "<< pp.se; return; }
}
//}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);

    cin >> n >> m >> k;
    for( int i= 1; i<= n; ++i ) cin >> a[i];

    if( m == 0 && k == 0 ) sub1();
    else if( m == 0 ) sub2();
    else cout << -1;

    return 0;
}
