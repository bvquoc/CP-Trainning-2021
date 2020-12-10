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

const int N = 100005;
int n, T, h[N];
int a[N], psum[N];

bool check(int min_high) {
    FOR(i,1,n) a[i] = h[i];

    int T = ::T;
    FOR(i,1,n) {
        T -= (a[i] - min_high);
        a[i] = min_high;
        if (T < 0) continue;
        if (T == 0) {
            bool ok = true;
            FOR(j,1,n-1) if (Abs(a[j] - a[j+1]) > 1) {
                ok = false;
                break;
            }
            if (ok) return true;
            continue;
        }
    }
    return false;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DIGGING.INP","r",stdin);
    freopen("DIGGING.OUT","w",stdout);
    #endif
    Read(n); Read(T);
    FOR(i,1,n) {
        Read(h[i]);
        psum[i] = h[i] + psum[i-1];
    }

    const int L = *min_element(h + 1, h + 1 + n) - T, R = *max_element(h + 1, h + 1 + n);
    
    int res = *min_element(h + 1, h + 1 + n);
    int lo = L, hi = R, mi;

    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (check(mi)) {
            res = mi;
            hi = mi - 1;
        } else lo = mi + 1;
    }

    Write(res);
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}