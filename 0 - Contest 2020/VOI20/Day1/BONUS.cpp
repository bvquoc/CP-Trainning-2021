/* Author: Bui Vi Quoc */
// https://codeforces.com/group/FLVn1Sc504/contest/266446/problem/A
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
// #define int long long
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

const int N = 302;
const ll INF = 1e15;

int n, k, a[N];
ll f[N][N][N];

ll dp(const int &l, const int &r, const int &k) {
    if (f[l][r][k] != -1) return f[l][r][k];
    if (k <= 0 || l >= r) return 0;

    if (l+1 == r) {
        if (k == 1) return Abs(a[l] - a[r]);
        if (k == 0) return 0;
        return -INF;
    }

    ll &ans = f[l][r][k];
    ans = dp(l+1, r-1, k-1) + Abs(a[l] - a[r]);
    maximize(ans, max(Abs(a[l] - a[l+1]) + dp(l+2, r, k-1), dp(l, r-2, k-1) + Abs(a[r-1] - a[r])));
    if (r - l + 1 > k * 2 && k > 0) {
        maximize(ans, dp(l+1, r, k));
        maximize(ans, dp(l, r-1, k));
    }

    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    #endif
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    
    memset(f, -1, sizeof f);
    cout << dp(1,n,k);
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}