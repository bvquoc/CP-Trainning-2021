#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int maxn = 4e5 + 7, mod = 1e6 + 3;

int gt[maxn], inv[maxn], n, m, a[maxn], f[4007] = {}, cat[4007][4007] = {};

int pw(int cs, int sm)
{
    if (sm == 1) return cs;
    int hpw = pw(cs, sm / 2);
    hpw = (1LL*hpw*hpw) % mod;
    if (sm % 2) hpw = (1LL*hpw*cs) % mod;
    return hpw;
}

int get_c(int n, int k)
{
    if (k == 0) return 1;
    if (k > n) return 0;
    return (((1LL*gt[n]*inv[k]) % mod)*1LL*inv[n - k]) % mod;
}

int sum(int a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

void calc_cat()
{
    cat[0][0] = 1;
    for (int i = 1; i <= 4000; ++i)
    {
        cat[i][0] = cat[i - 1][1];
        for (int j = 1; j <= 4000; ++j) cat[i][j] = sum(cat[i - 1][j - 1], cat[i - 1][j + 1]);
    }
}

void calc_inv()
{
    gt[0] = 1;
    for (int i = 1; i < maxn; ++i) gt[i] = (1LL*gt[i - 1]*i) % mod, inv[i] = pw(gt[i], mod - 2);
}

void solve()
{
    if (n > 4000) calc_inv(), cout << (get_c(n, n / 2) + mod - get_c(n, n / 2 - 1)) % mod; else
    {
        calc_cat();
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = i - 1; j >= 1 && a[i] - a[j] <= m; --j)
                f[i] = sum(f[i], (1LL*f[j - 1]*cat[i - j - 1][0]) % mod);
        cout << f[n];
    }
}

void enter()
{
    freopen("MINE.INP","r",stdin);
    freopen("MINE.OUT","w",stdout);
    io;
    cin >> n >> m, n *= 2;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

int main()
{
    enter();
    solve();
}
