/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
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
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

/*
(\_/)
( •_•)
/ >?? */

const int N = 200005, INF = LLONG_MAX;
int n, k, a[N];
vector <int> pos[N];
map <int, int> f[N];

bool solved(const int &div, const int &pos) {
    return (f[div].find(pos) != f[div].end());
}

int dp(const int &div, const int &pos) {
    if (div == k) return 0;
    if (solved(div, pos)) return f[div][pos];
    int ans = INF;
    for (int x: ::pos[div + 1]) {
        int cost = 0;
        if (div == 1) cost = 1;
        if (x > pos) cost += (x - pos);
        else cost += (n - pos) + x;
        minimize(ans, cost + dp(div + 1, x));
    }
    f[div][pos] = ans;
    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("codeforce.inp","r",stdin);
    freopen("codeforce.out","w",stdout);
    #endif
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
    }
    
    int res = INF;
    for (auto x: pos[1]) {
        minimize(res, dp(1, x));
    }
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}