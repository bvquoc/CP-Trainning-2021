#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;

long long test, n, k, f[105], sz, g[85][85], a[85];

void solve()
{
    cin >> n >> k;
    for (long i = sz; i >= 1; i--)
    {
        if (n >= f[i])
        {
            n -= f[i];
            a[i] = 1;
        }
        else a[i] = 0;
    }
    long long res = 0, cnt = 0;
    //cout << g[4][2] << '\n';
    for (long i = sz; i >= 1; i--)
    {
        if (a[i] == 0) continue;
        for (long j = max((long long)0, k - cnt); j <= i - 1; j++)
        {
            res += g[i - 1][j] * (j + cnt);
        }
        cnt++;
    }

    if (cnt >= k) res += cnt;
    cout << res << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    f[1] = 1;
    f[2] = 2;
    sz = 2;
    while (f[sz] <= 1e15)
    {
        sz++;
        f[sz] = f[sz - 1] + f[sz - 2];
    }
    //g[0][1] = 1;
    g[0][0] = 1;
    g[1][0] = 1;
    g[1][1] = 1;
    g[2][0] = 1;
    g[2][1] = 2;
    g[2][2] = 0;
    for (long i = 3; i <= sz; i++)
    {
        for (long j = 0; j <= i; j++)
        {
            g[i][j] = g[i - 1][j];
            if (j > 0) g[i][j] += g[i - 2][j - 1];
        }
    }
    cin >> test;
    while (test--) solve();
    return 0;
}
