#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7; 

int n, ans_a, ans_b; 
int a[200005], fac[200005], div2;

int bp(int a, int n) {
	int ret = 1; 
	while(n) {
		if(n & 1) ret = ret * a % mod; 
		a = a * a % mod; 
		n >>= 1; 
	}
	return ret; 
}

int f(int n) {
	int ret = fac[n] * div2 % mod; 
	ret = ret * n % mod * (n - 1) * div2 % mod; 
	return ret; 
}

int fen[200005]; 

void Update(int i, int val) {
	while(i <= n) {
		fen[i] += val; 
		i += (i & (-i)); 
	}
}

int Get(int i) {
	int ret = 0; 
	while(i) {
		ret += fen[i]; 
		i -= (i & (-i)); 
	}
	return ret; 
}

void Reset_fen() {
	for(int i = 1; i <= n; i++) fen[i] = 0;  
}

int Solve_single() {
	Reset_fen(); 
	int ret = 0; 
	for(int i = n; i; i--) {
		ret = (ret + Get(a[i])) % mod; 
		Update(a[i], 1); 
	}
	return ret; 
}

int Solve() {
	int ret = 0; 
	int lef = 0;
	Reset_fen(); 
	for(int i = 1; i <= n; i++) {
		Update(i, 1); 
	} 
	for(int i = 1; i <= n; i++) {
		Update(a[i], -1); 
		int Smaller = Get(a[i]); 
		int ans_when_fixed = fac[n - i] * lef % mod + f(n - i); 
		ans_when_fixed %= mod; 
		int sum_rank = (Smaller) * (Smaller - 1) / 2; 
		sum_rank %= mod;
		sum_rank = sum_rank * fac[n - i] % mod;  
		ret = (ret + Smaller * ans_when_fixed % mod) % mod; 
		ret = (ret + sum_rank) % mod; 
		lef = (lef + Smaller) % mod; 
	}
	ret = (ret + Solve_single()) % mod; 
	return ret; 
}

signed main() {
	freopen("permeow.inp", "r", stdin); 
	freopen("permeow.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n; 
	fac[0] = 1; 
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod; 
	}
	div2 = bp(2, mod - 2); 
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	ans_a = Solve() - Solve_single(); 
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	ans_b = Solve(); 
	int ans = (ans_b - ans_a) % mod; 
	if(ans < 0) ans += mod; 
	cout << ans; 
}