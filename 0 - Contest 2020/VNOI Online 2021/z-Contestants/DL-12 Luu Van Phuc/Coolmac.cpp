#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair< int, int > ii;
ii a[100005];
int L = 1e9, R;
int n, m;
int cnt;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Coolmac.inp", "r", stdin );
    freopen( "Coolmac.out", "w", stdout );
    cin >> m;
    for( int i = 1; i <= m; ++i ) cin >> a[i].X >> a[i].Y;
    sort( a + 1, a + 1 + m );
    cin >> n;
    for( int i = 1; i <= n; ++i )
    {
        int x;
        cin >> x;
        L = min( L, x );
    }
    a[m+1].X = 1e9;
    for( int i = 1; i <= m + 1; ++i )
    {
        if( a[i].X <= L )
        {
            R = max( a[i].Y, R );
            continue;
        }
        L = R; ++cnt;
        if( L < a[i].X && i != m + 1 )
        {
            cout << -1;
            return 0;
        }
        R = max( R, a[i].Y );
    }
    if( !cnt )
    {
        cout << -1;
        return 0;
    }
    if( L < 1e5 )
    {
        cout << -1;
        return 0;
    }
    cout << cnt;
}
