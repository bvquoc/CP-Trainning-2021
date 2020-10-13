#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
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
inline bool minimize(T &x, T y) {
    if (x > y) { x = y; return true; }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005, INF = 1e18;
int n, a[N], b[N];
int res = INF;

signed main(void) {
    FastIO;
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    Read(n);
    FOR(i,1,n) Read(a[i]);
    FOR(i,1,n) Read(b[i]);
    sort(b+1, b+1+n);
    for (int i=1;i<=n;i++) {
        int k = lower_bound(b+1, b+1+n, a[i]) - b;
        if (k <= n) minimize(res, abs(b[k]+a[i]));
        if (k>1) minimize(res, abs(b[k-1]+a[i]));
        k = lower_bound(b+1,b+1+n, -a[i]) - b;
        if (k<=n) minimize(res, abs(b[k]+a[i]));
        if (k>1) minimize(res, abs(b[k-1]+a[i]));
    }
    printf("%lld", res);
    return 0;
}