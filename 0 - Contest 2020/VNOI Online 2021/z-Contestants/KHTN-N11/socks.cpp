#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, q; 
vector<int> adj[500005]; 

bool col[500005]; 

void Subtask1() {
	int red = 0; 
	for(int i = 1; i <= n; i++) {
		red += col[i]; 
	}
	cout << (red <= 1 ? 0 : 1) << '\n'; 
	for(int i = 1; i <= q; i++) {
		int u; 
		cin >> u; 
		if(col[u]) red--; 
		else red++; 
		col[u] ^= 1; 
		cout << (red <= 1 ? 0 : 1) << '\n'; 
	}
}

int type[500005], root; 
int cnt[5]; 

void dfs(int u, int color) {
	type[u] = color; 
	for(auto v : adj[u]) {
		if(!type[v]) dfs(v, color); 
	}
}

int get() {
	if(cnt[1] + cnt[2] + cnt[3] + col[root] < 2) return 0; 
	if(!cnt[1] or !cnt[2] or !cnt[3]) return 1; 
	return 2; 
}

void Subtask2() {
	root = 1; 
	for(int i = 1; i <= n; i++) {
		if((int)adj[i].size() == 3) {
			root = i; 
			break; 
		}
	}
	type[root] = 4; 
	for(int i = 0; i < 3; i++) {
		dfs(adj[root][i], i + 1); 
	}
	for(int i = 1; i <= n; i++) {
		if(i != root) {
			cnt[type[i]] += col[i];  	
		}
	}
	cout << get() << '\n'; 
	for(int i = 1; i <= q; i++) {
		int u; 
		cin >> u; 
		if(col[u]) cnt[type[u]]--; 
		else cnt[type[u]]++; 
		col[u] ^= 1; 
		cout << get() << '\n'; 
	}
}

int dp[500005];
bool subtree[500005]; 

void dfs_dp(int u, int p) {
	if(col[u]) {
		subtree[u] = true; 
	}
	int sum = 0; 
	for(auto v : adj[u]) {
		if(v != p) {
			dfs_dp(v, u); 
			if(subtree[v]) {
				subtree[u] = true; 
				sum++; 
				dp[u] += dp[v]; 
			}
		}
	}
	dp[u] += sum / 2; 
}

int Cal_dp() {
	int tot = 0; 
	for(int i = 1; i <= n; i++) {
		dp[i] = 0; 
		subtree[i] = false; 
		tot += col[i]; 
	}
	dfs_dp(1, 1); 
	int sum = 0; 
	for(auto v : adj[1]) {
		sum += subtree[v]; 
	}
	return min(dp[1] + (sum % 2 == 1 and tot > 1), (tot + 1) / 2); /// this dp wrong af but who cares
}

void Subtask3() {
	cout << Cal_dp() << '\n'; 
	for(int i = 1; i <= q; i++) {
		int u; cin >> u; 
		col[u] ^= 1; 
		cout << Cal_dp() << '\n'; 
	}
}

signed main() {	
	freopen("socks.inp", "r", stdin); 
	freopen("socks.out", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> q; 
	for(int i = 1; i <= n; i++) {
		cin >> col[i]; 
	}
	for(int i = 1; i < n; i++) {
		int u, v; 
		cin >> u >> v; 
		adj[u].pb(v); 
		adj[v].pb(u); 
	}
	int mxdeg = 0; 
	for(int i = 1; i <= n; i++) {
		mxdeg = max(mxdeg, (int)adj[i].size()); 
	}
	if(mxdeg <= 2) Subtask1(); 
	else if(mxdeg == 3) Subtask2(); 
	else {
		Subtask3(); 
	}
}
