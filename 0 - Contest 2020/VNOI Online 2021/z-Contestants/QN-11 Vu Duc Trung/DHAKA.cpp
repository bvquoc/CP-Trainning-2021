#include <bits/stdc++.h>
#define task "DHAKA"
typedef long long int ll;
using namespace std;
typedef pair<ll,ll> ii;
typedef pair<pair<ll, set<ll> >, ll> iii;
const int N = 100010;
int n, m, k, l;
ll s[N], a[N][10];
vector<ii> adj[N];

pair<ll, set<ll> > dd[N][10];

void DIJKSTRA(int r) {
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j )dd[i][j].first = 1e18, dd[i][j].second.clear();
    for (int i = 1; i <= s[r]; ++i) dd[r][s[r]].second.insert(a[r][i]);
    dd[r][s[r]].first = 0;
    pq.push({dd[r][s[r]], r});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll du = pq.top().first.first;
        set<ll> su = pq.top().first.second;
        pq.pop();
        if (du != dd[u][su.size()].first) continue;
        for (auto pv : adj[u]) {
            ll v = pv.first, w = pv.second;
            set<ll> sv = su;
            for (int i = 1; i <= s[v]; ++i) sv.insert(a[v][i]);
            if (du + w < dd[v][sv.size()].first) {
                dd[v][sv.size()] = {du + w, sv};
                pq.push({dd[v][sv.size()], v});
            }
        }
    }
}

void sub1(void) {
    DIJKSTRA(1);
    ll res = 1e18;
    for (int i = l; i <= k; ++i) res = min(res, dd[n][i].first);
    cout << (res == 1e18 ? -1 : res);
}

ll d[N];
void dijkstra(int r) {
    for (int i = 1; i <= n; ++i) d[i] = 1e18;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, r});
    d[r] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (auto pv : adj[u]) {
            ll v = pv.first, w = pv.second;
            if (du + w < d[v]) {
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
}
void sub2(void) {
    dijkstra(1);
    cout << (d[n] == 1e18 ? -1 : d[n]);
}


int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if (l == 0) sub2();
    else sub1();
    return 0;
}

