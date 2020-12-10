/* Author: Bui Vi Quoc */
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
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
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

struct Point {
    int x, y;
    Point () { x = 0; y = 0; }
    Point (int _x, int _y) { x = _x; y = _y; }
    bool operator == (const Point &p) const { return (x == p.x && y == p.y); }
    bool operator < (const Point &p) const { return (y == p.y ? x < p.x : y < p.y); }
    bool operator != (const Point &p) const { return (x != p.x || y != p.y); }
};
istream& operator >> (istream &is, Point &p) { return is >> p.x >> p.y; }

const int N = 100005;
int n; Point a[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DIFTRI.INP","r",stdin);
    freopen("DIFTRI.OUT","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    
    cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}