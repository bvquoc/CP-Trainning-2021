#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}
typedef long long ll;
const int N = 2011,
          mod = 1e9 + 7;
int n, m;
int a[N], dp[N][N];
ll f[N], g[N];
int main() {
    freopen("Mine.inp", "r", stdin);
    freopen("Mine.out", "w", stdout);
    read(n); read(m);
    int nn = 2 * n;
    for (int i = 1; i <= nn; i++)
        read(a[i]);
    g[0] = dp[0][0] = 1;
    for (int i = 1; i <= nn; i++) {
        for (int j = 0; j <= n; j++) {
            if (j > 0)
                dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= mod;
        }
        g[i] = dp[i][0];
    }
    f[0] = 1;
    for (int i = 2; i <= nn; i += 2) {
        for (int j = i - 1; j > 0; j -= 2)
            if (a[i] - a[j] <= m)
                f[i] += f[j - 1] * g[i - j - 1] % mod;
        f[i] %= mod;
    }
    cout << f[nn];
}
