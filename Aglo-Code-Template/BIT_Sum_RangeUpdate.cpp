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
using ll = int;
using ld = long double;

/*
(\_/)
( •_•)
/ >?? */

struct FenwickTree {
    int n;
    vector<int> bit_add, bit_sub;

    void assign(int size) {
        n = size + 1;
        bit_add.assign(n, 0);
        bit_sub.assign(n, 0);
    }

    FenwickTree(int size = 0) : n(size + 1) {
        bit_add.assign(n, 0);
        bit_sub.assign(n, 0);
    }

    void update(int x, int value) {
        for (int i = x; i < n; i += i & -i) {
            bit_sub[i] += value;
        }
    }
    void update(int l, int r, int value) {
        for (int i = l; i < n; i += i & -i) {
            bit_add[i] += value;
            bit_sub[i] -= 1LL * (l - 1) * value;
        }
        for (int i = r + 1; i < n; i += i & -i) {
            bit_add[i] -= value;
            bit_sub[i] += 1LL * r * value; 
        }
    }
    int get(int x) {
        int a1 = 0, a2 = 0;
        for (int i = x; i > 0; i -= i & -i) {
            a1 += bit_add[i];
            a2 += bit_sub[i];
        }
        return a1 * x + a2;
    }
    int get(int l, int r) { return get(r) - get(l - 1); }

} myBIT;

// #define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("input.txt","r",stdin);
    #endif
    
    int n, q;
    cin >> n >> q;
    myBIT.assign(n);
    FOR(i,1,n) {
        int x; cin >> x;
        myBIT.update(i, i, x);
    }

    int type, l, r, v;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> v;
            myBIT.update(l, r, v);
        } else cout << myBIT.get(l, r) << endl;
    }

    return 0;
}