#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e6 + 3;
const int N = 2003;
const int lim = 4e5 + 3;
int gt[lim];
int dp[N][N], a[2*N];
bool b[2*N];
int n, m;
int mul(int a, int b) {
	return a * b % mod;
}
int binpow(int a, int b) {
	if(b == 0) return 1;
	int res = binpow(a, b / 2);
	res = mul(res, res);
	if(b % 2 == 0) return res;
	else return mul(a, res);
}
int Ckn(int k, int n) {
	int res = mul(gt[n - k], gt[k]);
	res = binpow(res, mod - 2);
	return mul(gt[n], res);
}
int ans = 0;
bool ck() {
	stack <int > s;
	for(int i = 1; i <= 2*n; i++) {
		if(b[i] == 1) {
			s.push(i);
		}
		else {
			if(s.size() == 0) return false;
			int u = s.top();
			s.pop();
			if(a[i] - a[u] > m) return false;
		}
	}
	if(s.size() == 0) return true;
	else return false;
}
void show() {
	for(int i = 1; i <= 2*n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}
void back(int u) {
	if(u == 2 * n + 1) {
		ans += ck();

	}
	else{
		b[u] = 1;
		back(u + 1);
		b[u] = 0;
		back(u + 1);
	}
}
signed main() {
	freopen("mine.inp", "r", stdin);
	freopen("mine.out", "w", stdout);
	gt[0] = 1;
	for(int i = 1; i < lim; i++) {
		gt[i] = mul(gt[i - 1], i);
	}
	cin >> n >> m;
	if(m == 1e6) {
		// Catalan
		return cout << mul(Ckn(n + 1, 2*n), binpow(n, mod - 2)), 0;
	}

	for(int i = 1; i <= 2*n; i++) {
		cin >> a[i];
	}
	back(1);
	cout << ans;
}