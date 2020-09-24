#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'

using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = pair<ii, ll>;

const int N = 1000005;
const ll INF = 1e18;

int n, k;
iii a[N];
ll dp[N], p[N], q[N];
ld x[N];

bool ok (int i) {
    ll P = a[i].fi.fi;
    ll Q = dp[i];
    ld xm = (ld) (Q - q[k]) / (p[k] - P);
    ld xn = (ld) (Q - q[k - 1]) / (p[k - 1] - P);
    return (xn < xm);
}

int main() {
    FastIO;
    freopen ("SREC.INP", "r", stdin);
    freopen ("SREC.OUT", "w", stdout);

    Read(n);
    FOR(i,1,n) {
        int u, v; ll w;
        Read(u); Read(v); Read(w);
        a[i] = {{u, v}, w};
    }

    sort (a + 1, a + n + 1);
    dp[0] = 0;
    k = 0;
    x[0] = -INF, p[0] = a[0].fi.fi, q[0] = dp[0];
    int u = 0;
    FOR(i,1,n) {
        while (u <= k && x[u] <= -a[i].fi.se)
            ++u;
        --u;
        dp[i] = 1ll * a[i].fi.fi * a[i].fi.se - a[i].se + q[u] + p[u] * (-a[i].fi.se);
        while (k > 0 && !ok (i))
            --k;
        p[++k] = a[i].fi.fi, q[k] = dp[i];
        x[k] = (ld) (q[k] - q[k - 1]) / (p[k - 1] - p[k]);
    }
    ll res = *max_element(dp+1,dp+1+n);
    Write(res);
}