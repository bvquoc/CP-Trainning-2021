#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define S second
#define F first
#define pb push_back
#define mp make_pair

int n, m, k, l;
const int N = 1e5+5;
int melon[N];
vector<pair<int, ll>> adj[N];

void Input() {
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i) {
        melon[i] = 0;
        int s; cin >> s;
        for(int j = 0; j < s; ++j) {
            int x; cin >> x;
            x--;
            melon[i] |= (1<<x);
        }
    }
    for(int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
}

void dotask1() {
    ll dist[N]; memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    bitset<N> visited; visited.reset();
    priority_queue<pair<ll, int>> q;
    q.push(mp(0, 1));
    while (!q.empty()) {
        int u = q.top().S; q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (u == n) {
            cout << dist[u];
            return;
        }
        for(auto &e : adj[u]) {
            if (dist[e.F] > dist[u] + e.S) {
                dist[e.F] = dist[u] + e.S;
                q.push(mp(-dist[e.F], e.F));
            }
        }
    }
    cout << -1;
}

void dotask2() {
    ll dist[N][2]; memset(dist, 0x3f, sizeof dist);
    dist[1][melon[1]] = 0;
    bool visited[N][2]; memset(visited, 0, sizeof visited);
    priority_queue<pair<ll, pair<int, bool>>> q;
    q.push(mp(0, mp(1, melon[1])));
    while (!q.empty()) {
        int u; bool t; tie(u, t) = q.top().S; q.pop();
        if (visited[u][t]) continue;
        visited[u][t] = true;
        if (u == n && t >= l) {
            cout << dist[u][t];
            return;
        }
        for(auto &e : adj[u]) {
            int t1 = t | melon[e.F];
            if (dist[e.F][t1] > dist[u][t] + e.S) {
                dist[e.F][t1] = dist[u][t] + e.S;
                q.push(mp(-dist[e.F][t1], mp(e.F, t1)));
            }
        }
    }
    cout << -1;
}

void dotask3() {
    ll dist[n+5][1<<5]; memset(dist, 0x3f, sizeof dist);
    bool visited[n+5][1<<5]; memset(visited, 0, sizeof visited);
    dist[1][melon[1]] = 0;
    priority_queue<pair<ll, pair<int, int>>> q;
    q.push(mp(0, mp(1, melon[1])));
    while (!q.empty()) {
        int u, t; tie(u, t) = q.top().S; q.pop();
        if (visited[u][t]) continue;
        visited[u][t] = true;
        if (u == n && __builtin_popcount(t) >= l) {
            cout << dist[u][t];
            return;
        }
        for(auto &e : adj[u]) {
            int t1 = melon[e.F] | t;
            if (dist[e.F][t1] > dist[u][t] + e.S) {
                dist[e.F][t1] = dist[u][t] + e.S;
                q.push(mp(-dist[e.F][t1], mp(e.F, t1)));
            }
        }
    }
    cout << -1;
}

void Solve() {
    if (l == 0) dotask1();
    else if (k == 1) dotask2();
    else dotask3();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    Input();
    Solve();
    return 0;
}
