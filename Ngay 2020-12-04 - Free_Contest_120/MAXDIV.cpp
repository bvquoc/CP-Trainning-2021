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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 300005;
int n, k, a[N];
ll res = 0;
int cnt[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("MAXDIV.INP","r",stdin);
    freopen("MAXDIV.OUT","w",stdout);
    #endif
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        if (a[i] % k == 0) cnt[i] = 1;
    }
    FOR(i,2,n) cnt[i] += cnt[i-1];

    FOR(i,1,n) {
        int lo = i, hi = n, mi, p = -1;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            if (cnt[mi] <= cnt[i-1] + 1) {
                p = mi;
                lo = mi + 1;
            } else hi = mi - 1;
        }
        if (p == -1) continue;
        res += (p - i + 1);
    }

    cout << res;
    return 0;
}