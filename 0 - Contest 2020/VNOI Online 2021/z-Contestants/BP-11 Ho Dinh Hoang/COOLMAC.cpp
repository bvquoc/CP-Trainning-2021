#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
using namespace std;

void file()
{
    freopen ( "COOLMAC.inp", "r", stdin );
    freopen ( "COOLMAC.out", "w", stdout );
}

typedef pair<int, int> ii;

const int maxn = 1e5 + 7;

int n, Min;
ii a[maxn];

bool com ( ii x, ii y )
{
    if ( x.ss < y.ss )
        return true;
    if ( x.ss == y.ss )
        return x.ff < y.ff;
    return false;
}

int mem[maxn];
int seg[4 * maxn];

void update ( int pos, int l, int r, int idx, int val )
{
    if ( l == r )
    {
        seg[pos] = min ( seg[pos], val );
        return;
    }
    int mid = ( l + r ) >> 1;
    if ( l <= idx && idx <= mid )
        update ( pos << 1, l, mid, idx, val );
    else
        update ( ( pos << 1 ) + 1, mid + 1, r, idx, val );
    seg[pos] = min ( seg[pos << 1], seg[ ( pos << 1 ) + 1] );
}

int findMin ( int pos, int l, int r, int lt, int lp )
{
    if ( l > r || l > lp || r < lt )
        return 1e9 + 7;
    if ( l >= lt && r <= lp )
        return seg[pos];
    int mid = ( l + r ) >> 1;
    return min ( findMin ( pos << 1, l, mid, lt, lp ), findMin ( ( pos << 1 ) + 1, mid + 1, r, lt, lp ) );
}

void process()
{
    sort ( a + 1, a + 1 + n, com );

    if ( a[n].ss != 1e5 )
    {
        cout << -1;
        return;
    }

    for ( int i = 0; i < 4 * maxn; ++i )
        seg[i] = 1e9 + 7;

    for ( int i = n; i > 0; --i )
    {
        if ( a[i].ss == 1e5 )
        {
            mem[i] = 1;
            update ( 1, 0, 1e5, a[i].ff, 1 );
            continue;
        }
        mem[i] = 1e9 + 7;
        int x = findMin ( 1, 0, 1e5, a[i].ff, a[i].ss );
        mem[i] = x + 1;
        update ( 1, 0, 1e5, a[i].ff, mem[i] );
    }
    int res = 1e9 + 7;
    for ( int i = 1; i <= n; ++i )
        if ( a[i].ff <= Min )
            res = min ( res, mem[i] );
    if ( res > n )
        cout << -1;
    else
        cout << res;
}

signed main()
{
    faster
    file();
    cin >> n;
    for ( int i = 1; i <= n; ++i )
    {
        int l, r;
        cin >> l >> r;
        a[i].ff = l;
        a[i].ss = r;
    }
    int m;
    cin >> m;
    Min = 1e5 + 7;
    for ( int i = 1; i <= m; ++i )
    {
        int x;
        cin >> x;
        Min = min ( Min, x );
    }

    process();

}
