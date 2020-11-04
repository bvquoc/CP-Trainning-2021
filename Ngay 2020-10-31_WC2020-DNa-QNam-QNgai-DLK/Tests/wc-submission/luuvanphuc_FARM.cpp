#include <bits/stdc++.h>
using namespace std;
int n, k, Q, P;
int a[10005],f[10005][10005];
int Get( int day, int _Q )
{
    if( _Q <= 0 || day > n ) return 0;
    int &res = f[day][_Q];
    if( res != -1e9 ) return res;
    res = Get( day + 1, _Q );
    int T = min( P, _Q );
    res = max( res, Get( day + k, _Q - T ) + T * a[day] );
    T = _Q % P;
    res = max( res, Get( day + k, _Q - T ) + T * a[day] );
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> Q >> P;
    for( int i = 1; i <= n; ++i ) cin >> a[i];
    for( int i = 1; i <= n; ++i ) for( int j = 1; j <= Q; ++j ) f[i][j] = -1e9;
    cout << Get( 1, Q );
}
