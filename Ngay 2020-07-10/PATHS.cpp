#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

using ii = pair <int,int>;
const int N = 1503, INF = LLONG_MAX;
int n, m, d[N], trace[N];
int from[N], to[N];
vector <ii> a[N];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra(int _u) {
    for (int i=1; i<=n; i++) {
        d[i] = INF;
        trace[i] = i;
    }
    d[_u] = 0;
    pq.push(ii(0, _u));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;

        for (ii tmp: a[u]) {
            int v = tmp.second, uv = tmp.first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                trace[v] = u;
                pq.push(ii(d[v], v));
            }
        }
    }

    for (int _v=1; _v<=n; _v++) {
        if (_u == _v || d[_v]>=INF) continue;
        int x = _v;
        do {
            to[x]++;
            from[trace[x]]++;
            x = trace[x];
        } while (trace[x] != x);
    }
}

int32_t main(void) {
    FastIO;
    freopen("PATHS.INP","r",stdin);
    freopen("PATHS.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(ii(w,v));
    }

    for (int i=1; i<=n; i++) {
        dijkstra(i);
    }
    for (int i=1; i<=n; i++) {
        cout << from[i]*to[i] << '\n';
    }
    return 0;
}