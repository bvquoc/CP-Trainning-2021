#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500005;

int n, m, k;
string s;
vector<int> adj[N];
vector<int> comp[N];
int nComp, idComp[N];
int cntOn[N], cntOff[N];
int ansL, ansR;

void dfs(int u) {
	idComp[u] = nComp;
	comp[nComp].push_back(u);
	for (int v : adj[u]) {
		if (idComp[v] == 0) dfs(v);
	}
}

bool check(int val) {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= nComp; i++) {
		cntOn[i] = cntOff[i] = 0;
		for (int u : comp[i]) {
			if (s[u] == '1' && (u < 1 || u > val)) cntOn[i]++;
			if (s[u] == '0' && u >= 1 && u <= val) cntOff[i]++;
		}
		sum += min(cntOn[i], cntOff[i]);
	}
	for (int i = 1; i <= val; i++) if (s[i] == '1') cnt++;
	
	bool ok = 0;
	for (int i = 1; i + val - 1 <= n; i++) {
		if (cnt + sum + k >= val) {
			ok = 1;
			ansL = i; ansR = i + val - 1;
			break;
		}
		if (i + val <= n) {
			if (s[i] == '1') {
				cnt--;
				int id = idComp[i];
				sum -= min(cntOn[id], cntOff[id]);
				cntOn[id]++;
				sum += min(cntOn[id], cntOff[id]);
			} else {
				int id = idComp[i];
				sum -= min(cntOn[id], cntOff[id]);
				cntOff[id]--;
				sum += min(cntOn[id], cntOff[id]);
			}
			if (s[i + val] == '1') {
				cnt++;
				int id = idComp[i + val];
				sum -= min(cntOn[id], cntOff[id]);
				cntOn[id]--;
				sum += min(cntOn[id], cntOff[id]);
			} else {
				int id = idComp[i + val];
				sum -= min(cntOn[id], cntOff[id]);
				cntOff[id]++;
				sum += min(cntOn[id], cntOff[id]);
			}
		}
	}
	
	return ok;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DECOR.inp", "r", stdin);
	freopen("DECOR.out", "w", stdout);
	
	cin >> n >> m >> k;
	cin >> s; s = " " + s;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (idComp[i] == 0) {
			nComp++; dfs(i);
		}
	}
	
	int L = 1, R = n;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			L = mid;
		} else {
			R = mid;
		}
	}
	if (check(R)) {
		cout << ansL << " " << ansR;
	} else {
		if (check(L)) {
			cout << ansL << " " << ansR;
		} else {
			cout << -1;
		}
	}
}
