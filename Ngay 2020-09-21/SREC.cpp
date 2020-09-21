#include <bits/stdc++.h>
#define maxn 1000005
#define ft first
#define sc second
#define oo 1.0e18

using namespace std;
typedef pair<int, int> II;
typedef pair<II, int64_t> III;

int n;
III a[maxn];
int64_t dp[maxn];
int k;
int64_t p[maxn], q[maxn];
long double x[maxn];

bool ok (int i) {
    int64_t P = a[i].ft.ft;
    int64_t Q = dp[i];
    long double xm = (long double) (Q - q[k]) / (p[k] - P);
    long double xn = (long double) (Q - q[k - 1]) / (p[k - 1] - P);
    return (xn < xm);
}

int main() {
    freopen("SREC.INP", "r", stdin);
    freopen("SREC.OUT", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        int64_t w;
        scanf ("%d %d %I64d", &u, &v, &w);
        a[i] = {{u, v}, w};
    }
    sort (a + 1, a + n + 1);
    dp[0] = 0;
    k = 0;
    x[0] = -oo, p[0] = a[0].ft.ft, q[0] = dp[0];
    int u = 0;
    for (int i = 1; i <= n; ++i) {
        while (u <= k && x[u] <= -a[i].ft.sc)
            ++u;
        --u;
        dp[i] = 1ll * a[i].ft.ft * a[i].ft.sc - a[i].sc + q[u] + p[u] * (-a[i].ft.sc);
        while (k > 0 && !ok (i))
            --k;
        p[++k] = a[i].ft.ft, q[k] = dp[i];
        x[k] = (long double) (q[k] - q[k - 1]) / (p[k - 1] - p[k]);
    }
    int64_t res = dp[1];
    for (int i = 2; i <= n; ++i)
        res = max (res, dp[i]);
    printf ("%I64d", res);
}
