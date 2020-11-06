#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Dijkstra {
    typedef pair<long long, long long> II;
    vector<vector<II>> adj;
    vector<long long> d;
    int n;

    Dijkstra(int n): n(n) {
        adj.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void dijkstra(int a) {
        for (int i = 1; i <= n; i++) {
            d[i] = INF;
        }
        d[a] = 0;

        priority_queue<II, vector<II>, greater<II>> pq;
        pq.push({0, a});

        while (!pq.empty()) {
            long long du = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d[u] != du) continue;

            for (auto i: adj[u]) {
                int v = i.first;
                long long uv = i.second;

                if (d[v] > du + uv) {
                    d[v] = du + uv;
                    pq.push({d[v], v});
                }
            }

        }
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, m, p, l, k;
    cin >> n >> m >> p >> l >> k;

    Dijkstra dijkstra(n);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        dijkstra.addEdge(u, v, w);
    }

    dijkstra.dijkstra(1);

    cout << dijkstra.d[n];

    return 0;
}