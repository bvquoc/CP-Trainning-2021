#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(ll i = (a); i <= (b); ++i)
#define req(i, a, b) for(ll i = (a); i >= (b); --i)
#define name "PERMEOW"
#define pb push_back
#define eb emplace_back
#define sz size()
#define ff first
#define ss second
typedef pair < ll, ll > ii;
const ll maxn = 1e5 + 7, oo = 1e18, mod = 1e9 + 7;
ll n, a[maxn], b[maxn];
bool isSub1()
{
    rep (i, 1, n)
        if (a[i] != b[i])
            return false;
    return true;
}
bool isSub2()
{
    rep (i, 1, n)
    {
        if (i != a[i])
            return false;
        if (n - i + 1 != b[i])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n;
    rep (i, 1, n)
        cin >> a[i];
    rep (i, 1, n)
        cin >> b[i];
    if (isSub1())
    {
        int res = 0;
        rep (i, 1, n)
        {
            // tim so i
            int p = 0;
            rep (j, 1, n)
            {
                if (a[j] == i)
                    p = j;
            }
            for (int j = p; j > i; --j)
            {
                swap(a[j], a[j - 1]);
                ++res;
            }
        }
        cout << res;
        exit(0);
    }
    if (isSub2())
    {
        if (n == 2)
        {
            cout << -1;
            return 0;
        }
        ll tmp = 9;
        ll res = 9;
        rep (i, 4, n)
        {
            tmp += 6;
            if (tmp > mod)
                tmp -= mod;
            res += tmp;
            res %= mod;
        }
        cout << res;
    }
}
