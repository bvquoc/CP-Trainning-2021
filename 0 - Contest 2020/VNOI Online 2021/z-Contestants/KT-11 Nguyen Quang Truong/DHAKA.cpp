#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int64_t INF = 1e18;

int n, m, k, l;
std::set<int> a[N];
std::vector<std::pair<int, int64_t>> g[N];
std::vector<std::vector<int64_t>> cost;

namespace Dijkstra {
std::priority_queue<std::pair<int64_t, int>> q;

void Dijkstra(int64_t *d, int s) {
    std::fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    q.emplace(0, s);

    while (!q.empty()) {
        const auto [du, u] = q.top();
        q.pop();

        if (-du > d[u]) continue;

        for (const auto &[v, c] : g[u]) {
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                q.emplace(-d[v], v);
            }
        }
    }
}
} // namespace Dijkstra

namespace sub2 {
int64_t d[N];

void solve() {
    Dijkstra::Dijkstra(d, 1);
    if (d[n] == INF) std::cout << -1;
    else std::cout << d[n];
}
} // namespace sub2

namespace sub3 {
int64_t d1[N], dn[N];
int64_t ans = INF;

void solve() {
    Dijkstra::Dijkstra(d1, 1);
    Dijkstra::Dijkstra(dn, n);

    for (int i = 1; i <= n; i++) {
        if (a[i].empty()) continue;
        ans = std::min(ans, d1[i] + dn[i]);
    }

    if (ans == INF) ans = -1;
    std::cout << ans;
}
} // namespace sub3

signed main() {
#ifndef LOCAL
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k >> l;

    for (int i = 1; i <= n; i++) {
        int s;
        std::cin >> s;

        while (s--) {
            int x;
            std::cin >> x;
            a[i].insert(x);
        }
    }

    while (m--) {
        int u, v;
        int64_t c;

        std::cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    if (l == 0) {
        sub2::solve();
    }
    else if (k == 1) {
        sub3::solve();
    }
    else {
        std::cout << -1;
    }

    return 0;
}
