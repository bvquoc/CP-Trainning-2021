#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int n;
long long M;
int main()
{
    cin >> M >> n;
    for( int i = 1; i <= n; ++i )
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int L = 0;
    for( int i = 0; i <= n - L; ++i )
    {
        int pos = lower_bound( a + 1, a + 1 + n, a[i] + M ) - a;
        L = max( L, pos - i );
    }
    cout << L;
}
