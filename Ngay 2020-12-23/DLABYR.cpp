/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
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

/*
(\_/)
( •_•)
/ >?? */

const int N = 302, M = 100005;
int n, m, q;
vector <int> adj[N];


namespace brute_force {
    bool free[N], mark[N];

    void init() {
        FOR(i, 1, n) free[i] = false;
    }

    bool ok;
    void DFS(int u, const int &isEnd) {
        mark[u] = true;
        if (u == isEnd) {
            ok = true;
            putchar('Y');
            return;
        }
        for (int v: adj[u]) if (free[v] && !mark[v]) DFS(v, isEnd);
    }

    void solve() {
        char type;
        REP(id, q) {
            cin >> type;
            if (type == 'X') {
                int x; cin >> x;
                free[x] = true;
                continue;
            }
            
            int u, v;
            cin >> u >> v;

            ok = false;
            FOR(i,1,n) mark[i] = false;
            if (free[u]) DFS(u, v);

            if (!ok) putchar('N');
        }
        exit(0);
    }

    void main_code() {
        init();
        solve();
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DLABYR.INP","r",stdin);
    freopen("DLABYR.OUT","w",stdout);
    #endif
    
    cin >> n >> m >> q;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    brute_force::main_code();

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}