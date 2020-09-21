#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'

using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000006;
const ll INF = 1e18;

int n, a, b, c;
int s[N];
ll dp[N], p[N], q[N];
int k;
ld x[N];

bool ok (int i) {
    ll P = -2LL*a*s[i];
    ll Q = dp[i] + 1LL*a*s[i]*s[i] - 1LL*b*s[i];
    ld xm = (ld) (Q-q[k]) / (p[k]-P);
    ld xn = (ld) (Q-q[k-1]) / (p[k-1]-P);
    return (xn<xm);
}


int main() {
    freopen ("COMMANDO.INP", "r", stdin);
    freopen ("COMMANDO.OUT", "w", stdout);
    cin >> n >> a >> b >> c;
    FOR(i,1,n) cin >> s[i];
    s[0] = 0;
    FOR(i,1,n) s[i] += s[i-1];

    dp[0] = 0;
    k = 0, x[0] = -INF, p[0] = 0;
    q[1] = 0;
    int u = 0;
    FOR(i,1,n) {
        while (u<=k && x[u] <= s[i]) ++u;
        --u;
        dp[i] = 1LL*a*s[i]*s[i] + 1LL*b*s[i] + c + q[u] + 1LL*p[u]*s[i];
        while (k>0 && !ok(i))
            --k;
        p[++k] = -2LL*a*s[i];
        q[k] = dp[i] + 1LL*a*s[i]*s[i] - 1LL*b*s[i];
        x[k] = (ld) (q[k]-q[k-1]) / (p[k-1]-p[k]);
    }
    cout << dp[n];
}