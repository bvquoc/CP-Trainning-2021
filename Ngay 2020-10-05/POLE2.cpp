#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
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
using ll = long long;
using ld = long double;

const int N = 4003;
int n, d, c[N], h[N];
ll res;

int val_h[N];
void Try(int k) {
    FOR(j,0,2) {
        val_h[k] = j;
        if (k == n) {
            ll cur = val_h[n]*val_h[n];
            int x, y, delta;
            FOR(i,1,n-1) {
                x = h[i] + val_h[i];
                y = h[i+1] + val_h[i+1];
                delta = abs(x-y);
                if (delta > d) return;
                cur += c[i]*delta;
                cur += val_h[i]*val_h[i];
            }
            res = min(res, cur);
        } else Try(k+1);
    }
}

signed main(void) {
    FastIO;
    freopen("POLE2.INP","r",stdin);
    freopen("POLE2.OUT","w",stdout);
    Read(n); Read(d);
    FOR(i,1,n-1) Read(c[i]);
    FOR(i,1,n) Read(h[i]);
    if (n<=10) {
        res = LLONG_MAX;
        Try(1);
    } else {
        res = 0;

    }
    Write(res);
    return 0;
}