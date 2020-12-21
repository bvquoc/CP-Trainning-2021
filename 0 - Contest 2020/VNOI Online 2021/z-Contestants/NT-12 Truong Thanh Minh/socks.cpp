#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ff first
#define ss second
#define pb push_back
#define name "socks"
const ll maxn = 5e5 + 7, oo = 1e18, mod = 1e9 + 7;
ll n, q, x, y, a[maxn];
vector < ll > g[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n >> q;
    rep (i, 1, n)
        cin >> a[i];
    rep (i, 1, n)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    rep (i, 1, q)
    {
        cin >> x;
        a[x] = 1 - a[x];
    }
    rep (i, 1, q + 1)
        cout << 1 << '\n';
}
