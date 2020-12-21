#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k, melon[100010], l, s[100010];
ll dist[100010][100], oo = 1e18;
vector <pair <int, ll>> adj[100010];

void dijkstra () {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < (1 << k); ++ j)
            dist[i][j] = oo;
    }
    priority_queue <pair <ll, pair <int, int>>,
                    vector <pair <ll, pair <int, int>>>,
                    greater <pair <ll, pair <int, int>>>> pq;
    dist[1][melon[1]] = 0;
    pq.push({0, {1, melon[1]}});
    while (!pq.empty()) {
        int u = pq.top().second.first, mask = pq.top().second.second;
        ll du = pq.top().first;
        pq.pop();
        if (du > dist[u][mask]) continue;

        for (auto pv : adj[u]) {
            int v = pv.first, maskv = melon[v]; ll w = pv.second;
            int newmask = (maskv | mask);
            if (dist[v][newmask] > du + w) {
                dist[v][newmask] = du + w;
                pq.push({du + w, {v, newmask}});
            }
        }
    }
}

int main () {
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++ i) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; ++ j) {
            int z; cin >> z; melon[i] |= (1 << (z - 1));
        }
    }
    for (int i = 1; i <= m; ++ i) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    ll ans = oo;
    for (int mask = 0; mask < (1 << k); ++ mask) {
        if (__builtin_popcount(mask) >= l) {
            ans = min(ans, dist[n][mask]);
        }
    }
    if (ans == oo) {
        cout << -1;
    }else cout << ans;
    return 0;
}
