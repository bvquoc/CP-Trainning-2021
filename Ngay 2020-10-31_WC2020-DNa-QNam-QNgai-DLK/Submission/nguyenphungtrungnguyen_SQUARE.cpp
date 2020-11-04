#include <bits/stdc++.h>
using namespace std;
long long k,n;
vector<long long> c,a;
int main()
{
    cin >> k;
    n = abs(k);
    for(long i = 1; i <= sqrt(n); i++)
    {
        if( n % i == 0 )
        {
            c.push_back(i);
            if( i != sqrt(n) ) c.push_back( n/i );
        }
    }
    if( k == 0 )
    {
        cout << 0;
        return 0;
    }
    long long res = 1e18;
    for(long i = 0; i < c.size(); i++)
    {
        long long tmp = k/c[i] - c[i];
        if( (tmp % 2) == 0 && ( tmp / 2 + c[i] ) >= 0 ) res = min( res, tmp / 2 + c[i] );
        tmp = k/(-c[i]) - (-c[i]);
        if( (tmp % 2) == 0 && ( tmp / 2 - c[i] ) >= 0 ) res = min( res, tmp / 2 - c[i] );
    }
    if( res == 1e18 )
    {
        cout << "none";
        return 0;
    }
    cout << res;
}
