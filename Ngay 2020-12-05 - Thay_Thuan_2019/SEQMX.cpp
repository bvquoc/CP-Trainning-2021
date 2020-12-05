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

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-8;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-8;
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
const double epsilon = 1e-8;

int n, k;
double a[N];
double b[N], f[N];
double psum[N];

bool check(double d) {
    double res=INT_MIN;
    FOR(i,1,n) b[i] = (double) a[i] - d;
    FOR(i,1,n) {
        psum[i] = psum[i-1] + b[i];
        f[i] = max(f[i-1] + b[i], b[i]);
    }
    FOR(i,k,n) {
        maximize(res, max(0.0,f[i-k]) + psum[i] - psum[i-k]);
        if(res>=0) return true;
    }
    return false;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("SEQMX.INP","r",stdin);
    freopen("SEQMX.OUT","w",stdout);
    #endif
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];

    double res = -1e5;
    double lo = -1e5, hi = 1e5;
    while (hi - lo >= epsilon) {
        double mi = double(lo+hi) / 2;
        if(check(mi)) {
            res = mi;
            lo = mi + epsilon;
        } else hi = mi - epsilon;
    }

    cout << fixed << setprecision(5) << res;

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(psum).";
    return 0;
}