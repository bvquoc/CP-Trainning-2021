#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 5003;
int n, a[N];
vector <int> adj[N], child[N];
int f[N][N];

void dfs(int u, int p) {
	for (int v: adj[u]) if (v != p) {
		child[u].push_back(v);
		dfs(v,u);
	}
}

#define isLeaf(x) (child[x].empty())
int dp(int u, int sum) {
	if (f[u][sum] != -1) return f[u][sum];
	int cur_cost = abs(a[u]-sum);
	if (isLeaf(u)) {
		if (sum > 1 || sum < 0) return INT_MAX;
		return cur_cost;
	}
	if (child[u].size() == 1) return f[u][sum] = cur_cost + dp(child[u][0],sum);
	
	int cur = LLONG_MAX;
	int v1 = child[u][0], v2 = child[u][1];
	FOR(s, 0, sum) cur = min(cur, cur_cost+dp(v1,s)+dp(v2,sum-s));
	return f[u][sum] = cur;
}

signed main() {
    FastIO;
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
	cin >> n; 
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n-1) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,-1);
	memset(f, -1, sizeof(f));
    int ans = LLONG_MAX;
	FOR(i,0,n) ans = min(ans,dp(1,i));
	cout << ans;
    return 0;
}