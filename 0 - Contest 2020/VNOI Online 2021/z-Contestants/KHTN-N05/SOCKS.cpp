#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500005;

int n, q;
int color[N];
vector<int> adj[N];
int now, tin[N], tout[N];
int h[N], par[N][20];
set<pair<int, int> > s;

void dfs(int u, int p) {
	tin[u] = ++now;
	for (int v : adj[u]) {
		if (v != p) {
			h[v] = h[u] + 1;
			par[v][0] = u;
			dfs(v, u);
		}
	}
	tout[u] = now;
}
int findLCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    } else {
        for (int i = 19; i >= 0; i--) {
            if (par[u][i] != -1 && par[v][i] != -1 && par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
}
bool inTree(int u, int v) {
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}
int checkRoot() {
	if (s.size() <= 1) return 0;
	auto it = s.begin();
	auto it1 = s.end(); it1--;
	auto it0 = it; it0++;
	int u1 = it -> second, u2 = it1 -> second, u3 = it0 -> second;
	if (findLCA(u1, u2) == u1 && findLCA(u3, u2) != u1) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SOCKS.inp", "r", stdin);
	freopen("SOCKS.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> color[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 19; j++) {
			par[i][j] = -1;
		}
	}
	dfs(1, 1);
	for (int j = 1; j <= 19; j++) {
		for (int i = 1; i <= n; i++) {
			if (par[i][j - 1] != -1) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
	}
	
	int cntLeaf = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) continue;
		pair<int, int> tmp = {tin[i], i};
		s.insert(tmp);
		if ((int)s.size() > 1) {
			auto it = s.find(tmp);
			auto it0 = it, it1 = it;
			it1++;
			if (it0 == s.begin()) {
				if (it1 != s.end()) {
					int u = it1 -> second;
					if (tin[i] <= tin[u] && tout[u] <= tout[i]) {
						cntLeaf = cntLeaf;
					} else {
						cntLeaf++;
					}
				}
			} else {
				it0--;
				int u = it0 -> second;
				if (it1 != s.end()) {
					int v = it1 -> second;
					if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
						cntLeaf = cntLeaf;
					} else {
						cntLeaf--;
					}
					if (tin[i] <= tin[v] && tout[v] <= tout[i]) {
						cntLeaf = cntLeaf;
					} else {
						cntLeaf++;
					}
				}
				if (tin[u] <= tin[i] && tout[i] <= tout[u]) {
					cntLeaf = cntLeaf;
				} else {
					cntLeaf++;
				}
			}
			if (it1 == s.end()) cntLeaf++;
		}
	}
	int hah = cntLeaf + checkRoot();
	cout << hah / 2 + hah % 2 << "\n";
	
	while (q--) {
		int i; cin >> i;
		if (color[i] == 0) {
			color[i] = 1;
			pair<int, int> tmp = {tin[i], i};
			s.insert(tmp);
			if ((int)s.size() > 1) {
				auto it = s.find(tmp);
				auto it0 = it, it1 = it;
				it1++;
				if (it0 == s.begin()) {
					if (it1 != s.end()) {
						int u = it1 -> second;
						if (tin[i] <= tin[u] && tout[u] <= tout[i]) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf++;
						}
					}
				} else {
					it0--;
					int u = it0 -> second;
					if (it1 != s.end()) {
						int v = it1 -> second;
						if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf--;
						}
						if (tin[i] <= tin[v] && tout[v] <= tout[i]) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf++;
						}
					}
					if (tin[u] <= tin[i] && tout[i] <= tout[u]) {
						cntLeaf = cntLeaf;
					} else {
						cntLeaf++;
					}
				}
				if (it1 == s.end()) cntLeaf++;
			}
		} else {
			color[i] = 0;
			pair<int, int> tmp = {tin[i], i};
			if ((int)s.size() > 1) {
				auto it = s.find(tmp);
				auto it0 = it, it1 = it;
				it1++;
				if (it0 == s.begin()) {
					if (it1 != s.end()) {
						int u = it1 -> second;
						if (inTree(i, u)) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf--;
						}
					}
				} else {
					it0--;
					int u = it0 -> second;
					if (it1 != s.end()) {
						int v = it1 -> second;
						if (inTree(i, v)) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf--;
						}
						if (inTree(u, v)) {
							cntLeaf = cntLeaf;
						} else {
							cntLeaf++;
						}
					}
					if (inTree(u, i)) {
						cntLeaf = cntLeaf;
					} else {
						cntLeaf--;
					}
				}
				if (it1 == s.end()) cntLeaf--;
			}
			s.erase(tmp);
		}		
		int hah = cntLeaf + checkRoot();
		cout << hah / 2 + hah % 2 << "\n";
	}
}
