#include <bits/stdc++.h>

#define name "MINE."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
const ll N = 2e5 + 7;
const ll mod = 1e6 + 3;

int n, t, sub, ma;
int a[N << 1];

void inp()
{
    cin >> n >> t;
    fu(i, 1, 2 * n) cin >> a[i], ma = max (ma, a[i]);
    if (n <= 10) sub = 1;
    else if (ma <= t)
        sub = 2;
}
struct sub1
{
    int x[50];
    ll res;

    void update()
    {
        int cnt = accumulate (x + 1, x + n + 1, 0);
        if (cnt != n / 2) return;

        vector <int> v(0);
        v.pb(1);
        fu(i, 2, n)
        {
            if (v.size() && a[i] - a[v[0]] > t)
                return;
            if (!x[i])
            {
                if (!v.size()) return;
                else v.pop_back();
            }
            else v.pb(i);
        }
        ++res;
    }
    void Try(int i)
    {
        x[i] = 0;
        if (i == n - 1) update();
        else Try(i + 1);

        x[i] = 1;
        if (i == n - 1) update();
        else Try(i + 1);
    }
    void solve()
    {
        n <<= 1;
        x[1] = 1; x[n] = 0;
        res = 0;
        Try(2);
        cout << res;
    }
} sub1;
struct sub2
{
    ll f[5000][5000];

    ll calc(int i, int c)
    {
        auto &res = f[i][c];
        if (res != -1) return res;
        if (i == n) return res = (!c);

        res = 0;

        if (c > 0) res = calc(i + 1, c - 1);
        if (c < n / 2) res = (res + calc(i + 1, c + 1)) % mod;
        return res %= mod;
    }
    void solve()
    {
        n <<= 1;
        fu(i, 0, n)
            fu(j, 0, n * 2)
                f[i][j] = -1;
        cout << calc(0, 0);
    }
} sub2;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);

    inp();
    if (sub == 1) sub1.solve();
    else if (sub == 2) sub2.solve();

    return 0;
}
