#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<int>> melon(n + 1);
    for (int i = 1; i <= n; i++) {
        int nn;
        cin >> nn;
        for (int j = 1; j <= nn; j++) {
            int x;
            cin >> x;
            melon[i].push_back(x);
        }
    }
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    vector<bool> d_melon(k + 1, true);
    int cnt = 0;
    long long sum = 0, ans = 1e18;
    for (int Melon : melon[1]) {
        if (d_melon[Melon]) {
            ++cnt;
            d_melon[Melon] = false;
        }
    }
    function<void(int)> DFS = [&] (int u) {
        if (u == n && cnt >= l) {
            ans = min(ans, sum);
            return;
        }
        for (pair<int, int> edge : g[u]) if (d[u][edge.first] < 2) {
            int v = edge.first;
            int uv = edge.second;
            vector<int> tmp;
            for (int Melon : melon[v]) {
                if (d_melon[Melon]) {
                    ++cnt;
                    d_melon[Melon] = false;
                    tmp.push_back(Melon);
                }
            }
            sum += uv;
            ++d[u][v];
            ++d[v][u];
            DFS(v);
            --d[v][u];
            --d[u][v];
            sum -= uv;
            cnt -= tmp.size();
            for (int Melon : tmp) d_melon[Melon] = true;
        }
    };
    DFS(1);
    if (ans == 1e18) ans = -1;
    cout << ans << endl;
    return 0;
}
