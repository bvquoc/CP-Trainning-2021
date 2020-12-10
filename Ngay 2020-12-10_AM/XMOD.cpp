/* Author: Bui Vi Quoc */
// http://csloj.ddns.net/problem/1362
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
// #define int long long
using namespace std;

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
int n, m, a[N], b[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("XMOD.INP","r",stdin);
    freopen("XMOD.OUT","w",stdout);
    #endif
    cin >> n >> m;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> b[i];

    /* compress */ {
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - a - 1;
    }

    #define subtask_1 (n <= 1000 && m <= 1000)

    FOR(i,1,m) {
        int mn = INT_MAX, mx = INT_MIN;
        FOR(j,1,n) {
            minimize(mn, b[i] % a[j]);
            maximize(mx, b[i] % a[j]);
        }
        cout << mn << ' ' << mx << endl;
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}