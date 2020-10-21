#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(ll i=a; i<=b; i++)
#define FORD(i, a, b) for(ll i=a; i>=b; i--)
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

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 40;
int n, a[N];
ll S, res = 0;

signed main(void) {
    FastIO;
    freopen("TRAVEL.INP","r",stdin);
    freopen("TRAVEL.OUT","w",stdout);
    Read(n); Read(S);
    FOR(i,0,n-1) Read(a[i]);
    
    FOR(state,0,((1LL<<n)-1)) {
        ll cur_S = 0;
        FOR(i,0,n-1) {
            if (state & (1LL<<i)) {
                cur_S += ll(a[i]);
            }
        }
        if (cur_S == S) res++;
    }
    Write(res);
    return 0;
}