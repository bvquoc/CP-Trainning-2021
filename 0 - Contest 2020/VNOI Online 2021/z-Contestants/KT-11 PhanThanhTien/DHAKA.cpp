#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;

#define PI (2*acos(0));
#define sqr(x) ((x) * (x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>void maximize(T &a, T b) {if (a < b) a = b;}
template<typename T>void minimize(T &a, T b) {if (a > b) a = b;}
template<typename T1, typename T2> T1 power(T1 a, T2 b) {if (b == 1) return a; T1 t = power(a, b / 2); return (b & 1 ? t * t * a : t * t);}


struct Node {
	int u, w, melon;
};

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, k, l;
vector<pair<int, int>> adj[N];
vector<int> melon[N];
vector<int> d(N), p(N);

namespace sub2{
	void Dijkstra(int s, int f) {
		d.assign(n + 1, INT_MAX);
		d[s] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> q;
		q.push({0, s});
	 
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
	 
			if (u == f) {cout << d[f]; return;}
	 
			for (pii edge : adj[u]) {
				int v = edge.first;
				int len = edge.second;
	 
				if (d[u] + len < d[v]) {
					d[v] = d[u] + len;
					q.push({d[v], v});
				}
			}
		}
		if (d[f] != INT_MAX) cout << -1;
		else cout << d[f];
	}
}

int main() {
	freopen("DHAKA.inp", "r", stdin);
	freopen("DHAKA.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t;
		for (int j = 1; j <= t; ++j) {
			int x; cin >> x;
			melon[i].push_back(x);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	if (l == 0) {sub2::Dijkstra(1, n); return 0;};	


	cout << -1;

	return 0;
} 