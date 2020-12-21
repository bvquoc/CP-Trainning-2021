#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int t[N], n, m, mx;
vector <int> l[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("COOLMAC.INP", "r", stdin);
	freopen("COOLMAC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		mx = max(mx, v);
		l[u].push_back(v);
	}
	priority_queue <int> pq;
	while (!pq.empty()) pq.pop();
	cin >> m;
	int mi = N;
	for (int i = 1; i <= m; ++i) {
		cin >> t[i];
		mi = min(mi, t[i]);
	}
	for (int i = 0; i <= mi; ++i) {
		for (int j : l[i]) pq.push(j);
	}
	int res = 0;
	while (mi <= (int)1e5) {
		if (pq.empty()) {
			cout << -1 << endl;
			return 0;
		}
		int u = pq.top();
		pq.pop();
		res++;
		if (u < mi) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = mi + 1; i <= u + 1; ++i) {
			for (int j : l[i]) pq.push(j);
		}
		mi = u + 1;
	}
	cout << res << endl;

	return 0;
}