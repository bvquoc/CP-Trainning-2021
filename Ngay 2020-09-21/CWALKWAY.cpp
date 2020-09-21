#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'

using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000006;
const ll INF = 1e15;

int n, c, a[N];
ll dp[N];
int k;
ll p[N], q[N];
double x[N];

bool ok (int i) {
    ll P = -2LL*a[i+1];
    ll Q = dp[i] + 1LL*a[i+1]*a[i+1];
    double xm = (double(Q)-q[k]) / (p[k]-P);
    double xn = (double(Q)-q[k-1]) / (p[k-1]-P);
    return (xn<xm);
}

signed main() {
    FastIO;
    freopen("CWALKWAY.INP", "r", stdin);
    freopen("CWALKWAY.OUT", "w", stdout);
    cin >> n >> c;
    a[0] = 0;
    FOR(i,1,n) cin >> a[i];

    dp[0] = 0;
    k = 0, x[0] = -INF, p[0] = -2LL*a[1], q[0] = dp[0] + 1LL*a[1]*a[1];
    int u = 0;
    FOR(i,1,n) {
        while (u<=k && x[u]<=a[i]) ++u;
        --u;
        dp[i] = 1LL*a[i]*a[i] + c + q[u] + 1ll*p[u]*a[i];
        while (k>0 && !ok(i)) --k;
        p[++k] = -2LL*a[i+1], q[k] = dp[i] + 1LL*a[i+1]*a[i+1];
        x[k] = 1.0*(q[k]-q[k-1]) / (p[k-1]-p[k]);
    }
    cout << dp[n];
    return 0;
}
