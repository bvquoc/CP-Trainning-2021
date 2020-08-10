// http://lqdoj.edu.vn/problem/stonefrog2
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

const int N = 100005, INF = LLONG_MAX;
int n, k, a[N], f[N];

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    Read(n); Read(k);
    FOR(i,1,n) Read(a[i]);
    f[1] = 0;
    f[2] = abs(a[1]-a[2]);
    FOR(i,3,n) {
        f[i] = INF;
        FOR(j,1,k) {
            if (i-j<=0) break;
            f[i] = min(f[i], f[i-j]+abs(a[i]-a[i-j]));
        }
    }
    Write(f[n]);
    return 0;
}