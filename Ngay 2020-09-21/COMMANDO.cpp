#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
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


signed main() {
    FastIO;
    freopen ("COMMANDO.INP", "r", stdin);
    freopen ("COMMANDO.OUT", "w", stdout);
    Read(n); Read(a); Read(b); Read(c);
    FOR(i,1,n) Read(s[i]);
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
    Write(dp[n]);
    return 0;
}