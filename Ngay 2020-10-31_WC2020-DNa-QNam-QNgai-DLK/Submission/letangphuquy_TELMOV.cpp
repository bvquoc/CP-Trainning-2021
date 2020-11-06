#include<bits/stdc++.h>
using namespace std;

const int oo = 1e9;
const int maxN = 1e4 + 500;

struct TEdge {
	int to, weight = 0;
	TEdge (int to = 0, int weight = 0) : to(to), weight(weight) {
	}
};
vector<TEdge> adj[maxN];
int n, m, P, L, K;

struct TState {
	int id, tele, dist; //distance from last teleport requirement
	int weight;
	TState (int id = 0, int tele = 0, int dist = 0, int weight = 0) : 
		id(id), tele(tele), dist(dist), weight(weight) {
	}
	bool operator< (const TState& other) const {
		return weight > other.weight;
	}
	void debug() {
		cerr << "(" << id << "," << tele << "," << dist << ") : [" << weight << "]\n";
	}
};

int find_shortest_path(int s, int t) {
	int Min[maxN][K + 1][L + 2];
	for (int i = 1; i <= n; i++) 
		for (int k = 0; k <= K; k++) 
			for (int l = 0; l <= L + 1; l++) Min[i][k][l] = oo;
	Min[s][0][L + 1] = 0;
	priority_queue<TState> heap;
	heap.push(TState(s, 0, L + 1, 0));
	while (heap.size()) {
		TState cur = heap.top();
		heap.pop();
		if (Min[cur.id][cur.tele][cur.dist] != cur.weight) continue;
//		cur.debug();
		for (auto edge : adj[cur.id]) {
			//keep moving without teleporting
//			cerr << "HEY : " << cur.dist << " / " << L << "\n";
			if (cur.dist == L) continue; //must be teleported
			const int& nxt = edge.to;
			int relax = cur.weight + (cur.dist <= L ? 0 : edge.weight);
			int new_dist = cur.dist + (cur.dist < L);
			TState nxtState(nxt, cur.tele, new_dist, relax);
//			cerr << "go to : "; nxtState.debug();
			if (relax < Min[nxt][cur.tele][new_dist]) {
				Min[nxt][cur.tele][new_dist] = relax;
				heap.push(nxtState);
			}
		}
		//sending teleport requirement
		if (cur.dist == L + 1) {
			if (cur.weight < Min[cur.id][cur.tele][0]) {
				Min[cur.id][cur.tele][0] = cur.weight;
				heap.push(TState(cur.id, cur.tele, 0, cur.weight));
			}
		}
		//teleport to cur
		if (cur.dist <= L and cur.tele < K) {
			int relax = cur.weight + P;
			if (relax < Min[cur.id][cur.tele + 1][L + 1]) {
				Min[cur.id][cur.tele + 1][L + 1] = relax;
				heap.push(TState(cur.id, cur.tele + 1, L + 1, relax));
			}
		}
	}
	int ans = oo;
	for (int k = 0; k <= K; k++) ans = min(ans, Min[t][k][L + 1]); //finished all teleport
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> P >> L >> K;
	for (int x, y, t; m --> 0;) {
		cin >> x >> y >> t;
		adj[x].push_back(TEdge(y, t));
		adj[y].push_back(TEdge(x, t));
	}
	cout << find_shortest_path(1, n);
}
