/* Author: Bui Vi Quoc */
// https://lqdoj.edu.vn/problem/querysum2
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

const int N = 1e5+5, INF = 1e9;

int n, q, a[N];

struct SegmentTree {
    int n;
    vector <int> st, lazy;

    void assign(int size) {
        n = size;
        st.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    SegmentTree(int size = 0) : n(size) {
        st.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void down(int id, int l, int r, int mid) {
        int t = lazy[id];

        st[id << 1]+= t*(mid - l + 1);
        lazy[id << 1]+= t;

        st[(id << 1) + 1]+= t*(r - mid);
        lazy[(id << 1) + 1]+= t;

        lazy[id] = 0;
    }

    void build(int id, int l, int r) {
        if (l == r){
            st[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1LL;

        build(id << 1, l, mid);
        build((id << 1) + 1, mid+1, r);

        st[id] = st[id << 1] + st[(id << 1) + 1];
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            st[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        int mid = (l + r) >> 1LL;

        down(id, l, r, mid);

        update(id << 1, l, mid, u, v, val);
        update((id << 1) + 1, mid+1, r, u, v, val);

        st[id] = st[id << 1] + st[(id << 1) + 1];
    }

    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[id];

        int mid = (l + r) >> 1LL;
        down(id, l, r, mid);

        return get(id << 1, l, mid, u, v) + get((id << 1) + 1, mid+1, r, u, v);
    }

    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int get(int l, int r) { return get(1, 1, n, l, r); }
} myST;

signed main(void) {
    FastIO;
    
    cin >> n >> q; 
    FOR(i,1,n) cin >> a[i];

    myST.assign(n);
    myST.build(1, 1, n);

    int type, u, v, val; 
    while (q--) {
        cin >> type >> u >> v;
        if (type == 1) {
            cin >> val;
            myST.update(u, v, val);
        } else cout << myST.get(u, v) << endl;
    }
    return 0;
}