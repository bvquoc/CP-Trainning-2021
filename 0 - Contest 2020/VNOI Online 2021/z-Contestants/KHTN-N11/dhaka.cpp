#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ii pair<int, int> 
#define iii pair<int, ii>
#define fi first
#define se second
using namespace std;

const int INF = 1e18; 
int n, m, k, l; 
vector<ii> adj[100005];  

int melon[100005]; 
priority_queue<iii, vector<iii>, greater<iii> > pq; 
int dis[100005][50]; 

signed main() {
	freopen("dhaka.inp", "r", stdin); 
	freopen("dhaka.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m >> k >> l; 
	for(int i = 1; i <= n; i++) {
		int s; cin >> s; 
		for(int j = 1; j <= s; j++) {
			int val; 
			cin >> val;
			melon[i] |= (1 << (val - 1));  
		}
	}
	for(int i = 1; i <= m; i++) {
		int u, v, w; 
		cin >> u >> v >> w; 
		adj[u].pb({v, w}); 
		adj[v].pb({u, w}); 
	}
	for(int i = 1; i <= n; i++) {
		for(int mask = 0; mask < (1 << k); mask++) {
			dis[i][mask] = INF; 
		}
	}
	dis[1][melon[1]] = 0; 
	pq.push({0, {1, melon[1]}}); 
	while(!pq.empty()) {
		iii T = pq.top(); 
		pq.pop(); 
		int d = T.fi, u = T.se.fi, mask = T.se.se; 
		if(d > dis[u][mask]) continue; 
		for(auto tmp : adj[u]) {
			int v = tmp.fi, w = tmp.se; 
			int mask_ = mask | melon[v]; 
			if(dis[v][mask_] > dis[u][mask] + w) {
				dis[v][mask_] = dis[u][mask] + w; 
				pq.push({dis[v][mask_], {v, mask_}}); 
			}
		}
	}
	int ans = INF; 
	for(int mask = 0; mask < (1 << k); mask++) {
		if(__builtin_popcount(mask) >= l and ans > dis[n][mask]) {
			ans = dis[n][mask]; 
		}
	}
	cout << (ans == INF ? -1 : ans); 
}