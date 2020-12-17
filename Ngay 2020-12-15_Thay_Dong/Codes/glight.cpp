#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector <int> adj[N];
int deg[N]; bool vs[N];

int main() {
    freopen("glight.inp", "r", stdin);
    freopen("glight.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (vs[i]) continue;
        queue <int> q;
        int odd = 0, cnt = 0;
        vs[i] = 1; q.push(i);
        while (q.size()) {
            int u = q.front(); q.pop();
            odd += deg[u] & 1; cnt++;
            for (int v : adj[u])
                if (!vs[v]) {
                    q.push(v); vs[v] = 1;
                }
        }
        if (cnt > 1)
            res += max(1, odd / 2);
    }
    cout << res << '\n';
}