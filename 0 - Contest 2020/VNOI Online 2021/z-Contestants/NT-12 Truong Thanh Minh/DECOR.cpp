#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(ll i = (a); i <= (b); ++i)
#define req(i, a, b) for(ll i = (a); i >= (b); --i)
#define name "DECOR"
#define pb push_back
#define eb emplace_back
#define sz size()
#define ff first
#define ss second
typedef pair < ll, ll > ii;
const ll maxn = 5e5 + 7, oo = 1e18, mod = 1e9 + 7;
ll n, m, k, a[maxn], b[maxn], pref[maxn], res, resl, resr;
string s;
ll findpos(int l, int r, int v)
{
    int p = l;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (pref[m] >= v)
        {
            p = m;
            r = m - 1;
        }
        else l = m + 1;
    }
}
void sub12()
{
    rep (i, 1, n)
        if (s[i] == '0')
            pref[i] = pref[i - 1] + 1;
        else pref[i] = pref[i - 1];
    rep (i, 1, n)
    {
        int j = findpos(0, i, pref[i] - k);
        if (i - j > res)
        {
            res = i - j;
            resl = j + 1;
            resr = i;
        }
    }
    if (resl == resr && resr == 0)
    {
        cout << -1;
        exit(0);
    }
    cout << resl << " " << resr;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n >> m >> k >> s;
    s = " " + s;
    rep (i, 1, m)
        cin >> a[i] >> b[i];
    if (m == 0)
        sub12();
    cout << -1;
}
