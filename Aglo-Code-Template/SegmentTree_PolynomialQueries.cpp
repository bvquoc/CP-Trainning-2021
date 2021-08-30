/* Author: Bui Vi Quoc */
// Task: https://cses.fi/problemset/task/1736
// Docs: https://leduythuccs.github.io/2020-07-07-Polynomial-Queries/
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Aint(v) (v).begin(), (v).end()
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountint(n)
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

const int N = 200005;
int n, q;
int a[N], st[N * 4], lazy1[N * 4], lazy2[N * 4];

void build(int id, int l, int r) {
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1LL;
    build(id << 1LL, l, mid);
    build((id << 1LL) + 1, mid + 1, r);
    st[id] = st[id << 1LL] + st[(id << 1LL) + 1];
}

int calc(int x) {
    return (x * (x + 1) / 2LL);
}

void push(int id, int l, int r, int x1, int x2){
    st[id] += x2 * (calc(r) - calc(l-1)) - x1 * (r - l + 1);
    lazy1[id] += x1;
    lazy2[id] += x2;
}

void downLazy(int id, int l, int r){
    int mid = (l + r) >> 1LL;
    push(id << 1LL, l, mid, lazy1[id], lazy2[id]);
    push((id << 1LL) + 1, mid + 1, r, lazy1[id], lazy2[id]);
    lazy1[id] = lazy2[id] = 0;
}

void update (int id, int l, int r, int u, int v){
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        push(id, l, r, u - 1, 1);
        return;
    }
    int mid = (l + r) >> 1LL;
    downLazy(id, l, r);
    update(id << 1LL, l, mid, u, v);
    update((id << 1LL) + 1, mid + 1, r, u, v);
    st[id] = st[id << 1LL] + st[(id << 1LL) + 1];
}

int get(int id, int l, int r, int u, int v){
    if (r < u || v < l) return 0LL;
    if (u <= l && r <= v) return st[id];
    downLazy(id, l, r);
    int mid = (l + r) >> 1LL;
    int lf = get(id << 1LL, l, mid, u, v);
    int rt = get((id << 1LL) + 1, mid + 1, r, u, v);
    return (lf + rt);
}

signed main(void) {
    FastIO;
    
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) update(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r) << endl;
    }

    return 0;
}