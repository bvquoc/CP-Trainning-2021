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
} BIT;

// #define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("input.txt","r",stdin);
    #endif
    
    int n, q;
    cin >> n >> q;
    BIT.assign(n);

    FOR(i,1,n) {
        int x; cin >> x;
        BIT.update(i, x);
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << BIT.getSum(l, r) << endl;
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}