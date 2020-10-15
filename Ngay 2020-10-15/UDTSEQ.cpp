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
using ld = long double;
using ll = long long;

const int N = 100005;
int n, m;
ll a[N];

signed main(void) {
    FastIO;
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    Read(n); Read(m);
    FOR(i,1,m) {
        int l, r, k;
        Read(l); Read(r); Read(k);
        a[l] += k; a[r+1] -= k;
    }
    FOR(i,1,n) {
        a[i] += a[i-1];
        Write(a[i]);
        putchar(' ');
    }
    return 0;
}