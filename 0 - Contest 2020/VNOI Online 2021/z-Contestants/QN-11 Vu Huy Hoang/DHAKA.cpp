#include <bits/stdc++.h>

using namespace std;

int n, m, k, l, a[100010];
long long res = 1e18;
long long d[100010][100];
priority_queue <pair <long long, pair <int, int> > > pq;
vector <pair <int, long long> > adj[100010];

int main() {
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++i) {
        int q;
        cin >> q;
        while (q--) {
            int s;
            cin >> s;
            a[i] |= (1 << s - 1);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i)
        for (int mask = 0; mask < (1 << k); ++mask) {
            d[i][mask] = 1e18;
        }
    d[1][a[1]] = 0;
    pq.push({0, {1, a[1]}});
    while (!pq.empty()) {
        int u = pq.top().second.first;
        int mask = pq.top().second.second;
        long long dist = - pq.top().first;
        pq.pop();
        if (dist != d[u][mask]) continue;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            long long w = adj[u][i].second;
            if (d[u][mask] + w < d[v][(mask | a[v])]) {
                d[v][(mask | a[v])] = d[u][mask] + w;
                pq.push({- d[v][(mask | a[v])], {v, (mask | a[v])}});
            }
        }
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        if (__builtin_popcount(mask) >= l) res = min(res, d[n][mask]);
    }
    if (res >= 1e18) cout << -1;
    else cout << res;
}
