#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
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

template <typename T>
inline bool maximize(T &x, T y) {
    if (x < y) { x = y; return true; }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1000006;
int n; ll LIM = -1;
pair <ll, ll> q[N];
map <ll, int> cnt;



signed main(void) {
    FastIO;
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    Read(n);
    FOR(i,1,n) {
        Read(q[i].first);
        Read(q[i].second);
        if (q[i].first > q[i].second) swap(q[i].first, q[i].second);
        maximize(LIM, q[i].second);
    }
    cout << LIM;

    return 0;
}