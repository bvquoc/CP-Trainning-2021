#include<bits/stdc++.h>
using namespace std;

const int oo = 1e9;
const int maxN = 5005;
int n, k;
int cost[maxN], qty[maxN];

vector<int> adj[maxN];
struct TState {
	int pos, rem, weight;
	TState (int pos = 0, int rem = 0, int weight = 0) :
		pos(pos), rem(rem), weight(weight) {
		}
	bool operator< (const TState& other) const {
		return weight > other.weight;
	}
};

int find_shortest_path(int s, int t) {
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) dp[i][j] = oo;
	dp[s][0] = 0;
	priority_queue<TState> heap;
	heap.push(TState(s, 0, 0));
	while (heap.size()) {
		TState cur = heap.top();
		heap.pop();
		if (cur.weight != dp[cur.pos][cur.rem]) continue;
		if (cur.rem > 0) 
			for (int nxt : adj[cur.pos]) {
				if (cur.weight < dp[nxt][cur.rem - 1]) {
					dp[nxt][cur.rem - 1] = cur.weight;
					heap.push(TState(nxt, cur.rem - 1, cur.weight));
				}
			}
		int relax = cur.weight + cost[cur.pos];
		if (relax < dp[cur.pos][qty[cur.pos]]) {
			dp[cur.pos][qty[cur.pos]] = relax;
			heap.push(TState(cur.pos, qty[cur.pos], relax));
		}
	}
	int answer = oo;
	for (int r = 0; r <= n; r++) answer = min(answer, dp[t][r]);
	return answer;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> cost[i] >> qty[i];
	for (int i, j; k --> 0;) {
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	cout << find_shortest_path(1, n);
}
