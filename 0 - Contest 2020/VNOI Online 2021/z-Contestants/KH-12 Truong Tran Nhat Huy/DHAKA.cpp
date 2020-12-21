#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 1e5 + 5, MASK = (1 << 5), oo = 1e18;
int n, msk[N], dist[N][MASK], m, k, l;
vector <ii> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DHAKA.INP", "r", stdin);
	freopen("DHAKA.OUT", "w", stdout);

	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; ++i) {
		int s;
		cin >> s;
		int cur = 0;
		while (s--) {
			int v;
			cin >> v;
			v--;
			cur |= (1 << v);
		}
		msk[i] = cur;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for (int i = 1; i <= n; ++i) {
		for (int msk = 0; msk < (1 << k); ++msk) {
			dist[i][msk] = oo;
		}
	}
	dist[1][msk[1]] = 0;
	priority_queue <iii, vector <iii>, greater <iii>> pq;
	while (!pq.empty()) pq.pop();
	pq.push({0, {1, msk[1]}});
	while (!pq.empty()) {
		iii D = pq.top(); pq.pop();
		int u = D.second.first, mask = D.second.second;
		if (D.first > dist[u][mask]) continue;
		for (ii vv : adj[u]) {
			int v = vv.first, w = vv.second, nmask = mask | msk[v];
			if (dist[u][mask] + w < dist[v][nmask]) {
				dist[v][nmask] = dist[u][mask] + w;
				pq.push({dist[v][nmask], {v, nmask}});
			}
		}
	}
	int res = oo;
	for (int i = 0; i < (1 << k); ++i) if (__builtin_popcount(i) >= l) {
		res = min(res, dist[n][i]);
	}
	if (res == oo) res = -1;
	cout << res << endl;

	return 0;
}