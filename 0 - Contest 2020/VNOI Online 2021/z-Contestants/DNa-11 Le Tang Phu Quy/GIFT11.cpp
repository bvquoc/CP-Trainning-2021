#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
//const int MOD = 2004010501;//>2e9
const int MOD = 998244353;//<1e9
void add(int& var, const int& val) { var += val; if (var >= MOD) var -= MOD; }

#define task "GIFT11"
const int base = 11;
const int MAX = 2005;
int POW10[MAX];

int ncards, cards[MAX], cnt[MAX], dif[MAX];
int digit_count(int n) { int res = 0; for (;n; n /= 10) ++res; return res; }
int diff_count(int n) {
	int res = 0, cnt = digit_count(n);
	for (int sign = (cnt % 2) ? +1 : -1; n; n /= 10, sign *= -1) 
		(res += sign * (n % 10) + base) %= base;
	return res; 
}

namespace Subtask2 {
	int f[MAX][base] = {};

	void solve() {
		for (int i = 0; i <= ncards; i++) for (int r = 0; r < base; r++) f[i][r] = 0;
		f[0][0] = 1;
		for (int i = 0; i < ncards; i++) for (int r = 0; r < base; r++) {
			if (!f[i][r]) continue;
			add(f[i + 1][(r + dif[i + 1]) % base], ((Int) f[i][r] * (i + 1)) % MOD); 
		}
		cout << f[ncards][0] << '\n';
	}
}

namespace Subtask3 {
	int f[MAX][base] = {};
	
	void solve() {
		for (int i = 0; i <= ncards; i++) for (int r = 0; r < base; r++) f[i][r] = 0;
		f[0][0] = 1;
		for (int i = 0; i < ncards; i++) for (int r = 0; r < base; r++) {
			if (!f[i][r]) continue;
			for (int j = 0; j <= i; j++) {
				if (j % 2 == 0) ;
			}
		}
		cout << f[ncards][0] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	POW10[0] = 1;
	for (int i = 1; i < MAX; i++) POW10[i] = ((Int) POW10[i - 1] * 10) % MOD;

	int num_tests;
	cin >> num_tests;
	
	srand(time(NULL));
	for (; num_tests --> 0; ) {
		cin >> ncards;
		bool is_all_even = true;
		bool is_all_odd = true;
		
		for (int i = 1; i <= ncards; i++) {
			cin >> cards[i]; 
			cnt[i] = digit_count(cards[i]);
			is_all_even &= cnt[i] % 2 == 0;
			is_all_odd &= cnt[i] % 2 != 0;
			dif[i] = diff_count(cards[i]);
		}
		
		if (ncards <= 8) {
			vector<int> order(ncards);
			iota(order.begin(), order.end(), 1);
			int ans = 0;
			do {
				int rem = 0;
				for (int i : order) rem = ((Int) rem * POW10[cnt[i]] + cards[i]) % base;
				ans += rem == 0;	
			} while (next_permutation(order.begin(), order.end()));
			cout << ans << '\n';
		} else
		if (is_all_even) {
			Subtask2::solve();
		} else
//		if (is_all_odd) {
//			Subtask3::solve();
//		} else 
		{
			cout << MOD - rand() % 1000;	
		}
	}
}

