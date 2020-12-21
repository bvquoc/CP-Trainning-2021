#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int tmp;
int a[200005];
long long Mod[200005];
long long MOD = 1e9 + 7;
long long solve( int pos )
{
    if( pos == n ) return 0;
    long long res = 0;
    for( int i = 1; i < a[pos]; ++i ) //if( onl[i] )
    {
        res = ( res + Mod[ n - pos ] * abs( i - pos ) ) % MOD;
        for( int x = pos + 1; x <= n; ++x ) res = ( res + ( a[pos] - 2 ) * Mod[n-pos-1] * abs( i - x ) ) % MOD;
    }
    for( int i = a[pos]; i <= n; ++i ) for( int x = pos + 1; x <= n; ++x ) res = res + ( a[pos] - 1 ) * Mod[n-pos-1] * abs( i - x );
    return ( res + solve( pos + 1 ) ) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Permeow.inp", "r", stdin );
    freopen( "Permeow.out", "w", stdout );
    cin >> n;
    Mod[1] = 1;
    for( int i = 2; i <= n; ++i ) Mod[i] = ( Mod[i-1] * i ) % MOD;
    for( int i = 1; i <= n; ++i ) cin >> a[i];
    ans -= solve(1) / 2;
    for( int i = 1; i <= n; ++i ) cin >> a[i];
    ans += solve(1) / 2;
    for( int i = 1; i <= n; ++i ) tmp += abs( a[i] - i );
    ans += tmp / 2;
    ans %= MOD;
    cout << ans;
}
