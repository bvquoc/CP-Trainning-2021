#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ff first
#define ss second
#define pb push_back
#define name "coolmac"
typedef pair < ll, ll > ii;
const ll maxn = 1e5 + 7, oo = 1e18, mod = 1e9 + 7;
ll m, n, t[maxn], ok[maxn], res = oo, mn = oo, tmin = oo, f[maxn];
ii a[maxn];
vector < ll > ke[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> m;
    rep (i, 1, m)
    {
        cin >> a[i].ff >> a[i].ss;
        if (a[i].ss == 100000)
            tmin = min (tmin, a[i].ff);
        else ke[a[i].ss].pb(a[i].ff);
    }
    cin >> n;
    rep (i, 1, n)
    {
        cin >> t[i];
        mn = min (mn, t[i]);
    }
    if (tmin <= mn)
    {
        cout << 1;
        return 0;
    }
    fill(f+1, f+1+100000, oo);
    rep (i, 1, m)
        if (a[i].ss != 100000)
            f[a[i].ff] = 0;
    rep (i, 1, 100000)
    {
        for (int j : ke[i])
            f[i] = min (f[i], f[j] + 1);
    }
    ll res = oo;
    rep (i, tmin, 100000)
        res = min (res, f[i]);
    if (res == oo)
    {
        cout << -1;
        return 0;
    }
    cout << res + 1;
}
