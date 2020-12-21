#include <bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
using namespace std;

void file()
{
    freopen ( "GIFT11.inp", "r", stdin );
    freopen ( "GIFT11.out", "w", stdout );
}

typedef long long ll;
typedef pair<ll, ll> ii;

const ll mod = 998244353;

ll n;
ll res = 0;
vector<string> s;

vector<ii> xuly ( vector<string> &h )
{
    vector<ii> a;
    a.assign ( n + 1, ii() );
    for ( ll i = 1; i <= n; ++i )
    {
        ll c = 0, l = 0;
        for ( ll j = 0; j < h[i].size(); ++j )
            if ( j % 2 == 0 )
                l += h[i][j] - '0';
            else
                c += h[i][j] - '0';
        a[i] = make_pair(l, c);
    }
    return a;
}

void trau ( ll mask, vector<string> & tmp )
{
    if ( mask == ( 1 << n ) - 1 )
    {
        vector<ii> a = xuly ( tmp );
        ll check = 1;
        ll l = 0, c = 0;
        for ( ll i = 1; i <= n; ++i )
        {
            if ( check == 1 )
            {
                l += a[i].ff;
                c += a[i].ss;
                if ( tmp[i].size() % 2 == 1 )
                    check = 0;
            }
            else
            {
                l += a[i].ss;
                c += a[i].ff;
                if ( tmp[i].size() % 2 == 1 )
                    check = 1;
            }
        }
        if ( abs ( l - c ) % 11 == 0 )
            ++res;
    }
    for ( ll j = 0; j < n; ++j )
        if ( ( ( mask >> j ) & 1 ) == 0 )
        {
            tmp.push_back ( s[j + 1] );
            ll n_mask = ( 1 << j ) | mask;
            trau ( n_mask, tmp );
            tmp.pop_back();
        }
}

void process()
{
    res = 0;
    cin >> n;
    s.assign ( n + 1, "" );
    for ( ll i = 1; i <= n; ++i )
        cin >> s[i];
    sort ( s.begin() + 1, s.end() );
    if ( n <= 10 )
    {

        vector<string> tmp;
        tmp.push_back ( "/" );
        trau ( 0, tmp );
        cout << res << '\n';
    }
    else
    {
        ll l = 0, c = 0;
        vector<ii> a = xuly ( s );
        for ( ll i = 1; i <= n; ++i )
            l += a[i].ff, c += a[i].ss;
        if ( abs ( l - c ) % 11 == 0 )
        {
            res = 1;
            for ( ll i = 1; i <= n; ++i )
                res = ( res * i ) % mod;
            cout << res << '\n';
        }
        else
            cout << 0 << '\n';
    }

}

signed main()
{
    faster
    file();
    ll t;
    cin >> t;
    while ( t-- )
        process();
}
