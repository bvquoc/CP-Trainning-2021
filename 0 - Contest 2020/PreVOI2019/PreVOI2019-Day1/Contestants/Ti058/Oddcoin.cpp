#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int q, x, t, a[20], f[N];

void solve()
{
    scanf("%d %d", &x, &t);

    a[16] = x;

    f[0] = 0;

    for(int i =1; i <= t; ++i)
    {
        f[i] = 2e9;
        for(int j = 1; j <= 16; ++j)
        if(a[j] <= i) f[i] = min(f[i], f[i - a[j]] + 1);
    }

    printf("%d\n", f[t]);
}
int main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);

    a[1] = 1, a[2] = 3, a[3] = 5, a[4] = 10,

    a[5] = 30, a[6] = 50, a[7] = 100, a[8] = 300,

    a[9] = 500, a[10] = 1000, a[11] = 3000, a[12] = 5000,

    a[13] = 10000, a[14] = 30000, a[15] = 50000;

    scanf("%d", &q);

    for(int i = 1; i <= q; ++i)
    {
        solve();
    }
}
