#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long MOD = 998244353;
int T, n;
int solve( int X )
{
    int k = 1;
    int sum = 0;
    while( X > 0 )
    {
        sum += X % 10 * k;
        k = 0 - k;
        X /= 10;
    }
    return sum;
}
long long GT( int X )
{
    long long ans = 1;
    for( int i = 1; i <= X; ++i )
    {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Gift11.inp", "r", stdin );
    freopen( "Gift11.out", "w", stdout );
    cin >> T;
    while( T-- )
    {
        int sum = 0;
        cin >> n;
        for( int i = 1; i <= n; ++i )
        {
            cin >> a[i];
            sum += solve( a[i] );
        }
        if( ( sum + 99999999 ) % 11 != 0 )
        {
            cout << 0 << endl;
            continue;
        }
        cout << GT( n ) << endl;
    }
}
