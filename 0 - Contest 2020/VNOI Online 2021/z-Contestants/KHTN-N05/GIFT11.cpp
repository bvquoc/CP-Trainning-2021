#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2005;
const ll mod = 998244353;

ll add(ll a, ll b) {
	return (a + b >= mod ? a + b - mod : a + b);
}
ll sub(ll a, ll b) {
	return (a - b < 0 ? a - b + mod : a - b);
}
ll mul(ll a, ll b) {
	return (a * b) % mod;
}
ll power(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x % mod;
	ll tmp = power(x, y / 2);
	if (y & 1) {
		return mul(mul(tmp, tmp), x);
	} else {
		return mul(tmp, tmp);
	}
}
ll invMod(ll x) {
	return power(x, mod - 2);
}
ll fac[N], rev[N];
ll C(int k, int n) {
	return mul(fac[n], mul(rev[n - k], rev[k]));
}

int n;
ll a[N], val[N];
ll dp[N][15];
ll dp1[15];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("GIFT11.inp", "r", stdin);
	freopen("GIFT11.out", "w", stdout);
	
	fac[0] = 1; rev[0] = invMod(fac[0]);
	for (int i = 1; i <= 2000; i++) {
		fac[i] = mul(fac[i - 1], i);
		rev[i] = invMod(fac[i]);
	}
	
	int tc; cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		vector<int> odd, even;
		for (int i = 1; i <= n; i++) {
			ll tmp = a[i], cnt = 0, rem = 0;
			while (tmp > 0) {
				cnt++;
				if (cnt & 1) {
					rem = (rem + (tmp % 10) + 11 * 11) % 11;
				} else {
					rem = (rem - (tmp % 10) + 11 * 11) % 11;
				}
				tmp /= 10;
			}
			val[i] = rem;
			if (cnt & 1) {
				odd.push_back(i);
			} else {
				even.push_back(i);
			}
		}
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 11; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		int szOdd = (int)odd.size();
		for (int i = 1; i <= szOdd; i++) {
			for (int j = szOdd; j >= 1; j--) {
				int rem = val[odd[i - 1]];
				for (int k = 0; k < 11; k++) {
					dp[j][k] = add(dp[j][k], dp[j - 1][(k - rem + 11) % 11]);
				}
			}
		}
		int half = (szOdd / 2) + (szOdd % 2), sum = 0;
		for (int i : odd) sum = (sum + val[i]) % 11;
		for (int i = 0; i < 11; i++) dp1[i] = 0;
		for (int i = 0; i < 11; i++) {
			int res = (sum - i + 11 * 11) % 11;
			res = (i - res + 11 * 11) % 11;
			dp1[res] = add(dp1[res], mul(dp[half][i], mul(fac[half], fac[szOdd - half])));
		}
		
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j < 11; j++) {
				dp[i][j] = 0;
			}
		}
		half = ((szOdd + 1) / 2) + ((szOdd + 1) % 2);
		for (int i = 0; i < 11; i++) dp[half][i] = dp1[i];
		
		if (szOdd == 0) {
			int sum = 0;
			for (int i : even) sum = (sum + val[i]) % 11;
			if (sum == 0) {
				cout << fac[(int)even.size()] << "\n";
			} else {
				cout << 0 << "\n";
			}
			continue;
		} else {
			int szEven = (int)even.size();
			for (int i = 1; i <= szEven; i++) {
				for (int j = n + 1; j >= 1; j--) {
					int tmp = szOdd + i;
					if (j > tmp) continue;
					int cnt0 = j, cnt1 = tmp - j;
					int rem = val[even[i - 1]];
					for (int k = 0; k < 11; k++) {
						ll res = 0;
						if (j >= 1) res = add(res, mul(dp[j - 1][(k - rem + 11) % 11], j - 1));
						if (cnt1 >= 1) res = add(res, mul(dp[j][(k + rem) % 11], cnt1 - 1));
						dp[j][k] = res;
					}
				}
			}
		}
		
		ll ans = 0;
		for (int i = 0; i <= n + 1; i++) ans = add(ans, dp[i][0]);
		cout << ans << "\n";
	}
}