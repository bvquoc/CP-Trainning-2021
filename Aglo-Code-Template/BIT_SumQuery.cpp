/* Author: Bui Vi Quoc */
// http://lqdoj.edu.vn/problem/querysum
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = (x << 3) + (x << 1) + (c - '0');
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

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

signed main(void) {
    FastIO;
    int n, q;
    Read(n); Read(q);

    FenwickTree BIT(n);

    for (int i = 1; i <= n; i++) {
        int x; Read(x);
        BIT.update(i,x);
    }

    while (q--) {
        int type; Read(type);
        if (type == 1) {
            int i, x;
            Read(i); Read(x);
            BIT.update(i,x);
        } else {
            int l, r;
            Read(l); Read(r);
            Write(BIT.get(l, r));
            putchar('\n');
        }
    }
    return 0;
}