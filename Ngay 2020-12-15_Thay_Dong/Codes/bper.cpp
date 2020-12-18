#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void madd(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void msub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
}

void mmul(int &x, int y) {
    x = ll(x) * y % MOD;
}

const int N = 105;

int f[N][11], g[N][11][N];

int main() {
    freopen("bper.inp", "r", stdin);
    freopen("bper.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n <= 9) {
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = n / 2 - 1; j >= 0; j--)
                for (int k = 0; k < 11; k++)
                    madd(f[j + 1][(i + k) % 11], f[j][k]);
        int s = (n * (n + 1) / 2) % 11, res = 0;
        for (int k = 0; k < 11; k++)
            if ((s - k + 11) % 11 == k)
                madd(res, f[n / 2][k]);

        for (int i = 1; i <= n / 2; i++)
            mmul(res, i);
        for (int i = 1; i <= (n + 1) / 2; i++)
            mmul(res, i);
        cout << res << '\n'; return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= 9; i++)
        for (int j = 3; j >= 0; j--)
            for (int k = 0; k < 11; k++)
                madd(f[j + 1][(i + k) % 11], f[j][k]);
    int mul = 1;
    for (int i = 1; i <= 4; i++) mmul(mul, i);
    for (int i = 1; i <= 5; i++) mmul(mul, i);
    for (int k = 0; k < 11; k++) {
        madd(g[9][(45 - k * 2) % 11][5],
        ll(f[4][k]) * mul % MOD);
    }
    for (int i = 10; i <= n; i++)
        for (int k = 0; k < 11; k++)
            for (int l = 0; l <= n; l++) {
                madd(g[i][(k + i % 10
                - i / 10 + 11) % 11][l + 1],
                ll(g[i - 1][k][l]) * l % MOD);
                madd(g[i][(k - i % 10
                + i / 10 + 11) % 11][l],
                ll(g[i - 1][k][l]) * (i - l) % MOD);
            }
    int res = 0;
    for (int l = 0; l <= n; l++)
        madd(res, g[n][0][l]);
    cout << res << '\n';
}