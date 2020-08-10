// http://lqdoj.edu.vn/problem/sumquery
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ld = long double;

const int N = 10004;
int n, q, a[N];

struct BIT_SumQuery {
    vector<int> bit;
    int n;
    BIT_SumQuery() {}
    BIT_SumQuery(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }
    void assign (int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 1; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx <= n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} BIT;

signed main(void) {
    FastIO;
    Read(n); Read(q);
    BIT.assign(n);
    FOR(i,1,n) {
        Read(a[i]);
        BIT.add(i,a[i]);
    }

    int x, i, l, r;
    while (q--) {
        Read(x);
        if (x == 1) {
            Read(l); Read(r);
            Write(BIT.sum(l,r));
            putchar('\n');
        } else {
            Read(i); Read(x);
            BIT.add(i, x-a[i]);
            a[i] = x;
        }
    }
    return 0;
}