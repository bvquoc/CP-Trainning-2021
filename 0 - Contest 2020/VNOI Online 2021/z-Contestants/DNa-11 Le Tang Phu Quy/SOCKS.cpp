#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
const int MOD = 2004010501;//>2e9

#define task "SOCKS"
const int MAX = (int) 5e5 + 500;
int num_nodes, num_queries;
bool color[MAX]; int que[MAX];

vector<int> adj[MAX];

int root = 1;
int height[MAX], group[MAX], gr_counter = 0;
void dfs(int cur, int pa) {
	height[cur] = height[pa] + 1;
	if (pa == root) group[cur] = ++gr_counter;
	else group[cur] = group[pa]; //root ? IDFC  
	for (int nxt : adj[cur]) 
		if (!height[nxt] and nxt != pa) dfs(nxt, cur);
}

void Subtask1() {
	int cnt = 0;
	for (int u = 1; u <= num_nodes; u++) cnt += color[u];
	cout << (cnt > 1);
	for (int i = 1; i <= num_queries; i++) {
		if (color[que[i]]) --cnt; else ++cnt;
		color[que[i]] = !color[que[i]];
		cout << '\n' << (cnt > 1);
	}
}

int force_of[4] = {};
int num_active_groups() {
	return (force_of[1] > 0) + (force_of[2] > 0) + (force_of[3] > 0); 
}
void Subtask2() {
	int cnt = 0;
	
	for (int g = 1; g <= gr_counter; g++) force_of[g] = 0;
	for (int u = 1; u <= num_nodes; u++) if (color[u])
		++cnt, ++force_of[group[u]];
		
	int res = num_active_groups() - 1;
	if (!res) res = cnt > 1;
	cout << res;
	
	for (int i = 1; i <= num_queries; i++) {
		if (color[que[i]]) {
			--cnt; 
			--force_of[group[que[i]]];	
		}
		else {
			++cnt;
			++force_of[group[que[i]]];	
		}
		color[que[i]] = !color[que[i]];
		
		int res = num_active_groups() - 1;
		if (!res) res = cnt > 1;
		cout << '\n' << res;
	}
}

const int INF = 1e9;
int f[MAX][2];
void cal_dp(int u, int pa) {
	f[u][0] = 0, f[u][1] = 1;
	for (int v : adj[u]) if (v != pa) {
		cal_dp(v, u);
		int f0 = f[u][1] + f[v][1] - 1; //concatenate two ropes
		int careless_f0 = f[u][0] + min(f[v][0], f[v][1]);
		int f1 = min(f[u][1] + min(f[v][0], f[v][1]), f[u][0] + f[v][1]);
		//f[u][1] will ensure we solve the problem
		//how can we assure this with f[u][0] ? (this if-statement works?)
		if (!color[u] or careless_f0 > 0) f0 = min(f0, careless_f0);
		f[u][0] = f0, f[u][1] = f1;
	}
	if (!f[u][0] and color[u]) f[u][0] = INF; //nothing is free - said Joker
//	cerr << "Node " << u << ':' << f[u][0] << ',' << f[u][1] << ", misc. = " << color[u] << '\n';
}

void Subtask3() {
	int cnt = 0;
	for (int u = 1; u <= num_nodes; u++) cnt += color[u];

	cal_dp(root, 0);
	int res = min(f[root][0], f[root][1]);
	if (cnt <= 1) res = 0;
	cout << res;
	
	for (int i = 1; i <= num_queries; i++) {
		if (color[que[i]]) --cnt; else ++cnt;
		color[que[i]] = !color[que[i]];
		cal_dp(root, 0);
		int res = min(f[root][0], f[root][1]);
		if (cnt <= 1) res = 0;
		cout << '\n' << res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	cin >> num_nodes >> num_queries;
	for (int u = 1; u <= num_nodes; u++) cin >> color[u];
	
	for (int u, v, i = 1; i < num_nodes; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool is_line = true, is_T_shape = true;
	int cnt_deg_3 = 0;
	
	for (int u = 1; u <= num_nodes; u++) {
		int deg = (int) adj[u].size();
		is_line &= deg <= 2;
		is_T_shape &= deg <= 3;
		if (deg == 3) cnt_deg_3++, root = u;
	}
	is_T_shape &= cnt_deg_3 == 1;
	
//	cin >> num_queries;
	for (int i = 1; i <= num_queries; i++) cin >> que[i];
	
	dfs(root, 0);
	
	if (is_line) Subtask1(); else
	if (is_T_shape) Subtask2(); else
	Subtask3();
}

