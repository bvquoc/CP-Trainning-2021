#include <bits/stdc++.h>

using namespace std;
int n, m, k, l, s[100005], a[100005][10];
long long f[100005][1 << 5];
vector<pair<int, int> > adj[100005];
void djs(int st) {
    priority_queue<pair<int, pair<long long, int> >, vector<pair<int, pair<long long, int> > >, greater<pair<int, pair<long long, int> > > > q;
    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j < (1 << k); ++ j) f[i][j] = 1e15;
    f[st][0] = 0;
    q.push({0, {0, st}});
    while (!q.empty()) {
        int tt = q.top().first; long long cost = q.top().second.first; int u = q.top().second.second; q.pop();
        if (cost > f[u][tt]) continue; int last = tt;
        for (auto i : adj[u]) {
            int v = i.first, val = i.second; tt = last;
            for (int j = 1; j <= s[v]; ++ j) {
                if ((tt >> (a[v][j] - 1)) & 1) continue;
                tt |= (1 << (a[v][j] - 1));
            }
            if (f[v][tt] > f[u][last] + val) {
                    f[v][tt] = f[u][last] + val;
                    q.push({tt, {f[v][tt], v}});
            }
        }
    }
    long long res = 1e15;
    for (int i = 0; i < (1 << k); ++ i) {
        int val = __builtin_popcount(i);
        if (val >= l) res = min(res, f[n][i]);
    }
    if (res == 1e15) cout << -1; else cout << res;
}
int main()
{
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++ i) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; ++ j) cin >> a[i][j];
    }
    for (int i = 1; i <= m; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    djs(1);
    return 0;
}
