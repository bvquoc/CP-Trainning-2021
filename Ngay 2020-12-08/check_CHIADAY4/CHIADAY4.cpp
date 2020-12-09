/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
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
        x = (x << 3) + (x << 1) + (c - '0');
    if (Neg) x = -x;
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
int n, a[N], res = LLONG_MIN;
int psum[N], f[N], g[N];

int Sum(const int &l, const int &r) {
    return psum[r-1] - psum[l-1];
}

signed main(int argc, char *argv[]) {
	if (argc >= 3) {
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}

    Read(n);
    FOR(i,1,n) {
        Read(a[i]);
        psum[i] = a[i] + psum[i-1];
    }


    FOR(i,1,n+1) f[i] = LLONG_MIN;
    FOR(x1, 1, n+1) FOR(x2, x1, n+1) maximize(f[x2], Sum(1, x1) - Sum(x1, x2));
    
    FOR(x2, 1, n+1) {
        g[x2] = LLONG_MIN;
        FOR(x3, x2, n+1) maximize(g[x2], Sum(x2, x3) - Sum(x3, n+1));
    }

    FOR(i,1,n+1) maximize(res, f[i] + g[i]);

    cout << res;

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}