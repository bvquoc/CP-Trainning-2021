#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

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


const int N = 100005;
int n, m, p, d[N], w[N];
int pw[N], pp[N], cur;
ii a[N];

signed main() {
    FastIO;
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    Read(n); Read(m);
    for (int i=1; i<=n; i++) Read(a[i].first);
    for (int i=1; i<=n; i++) Read(a[i].second);

    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++) {
        d[i] = a[i].first; w[i] = a[i].second;
        pp[i] = pp[i-1] + w[i]*d[i];
        pw[i] = pw[i-1] + w[i];
    }
    while (m--) {
        Read(p);
        int i = upper_bound(d+1,d+1+n,p) - d;
        cur = pw[i-1]*p - pp[i-1];
        if (i<=n) cur += (pp[n]-pp[i-1])-(pw[n]-pw[i-1])*p;
        Write(cur); putchar('\n');
    }
    return 0;
}
