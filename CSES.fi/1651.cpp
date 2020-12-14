/* Author: Bui Vi Quoc */
// https://cses.fi/problemset/task/1651
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

const int INF = LLONG_MAX;
struct SegmentTree {
    int n;
    vector<int> st, lazy;
    
    void assign(int _n) {
        n = _n;
        st.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }
    SegmentTree(int _n = 0) { assign(_n); }
    
    void pushDown(int i) {
        for (int j = i << 1; j <= (i << 1) + 1; j++) {
            st[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            st[i] += c;
            lazy[i] += c;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(i << 1, l, m, u, v, c);
        update((i << 1) + 1, m + 1, r, u, v, c);

        st[i] = min(st[i << 1], st[(i << 1) + 1]);
    }

    int getMin(int i, int l, int r, int u, int v) {
        if (l > v || r < u || l > r || v < u) return INF;
        if (u <= l && r <= v) return st[i];
        pushDown(i);
        int m = (l + r) >> 1;
        int L = getMin(i << 1, l, m, u, v);
        int R = getMin((i << 1) + 1, m + 1, r, u, v);
        return min(L, R);
    }

	void update(int u, int v, int c) { update(1, 1, n, u, v, c); }
	int getMin(int u, int v) { return getMin(1, 1, n, u, v); }

} myST;

// #define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("input.txt","r",stdin);
    #endif
    
    int n, q;
    cin >> n >> q;
    myST.assign(n);

    FOR(i,1,n) {
        int x; cin >> x;
        myST.update(i, i, x);
    }
    
    int type, l, r, val;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> val;
            myST.update(l, r, val);
        } else {
            cin >> l;
            cout << myST.getMin(l, l) << endl;
        }
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}