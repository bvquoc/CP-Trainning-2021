#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long n, a[200005], b[200005];
long long fac[200005], c[2005][2005];

struct ssuubb1
{
    long f[200005];

    void update(long i)
    {
        for (; i >= 1; i -= i & (-i)) f[i]++;
    }
    long get(long i)
    {
        long r = 0;
        for (; i <= n; i += i & (-i)) r += f[i];
        return r;
    }
    void solve()
    {
        fill(f, f + n + 1, 0);
        long res = 0;
        for (long i = 1; i <= n; i++)
        {
            res = (res + get(a[i] + 1)) % MOD;
            update(a[i]);
        }
        cout << res;
    }
};

void pre()
{
    fac[0] = 1;
    for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
    c[0][0] = 1;
    for (long i = 1; i <= n; i++)
    {
        c[0][i] = 1;
        for (long j = 1; j <= i; j++)
        {
            c[j][i] = (c[j][i - 1] + c[j - 1][i - 1]) % MOD;
        }
    }

}

void sub2()
{
    pre();
    long long res = 0;
    for (long i = 1; i <= n; i++)
    {
        for (long x = 1; x <= n - i; x++)
        {
            for (long y = 0; y <= i - 1; y++)
            {
                long long tmp = (c[x][n - i] * c[y][i - 1]) % MOD;
                tmp = (tmp * fac[x + y]) % MOD;
                tmp = (tmp * fac[n - x - y - 1]) % MOD;
                res += (tmp * x) % MOD;
                res %= MOD;
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    cin >> n;
    bool ssub1 = true;
    for (long i = 1; i <= n; i++) cin >> a[i];
    for (long i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i] != b[i]) ssub1 = false;
    }
    if (ssub1)
    {
        ssuubb1 sub1;
        sub1.solve();
        return 0;
    }
    sub2();
    return 0;
}
