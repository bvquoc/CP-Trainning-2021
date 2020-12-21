#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int nmax= 1e5+9;

int n; pair< int, int > a[ nmax ];
int m, t1= 1e5, t2= 1e5;


int NPsearch( int x )
{
    int d= 1, c= n, vt= -1;
    while( d <= c )
    {
        int i= (d+c)/2;
        if( a[i].fi <= x ) { vt= i; d= i+1; }
        else c= i-1;
    }

    return vt;
}
int MAX[ nmax ];
void solve()
{
    sort( a+1, a+n+1 );
    MAX[1]= a[1].se; for( int i= 2; i<= n; ++i ) MAX[i]= max( MAX[i-1], a[i].se );

    int L= t1; int kq= 0;
    while( L <= t2 )
    {
        int vt= NPsearch( L ); if( vt == -1 ) { cout << -1; return; } // vo han
        if( MAX[vt] < L ) { cout << -1; return; } // vo han
        else L= MAX[vt]+1; // doan [ L, MAX[vt] ] da dc phu
        kq++;
    }

    cout << kq;
}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);


    cin >> n; for( int i= 1; i<= n; ++i )
    {
        cin >> a[i].fi >> a[i].se;
    }

    cin >> m; for( int i= 1; i<= m; ++i )
    {
        int x; cin >> x;
        t1= min( t1, x );
    }


    solve();
    return 0;
}
