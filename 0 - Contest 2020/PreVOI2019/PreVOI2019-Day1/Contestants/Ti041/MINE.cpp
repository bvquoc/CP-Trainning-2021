#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e6 + 3, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 4e5 + 5, N2 = 4005;
int n, m, a[N], fac[N], ifac[N], invNum[N2], dp[N2], catalan[N2];
void add(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
int fpow(int a, int p) {
	if (!p) return 1;
	int tmp = fpow(a, p >> 1);
	tmp = mul(tmp, tmp);
	if (p & 1) tmp = mul(tmp, a);
	return tmp;
}
int inv(int a) {
	return fpow(a, mod - 2);
}
void sub4() {
	//Locate outmost brackets, then the stuff inside can be calculated by Catalan.
	fw (i, 0, n + 1) catalan[i] = mul(invNum[i + 1], mul(fac[i << 1], mul(ifac[i], ifac[i])));
	n <<= 1;
	dp[0] = 1;
	for (int i = 0; i < n; i += 2) {
		for (int j = i + 1; j < n; j += 2) {
			if (a[j] - a[i] > m) break;
			add(dp[j + 1], mul(dp[i], catalan[(j - i - 1) >> 1]));
		}
	}
	cout << dp[n];
}
void sub5() {
	int ans = inv(n + 1);
	int numerator = fac[n << 1], detominator = mul(ifac[n], ifac[n]);
	ans = mul(ans, mul(numerator, detominator));
	cout << ans;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
//	out("ans1.out");
	#else
	inout("mine", "inp", "out");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fw (i, 0, (n << 1)) cin >> a[i];
	//n <= 2e5 and m = 1e6, count valid bracket sequences by Catalan.
	//n <= 2000, fix outmost brackets and the part inside can be done by Catalan.
	fac[0] = 1;
	fw (i, 1, N) fac[i] = mul(fac[i - 1], i);
	ifac[N - 1] = inv(fac[N - 1]);
	bw (i, N - 1, 0) ifac[i] = mul(ifac[i + 1], i + 1);
	fw (i, 1, N2) invNum[i] = inv(i);
	if (n <= 2000) {
		sub4();
	} else {
		sub5();
	}
	return 0;
}
