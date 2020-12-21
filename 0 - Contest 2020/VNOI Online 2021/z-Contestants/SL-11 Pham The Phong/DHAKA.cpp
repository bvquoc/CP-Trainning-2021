#include <bits/stdc++.h>
#define maxn 100005
#define maxm 30005
#define fw(a, b, c) for (ll c = a; c <= b; c++)
#define bw(a, b, c) for (ll c = a; c >= b; c--)
#define fileIO(TASK)                  \
	freopen(TASK ".inp", "r", stdin); \
	freopen(TASK ".out", "w", stdout);
#define effective            \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define newbieCoder main()
#define timing cerr << "Executed in " << clock() * 1000 / CLOCKS_PER_SEC << " ms";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 1e9 + 7;

int n, m, k, l;
struct edge {
	int u, v, c;
} e[2 * maxn];
int head[maxn], link[2 * maxn];
vector<int> s[maxn];

namespace Dijkstra {
	struct label {
		int u;
		ll d;
	};
	struct cmp {
		bool operator() (label &a, label &b) {
			return a.d > b.d;
		}
	};
	typedef priority_queue<label, vector<label>, cmp> pQueue;
	ll d[maxn];
	bool vis[maxn];
	ll dijkstra(int s, int t) {
		fill_n(d, n + 1, oo);
		d[s] = 0;	
		memset(vis, 1, sizeof vis);
		pQueue q;
		q.push({s, 0});
		while (!q.empty()) {
			label u = q.top();
			q.pop();
			if (u.u == t)
				break;
			if (!vis[u.u]) continue;
			vis[u.u] = 0;
			for (int i = head[u.u]; i; i = link[i]) {
				int v = e[i].v, c = e[i].c;
				if (d[v] > d[u.u] + c) {
					d[v] = d[u.u] + c;
					q.push({v, d[v]});
				}
			}
		}
		return d[t];
	}
}

using namespace Dijkstra;

namespace sub2 {
	void solve() {
		cout << dijkstra(1, n);
	}
}

namespace sub3 {
	void solve() {
		ll res = oo;
		fw(1, n, i)
			if (s[i].size())
				res = min(res, dijkstra(1, i) + dijkstra(i, n));
		cout << res;
	}
}

newbieCoder {
	effective;
  	fileIO("DHAKA");
	cin >> n >> m >> k >> l;
	fw(1, n, i) {
		int sz;
		cin >> sz;
		s[i].resize(sz);
		fw(0, sz - 1, j)
			cin >> s[i][j];
	}
	fw(1, m, i) {
		int u, v, c;
		cin >> u >> v >> c;
		e[i] = {u, v, c};
		e[i + m] = {v, u, c};
	}
	memset(head, 0, sizeof head);
	fw(1, 2 * m, i) {
		link[i] = head[e[i].u];
		head[e[i].u] = i;
	}
	if (!l)
		sub2::solve();
	else if (k == 1)
		sub3::solve();
}