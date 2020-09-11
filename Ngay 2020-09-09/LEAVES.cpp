#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

signed main(void) {
    FastIO;
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);

    return 0;
}


#include <bits/stdc++.h>
#define maxn 100005
#define maxm 15
#define oo 1.0e15

using namespace std;

int n, m, a[maxn];
int s[maxn];
int64_t t[maxn];
int64_t dp[maxm][maxn];
double x[maxn];
int64_t p[maxn], q[maxn];
int k;

bool ok (int i, int j) {
    int64_t P = -j;
    int64_t Q = dp[i - 1][j - 1] + t[j - 1];
    double xm = 1.0 * (Q - q[k]) / (p[k] - P);
    double xn = 1.0 * (Q - q[k - 1]) / (p[k - 1] - P);
    return (xn < xm);
}

int main() {
    freopen("LEAVES.inp","r",stdin);
    freopen("LEAVES.out","w",stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf ("%d", &a[i]);

    // Tinh cac mang tong tien to
    s[0] = 0;
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    t[0] = 0;
    for (int i = 1; i <= n; ++i)
        t[i] = t[i - 1] + s[i];

    // Dynamic convex
    for (int j = 1; j <= n; ++j)
        dp[1][j] = 1LL * (j - 1) * s[j] - t[j - 1];
    for (int i = 2; i <= m; ++i) {
        dp[i][i] = 0;
        x[0] = -oo;
        k = 0;
        p[0] = -i;
        q[0] = dp[i - 1][i - 1] + t[i - 1];
        int u = 0;
        for (int j = i + 1; j <= n; ++j) {
            while (u <= k && x[u] <= s[j])
                ++u;
            --u;
            dp[i][j] = 1LL * j * s[j] - t[j - 1] + q[u] + p[u] * s[j];
            while (k > 0 && !ok (i, j))
                --k;
            p[++k] = -j;
            q[k] = dp[i - 1][j - 1] + t[j - 1];
            x[k] = 1.0 * (q[k] - q[k - 1]) / (p[k - 1] - p[k]);
        }
    }
    printf ("%I64d", dp[m][n]);
}