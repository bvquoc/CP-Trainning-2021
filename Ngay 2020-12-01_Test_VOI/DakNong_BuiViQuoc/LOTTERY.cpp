/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
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
        x = x * 10 + c - '0';
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 4003, MOD = 1000000007;
int n, m, res[N];
bool a[20][20];
bool mark[N];
set <int> adj[N];

void dfs(int u, int d) {
    mark[u] = true;
    res[d]++;
    if (res[d] > MOD) res[d] -= MOD;
    if (d == n) return;

    for (int v: adj[u]) if (!mark[v]) {
        mark[v] = true;
        dfs(v, d+1);
        mark[v] = false;
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("LOTTERY.INP","r",stdin);
    freopen("LOTTERY.OUT","w",stdout);
    #endif
    Read(n); Read(m);
    FOR(i,1,m) {
        int u, v; Read(u); Read(v);
        if (n <= 10) {
            a[u][v] = true;
            a[v][u] = true;
        }
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if (n <= 10) { /* subtask 1 */
        int b[20];
        iota(b + 1, b + 1 + n, 1);
        do {
            FOR(i,2,n) {
                if (a[b[i-1]][b[i]]) {
                    res[i]++;
                    if (res[i] > MOD) res[i] -= MOD;
                } else break;
            }
        } while (next_permutation(b + 1, b + 1 + n));

        res[1] = n;
        #define SPACE putchar(' ')
        FOR(i,1,n) {
            Write(res[i]);
            SPACE;
        }
        exit(0);
    }

    auto prepare = [&]() {
        FOR(i,1,n) {
            mark[i] = false;
        }
    };

    FOR(i,1,n) {
        prepare();
        dfs(i, 1);
    }

    #define SPACE putchar(' ')
    FOR(i,1,n) {
        Write(res[i]);
        SPACE;
    }
    return 0;
}