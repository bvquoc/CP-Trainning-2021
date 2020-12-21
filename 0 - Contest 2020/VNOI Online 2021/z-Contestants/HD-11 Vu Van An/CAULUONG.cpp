//
#include <bits/stdc++.h>

using namespace std;
#define task        "CAULUONG"
#define maxn        1505
#define maxm
#define maxs
#define p_b         push_back
#define fs          first
#define sc          second
#define oo          2000000000000000000
#define mod         998244353
#define ll          long long

typedef pair <ll, int> II;
typedef pair <II, ll> III;

int m, n;
set<II> s;
ll cnt[maxn], d[maxn];
vector <II> g[maxn];
III e[maxn];
ll kc[maxn][maxn], a[maxn][maxn];

void dij (int xp) {
    for (int i = 1; i <= n; i++)
        d[i] = oo, cnt[i] = 0;
    s.insert({0,xp});
    d[xp] = 0;
    cnt[xp] = 1;
    while (!s.empty()) {
        int u = s.begin() -> sc;
        s.erase (*s.begin());
        for (auto t : g[u]) {
            int v = t.fs;
            ll w = t.sc;
            if (d[v] > d[u] + w) {
                cnt[v] = cnt[u];
                d[v] = d[u] + w;
                s.insert ({d[v], v});
            } else if (d[v] == d[u] + w)
                cnt[v] = (cnt[u] + cnt[v]) % mod;
        }
    }
}

//
int main() {
    freopen (task".inp", "r", stdin);
    freopen (task".out", "w", stdout);
    ios::sync_with_stdio (false);
//    cin.tie(0);
//    cout.tie(0);
    int subtask;
    cin >> subtask;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].p_b ({v, w});
        e[i] = {{u, v}, w};
    }
    for (int i = 1; i <= n; i++) {
        dij (i);
        for (int j = 1; j <= n; j++) {
            a[i][j] = d[j];
            kc[i][j] = cnt[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = e[i].fs.fs, v = e[i].fs.sc, w = e[i].sc;
        ll res = 0;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) if (w + a[x][u] + a[v][y] == a[x][y]) {
                res = (res + kc[x][u] * kc[v][y] % mod) % mod;
            }
        }
        cout << res << "\n";
    }
}
