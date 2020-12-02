/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int MAX = 100005;
int n, m, M, d[MAX];
vector <ii> E(1);

int getPos(int d, int i) {
    if (i == 1) return d;
    if (::d[i-1] <= d) return getPos(d + 1, i-1);
    return getPos(d, i - 1);
}

ii findComp(int pos) {
    int lo, hi, mi, u, v;

    lo = 1; hi = n - 1;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        int k = n - mi;
        k = k * (k + 1) / 2;
        k = M - k;
        if (k < pos) {
            u = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    lo = u+1; hi = n;
    int k = (n - u); k = M - (k * (k + 1) / 2);
    while (lo <= hi) {
        mi = (lo + hi) / 2;
        if (mi - u + k == pos) {
            v = mi;
            break;
        }
        if (mi - u + k < pos) lo = mi + 1;
        else hi = mi - 1;
    }
    
    return ii(u, v);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("GENTEST.INP","r",stdin);
    freopen("GENTEST.OUT","w",stdout);
    #endif
    Read(n); Read(m); M = n * (n - 1) / 2;
    FOR(i,1,m) Read(d[i]);

    FOR(i,1,m) {
        int k = getPos(d[i], i);
        ii p = findComp(k);
        Write(p.first); putchar(' ');
        Write(p.second); putchar(endl);
    }
    
    return 0;
}