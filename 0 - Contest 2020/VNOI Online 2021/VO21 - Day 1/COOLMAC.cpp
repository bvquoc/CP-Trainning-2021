/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define L first
#define R second
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
const int N = 1000005, INF = 2e9, LIM = 100001;
struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree() {}
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, INF);
    }
    void assign (int n) {
        this->n = n;
        bit.assign(n+1, INF);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) update(i, a[i]);
    }

    int getMin(int r) {
        int res = INF;
        for (; r >= 1; r = (r & (r + 1)) - 1) minimize(res, bit[r]);
        return res;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx |= (idx + 1)) 
            bit[idx] = min(bit[idx], val);
    }
} BIT;

int m, n;
ii a[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    #endif
    
    Read(m);
    FOR(i,1,m) {
        Read(a[i].L), Read(a[i].R);
        a[i].L++; a[i].R++;
    }

    sort(a + 1, a + 1 + m, greater <ii>());

    BIT.assign(LIM);
    FOR(i,1,m) {
        int ans = N;
        if (a[i].R == LIM) ans = 1;
        else minimize(ans, BIT.getMin(a[i].R)+1);
        BIT.update(a[i].L, ans);
    }

    int minT = INF;
    Read(n);
    FOR(i,1,n) {
        int x; Read(x); x++;
        minimize(minT, x);
    }

    int res = BIT.getMin(minT);
    if (res > LIM) res = -1;
    Write(res);
    exit(0);

    return 0;
}