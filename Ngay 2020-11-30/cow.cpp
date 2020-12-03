/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define FORD(i, a, b) for(int i=(a); i>=(b); --i)
#define REP(i, n) for(int i=0, _n=(n); i<_n; ++i)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = (x << 3) + (x << 1) + (c - '0');
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

/*
(\_/)
( •_•)
/ >?? */

const int N = 100005;
int n, c, a[N];
int res;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("cow.inp","r",stdin);
    freopen("cow.out","w",stdout);
    #endif

    int T; Read(T);
    while (T--) {
        Read(n); Read(c);
        FOR(i,1,n) Read(a[i]);
        sort(a + 1, a + 1 + n);
        res = 0;
        int lo = 0, hi = 1000000000, mi;
        int m, k;
        while (lo <= hi) {
            m = c;
            mi = (lo + hi) >> 1;
            for (int i = 1; i <= n; i++) {
                if (m == c) {
                    k = a[i];
                    m--;
                }
                if (!m) break;
                if (a[i] - k >= mi) {
                    k = a[i];
                    m--;
                }
            }
            if (!m) {
                res = mi;
                lo = mi + 1;
            } else hi = mi - 1;
        }
        Write(res);
        putchar(endl);
    }
    return 0;
}