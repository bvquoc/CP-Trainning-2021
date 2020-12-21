#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
const int MOD = 2004010501;//>2e9

#define task "DECOR"
const int MAX = (int) 5e5 + 500;
int num_nodes, num_edges, num_fills;
bool color[MAX];
vector<int> adj[MAX];

void Subtask1() {
	int pref[num_nodes + 5] = {}, suff[num_nodes + 5] = {};
	int f_of[num_nodes + 5] = {};
	f_of[0] = pref[0] - 0;
	for (int i = 1; i <= num_nodes; i++) 
		pref[i] = pref[i - 1] + color[i],
		f_of[i] = pref[i] - i;
	for (int i = num_nodes; i >= 1; i--) suff[i] = max(suff[i + 1], f_of[i]);
	
	int _l = 0, _r = 0;
	for (int l = 0; l < num_nodes; l++) {
		int lo = l + 1, hi = num_nodes, ans = 0;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (f_of[mid] < f_of[l] - num_fills) hi = mid - 1;
			else ans = mid, lo = mid + 1;
		}
		if (ans > 0) if (ans - l > _r - _l) _l = l, _r = ans;
	}
	if (_r > 0) cout << _l + 1 << ' ' << _r;
	else cout << -1;
}

void Subtask3() {
	int group_of[num_nodes + 5] = {};
	int force_of[num_nodes + 5] = {};
	queue<int> bfs;
	for (int u = 1; u <= num_nodes; u++) if (!group_of[u]) {
		group_of[u] = u;
		bfs.push(u);
		while (bfs.size()) {
			int cur = bfs.front(); bfs.pop();
			force_of[group_of[cur]] += color[cur];
			for (int nxt : adj[cur]) if (!group_of[nxt]) {
				group_of[nxt] = group_of[cur];
				bfs.push(nxt);
			}
		}
	}
	
	int first_l[num_nodes + 5] = {};
	bool is_appearing[num_nodes + 5] = {};
	int remaining[num_nodes + 5] = {};
	
	for (int l = 1; l <= num_nodes; l++) {
		for (int i = 1; i <= num_nodes; i++) 
			is_appearing[i] = false, remaining[i] = 0;
	
		for (int lack = 0, r = l; r <= num_nodes; r++) {
			if (!is_appearing[group_of[r]]) {
				is_appearing[group_of[r]] = true;
				remaining[group_of[r]] += force_of[group_of[r]];
			}
			--remaining[group_of[r]]; //taking "r" to extend the segment
			if (remaining[group_of[r]] < 0) ++lack;
			
			if (lack <= num_fills) if (!first_l[r - l + 1])
				first_l[r - l + 1] = l;
		}
	}
	
	for (int len = num_nodes; len > 0; len--) if (first_l[len]) {
		cout << first_l[len] << ' ' << first_l[len] + len - 1;
		return ;
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	cin >> num_nodes >> num_edges >> num_fills;
	string Binary; cin >> Binary;
	int idx = 1; for (auto ch : Binary) color[idx++] = ch == '1';
	
	for (int u, v, i = 1; i <= num_edges; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if (num_edges == 0) Subtask1(); else
	Subtask3();
}
