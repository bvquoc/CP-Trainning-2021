#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll nmax = 500001;

ll n, m, k;
ll s[nmax];
vector<pll> some_trans;
pll evaluate() {
	ll l = 0, r = 0;
	ll l_res = 0, r_res = 0;
	ll ma = -1;
	bool on = false;

	for (ll i = 1; i <= n; ++ i) {
		if (s[i]) {
			if (on)
				r = i;
			else {
				l = i;
				r = i;
				on = true;
			}
		} else {
			if (!on)
				continue;

			if (r - l + 1 > ma) {
				l_res = l;
				r_res = r;
				ma = r - l + 1;
			}

			on = false;
		}
	}

	return {l_res, r_res};
}

void sub1() {
	pll res = evaluate();
	cout << res.first << " " << res.second << "\n";
	return ;
}

ll tree[nmax << 2];

void build (ll node, ll l, ll r) {
	if (l == r) {
		tree[node] = s[l];
		return;
	}

	ll mid = (l + r) >> 1;
	build (node * 2, l, mid);
	build (node * 2 + 1, mid + 1, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query (ll node, ll l, ll r, const ll& L, const ll& R) {
	if (R < l || r < L)
		return 0;

	if (L <= l && r <= R)
		return tree[node];

	ll mid = (l + r) >> 1;
	return
		query (node * 2, l, mid, L, R)
		+ query (node * 2 + 1, mid + 1, r, L, R);
}

ll check (ll mid) {
	for (ll i = 1; i <= n - mid + 1; ++ i) {
		//		ll temp = query (1, 1, n, i, i + mid - 1);
		if (query (1, 1, n, i, i + mid - 1) + k >= mid)
			return i;
	}

	return 0;
}

void sub2() {
	build (1, 1, n);
	ll l = 1, r = query (1, 1, n, 1, n) + k;
	ll res = 0;

	if (r >= n) {
		cout << 1 << " " << n;
		return;
	}

#define mid ((l + r) >> 1)

	while (l <= r) {
		if (check (mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

#undef mid
	ll real_res = check (res);
	cout << real_res << " " << real_res + res - 1;
}

struct state {
	bitset<2001> hello;
	bool operator< (const state& rhs) const {
		return hello.to_string() < rhs.hello.to_string();
	}
} st;

map<state, bool> visit;

void build_use_state (ll node, ll l, ll r, const state& ss) {
	if (l == r) {
		tree[node] = ss.hello[l];
		return;
	}

	ll mid = (l + r) >> 1;
	build_use_state (node * 2, l, mid, ss);
	build_use_state (node * 2 + 1, mid + 1, r, ss);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

bool compp (const pll& lhs, const pll& rhs) {
	if (lhs.second - lhs.first == rhs.second - rhs.first)
		return lhs.second < rhs.second;

	return lhs.second - lhs.second > rhs.second - rhs.first;
}

pll res_sub3 = {0, -1};

void make_eval (const state& sss) {
	build_use_state (1, 1, n, sss);
	ll l = 1, r = query (1, 1, n, 1, n) + k;
	ll res = 0;
#define mid ((l + r) >> 1)

	while (l <= r) {
		if (check (mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

#undef mid
	ll real_res = check (res);
	res_sub3 = min (res_sub3, pll (real_res, real_res + res - 1), compp);
//	cerr << tree[1] << " " << k << "\n";

	if (res_sub3 == pll (1, tree[1] + k)) {
		cout << 1 << " " <<  tree[1] + k;
		exit (0);
	}
}

void sub3() {
	make_eval (st);
	queue<state> qq;
	visit[st] = true;
	qq.emplace (st);

	while (!qq.empty()) {
		state now = qq.front();
		qq.pop();
		state __next = now;

		for (const auto psy : some_trans) {
			ll u = psy.first;
			ll v = psy.second;

			if (now.hello[u] != now.hello[v]) {
				assert (now.hello == __next.hello);
				__next.hello[u] = now.hello[v];
				__next.hello[v] = now.hello[u];

				if (visit.find (__next) != visit.end()) {
					__next.hello[u] = now.hello[u];
					__next.hello[v] = now.hello[v];
					continue;
				}

				make_eval (__next);
				qq.push (__next);
				visit[__next] = true;
				__next.hello[u] = now.hello[u];
				__next.hello[v] = now.hello[v];
			}
		}
	}

	cout << res_sub3.first << " " << res_sub3.second << "\n";
	return ;
}

int main() {
	if (fopen ("decor.inp", "r")) {
		freopen ("decor.inp", "r", stdin);
		freopen ("decor.out", "w", stdout);
	}

	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	cin >> n >> m >> k;
	bool nok = true;

	for (ll i = 1; i <= n; ++ i) {
		char temp;
		cin >> temp;
		s[i] = (temp == '1');
		st.hello[i] = s[i];

		if (s[i])
			nok = false;
	}

	for (ll i = 1; i <= m; ++ i) {
		ll u, v;
		cin >> u >> v;
		some_trans.emplace_back (u, v);
	}

	if (nok && k == 0) {
		cout << -1;
		return 0;
	}

	if (m == 0 && k == 0) {
		sub1();
		return 0;
	}

	if (m == 0) {
		sub2();
		return 0;
	}

	sub3();
	return 0;
}
