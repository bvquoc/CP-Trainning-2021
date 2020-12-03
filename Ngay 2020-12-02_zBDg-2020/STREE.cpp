/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
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

const int N = 5003, INF = LLONG_MAX;
int n, a[N], res = INF;
int child_cnt[N];
vector <int> ke[N], child[N];

void DFS(int u, int par)  {
    bool isLeaf = true;
    for (int v: ke[u]) {
        if (v != par) {
            child[u].push_back(v);
            DFS(v, u); 
            child_cnt[u] += child_cnt[v];
            isLeaf = false;
        }
    }
    child_cnt[u] += isLeaf;
}

int f[N][N];
int dp(int u, int s) {
    int &ans = f[u][s];
    if (ans != INF) return ans;
    if (child[u].size() == 0) {
        if (s >= 2 || s < 0) return INF;
        return ans = Abs(a[u] - s);
    }
    if (child[u].size() == 1) {
        int cur = dp(child[u][0], s) + Abs(a[u] - s);
        return ans = cur;
    }
    if (child[u].size() == 2) {
        int v1 = child[u][0], v2 = child[u][1];
        FOR(t1,0,s) {
            int t2 = s-t1;
            if (t1 <= child_cnt[v1] && t2 <= child_cnt[v2])
                minimize(ans, Abs(a[u] - s) + dp(v1, t1) + dp(v2, t2));
        }
    }
    return ans;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("STREE.INP","r",stdin);
    freopen("STREE.OUT","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n-1) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    DFS(1,-1);
    FOR(i,0,n) FOR(j,0,child_cnt[i]) f[i][j] = INF;
    FOR(i,0,child_cnt[1]) res = min(res, dp(1, i));
    cout << res;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}