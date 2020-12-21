///link:
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ll long long
const int maxn = 1 + 1e6;
const ll mod = 1e9 + 7;
const int inf = (1 << 30);

int n, m, k;

namespace sub1 {

vector <int> vt;
int cnt = 1;
int ans = 0;
int ansl, ansr, l, r;

void run() {
  for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		vt.push_back(c - '0');
  }
  for (int i = 0; i <  n; ++i) {
    if (vt[i] == vt[i + 1]) {
			++cnt;
			r = i + 1;
    }
    else {
			if (vt[i] == 1) {
				if (ans < cnt) {
					ans = cnt;
					ansl = l, ansr = r;
				}
			}
			l = i + 1;
			r = i + 1;
			cnt = 1;
    }
  }
  cout << ansl + 1 << " " << ansr + 1 << '\n';
}

}

namespace sub2 {

vector <int> vt;
int ans = 0;
int f[maxn];
int ansl;

bool check(int len) {
	for (int i = 1; i <= n - len + 1; ++i) {
    if (f[i + len - 1] - f[i - 1] + k >= len) {
			return i;
    }
	}
	return 0;
}

void run() {
	vt.push_back(-1);
  for (int i = 1; i <= n; ++i) {
		char c; cin >> c;
		vt.push_back(c - '0');
    f[i] = f[i - 1] + vt[i];
  }
  int l = 0, r = n;
	while (l <= r) {
    #define mid (l + r) / 2
    int v = check(mid);
    if (v) {
			ans = mid;
			ansl = v;
			l = mid + 1;
    }
    else {
			r = mid - 1;
    }
	}
	cout << ansl << " " << ansl + ans - 1 << '\n';
}

}

namespace sub3 {

vector <int> vt;
int ansl[maxn], ansr[maxn];
int ncc = 0;
vector <int> g[maxn], tplt[maxn];
int del[maxn];
int id[maxn];
int L = -1, R = -1;

void dfs(int u) {
	id[u] = ncc;
	for (auto v : g[u]) {
		if (id[v]) continue;
		dfs(v);
	}
}

void update(int l, int r) {
  if (L == -1) {
		L = l, R = r;
		return ;
  }
  #define len (r - l + 1)
  if (R - L + 1 < len) {
		L = l, R = r;
		return ;
  }
  if (R - L + 1 == len) {
		if (L > l) {
			L = l, R = r;
			return ;
		}
  }
}

void run() {
	vt.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		char c; cin >> c;
		vt[i] = c - '0';
		id[i] = 0; del[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
	}

	for (int u = 1; u <= n; ++u) {
		if (!id[u]) {
			++ncc;
			dfs(u);
		}
	}

	for (int u = 1; u <= n; ++u) {
		tplt[id[u]].push_back(u);
		del[id[u]] += vt[u];
	}

	for (int i = 1; i <= ncc; ++i) {
		ansl[i] = ansr[i] = -1;
	}

	for (int l = 1; l <= n; ++l) {
		int ret = 0;
		for (int r = l; r <= n; ++r) {
			int i = id[r];
			int p = lower_bound(all(tplt[i]), r) - tplt[i].begin();
			if (ansl[i] == -1) {
				ret += min(del[i], 1);
				ansl[i] = p;
				ansr[i] = p;
			}
			else {
				ret -= min (del[i], ansr[i] - ansl[i] + 1);
				ansr[i] = p;
				ret += min (del[i], ansr[i] - ansl[i] + 1);
			}
			if (ret + k >= r - l + 1) {
				#define len (r - l + 1)
				if (L == -1) {
					L = l, R = r;
				}
				else if (R - L + 1 < len) {
					L = l, R = r;
				}
				else if (R - L + 1 == len) {
					if (L > l) {
						L = l, R = r;
					}
				}
				#undef len
			}
		}
		for (int i = 1; i <= ncc; ++i) {
			ansl[i] = ansr[i] = -1;
		}
	}

	if (L == -1) cout << -1 << '\n';
	else cout << L << " " << R << '\n';
}

}
int main()
{
	#define Task "decor"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n >> m >> k;
	if (m == 0 && k == 0) {
		sub1::run();
	}
	else if (m == 0) {
		sub2::run();
	}
	else {
		sub3::run();
	}

   return 0;
}
