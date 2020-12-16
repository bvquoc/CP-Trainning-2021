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

const int N = 1000005, INF = 2e9, LIM = 100000;
int m, n, a[N];
struct Clo { 
    int L, R; 
    bool operator< (const Clo &B) {
        return L < B.L || (L == B.L && R > B.R);
    }
} b[N];
int res = INF;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    #endif
    
    Read(m);
    FOR(i,1,m) Read(b[i].L), Read(b[i].R);
    Read(n);
    FOR(i,1,n) Read(a[i]);

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    #define subtask_1 (n <= 10 && m <= 16)

    // if (subtask_1) {
    //     vector <int> d;
    //     REP(mask, MASK(m)) {
    //         d.clear();
    //         REP(i, m) if (BIT(mask, i)) d.emplace_back(i+1);
    //         int L = a[1];
    //         for(int i: d) {
    //             if (b[i].L <= L && L <= b[i].R) {
    //                 L = b[i].R;
    //             }
    //         }

    //         if (L >= LIM) minimize(res, d.size());
    //     }

    //     if (res == INF) res = -1;
    //     Write(res);
    //     exit(0);
    // }

    int mx_R = INT_MIN, mn_L = b[1].L;
    FOR(i, 1, m) maximize(mx_R, b[i].R);

    if (mx_R < LIM || mn_L > a[1]) {
        putchar('-');
        putchar('1');
        exit(0);
    }

    vector <int> d;
    REP(mask, MASK(m)) {
        d.clear();
        REP(i, m) if (BIT(mask, i)) d.emplace_back(i+1);
        int L = a[1];
        for(int i: d) {
            if (b[i].L <= L && L <= b[i].R) {
                L = b[i].R;
            }
        }

        if (L >= LIM) minimize(res, d.size());
    }

    if (res == INF) res = -1;
    Write(res);
    exit(0);

    return 0;
}