#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
using namespace std;

void file()
{
    freopen ( "DECOR.inp", "r", stdin );
    freopen ( "DECOR.out", "w", stdout );
}

typedef pair<int, int> ii;

const int maxn = 5e5 + 7;

int n, m, k;
ii a[maxn];
string s;

void sub1()
{
    int cnt = 0;
    int res = 0;
    for ( int i = 0; i < s.size(); ++i )
        if ( s[i] == '0' )
        {
            res = max ( res, cnt );
            cnt = 0;
        }
        else
        {
            ++cnt;
        }
    res = max ( res, cnt );
    cout << res;
}

int res = 0;
vector<ii> v;

void xuly ( int &l, int &r, int cnt, int tmp, int j, int i )
{
    if ( res > min ( n, cnt + tmp ) )
        return;
    else
    {
        res = min ( n, cnt + tmp );
        if ( j != 0 )
        {
            int limit = max ( v[j - 1].ss + 1, v[j].ff - cnt );
            l = limit;
        }
        else
            l = max ( 0, v[j].ff - cnt );

        cnt -= v[j].ff - l;
        if ( i != v.size() - 1 )
        {
            int limit = min ( v[i + 1].ff - 1, v[i].ss + cnt );
            r = limit ;
        }
        else
            r = min ( v[i].ss + cnt, n - 1 );
    }
}

void sub2()
{

    int l = -1;
    for ( int i = 0; i < s.size(); ++i )
    {
        if ( s[i] == '0' )
        {
            if ( l != -1 )
            {
                v.push_back ( {l, i - 1} );
                l = -1;
            }
        }
        else
        {
            if ( l == -1 )
                l = i;
        }
    }
    n = s.size();
    if ( l != -1 )
        v.push_back ( {l, s.size() - 1} );

    int j = 0, cnt = k, tmp = v[0].ss - v[0].ff + 1;
    int  r = 0;
    l = 0;
    xuly ( l, r, cnt, tmp, j, 0 );

    for ( int i = 1; i < v.size(); ++i )
    {
        cnt -= v[i].ff - ( v[i - 1].ss + 1 );
        tmp += v[i].ss - v[i].ff + 1 + ( v[i].ff - v[i - 1].ss - 1 );
        while ( cnt < 0 )
        {
            tmp -= v[j + 1].ff - v[j].ff;
            cnt += v[j + 1].ff - v[j].ss - 1;
            ++j;
        }
        xuly ( l, r, cnt, tmp, j, i );
    }
    cout << l+1 << ' ' << r+1;
}

signed main()
{
    faster
    file();
    cin >> n >> m >> k;
    cin >> s;
    for ( int i = 1; i <= m; ++i )
    {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }
    if ( m + k == 0 )
        sub1();
    else
        sub2();
}
