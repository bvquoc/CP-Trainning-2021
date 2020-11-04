#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll k;
    cin >> k;

    if (k == 0)
    {
        cout << 0;
        return 0;
    }

    vector<ll> c;
    ll n = abs(k);
    int lim = sqrt(n);
    for (int x = 1; x <= lim; ++x)
    {
        if (n % x == 0)
        {
            c.push_back(-x);
            c.push_back(-n / x);
            c.push_back(+n / x);
            c.push_back(+x);
        }
    }

    ll res = 1e18;
    for (ll x : c)
    {
        ll t = k / x - x;
        if (t % 2 == 0)
        {
            ll g = t / 2 + x;
            if (g >= 0) res = min(res, g);
        }
    }

    if (res == 1e18)
        cout << "none";
    else 
        cout << res;
}