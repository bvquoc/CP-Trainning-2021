#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

using ii = pair <int,int>;
const int N = 1003, INF = 90000000000000000;
int n, d[N], dd[N][N];
vector <ii> a[N];

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

        for (ii tmp: a[u]) {
            int v = tmp.second, uv = dd[u][v];
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("ROBINSON.INP","r",stdin);
    freopen("ROBINSON.OUT","w",stdout);
    cin >> n;
    { // Read input
        int u, v, w;
        while (cin >> u >> v >> w) {
            if (w == 0) {
                w = 9999999999;
            }
            a[u].push_back(ii(w,v));
            dd[u][v] = w;
            a[v].push_back(ii(w,u));
            dd[v][u] = w;
        }
    }
    dijkstra(1);
    if (d[n] >= INF) {
        cout << '-' << '1';
    } else {
        int cnt = d[n]/9999999999;
        int ans = d[n]-cnt*9999999999;
        cout << ans << '\n';
        cout << cnt;
    }
    return 0;
}