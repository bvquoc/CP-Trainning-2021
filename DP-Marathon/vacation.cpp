// http://lqdoj.edu.vn/problem/vacation
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

const int N = 100005;
int n, a, b, c, f[N][4];

signed main(void) {
    FastIO;
    Read(n);
    for(int i=1; i<=n; i++) {
        Read(a); Read(b); Read(c);
        f[i][1] = max(f[i-1][2], f[i-1][3])+a;
        f[i][2] = max(f[i-1][1], f[i-1][3])+b;
        f[i][3] = max(f[i-1][1], f[i-1][2])+c;
    }
    Write(max({f[n][1], f[n][2], f[n][3]}));
    return 0;
}