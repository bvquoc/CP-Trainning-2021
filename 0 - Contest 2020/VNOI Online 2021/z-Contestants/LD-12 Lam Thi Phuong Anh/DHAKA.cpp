#include<bits/stdc++.h>
#define int long long
using namespace std;
using ii = array<int, 2>;
const int Sz = 1e5 + 5;
int a[Sz];
vector<ii> G[Sz];
int n, m, k, l;
int dist[Sz][64];

int dij(int st){
	int res = 1e15;
	memset(dist, -1, sizeof dist);
	priority_queue<array<int, 3>> q;
	
	q.push({0, a[st], st});
	dist[st][a[st]] = 0;
	
	while(q.size()){
		
		int du, au, u;
		
		du = -q.top()[0];
		au = q.top()[1];
		u = q.top()[2];
		q.pop();

		if(du != dist[u][au]) continue;
		
		//cout << du << " " << au << " " << u << "\n";

		if(__builtin_popcount(au) >= l && u == n) res = min(res, du);

		for(ii i : G[u]){
			int v = i[0];
			int w = i[1];
			int &dv = dist[v][a[v] | au];
			if(dv == -1 || dv > du + w){
				dv = du + w;
				q.push({-dv, a[v] | au, v});
			}
		}
	}
	if(res < 1e14 + 1) return res;
	return -1;
}

int32_t main(){

	freopen("DHAKA.INP", "r", stdin);
	freopen("DHAKA.OUT", "w", stdout);

	cin >> n >> m >> k >> l;

	for(int i = 1; i <= n; i++){
		cin >> k;
		a[i] = 0;
		int x;
		while(k--){
			cin >> x;
			a[i] = a[i] * 2 + x;
		}
	}

	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	cout << dij(1) << "\n";

	return 0;
}