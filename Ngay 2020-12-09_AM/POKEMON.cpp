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

const int N = 45;
int n, m;
struct Data { int x, y, t; } q[N];

double res = DBL_MAX, cur = 0.0;
int order[N]; bool mark[N];
double dist(const Data &A, const Data &B) {
    ll tmp = 1LL * sqr(A.x - B.x) + sqr(A.y - B.y);
    return sqrt(tmp);
}
double d[N][N];

void Try(int id) {
    if (id > n) {
        // FOR(i,1,n) cout << order[i] << ' ';
        // cout << cur << endl;
        res = cur;
        return;
    }

    FOR(i,1,n) if (!mark[i]) {
        double tmp = d[order[id-1]][i];
        if (cur + tmp > res) continue;
        order[id] = i;
        mark[i] = true;
        cur += tmp;
        Try(id+1);
        cur -= tmp;
        mark[i] = false;
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("POKEMON.INP","r",stdin);
    freopen("POKEMON.OUT","w",stdout);
    #endif
    Read(n); Read(m);
    q[0] = {0,0,0};
    FOR(i,1,n) {
        Read(q[i].x);
        Read(q[i].y);
        Read(q[i].t);
    }

    order[0] = 0;
    FOR(i,0,n) FOR(j,0,n) d[i][j] = dist(q[i], q[j]);
    Try(1);
    cout << fixed << setprecision(3) << res;

    #define subtask_1 (n <= 17 && m == n)
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}