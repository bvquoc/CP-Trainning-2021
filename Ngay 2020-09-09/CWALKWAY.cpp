#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const signed N = 1000006;
const int INF = LLONG_MAX;

int n, c, a[N];
int dp[N], k;
int p[N], q[N];
ld x[N];

bool check (int i) {
    ld P = -2*a[i+1], Q = dp[i] + a[i+1]*a[i+1];
    ld xm = (Q-q[k])/(p[k]-P);
    ld xn = (Q-q[k-1])/(p[k-1]-P);
    return (xn<xm);
}

signed main() {
    FastIO;
    freopen ("CWALKWAY.INP", "r", stdin);
    freopen ("CWALKWAY.OUT", "w", stdout);
    cin >> n >> c;
    FOR(i,1,n) cin >> a[i];

    k = 0, x[0] = -INF, p[0] = -2*a[1], q[0] = dp[0] + a[1]*a[1];
    int u = 0;
    FOR(i,1,n) {
        while (u <= k && x[u] <= a[i]) u++;
        u--;
        dp[i] = a[i]*a[i] + c + q[u] + p[u]*a[i];
        while (k>0 && !check (i)) k--;
        p[++k] = -2*a[i+1], q[k] = dp[i] + a[i+1]*a[i+1];
        x[k] = ld(q[k]-q[k-1])/(p[k-1]-p[k]);
    }

    cout << dp[n];
    return 0;
}