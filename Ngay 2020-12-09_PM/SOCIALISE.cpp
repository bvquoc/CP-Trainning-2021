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

const int N = 302;
int n, a[N];
map <int, int> cnt;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("SOCIALISE.INP","r",stdin);
    freopen("SOCIALISE.OUT","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) a[i];
    // sort(a + 1, a + 1 + n);

    // int ans, LIM = a[n] + 1;
    // FOR(g,1,n) {
    //     ans = -1;
    //     int lo = 1, hi = LIM, mi;
    //     while (lo <= hi) {
    //         mi = lo + ((hi - lo) >> 1);
    //         cnt.clear();
    //         FOR(i,1,n) cnt[trunc(a[i] / mi)]++;
    //         bool ok = false;
    //         for (ii x: cnt) if (x.second == g) {
    //             ok = true;
    //             break;
    //         }
    //         if (ok) {
    //             ans = mi;
    //             hi = mi - 1;
    //         } else lo = mi + 1;
    //     }
    //     cout << ans << endl;
    // }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}