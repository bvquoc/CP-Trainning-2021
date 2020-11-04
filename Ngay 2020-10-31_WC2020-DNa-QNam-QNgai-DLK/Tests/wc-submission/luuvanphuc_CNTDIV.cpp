#include<bits/stdc++.h>
using namespace std;
int prime[1000020];
int cnt[1000020];
vector<int> res;
int n;
int T;
void spare( int N )
{
    while( N > 1 )
    {
        int x = prime[N];
        ++cnt[x];
        if( cnt[x] == 1 ) res.push_back(x);
        N /= x;
    }
}
int main()
{
    for( int i = 2; i * i <= 1e6 + 10; ++i ) if( !prime[i] ) for( int j = i * i; j <= 1e6 + 10; j += i ) prime[j] = i;
    for( int i = 2; i <= 1e6 + 10; ++i ) if( !prime[i] ) prime[i] = i;
    cin >> T;
    while( T-- )
    {
        res.clear();
        long long ans1 = 1, ans2 = 1;
        cin >> n;
        spare( n );
        spare( n + 1 );
        spare( n + 2 );
        for( int x : res )
        {
            ans1 *= cnt[x] + 1;
            ans2 *= 2 * cnt[x] + 1;
            cnt[x] = 0;
        }
        ans2 /= 2;
        cout << ans2 - ans1 + 1 << endl;
    }
}
