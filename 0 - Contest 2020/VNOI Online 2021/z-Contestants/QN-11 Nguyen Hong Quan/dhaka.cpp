#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll inf = 1000000000000000000;
const ll nmax = 100001;

struct Edge {
	ll to;
	ll cost;
	Edge (ll v, ll w) : to (v), cost (w) {};
};

struct Node {
	vector<ll> melons;
	vector<Edge> ct;
} node[nmax];

ll n, m, k, l;

ll dist_sub1[101][101];
void sub1() {
	for (ll i = 1; i <= n; ++ i) {
		for (ll j = i + 1; j <= n; ++ j)
			dist_sub1[i][j] = dist_sub1[j][i] = inf;
	}

	for (ll i = 1; i <= n; ++ i) {
		for (auto v : node[i].ct)
			dist_sub1[i][v.to] = min (dist_sub1[i][v.to], v.cost);
	}

	for (ll kk = 1; kk <= n; ++ kk) {
		for (ll i = 1; i <= n; ++ i) {
			for (ll j = 1; j <= n; ++ j)
				dist_sub1[i][j] = min (dist_sub1[i][j], dist_sub1[i][kk] + dist_sub1[j][kk]);
		}
	}

	set<ll> pre_com;

	for (auto v : node[1].melons)
		pre_com.insert (v);

	for (auto v : node[n].melons)
		pre_com.insert (v);

	ll res = inf;
	for (ll mask = 0; mask < (1 << (n - 2)); ++ mask) {
		set<ll> sll = pre_com;
		vector<ll> check = {1};

		for (ll j = 2; j < n; ++ j) {
			if ( (mask >> (j - 2)) & 1) {
				for (auto v : node[j].melons)
					sll.insert (v);

				check.push_back (j);
			}
		}

		check.push_back (n);

		if (sll.size() < l)
			continue;

		ll ans = 0;

		for (ll i = 1; i < check.size(); ++ i) {
			ans += dist_sub1[check[i - 1]][check[i]];
		}
		res = min(res, ans);
	}
	cout << (res == inf ? -1 : res);
	return;
}

ll dist_sub2[nmax];
void sub2() {
	priority_queue<pll, vector<pll>, greater<pll>> qq;

	for (ll i = 2; i <= n; ++ i)
		dist_sub2[i] = inf;

	qq.emplace (0, 1);

	while (!qq.empty()) {
		ll u = qq.top().second;
		ll du = qq.top().first;
		qq.pop();

		if (du != dist_sub2[u])
			continue;

		for (Edge f : node[u].ct) {
			ll to = f.to;
			ll cost = f.cost;

			if (dist_sub2[to] > du + cost) {
				dist_sub2[to] = du + cost;
				qq.emplace (dist_sub2[to], to);
			}
		}
	}

	cout << (dist_sub2[n] == inf ? -1 : dist_sub2[n]);
	return;
}

ll dist_sub3[2][nmax];
void sub3() {
	priority_queue<pll, vector<pll>, greater<pll>> qq;

	for (ll i = 2; i <= n; ++ i)
		dist_sub3[0][i] = inf;

	qq.emplace (0, 1);

	while (!qq.empty()) {
		ll u = qq.top().second;
		ll du = qq.top().first;
		qq.pop();

		if (du != dist_sub3[0][u])
			continue;

		for (Edge f : node[u].ct) {
			ll to = f.to;
			ll cost = f.cost;

			if (dist_sub3[0][to] > du + cost) {
				dist_sub3[0][to] = du + cost;
				qq.emplace (dist_sub3[0][to], to);
			}
		}
	}

	for (ll i = 1; i < n; ++ i)
		dist_sub3[1][i] = inf;

	qq.emplace (0, n);

	while (!qq.empty()) {
		ll u = qq.top().second;
		ll du = qq.top().first;
		qq.pop();

		if (du != dist_sub3[1][u])
			continue;

		for (Edge f : node[u].ct) {
			ll to = f.to;
			ll cost = f.cost;

			if (dist_sub3[1][to] > du + cost) {
				dist_sub3[1][to] = du + cost;
				qq.emplace (dist_sub3[1][to], to);
			}
		}
	}

	for (ll i = 1; i <= n; ++ i)
		cerr << dist_sub3[0][i] << " ";

	cerr << "\n";

	for (ll i = 1; i <= n; ++ i)
		cerr << dist_sub3[1][i] << " ";

	ll res = inf;

	for (ll i = 1; i <= n; ++ i) {
		if (node[i].melons.size())
			res = min (res, dist_sub3[0][i] + dist_sub3[1][i]);
	}

	cout << res;
}

int main() {
	if (fopen ("dhaka.inp", "r")) {
		freopen ("dhaka.inp", "r", stdin);
		freopen ("dhaka.out", "w", stdout);
	}

	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	cin >> n >> m >> k >> l;
	set<ll> sll;

	for (ll i = 1; i <= n; ++ i) {
		ll t;
		cin >> t;

		for (; t -- > 0;) {
			ll temp;
			cin >> temp;
			sll.insert (temp);
			node[i].melons.push_back (temp);
		}
	}

	for (ll i = 1; i <= m; ++ i) {
		ll u, v, w;
		cin >> u >> v >> w;
		node[u].ct.emplace_back (v, w);
		node[v].ct.emplace_back (u, w);
	}

	if (sll.size() < l) {
		cout << -1;
		return 0;
	}

	if (n <= 10) {
		sub1();
		return 0;
	}

	if (l == 0) {
		sub2();
		return 0;
	}

	if (l == 1) {
		sub3();
		return 0;
	}

	return 0;
}
