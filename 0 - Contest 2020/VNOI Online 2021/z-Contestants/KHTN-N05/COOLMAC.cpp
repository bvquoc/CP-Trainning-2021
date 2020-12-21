#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200005;

int n, m;
int t[N];
int par[N][20];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("COOLMAC.inp", "r", stdin);
	freopen("COOLMAC.out", "w", stdout);
	
	cin >> m;
	for (int j = 0; j <= 18; j++) {
		for (int i = 0; i <= 1e5; i++) {
			par[i][j] = -1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		par[l][0] = max(par[l][0], r);
	}
	cin >> n;
	int pos = 1e9;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		pos = min(pos, t[i]);
	} 
	
	int Max = -1e9;
	for (int i = 0; i <= 1e5; i++) {
		Max = max(Max, par[i][0]);
		if (Max >= i) {
			par[i][0] = Max;
		} else {
			par[i][0] = -1;
		}
	}
	for (int j = 1; j <= 18; j++) {
		for (int i = 0; i <= 1e5; i++) {
			if (par[i][j - 1] != -1) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
	}
	
	int ans = 0;
	for (int j = 18; j >= 0; j--) {
		if (par[pos][j] != -1 && par[pos][j] < 1e5) {
			pos = par[pos][j];
			ans += (1 << j);
		}
	}
	if (par[pos][0] != -1 && par[pos][0] >= 1e5) {
		cout << ans + 1;
	} else {
		cout << -1;
	}
}
