#include <bits/stdc++.h>

using namespace std;

using ld = long double;

const int N = 1000006;
const long long INF = LLONG_MAX;
int n, a, b, c;
int s[N], k;
int64_t dp[N], p[N], q[N];
ld x[N];

bool ok (int i) {
    int64_t P = -2LL * a * s[i];
    int64_t Q = dp[i] + 1LL * a * s[i] * s[i] - 1LL * b * s[i];
    ld xm = ld(Q - q[k]) / (p[k] - P);
    ld xn = ld(Q - q[k - 1]) / (p[k - 1] - P);
    return (xn < xm);
}

int main() {
    freopen ("COMMANDO.INP", "r", stdin);
    freopen ("COMMANDO.OUT", "w", stdout);
    scanf ("%d", &n);

    scanf ("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= n; ++i)
        scanf ("%d", &s[i]);
    s[0] = 0;
    for (int i = 1; i <= n; ++i)
        s[i] += s[i - 1];
    //Convex dynamic
    dp[0] = 0;
    k = 0, x[0] = -INF, p[0] = 0;
    q[1] = 0;
    int u = 0;
    for (int i = 1; i <= n; ++i) {
        while (u <= k && x[u] <= s[i])
            ++u;
        --u;
        dp[i] = 1LL * a * s[i] * s[i] + 1LL * b * s[i] + c + q[u] + 1LL * p[u] * s[i];
        while (k > 0 && !ok (i))
            --k;
        p[++k] = -2LL * a * s[i];
        q[k] = dp[i] + 1LL * a * s[i] * s[i] - 1LL * b * s[i];
        x[k] = (ld) (q[k] - q[k - 1]) / (p[k - 1] - p[k]);
    }
    printf ("%ld\n", dp[n]);
}