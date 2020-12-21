#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
//const int MOD = 2004010501;//>2e9
const int MOD = (int) 1e9 + 7;
void add(int& var, const int& val) { var += val; if (var >= MOD) var -= MOD; }

#define task "PERMEOW"
const int MAX = (int) 2e5 + 500;

int n, a[MAX], b[MAX];
int brute[MAX];

namespace Subtask1 {
	int fenwick[MAX];
	void update(int node) {
		for (; node > 0; node &= node - 1) ++fenwick[node];
	}
	
	int query(int node) {
		int res = 0; for (; node <= n; node += node & -node) res += fenwick[node];
		return res;
	}
	
	void solve(bool is_brute_forcing = false) {
		fill(fenwick, fenwick + 1 + n, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			add(ans, query(a[i]));
			update(a[i]);
		}
		if (!is_brute_forcing) cout << ans;
		else ++brute[ans];
	}
}

namespace Subtask2 {
	int fac[MAX], inv[MAX];
	int pwr_mod(int a, int n, int m) {
		if (!n) return 1;
		int cal = pwr_mod(a, n / 2, m);
		cal = ((Int) cal * cal) % m;
		if (n % 2 != 0) cal = ((Int) cal * a) % m;
		return cal;
	}
	
	void init(int n) {
		fac[0] = 1;
		for (int i = 1; i <= n; i++) fac[i] = ((Int) i * fac[i - 1]) % MOD;
		inv[n] = pwr_mod(fac[n], MOD - 2, MOD);
		for (int i = n - 1; i >= 0; i--) inv[i] = ((Int) (i + 1) * inv[i + 1]) % MOD;
	}
	
	int combi(int n, int k) {
		return ( (Int) fac[n] * (((Int) inv[n - k] * inv[k]) % MOD) ) % MOD;
	}
	
	void solve() {
		init(MAX - 1);
		int answer = 0;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y < x; y++) {
				int inv_create = ((Int) fac[y] * combi(x - 1, y)) % MOD;
				int remain_positioning = fac[x - 1 - y];
				int free_positioning = ((Int) fac[n - x] * combi(n, n - x)) % MOD;
				int num_permutations = ((Int) inv_create * remain_positioning) % MOD;
				num_permutations = ((Int) num_permutations * free_positioning) % MOD;
				add(answer, ((Int) num_permutations * y) % MOD);
			}
		}
		cout << answer;
	}
}

void brute_test_rule() {
//	for (::n = 1; n <= 7; n++) {
		fill(brute, brute + MAX, 0);
		iota(a + 1, a + 1 + n, 1);
		do {
			Subtask1 :: solve(true); 
		} while (next_permutation(a + 1, a + 1 + n));
		int cost = 0;
		for (int i = 0; i <= n * (n - 1) / 2; i++) {
			cost += i * brute[i];	
//			cerr << "cnt(" << i << ") = " << brute[i] << '\n';
		}
		cerr << "Total cost = " << cost << '\n';
//	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	bool sub1 = true, sub2 = true;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sub2 &= a[i] == i;
	for (int i = 1; i <= n; i++) cin >> b[i], sub1 &= a[i] == b[i], sub2 &= b[i] == n - i + 1;
	
	if (sub1) Subtask1 :: solve(); else
	if (sub2) Subtask2 :: solve();
	
}
