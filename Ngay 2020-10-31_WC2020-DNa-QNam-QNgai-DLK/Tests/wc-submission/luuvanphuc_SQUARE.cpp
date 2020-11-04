#include<bits/stdc++.h>
using namespace std;
long long K;
vector<long long> res;
long long ans = 1e18;
int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
    cin >> K;
    if( K == 0 )
    {
        cout << 0;
        return 0;
    }
    for( long long i = 1; i * i <= abs(K) ; ++i ) if( abs(K) % i == 0 )
    {
        res.push_back( i );
        res.push_back( -i );
        res.push_back( abs(K) / i );
        res.push_back( -abs(K) / i );
    }
    for( long long b : res )
    {
        long long tmp = K / b - b;
        if( abs(tmp) & 1 ) continue;
        long long a = tmp / 2;
        if( a + b < 0 ) continue;
        ans = min( ans, a + b );
    }
    if( ans == 1e18 ) cout << "none"; else cout << ans;
}
