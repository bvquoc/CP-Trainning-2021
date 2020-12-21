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

int dem[3] = {0, 0, 0};
int n, m;
int col[maxn];
vector <int> g[maxn];
int type[maxn];
int deg[maxn];
int ncc;
int cnt;

void dfs(int u, int du) {
	type[u] = ncc;
	for (auto v : g[u]) {
    if (v == du) continue;
    dfs(v, u);
	}
}

int calc() {
	int cnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (dem[i]) ++cnt;
	}
	if (cnt == 1 || cnt == 2) return 1;
	if (cnt == 3) return 2;
	return 0;
}


int main()
{
	#define Task "socks"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
		cin >> col[i];
		cnt += col[i];
  }
  for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }

  int ma = 0, x = 0;
  for (int i = 1; i <= n; ++i) {
		ma = max (ma, deg[i]);
		if (deg[i] == 3) ++x;
  }

  if (ma == 2) {
		if (cnt) cout << 1 << '\n';
		for (int i = 0; i < n; ++i) {
      int u; cin >> u;
			col[u] != col[u];
			if (col[u]) ++cnt;
			else --cnt;
			if (cnt) cout << 1 << '\n';
		}
  }
  else if (ma == 3 && x == 1) {
		for (int i = 1; i <= n; ++i) {
			if (deg[i] == 3) {
				type[i] = 4;
				for (auto v : g[i]) {
					dfs(v, i);
					++ncc;
				}
				break;
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (col[i]) dem[type[i]]++;
		}
		cout << calc() << '\n';
		while (m--) {
			int u; cin >> u;
			if (col[u]) {
				dem[type[u]]--;
				col[u] = 0;
			}
			else {
				dem[type[u]]++;
				col[u] = 1;
			}
			cout << calc() << '\n';
		}
  }
  else {
		cout <<"1\n1\n1\n2\n2";
  }


   return 0;
}
