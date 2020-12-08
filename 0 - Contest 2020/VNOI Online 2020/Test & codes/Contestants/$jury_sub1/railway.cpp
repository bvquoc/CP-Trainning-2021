#include <iostream> 
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <random>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

typedef pair<int , int> pt;
const long long INF = 1e18 + 123;
const int maxn = 300000 + 123;
int n, m;
std::vector<pt> V[maxn];
int start; 
int a[maxn];
map<pt, int> E;
int we[maxn];

void ReadData() {
	cin >> n >> m >> start;
	For(i, 1, n) cin >> a[i];
	For(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		V[u].push_back({v, w});
		we[i] = w;

		if (E.find({u, v}) == E.end()) {
			E[{u, v}] = i;
		} else {
			int j = E[{u, v}];
			if (we[j] > we[i]) E[{u, v}] = i;
		}
	}
}
long long best;
int ed;
long long d[maxn][2];
pt trace[maxn][2];
pair<long long, int> single[maxn];

void dijkstra(int cost) {
	Rep(i, maxn) Rep(j, 2) d[i][j] = INF;
	priority_queue<pair<long long, pt>> qu;

	d[start][0] = 0;
	qu.push({0, {start, 0}});

	while (sz(qu)) {
		auto x = qu.top(); qu.pop();
		long long current = x.first;
		int u = x.second.first, state = x.second.second;
		if (d[u][state] != -current) continue;

		if (!state && a[u] == cost) {
			if (d[u][1] > d[u][0] ) {
				d[u][1] = d[u][0] ;
				trace[u][1] = {u, 0};
				qu.push({-d[u][1], {u, 1}});
			}
		}

		for (auto nxt: V[u]) {
			int v = nxt.first, w = nxt.second;

			if (d[v][state] > d[u][state] + w) {
				d[v][state] = d[u][state] + w;
				trace[v][state] = pt(u, state);
				qu.push({-d[v][state], {v, state}});
			}
		}
	}

	For(i, 1, n) if (d[i][1] < INF) {
		single[i] = min(single[i], {d[i][1] + cost, cost});
	}
}

set<int> candidates;
void Process() {
	For(i, 1, n) {
		candidates.insert(a[i]);
		single[i] = {INF, 0};
	}

	for (auto c: candidates) {
		dijkstra(c);
	}

	best = -INF;
	int optCost;
	For(i, 1, n) {
		if (single[i].first < INF && best < single[i].first) {
			best = single[i].first;
			ed = i;
			optCost = single[i].second;
		}
	}
	dijkstra(optCost);
	vector<int> path(0);
	int current = ed, state = 1;
	path.push_back(current);
	//cout << "start is " << start << endl;
 	while (current != start || state != 0) {
		int p, q; tie(p, q) = trace[current][state];
		current = p, state = q; 
		if (current != path.back()) path.push_back(current);
	}

	cout << best << " " << ed << endl;
	cout << sz(path) - 1 << endl;
	reverse(path.begin(), path.end());

	//for (auto x: path) cout << x << " "; cout << endl;

	if (sz(path) >= 2) {
		for (int i = 0; i + 1 < sz(path); i++) {
			cout << E[{path[i], path[i + 1]}] << " ";
		} 
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#if ONLINE_JUDGE || THEMIS
    	freopen("railway.inp", "r", stdin);
    	freopen("railway.out", "w", stdout); 
	#else
    	freopen("input.txt", "r", stdin);
    	//freopen("local.out", "w", stdout);
	#endif


	ReadData();
	Process();

	return 0;

}
