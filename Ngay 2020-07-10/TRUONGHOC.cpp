#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

using ii = pair <int,int>;
const int N = 502, INF = 9000000000000000000;
int n, x, d[N], trace[N], t[N];
vector <ii> adj[N];

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

        for (ii tmp: adj[u]) {
            int v = tmp.second, uv = tmp.first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                t[v] = uv;
                trace[v] = u;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("TRUONGHOC.INP","r",stdin);
    freopen("TRUONGHOC.OUT","w",stdout);
    cin >> n >> x;
    for (int i=1; i<=n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
    dijkstra(x);
    int res = 0;
    for (int i=1; i<=n; i++) {
        res += ((i!=x) ? t[i] : 0);
    }
    cout << res;
    return 0;
}