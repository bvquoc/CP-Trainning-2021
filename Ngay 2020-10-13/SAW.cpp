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
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

template <typename T>
inline bool maximize(T &x, T y) {
    if (x < y) { x = y; return true; }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, T, m, h[N];
int psum[N], res;

bool check(int d) {
    int l = 1, r = n, mi, p = -1;
    while (l<=r) {
        mi = l + (r-l)/2;
        if (h[mi] >= d) {
            r = mi-1;
            p = mi;
        } else l = mi+1;
    }
    if (p == -1) return false;
    return psum[n]-psum[p-1] >= m + (n-p+1)*d;
}

signed main(void) {
    FastIO;
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    Read(n); Read(T);
    FOR(i,1,n) Read(h[i]);
    sort(h+1,h+1+n);
    FOR(i,1,n) psum[i] = psum[i-1] + h[i];
    while (T--) {
        Read(m);
        int lo = 0, hi = h[n], mi;
        res = 0;
        while (lo <= hi) {
            mi = lo + (hi-lo)/2;
            if (check(mi)) {
                lo = mi+1;
                maximize(res, mi);
            } else hi = mi - 1;
        }
        Write(res); putchar(' ');
    }
    return 0;
}