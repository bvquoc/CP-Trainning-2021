#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

const int N = 1e5 + 5;

int n, m, k, l, mndist[N][32], node_mask[N];
vector<ii> Adj[N];
priority_queue<iii, vector<iii>> pq;

void dijik(){
	pq.push({{0, 0}, 0});
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 32; j++) mndist[i][j] = oo;
	}
	while(!pq.empty()){
		int dist = pq.top().fi.fi, u = pq.top().fi.se, mask = pq.top().se;
		//cout << dist << " " << u << " " << mask << "\n";
		pq.pop();
		if(dist != mndist[u][mask]) continue;
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i].fi, w = Adj[u][i].se;
			if(mndist[v][mask | node_mask[v]] > mndist[u][mask] + w){
				mndist[v][mask | node_mask[v]] = mndist[u][mask] + w;
				pq.push({{mndist[v][mask | node_mask[v]], v}, mask | node_mask[v]});
			}
		}
	}
}

signed main(){
	freopen("DHAKA.inp", "r", stdin);
	freopen("DHAKA.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k >> l;
	for(int i = 1; i <= n; i++){
		int avai;
		cin >> avai;
		for(int j = 1; j <= avai; j++){
			int x;
			cin >> x;
			x--;
			node_mask[i] |= (1 << x);
		}
		//cout << i << " " << node_mask[i] << "\n";
	}
	Adj[0].pb({1, 0});
	Adj[1].pb({0, 0});
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Adj[u].pb({v, w});
		Adj[v].pb({u, w});
	}
	dijik();
	int mini = oo;
	for(int i = 0; i < 32; i++){
		if(__builtin_popcountll(i) >= l) mini = min(mini, mndist[n][i]);
	}
	cout << (mini == oo ? -1 : mini);
}


