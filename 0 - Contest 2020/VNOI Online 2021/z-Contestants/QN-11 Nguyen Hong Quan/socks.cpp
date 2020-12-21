#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

const ll nmax = 500001;

ll n, q, res;
ll red[nmax];
vll ct[nmax];

void sub1() {
	ll suze = 0;

	for (ll i = 1; i <= n; ++ i)
		suze += red[i];

	if (suze > 0)
		cout << 1;
	else
		cout << 0;

	cout << "\n";

	for (; q-- > 0;) {
		ll u;
		cin >> u;

		if (red[u])
			-- suze;
		else
			++ suze;

		red[u] ^= 1;

		if (suze > 0)
			cout << 1;
		else
			cout << 0;

		cout << "\n";
	}
}

ll col_s2[nmax];

void dfs_create_branch (ll u, ll papa, ll color) {
	col_s2[u] = color;

	if (ct[u].size() == 3) {
		for (ll i = 0; i < ct[u].size(); ++ i) {
			ll v = ct[u][i];
			dfs_create_branch (v, u, i + 1);
		}

		return ;
	}

	for (auto v : ct[u]) {
		if (v == papa)
			continue;

		dfs_create_branch (v, u, color);
	}
}

void sub2 (ll root) {
	ll c[4] = {0, 0, 0, 0};
	dfs_create_branch (root, root, 0);
	ll ht = 0;

	for (ll i = 1; i <= n; ++ i)
		c[col_s2[i]] += red[i];

	for (ll i = 1; i <= 3; ++ i)
		ht += c[i] > 0;

	if (!ht && c[0])
		res = 1;
	else
		res = ht / 2;

	cout << res << "\n";

	for (; q-- > 0;) {
		ll u;
		cin >> u;

		if (red[u]) {
			-- c[col_s2[u]];

			if (u != root && c[col_s2[u]] == 0)
				-- ht;
		} else {
			if (u != root && c[col_s2[u]] == 0)
				++ ht;

			++ c[col_s2[u]];
		}

		if (!ht && c[0])
			res = 1;
		else
			res = (ht + 1) / 2;

		cout << res << "\n";
		red[u] ^= 1;
	}
}

pair<ll, bool> dfs (ll u, ll papa) {
	bool leaf = true;
	ll ans = 0;
	ll dd = 0;
	for (auto v : ct[u]) {
		if (v == papa)
			continue;
		auto temp = dfs(v, u);
		ans += temp.first;
		dd += temp.second;
		leaf = false;
	}
	if (leaf)
		return {0, red[u]};
	ans += dd / 2;
	dd %= 2;
	if (red[u]) {
        if (dd > 0) return {ans, dd};
		else return {ans, dd + 1};
	}

	return {ans, dd};
}

void printres() {
	auto temp = dfs(1, 1);
	cout << temp.first + temp.second << "\n";
}

int main() {
	if (fopen ("socks.inp", "r")) {
		freopen ("socks.inp", "r", stdin);
		freopen ("socks.out", "w", stdout);
	}

	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	cin >> n >> q;

	for (ll i = 1; i <= n; ++ i)
		cin >> red[i];

	for (ll i = 1; i <= n - 1; ++ i) {
		ll u, v;
		cin >> u >> v;
		ct[u].push_back (v);
		ct[v].push_back (u);
	}

	bool request_s1 = true;
	bool request_s2 = true;
	ll sz3 = -1;

	for (ll u = 1; u <= n; ++ u) {
		if (ct[u].size() > 2)
			request_s1 = false;

		if (ct[u].size() == 3) {
			if (sz3 != -1)
				request_s2 = false;

			sz3 = u;
		} else if (ct[u].size() > 3)
			request_s2 = false;
	}

	if (request_s1) {
		sub1();
		return 0;
	}

	if (request_s2) {
		sub2 (sz3);
		return 0;
	}

	printres();

	for (; q -- > 0;) {
		ll u;
		cin >> u;
		red[u] ^= 1;
		printres();
	}

	return 0;
}
