/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr);
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (signed(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
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

const int  MOD = 1000000007;

int pw(int m, int n) {
    int ans = 1;
    while (n != 0) {
        if (n & 1) ans = (1LL * ans * m) % MOD;
        n /= 2;
        m = (1LL * m * m) % MOD;
    }
    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("NGUHANH.INP","r",stdin);
    freopen("NGUHANH.OUT","w",stdout);
    #endif
    
    int k, n; 
    string a;

    cin >> a >> k;
    n = a.size();
    
    int res = 0;
    REP(i, n) if (a[i] == '0' || a[i] == '5') (res += MASK(i)) % MOD;

    int t = pw((MASK(n)-1), MOD - 2);
    t = (t * (MASK(k*n) - 1)) % MOD;
    (res *= t) % MOD;
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}