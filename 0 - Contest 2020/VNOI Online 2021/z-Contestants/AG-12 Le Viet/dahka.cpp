#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, long long> ii;
typedef pair<long long, ii> iii;

const int N = 1e5 + 7;
const long long oo = 1e18;

vector<ii> g[N];
bool vsd[N][33];
long long w, f[N][33];
int n, m, k, u, v, l, c[N], q[33];

void read_input() {
    cin >> n >> m >> k >> l;

    for (int i = 1; i <= n; ++i) {
        int s, x;
        cin >> s;
        for (int j = 1; j <= s; ++j) {
            cin >> x;
            c[i] ^= 1 << (x - 1);
        }
    }

    for (int i = 1; i < 33; ++i)
        q[i] = q[i >> 1] + (i & 1);

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

struct cmp {
    bool operator() (const iii &a, const iii &b) {
        return a.ff > b.ff;
    }
};

void DIJKSTRA() {
    priority_queue<iii, vector<iii>, cmp> h;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 32; ++j) f[i][j] = oo;

    f[1][c[1]] = 0;

    h.push({0, {1, c[1]}});

    while (!h.empty()) {
        long long d = h.top().ff;
        int u = h.top().ss.ff, cc = h.top().ss.ss;
        h.pop();

        if (d != f[u][cc] || vsd[u][cc]) continue;

        if (u == n && q[cc] >= l) {
            cout << d; return;
        }

        vsd[u][cc] = true;

        for (ii v : g[u])
            if (!vsd[v.ff][cc | c[v.ff]] && f[v.ff][cc | c[v.ff]] > d + v.ss) {
                long long msk = cc | c[v.ff];
                f[v.ff][msk] = d + v.ss;
                h.push({f[v.ff][msk], {v.ff, msk}});
            }
    }

    cout << -1;
}

int main() {
    freopen("dahka.inp", "r", stdin);
    freopen("dahka.out", "w", stdout);

    read_input();
    DIJKSTRA();
}
