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
using ll = long long;
using ld = long double;

const int N = 100005;
int n; ii a[N];
int LIM = -1;

bool check(ll K) {
    int c = 0;
    FOR(i,1,n-1) {
        int x = a[i].second + c;
        if(x < K) c = x - K - (a[i+1].first-a[i].first);
        else {
            c = x - K - (a[i+1].first-a[i].first);
            c = max(0LL, c);
        }
    }
    return (a[n].second+c) >= K;
}

signed main(void) {
    FastIO;
    freopen("RICE.INP","r",stdin);
    freopen("RICE.OUT","w",stdout);
    Read(n);
    FOR(i,1,n) {
        Read(a[i].first);
        Read(a[i].second);
        LIM = max(LIM, a[i].second);
    }

    int l = 0, r = LIM, res = 0;
    while (l <= r) {
        int mi = l + (r-l)/2;
        if (check(mi)) {
            res = max(res, mi);
            l = mi + 1;
        } else r = mi - 1;
    }
    Write(res);
    return 0;
}