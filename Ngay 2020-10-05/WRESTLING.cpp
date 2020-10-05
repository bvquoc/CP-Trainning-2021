#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

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

const int N = 500005;
int n, a[N], pos[N];
int d[N];

signed main(void) {
    FastIO;
    freopen("WRESTLING.INP","r",stdin);
    freopen("WRESTLING.OUT","w",stdout);
    Read(n);
    FOR(i,1,n) Read(a[i]);
    FOR(i,1,n) {
        int x; Read(x);
        pos[x] = i;
    }
    FOR(i,1,n) {
        int u = pos[a[i]] - i;
        if (u < 0) u += n; d[u] ++;
    }
    int res = 0, cnt;
    FOR(i,0,n-1) {
        if (res < d[i]) {
            res = d[i];
            cnt = i;
        }
    }
    Write(cnt); putchar(' '); Write(res);
    return 0;
}