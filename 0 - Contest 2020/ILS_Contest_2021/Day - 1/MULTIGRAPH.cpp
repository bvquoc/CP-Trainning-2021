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
using iii = pair <int, ii>;
using ll = long long;
using ld = long double;

/*
(\_/)
( •_•)
/ >?? */

const int N = 100005;
const ll LINF = LLONG_MAX;
int n, q_sz, a[N];
iii q[N];

vector <ll> d[N];

void dijkstra(const int &st, vector <ll> &d) {
    d.assign(n + 1, LINF);
    d[st] = 0;

    priority_queue <ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, st));

    while (pq.size()) {
        int u = pq.top().second, du = pq.top().first; pq.pop();
        if (du != d[u]) continue;
        FOR(v, 1, n) if (u != v) {
            ll uv = 1LL * a[u] * a[v];
            if (minimize(d[v], du + uv)) pq.push(ii(d[v], v));
        }
    }
}


#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("MULTIGRAPH.INP","r",stdin);
    freopen("MULTIGRAPH.OUT","w",stdout);
    #endif
    
    Read(n); Read(q_sz);
    FOR(i,1,n) Read(a[i]);

    FOR(i,1,q_sz) {
        Read(q[i].first);
        Read(q[i].second.first);
        Read(q[i].second.second);

        if (q[i].first == 1) {
            FOR(i,1,n) d[i].clear();
            a[q[i].second.first] = q[i].second.second;
            continue;
        }

        /* q[i].first == 2 */

        if (q[i].second.first == q[i].second.second) {
            putchar('0');
            putchar(endl);
            continue;
        }

        if (d[q[i].second.first].empty()) dijkstra(q[i].second.first, d[q[i].second.first]);
        Write(d[q[i].second.first][q[i].second.second]);
        putchar(endl);
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}