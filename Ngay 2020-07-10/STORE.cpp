#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

using ii = pair <int,int>;
const int N = 1003, INF = 9000000000000000000;
int n, m, d[N], a[N][N];
int ans = INF, ans_id = 1;
vector <int> adj[N];

void dijkstra(int _u) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i=1; i<=n; i++) {
        d[i] = INF;
    }
    d[_u] = 0;
    pq.push(ii(0, _u));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int uv = a[u][v];
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("STORE.INP","r",stdin);
    freopen("STORE.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = w;
        a[v][u] = w;
    }

    // Solve
    for (int i=1;i<=n;i++) {
        int cur = 0;
        dijkstra(i);
        for (int j=1; j<=n; j++) {
            if (d[j]!=INF) {
                cur += d[j];
            }
        }
        if (ans > cur) {
            ans = cur;
            ans_id = i;
        }
    }
    cout << ans_id << ' ' << ans;
    return 0;
}