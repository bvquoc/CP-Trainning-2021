#include <bits/stdc++.h>
#define int64_t long long
using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

typedef pair<int64_t, int> ii;

int n, m, k, l;
vector<ii> graph[N];
vector<int> a[N];

int64_t d[N];

void dijkstra(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(d + 1, d + n + 1, oo);
    d[s] = 0;
    pq.push(ii(0, s));

    while(!pq.empty()) {
        int u = pq.top().second;
        int64_t du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].second;
            int64_t uv = graph[u][i].first;

            if(d[v] > d[u]+ uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

namespace Sub1 {

void solve() {
    cout << -1;
}

}//namespace Sub1()

namespace Sub2 {

void solve() {
    dijkstra(1);

    if(d[n] == oo) cout << -1 << '\n';
    else cout << d[n] << '\n';
}

} //namespace Sub2()

namespace Sub3 {
int64_t d1[N], dn[N];

void solve() {
    dijkstra(1);
    for(int i = 1; i <= n; ++i)
        d1[i] = d[i];

    dijkstra(n);
    for(int i = 1; i <= n; ++i)
        dn[i] = d[i];

    int64_t ans = oo;
    for(int i = 1; i <= n; ++i) {
        if(!a[i].empty())
            ans = min(ans, d1[i] + dn[i]);
    }

    if(ans == oo) cout << -1 << '\n';
    else cout << ans << '\n';
}

}//namespace Sub3()

int main() {
#ifdef DN
    //freopen("in.txt", "r", stdin);
#endif
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i) {
        int s; cin >> s;

        while(s--) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    if(l == 0)
        Sub2::solve();
    else if(k == 1)
        Sub3::solve();
    else if(n <= 10 && m <= 10)
        Sub1::solve();
    else cout << -1;

    return 0;
}
