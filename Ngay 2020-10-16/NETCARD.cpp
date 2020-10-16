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

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, k, ans[N];
set <int> good, bad;
vector <ii> q;

signed main(void) {
    FastIO;
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
    Read(n); Read(k);
    while (k--) {
        int x, y, MODE;
        Read(x); Read(y); Read(MODE);
        if (MODE == 1) {
            good.insert(x);
            good.insert(y);
            continue;
        }
        if (good.count(x) && !good.count(y)) {
            bad.insert(y);
            continue;
        }
        if (good.count(y) && !good.count(x)) {
            bad.insert(x);
            continue;
        }
        q.push_back(ii(x,y));
    }

    for (ii t: q) {
        int x = t.first, y = t.second;
        if (good.count(x) && !good.count(y)) {
            bad.insert(y);
            continue;
        }
        if (good.count(y) && !good.count(x)) {
            bad.insert(x);
            continue;
        }
    }
    
    FOR(i,1,n) ans[i] = 2;
    for (int x: good) ans[x] = 1;
    for (int x: bad) ans[x] = 0;
    
    FOR(i,1,n) {
        Write(ans[i]);
        putchar(' ');
    }
    return 0;
}