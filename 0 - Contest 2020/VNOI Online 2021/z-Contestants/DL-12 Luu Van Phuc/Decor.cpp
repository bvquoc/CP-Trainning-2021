#include<bits/stdc++.h>
using namespace std;
int mx;
int L, R;
int sum[500005], a[500005];
string str;
int n, m, k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen( "Decor.inp", "r", stdin );
    freopen( "Decor.out", "w", stdout );
    cin >> n >> m >> k;
    cin >> str;
    for( int i = 1; i <= n; ++i ) a[i] = str[i-1] - '0';
    for( int i = 1; i <= n; ++i ) sum[i] = sum[i-1] + ( !a[i] );
    for( int i = n; i >= 1; --i )
    {
        int pos = upper_bound( sum + 1, sum + 1 + n, sum[i-1] + k ) - sum;
        if( pos - i > mx )
        {
            mx = pos - i;
            L = i; R = pos - 1;
        }
    }
    cout << L << " " << R;
}
