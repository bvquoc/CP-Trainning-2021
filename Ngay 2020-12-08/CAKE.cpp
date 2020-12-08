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

const int N = 100005;
int n, T;
struct Cake {
    int pos, time;
} a[N];

map <int, int> f[N];

bool solved(const int &id, const int &T) {
    return (f[id].find(T) != f[id].end());
}

int dp(const int &id, const int &T, const int &pos) {
    if (T < 0) return 0;
    if (id == n) {
        if (T >= Abs(pos - a[id].pos) + a[id].time) return 1;
        return 0;
    }
    
    if (solved(id, T)) return f[id][T];
    int &ans = f[id][T]; ans = 0;
    if (T >= a[id].time + Abs(pos - a[id].pos)) ans = 1 + dp(id + 1, T - a[id].time - Abs(pos - a[id].pos), a[id].pos);
    maximize(ans, dp(id+1, T - Abs(a[id].pos - pos), a[id].pos));

    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
    #endif
    cin >> n >> T;
    FOR(i,1,n) cin >> a[i].pos >> a[i].time;

    cout << dp(1,T,0);
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}