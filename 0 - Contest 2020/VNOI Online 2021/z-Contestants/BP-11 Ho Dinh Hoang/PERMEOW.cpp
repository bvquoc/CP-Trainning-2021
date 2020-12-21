#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void file()
{
    freopen ( "PERMEOW.inp", "r", stdin );
    freopen ( "PERMEOW.out", "w", stdout );
}

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;

int n;
vector<int> a, b;
vector<int> seg;

void update ( int pos, int l, int r, int idx )
{
    if ( l == r )
    {
        seg[pos] += 1;
        return;
    }
    int mid = ( l + r ) >> 1;
    if ( l <= idx && idx <= mid )
        update ( pos << 1, l, mid, idx );
    else if ( mid + 1 <= idx && idx <= r )
        update ( ( pos << 1 ) + 1, mid + 1, r, idx );
    seg[pos] = seg[ ( pos << 1 )] + seg[ ( pos << 1 ) + 1];
}

long long findX ( int pos, int l, int r, int lt, int lp )
{
    if ( l > r || l > lp || r < lt )
        return 0;
    if ( l >= lt && r <= lp )
        return seg[pos];
    int mid = ( l + r ) >> 1;
    return findX ( pos << 1, l, mid, lt, lp ) + findX ( ( pos << 1 ) + 1, mid + 1, r, lt, lp );
}

signed main()
{
    faster
    file();
    cin >> n;
    a.assign ( n + 1, 0 );
    b.assign ( n + 1, 0 );
    for ( int i = 1; i <= n; ++i )
        cin >> a[i];
    for ( int i = 1; i <= n; ++i )
        cin >> b[i];
    long long res = 0;
    do
    {
        seg.assign ( 4 * n + 7, 0 );
        for ( int i = 1; i <= n; ++i )
        {
            res += findX ( 1, 1, n, a[i] + 1, n );
            if ( res >= mod )
                res -= mod;
            update ( 1, 1, n, a[i] );
        }
        int cnt = 0;
        for ( int i = 1; i <= n; ++i )
            if ( a[i] == b[i] )
                ++cnt;
        if ( cnt == n )
            break;
    }
    while ( next_permutation ( a.begin() + 1, a.end() ) );
    cout << res;

}
