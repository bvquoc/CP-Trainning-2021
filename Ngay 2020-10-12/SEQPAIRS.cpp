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
inline bool maximize(T &x, T y) {
    if (x < y) { x = y; return true; }
    return false;
}
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

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1003;
int a_sz, b_sz, a[N], b[N];
int psa[N], psb[N];
map <ll, int> cnt_a;
map <ll, int> cnt_b;
ll res = 0;

signed main(void) {
    FastIO;
    freopen("SEQPAIRS.INP","r",stdin);
    freopen("SEQPAIRS.OUT","w",stdout);
    Read(a_sz); Read(b_sz);
    FOR(i,1,a_sz) {
        Read(a[i]);
        psa[i] = psa[i-1]+a[i];
    }
    FOR(i,1,b_sz) {
        Read(b[i]);
        psb[i] = psb[i-1]+b[i];
    }

    FOR(l,1,a_sz) FOR(r,l,a_sz) cnt_a[psa[r]-psa[l-1]]++;
    FOR(l,1,b_sz) FOR(r,l,b_sz) cnt_b[psb[r]-psb[l-1]]++;
    for (ii x: cnt_a) res += x.second * cnt_b[x.first];

    cout << res;
    return 0;
}