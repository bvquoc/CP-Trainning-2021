#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using piii = pair<ll, pair<int, int> >;

const int N = 200005;

int n, m, k, l;
int melon[N];
vector<pair<ll, ll> > adj[N];
ll dist[N][35];
priority_queue<piii, vector<piii>, greater<piii> > pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DHAKA.inp", "r", stdin);
	freopen("DHAKA.out", "w", stdout);
	
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; i++) {
		int s; cin >> s;
		for (int j = 1; j <= s; j++) {
			int x; cin >> x;
			x--; melon[i] |= (1 << x);
		}
	}
	for (int i = 1; i <= m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	for (int i = 1; i <= n; i++) {
		for (int mask = 0; mask < (1 << k); mask++) {
			dist[i][mask] = 1e18;
		}
	}
	
	dist[1][melon[1]] = 0;
	pq.push({0, {1, melon[1]}});
	while (!pq.empty()) {
		ll val = pq.top().first;
		int u = pq.top().second.first, mask = pq.top().second.second;
		pq.pop();
		if (val > dist[u][mask]) continue;
		for (auto e : adj[u]) {
			ll v = e.first, w = e.second;
			if (dist[u][mask] + w < dist[v][mask | melon[v]]) {
				dist[v][mask | melon[v]] = dist[u][mask] + w;
				pq.push({dist[v][mask | melon[v]], {v, (mask | melon[v])}});
			}
		}
	}
	
	ll ans = 1e18;
	for (int mask = 0; mask < (1 << k); mask++) {
		if (__builtin_popcountll(mask) >= l) {
			ans = min(ans, dist[n][mask]);
		}
	}
	
	if (ans == 1e18) {
		cout << -1;
	} else {
		cout << ans;
	}
}
