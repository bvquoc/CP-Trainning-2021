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
#include <bits/stdc++.h>

int n;
int a[5011], nChild[5011];
int f[5011][5011]; // f[u][k] la so thao tac it nhat khi xet rieng cay con nut u va bien a[u] = k
int g[5001][5011]; // g[sub][k] la so thao tac it nhat khi xet qua sub nhanh cua cay con nut u (dang xet) va tong cua cac nut = k

vector<int> adj[5011];

void dfs(int u, int p) {
	nChild[u] = 1;
	if (adj[u].size() == 1 && u != 1) {
		f[u][0] = abs(a[u]);
		f[u][1] = abs(a[u] - 1);
		return;
	}

	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);    	
			nChild[u] += nChild[v];
		}
	
    FOR(i,0,5010) f[u][i] = 1e9;

	int id = 0;
    FOR(i,0,adj[u].size()-1)
        FOR(j,0,5010) g[i][j] = 1e9;
					
	g[0][0] = 0;

	int best = 0;
	for (int v : adj[u])
		if (v != p) {
			id++;
            FOR(i,0,best)
				for (int add = 0; add <= nChild[v]; add++)
					g[id][i + add] = min(g[id][i + add], g[id - 1][i] + f[v][add]);	
			best += nChild[v];
		}			
	FOR(i,0,5010)
		f[u][i] = g[id][i] + abs(a[u] - i);       
}

signed main() {
    FastIO;
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
	cin >> n; 
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (n == 1) return cout << min(abs(a[1]), abs(a[1] - 1)), 0;
	
    dfs(1, -1);
	int ans = 1e9;
	FOR(i,0,5010)
		ans = min(ans, f[1][i]);
    
	cout << ans;
    return 0;
}