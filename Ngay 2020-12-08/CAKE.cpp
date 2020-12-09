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
int n, T, res = 0;
struct Cake {
    int pos, time, id;
} a[N];

struct FenwickTree {
    int n; vector<int> v;
    void assign(int _n) {
        n = _n;
        v.assign(n + 7, 0);
    }
    FenwickTree(int _n = 0) { assign(_n); }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }
    int getSum(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
} sum, cnt;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
    #endif
    cin >> n >> T;
    FOR(i,1,n) cin >> a[i].pos >> a[i].time;

    /* compress */ {
        vector <ii> tmp;
        FOR(i,1,n) tmp.push_back(ii(a[i].time, i));
        sort(ALL(tmp));
        REP(i,n) a[tmp[i].second].id = i + 1;
    }

    sum.assign(n); cnt.assign(n);

    FOR(i,1,n) {
        int cur_time = T - a[i].pos;
        if (cur_time <= 0) break;
        cnt.update(a[i].id, 1);
        sum.update(a[i].id, a[i].time);
        int lo = 1, hi = n, mi, ans = 0;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            int cur_sum = sum.get(mi);
            if (cur_sum <= cur_time) {
                ans = mi;
                lo = mi + 1;
            } else hi = mi - 1;
        }
        if (ans) maximize(res, cnt.get(ans));
    }
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}