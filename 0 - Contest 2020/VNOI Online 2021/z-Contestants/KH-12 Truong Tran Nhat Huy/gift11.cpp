#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, MOD = 998244353;
int n, a[N], dp[N][N][11], fac[N], f[N][N][11], C[N][N];
vector <int> odd, even;

int num(int b) {
	int ret = 0;
	vector <int> dig; dig.clear();
	while (b) {
		dig.push_back(b % 10);
		b /= 10;
	}
	reverse(dig.begin(), dig.end());
	int v = 1;
	for (int d : dig) {
		ret += d * v;
		v *= -1;
	}
	ret = (ret + 11 * 100) % 11;
	return ret;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void mul(int &a, int b) {
	a = a * b % MOD;
}

void init() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int rem = 0; rem < 11; ++rem) {
				dp[i][j][rem] = 0;
				f[i][j][rem] = 0;
			}
		}
	}
	odd.clear(); even.clear();
}

void solve() {
	cin >> n;
	init();
	odd.push_back(0); even.push_back(0);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int sz = (int)log10(a[i]) + 1;
		if (sz & 1) {
			odd.push_back(num(a[i]));
		} else even.push_back(num(a[i]));
	}
	dp[0][0][0] = 1;
	int odd_sz = (int)odd.size() - 1, even_sz = (int)even.size() - 1;
	for (int i = 0; i < odd_sz; ++i) {
		for (int open = 0; open <= i; ++open) {
			for (int rem = 0; rem < 11; ++rem) {
				int cur = dp[i][open][rem];
				if (cur == 0) continue;
				add(dp[i + 1][open + 1][(odd[i + 1] + rem) % 11], cur);
				add(dp[i + 1][open][(rem - odd[i + 1] + 11) % 11], cur);
			}
		}
	}
	if (odd_sz & 1) {
		int block = (odd_sz >> 1), res = 0;
		f[0][0][0] = 1;
		for (int i = 0; i < even_sz; ++i) {
			for (int open = 0; open <= i; ++open) {
				for (int rem = 0; rem < 11; ++rem) {
					int cur = f[i][open][rem];
					if (cur == 0) continue;
					add(f[i + 1][open + 1][(rem - even[i + 1] + 11) % 11], cur);
					add(f[i + 1][open][(even[i + 1] + rem) % 11], cur);
				}
			}
		}
		for (int rem = 0; rem < 11; ++rem) {
			int ways = dp[odd_sz][block + 1][rem] * (block + 1) % MOD;
			if (ways == 0) continue;
			mul(ways, fac[block]); mul(ways, fac[block]);
			int want = (-rem + 11) % 11, T = 0;
			for (int i = 0; i <= even_sz; ++i) {
				int tmp = f[even_sz][i][want];
				if (tmp == 0) continue;
				mul(tmp, fac[i]); mul(tmp, fac[even_sz - i]);
				mul(tmp, C[block][block + i]);
				mul(tmp, C[block][block + even_sz - i]);
				add(T, tmp);
			}
			mul(ways, T);
			add(res, ways);
		}
		cout << res << endl;
	} else {
		// int block = (odd_sz >> 1), res = 0;
		// for (int rem = 0; rem < 11; ++rem) {
		// 	int ways = dp[odd_sz][block][rem];
		// 	mul(ways, fac[block]); mul(ways, fac[block]);
		// 	f[0][rem] = 1;
		// 	for (int i = 0; i < even_sz; ++i) {
		// 		for (int r = 0; r < 11; ++r) {
		// 			int cur = f[i][r];
		// 			if (cur == 0) continue;
		// 			add(f[i + 1][(r + even[i + 1]) % 11], cur * (block + 1));
		// 			add(f[i + 1][(r - even[i + 1] + 11) % 11], cur * block);
		// 		}
		// 	}
		// 	mul(ways, f[even_sz][0]);
		// 	add(res, ways);
		// }
		// cout << res << endl;
		int block = (odd_sz >> 1), res = 0;
		f[0][0][0] = 1;
		for (int i = 0; i < even_sz; ++i) {
			for (int open = 0; open <= i; ++open) {
				for (int rem = 0; rem < 11; ++rem) {
					int cur = f[i][open][rem];
					if (cur == 0) continue;
					if (block) add(f[i + 1][open + 1][(rem - even[i + 1] + 11) % 11], cur);
					add(f[i + 1][open][(even[i + 1] + rem) % 11], cur);
				}
			}
		}
		if (block == 0) {
			cout << f[even_sz][0][0] << endl;
			return;
		}
		for (int rem = 0; rem < 11; ++rem) {
			int ways = dp[odd_sz][block][rem];
			if (ways == 0) continue;
			mul(ways, fac[block]); mul(ways, fac[block]);
			int want = (-rem + 11) % 11, T = 0;
			for (int i = 0; i <= even_sz; ++i) {
				int tmp = f[even_sz][i][want];
				if (tmp == 0) continue;
				mul(tmp, fac[i]); mul(tmp, fac[even_sz - i]);
				mul(tmp, C[block - 1][block + i - 1]);
				mul(tmp, C[block][block + even_sz - i]);
				add(T, tmp);
			}
			mul(ways, T);
			add(res, ways);
		}
		cout << res << endl;
	}
}

void updateckn() {
	for (int k = 0; k < N; ++k)
		for (int n = 0; n < N; ++n) {
			if (k == 0 || k == n || n == 0) {
				C[k][n] = 1;
				continue;
			} else {
				C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]) % MOD;
			}
		}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("GIFT11.INP", "r", stdin);
	freopen("GIFT11.OUT", "w", stdout);

	fac[0] = 1;
	for (int i = 1; i <= N - 5; ++i) {
		fac[i] = fac[i - 1];
		mul(fac[i], i);
	}
	updateckn();

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}