#include <bits/stdc++.h>
#define int long long
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
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int MAX = 5e4, MAGIC = 2e5;
int x, t, cntCoins = 15;
int val[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int dp[20][MAGIC];
int calc(int cost) {
	if (cost < MAGIC) return dp[cntCoins][cost];
	else {
		//Keep using 50K coins until it's smaller than MAGIC.
		int tmp = cost % MAGIC;
		int cnt50 = (cost - tmp) / MAX;
		return cnt50 + dp[cntCoins][tmp];
	}
}
void proc() {
	cin >> x >> t;
	//x < MAX: Replace every 50k times of X with X 50k coins. So we use max 50k coins
	//x > MAX: Use at most t / MAX < 50k coins.
	int ans = 2 * inf;
	fw (cnt, 0, MAX) {
		int val = t - cnt * x;
		if (val < 0) break;
		ans = min(ans, cnt + calc(val));
	}
	cout << ans << "\n";
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#else
	inout("oddcoin", "inp", "out");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	fw (i, 0, cntCoins) fw (j, 0, MAGIC) {
		if (j + val[i] < MAGIC) dp[i][j + val[i]] = min(dp[i][j + val[i]], dp[i][j] + 1);
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
	}
	int t;
	cin >> t;
	while (t--) proc();
	return 0;
}

