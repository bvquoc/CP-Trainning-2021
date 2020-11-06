#include<bits/stdc++.h>
using namespace std;

const int maxN = 1005;

int vis[maxN], ppl;
int n, match[maxN], pr[maxN][maxN];
bool dfs(int u, const int& lim) {
	if (vis[u] == ppl) return false;
	vis[u] = ppl;
	for (int v = 1; v <= n; v++) if (pr[u][v] >= lim)
		if (!match[v] or dfs(match[v], lim)) {
			match[v] = u;
			return true;
		}
	return false;
}

bool isMatchable(const int& lim) {
	fill(vis, vis + 1 + n, 0);
	fill(match, match + 1 + n, 0);
	::ppl = 0;
	vector<int> order(n);
	iota(order.begin(), order.end(), 1);
	random_shuffle(order.begin(), order.end());
	int cntPairs = 0;
	for (int u : order) {
		++ppl;
		cntPairs += dfs(u, lim);
	}
	return (cntPairs == n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) cin >> pr[i][j];
	int lo = 1, hi = 1e9, ans = -1;
	while (lo <= hi) {
		int mid = lo + hi >> 1;
		if (!isMatchable(mid)) hi = mid - 1;
		else ans = mid, lo = mid + 1;
	}	
	cout << ans;
}
