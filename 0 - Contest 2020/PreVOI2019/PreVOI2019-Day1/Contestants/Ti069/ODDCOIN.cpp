// He always smiles :)
#include <bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "ODDCOIN"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"

using namespace std;

ll coin[50] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
ll q;
ll x, t, ans;
ll pt(ll p)
{
    ll ans(0);
    for (int i = 15 ; i ; i --)
        if(p >= coin[i])
    {
        ll n = p / coin[i];
        ans += n;
        p -= n * coin[i];
    }
    return ans;
}
ll ptx(ll p)
{
    ll ans(0);
    for (int i = 15 ; i ; i --)
        if(p >= coin[i] && coin[i - 1] >= x)
    {
        ll n = p / coin[i];
        ans += n;
        p -= n * coin[i];
    }
    ll n = p / x;
    ans += n;
    p -= n * x;
    for (int i = 15 ; i ; i --)
        if(p >= coin[i])
    {
        ll n = p / coin[i];
        ans += n;
        p -= n * coin[i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> q;

    while(q--)
    {
        cin >> x >> t;
        ll n = t / x;
        ans = pt(t - n * x) + n;
        for (int i = 15 ; i ; i --)
            if(t >= coin[i])
            {
                n = t / coin[i];
                ans = min(ans, pt(t - n * coin[i]) + n);
                ans = min(ans, ptx(t - n * coin[i]) + n);
            }
        cout << ans << endl;;
    }
    return 0;
}
