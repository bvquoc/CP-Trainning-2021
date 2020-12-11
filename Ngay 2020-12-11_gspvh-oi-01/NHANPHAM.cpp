/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
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

const int N = 100005, INF = 2e18 + 7;
int n, k, a[N], psum[N];

int calc(const int &n) {
    if (n & 1) return ((n + 1) >> 1) * n;
    return (n >> 1) * (n + 1);
}
int cost(const int &d) {
    if (d <= n) return psum[d-1];
    int x = psum[n-1] * (d / n);
    if (d % n) return x + psum[(d % n) - 1];
    return x;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("NHANPHAM.INP","r",stdin);
    freopen("NHANPHAM.OUT","w",stdout);
    #endif
    Read(n); Read(k);
    REP(i,n) Read(a[i]);

    #define subtask_1 (n == 1 && k == 0)
    #define subtask_2 (n == 1)
    #define subtask_3 (*max_element(a, a + n) <= 1000000)

    if (subtask_1) {
        ll res = a[0] * 2LL - 1;
        Write(res);
        exit(0);
    }

    if (subtask_2) {
        ll x = a[0] * 2LL - 1;
        int res = -1;
        int lo = x + 1, hi = 3e9, mi;
        while (lo <= hi) {
            mi = lo + ((hi - lo) >> 1);
            if (calc(mi) - 1LL * mi * a[0] >= k) {
                res = mi;
                hi = mi - 1;
            } else lo = mi + 1;
        }
        Write(res);
        exit(0);
    }

    psum[0] = a[0];
    FOR(i,1,n-1) psum[i] = a[i] + psum[i-1];

    int res = -1;
    int lo = 1, hi = 3e9, mi;
    while (lo <= hi) {
        mi = lo + ((hi - lo) >> 1);
        if (calc(mi) - cost(mi) >= k) {
            res = mi;
            hi = mi - 1;
        } else lo = mi + 1;
    }

    Write(res);
    return 0;
}