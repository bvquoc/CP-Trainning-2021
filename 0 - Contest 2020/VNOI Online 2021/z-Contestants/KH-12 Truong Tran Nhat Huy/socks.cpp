#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SOCKS.INP", "r", stdin);
	freopen("SOCKS.OUT", "w", stdout);

	int n, q;
	cin >> n >> q;
	set <int> S; S.clear();
	for (int i = 1; i <= n; ++i) {
		int j;
		cin >> j;
		if (j) S.insert(i);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
	}
	cout << (S.size() >= 2 ? 2 : (S.size() == 1 ? 1 : 0)) << endl;
	for (int i = 1; i <= q; ++i) {
		int v;
		cin >> v;
		if (S.find(v) == S.end())
			S.insert(v);
		else S.erase(v);
		cout << (S.size() >= 2 ? 2 : (S.size() == 1 ? 1 : 0)) << endl;
	}

	return 0;
}