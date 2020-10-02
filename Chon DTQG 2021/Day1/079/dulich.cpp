#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int maxN = 101;
const int oo = LLONG_MAX - INT_MAX*INT_MAX;

int n, m, a[maxN][maxN];
vector<pii> g[maxN];
vector<pii> e;
int ans = oo;
stack<int> tAns;

void dijkstra(int u0, int v0) {
    vector<bool> fre(n+1, true);
    vector<int> d(n+1, oo);
    vector<int> t(n+1, -1);
    stack<int> T;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    d[u0] = 0;
    pq.push(pii(d[u0], u0));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (u == v0) {
            if (ans > a[u0][v0] + d[v0]) {
                ans = a[u0][v0] + d[v0];
                while (u != -1) {
                    T.push(u);
                    u = t[u];
                } tAns = T;
            }
            return ;
        }
        if (!fre[u]) continue;
        fre[u] = true;

        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (!fre[v]) continue;
            if (u == u0 && v == v0) continue;
            if (d[v] < d[u] + w) continue;

            d[v] = d[u] + w;
            t[v] = u;
            pq.push(pii(d[v], v));
        }
    }
}

int32_t main() {
    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);

    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        if (a[u][v])
            a[u][v] = a[v][u] = min(a[u][v], w);
        else a[u][v] = a[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!a[i][j]) continue;
            e.push_back(pii(i, j));
            g[i].push_back(pii(j, a[i][j]));
            g[j].push_back(pii(i, a[i][j]));
        }
    }

    for (int i = 0; i < (int)e.size(); i++) {
        dijkstra(e[i].first, e[i].second);
    }

    if (ans != oo) {
        cout << "1\n";
        cout << ans << '\n';
        cout << tAns.size() << '\n';
        while (!tAns.empty()) {
            cout << tAns.top() << '\n';
            tAns.pop();
        }
    } else cout << '0';

    return 0;
}
