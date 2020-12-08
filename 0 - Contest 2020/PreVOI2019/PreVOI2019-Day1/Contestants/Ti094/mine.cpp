#include <iostream>
#include <fstream>
#define MOD 1000003
#define N 4002

using namespace std;

int n, m, f[N][N], a[N], d[N][N];

void mod(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("mine.inp", "r", stdin);
	freopen("mine.out", "w", stdout);
    cin >> n >> m;
    int i, j, k; n *= 2;
    for (i = 1; i <= n; ++i) cin >> a[i];
    for (i = 1; i <= n; ++i) f[i + 1][i] = d[i + 1][i] = 1;
    for (i = n - 1; i; --i)
    {
        for (j = i + 1; j <= n && a[i] + m >= a[j]; j += 2)
            mod(f[i][j], d[i + 1][j - 1]);
        for (j = i + 1; j <= n; j += 2)
            for (k = i + 1; k <= n; k += 2)
                mod(d[i][j], (1ll * f[i][k] * d[k + 1][j]) % MOD);
    }
    int re = 0;
    for (i = 2; i <= n; i += 2)
        mod(re, (1ll * f[1][i] * d[i + 1][n]) % MOD);
    cout << re;
	return 0;
}
