#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, k, mark[N], s[N], sz, tot[N], bel[N], cnt[N];
vector <int> adj[N], V;

void dfs(int u) {
	V.push_back(u);
	mark[u] = 1;
	for (int v : adj[u]) {
		if (mark[v]) continue;
		dfs(v);
	}
}

int check(int mid) {
	int light = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= mid; ++i) {
		light -= min(tot[bel[i]], cnt[bel[i]]);
		cnt[bel[i]]++;
		light += min(tot[bel[i]], cnt[bel[i]]);
	}
	if (light >= mid - k) return 1;
	for (int i = mid + 1; i <= n; ++i) {
		light -= min(tot[bel[i]], cnt[bel[i]]);
		cnt[bel[i]]++;
		light += min(tot[bel[i]], cnt[bel[i]]);
		light -= min(tot[bel[i]], cnt[bel[i]]);
		cnt[bel[i - mid]]--;
		light += min(tot[bel[i]], cnt[bel[i]]);
		if (light >= mid - k) return i - mid + 1;
	}
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DECOR.INP", "r", stdin);
	freopen("DECOR.OUT", "w", stdout);

	cin >> n >> m >> k;
	string S; cin >> S;
	for (int i = 1; i <= n; ++i) {
		if (S[i - 1] == '1') s[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		++sz;
		V.clear();
		dfs(i);
		for (int u : V) {
			tot[sz] += s[u];
			bel[u] = sz;
		}
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	if (ans == -1) {
		cout << -1 << endl;
		return 0;
	}
	cout << check(ans) << ' ' << check(ans) + ans - 1 << endl;

	return 0;
}