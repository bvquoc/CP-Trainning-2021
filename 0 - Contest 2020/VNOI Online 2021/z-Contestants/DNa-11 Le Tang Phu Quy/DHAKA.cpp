#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
const int MOD = 2004010501;//>2e9

#define task "DHAKA"
const Int oo = 1e18;
const int MAX = (int) 1e5 + 100;

int num_nodes, num_edges, num_types, req;
int fruit[MAX];

struct Arc {
	int to; Int weight;
	Arc(int to, Int weight) : to(to), weight(weight) {
	}
};
vector<Arc> adj[MAX];

namespace naive_dijkstra {
	struct State {
		Int weight; int pos;
		State(Int weight, int pos) : weight(weight), pos(pos) {
		}
		bool operator < (const State& other) const {
			return other.weight < weight;
		}
	};
	
	Int find_shortest_path(int sta, int fin) {
		vector<Int> dist(num_nodes + 1, oo);
		
		dist[sta] = 0;
		priority_queue<State> heap;
		heap.push(State(0, sta));
		
		while (heap.size()) {
			State cur = heap.top(); heap.pop();
			if (cur.weight != dist[cur.pos]) continue;
			
			for (auto arc : adj[cur.pos]) {
				Int relax = cur.weight + arc.weight;
				if (relax < dist[arc.to]) {
					dist[arc.to] = relax;
					heap.push(State(relax, arc.to));		
				}
			}
		}
		
		return dist[fin];
	}
}

namespace advanced_dijkstra {
	struct State {
		Int weight; int pos, msk;
		State(Int weight, int pos, int msk) : weight(weight), pos(pos), msk(msk) {
		}
		bool operator < (const State& other) const {
			return other.weight < weight;
		}
	};
	
	Int find_shortest_path(int sta, int fin) {
		Int dist[num_nodes + 1][1 << num_types];
		for (int u = 0; u <= num_nodes; u++)
			for (int msk = 0; msk < (1 << num_types); msk++) dist[u][msk] = oo;
		
		dist[sta][fruit[sta]] = 0;
		priority_queue<State> heap;
		heap.push(State(0, sta, fruit[sta]));
		
		while (heap.size()) {
			State cur = heap.top(); heap.pop();
			if (cur.weight != dist[cur.pos][cur.msk]) continue;
			
			for (auto arc : adj[cur.pos]) {
				Int relax = cur.weight + arc.weight;
				State nxt = State(relax, arc.to, cur.msk | fruit[arc.to]);
				
				if (relax < dist[nxt.pos][nxt.msk]) {
					dist[nxt.pos][nxt.msk] = relax;
					heap.push(nxt);		
				}
			}
		}
		
		Int res = oo;
		for (int msk = 0; msk < (1 << num_types); msk++) 
			if (__builtin_popcount(msk) >= req) res = min(res, dist[fin][msk]);
		return res;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	cin >> num_nodes >> num_edges >> num_types >> req;
	for (int i = 1; i <= num_nodes; i++) {
		bool sell[5] = {};
		int qty; cin >> qty;
		for (int a; qty --> 0; ) cin >> a, sell[--a] = true;
		fruit[i] = 0;
		for (int a = 0; a < num_types; a++) fruit[i] = 2 * fruit[i] + sell[a];
	}
	
	for (int u,v,w, i = 1; i <= num_edges; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(Arc(v, w));
		adj[v].push_back(Arc(u, w));
	}
	
//	cerr << "Finished input\n";
	if (req > 0) {
		Int dist = advanced_dijkstra :: find_shortest_path(1, num_nodes);
		if (dist == oo) cout << -1; else cout << dist;
	}
	else {
		Int dist = naive_dijkstra :: find_shortest_path(1, num_nodes);
		if (dist == oo) cout << -1; else cout << dist;
	}
}
