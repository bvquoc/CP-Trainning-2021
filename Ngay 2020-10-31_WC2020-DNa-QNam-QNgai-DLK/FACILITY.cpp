#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
#define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1000006;
int n, K; 
struct data { 
    int s, d, r; 
    bool operator < (const data &b) {
        return s < b.s || (s == b.s && d == b.d && r > b.r);
    }
} a[N];

signed main(void) {
    FastIO;
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    cin >> n >> K;
    REP(i,n) cin >> a[i].s >> a[i].d >> a[i].r;
    sort(a, a+n);
    int res = 0;
    REP(state,MASK(n)) {
        int cur_cost = 0, cur_time = 0;
        REP(i,n) if (BIT(state, i)) {
            if (a[i].s >= cur_time) {
                cur_cost += a[i].r;
                cur_time = a[i].s + a[i].d + K;
            }
        }
        maximize(res, cur_cost);
    }
    cout << res;
    return 0;
}