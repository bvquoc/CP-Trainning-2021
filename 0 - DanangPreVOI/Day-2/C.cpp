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

#define LIM 9999 // 82000001
#define MOD 1073741824

int a, b, c, d[3];
ll res = 0;

int prmDiv[LIM + 1];
map <int,int> cnt;

void factorize(int x) {
    while (x > 1) {
        int p = prmDiv[x];
        // if (p == 0) return;
        cnt[p]++;
        x /= p;
    }
}

int calc() {
    cnt.clear();
    int ans = 1;
    REP(i,3) factorize(d[i]);
    for (ii x: cnt) {
        ans *= (x.second + 1) % MOD;
        ans %= MOD;
    }
    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("C.INP","r",stdin);
    freopen("C.OUT","w",stdout);
    #endif
    
    /* sieve */ {
        FOR(i, 2, LIM-1) if (!prmDiv[i]) {
            prmDiv[i] = i;
            for (int j = i*i; j < LIM; j += i) if (!prmDiv[j]) prmDiv[j] = i;
        }
    }

    Read(a); Read(b); Read(c);

    FOR(x, 1, a) FOR(y, 1, b) FOR(z, 1, c) {
        d[0] = x; d[1] = y; d[2] = z;
        res += calc();
    }

    Write(res);
    return 0;
}