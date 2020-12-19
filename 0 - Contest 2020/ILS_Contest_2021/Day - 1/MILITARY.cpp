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

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = (x << 3) + (x << 1) + (c - '0');
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

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
int n, k;
bool isBarrack[N];
vector <int> barracks, adj[N];

int d[N];
bool mark[N];
bool check(const int &st) {
    FOR(i,1,n) {
        mark[i] = false;
        d[i] = 0;
    }

    queue <int> q;
    q.push(st);
    d[st] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        mark[u] = true;
        for (int v: adj[u]) if (!mark[v]) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    FOR(i,0,n) mark[i] = false;
    for (int x: barracks) {
        if (mark[d[x]]) return false;
        mark[d[x]] = true;
    }
    
    return true;
}
#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("MILITARY.INP","r",stdin);
    freopen("MILITARY.OUT","w",stdout);
    #endif
    
    Read(n); Read(k);
    FOR(i,1,k) {
        int x; Read(x);
        isBarrack[x] = true;
        barracks.emplace_back(x);
    }
    FOR(i,2,n) {
        int u, v; 
        Read(u); Read(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector <int> ans;
    FOR(i,1,n) if (check(i)) ans.emplace_back(i);

    Write(ans.size()); putchar(endl);
    for (int x: ans) {
        Write(x);
        putchar(' ');
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}