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

const int N = 1003;
int m, n, q;
int a[N][N];
ll psum[N][N];

ll getSum(int x, int y, int u, int v) {
    ll cur = psum[u][v] - psum[x-1][v] - psum[u][y-1] + psum[x-1][y-1];
    return cur;
}
signed main(void) {
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    Read(m); Read(n); Read(q);
    FOR(i,1,m) {
        FOR(j,1,n) {
            Read(a[i][j]);
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + a[i][j];
        }
    }
    while (q--) {
        int x, y, u, v;
        Read(x); Read(y);
        Read(u); Read(v);
        Write(getSum(x, y, u, v));
        putchar('\n');
    }
    return 0;
}