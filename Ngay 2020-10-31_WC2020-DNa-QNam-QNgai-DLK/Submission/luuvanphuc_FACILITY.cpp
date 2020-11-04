#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair< long long, int > ii;
int n, K;
priority_queue< ii, vector<ii>, greater<ii> > pq;
map< long long, long long > mp;
vector<long long> res;
struct custom
{
    long long L, R, fee;
} a[1000005];
int main()
{
    cin >> n >> K;
    for( int i = 1; i <= n; ++i )
    {
        cin >> a[i].L >> a[i].R >> a[i].fee;
        a[i].R += a[i].L;
        pq.push( ii( a[i].R, i ) );
    }
    res.push_back(0);
    while( pq.size() )
    {
        int i = pq.top().Y;
        int S = a[i].L;
        int F = a[i].R;
        S -= K;
        int pos = upper_bound( res.begin(), res.end(), S ) - res.begin() - 1;
        res.push_back( F );
        int en = res.size() - 1;
        mp[F] = max( mp[F], mp[res[pos]] + a[i].fee );
        mp[F] = max( mp[F], mp[res[en-1]] );
        pq.pop();
    }
    //for( long long x : res ) cout << x << " " << mp[x] << endl;
    cout << mp[res[res.size()-1]];
}
