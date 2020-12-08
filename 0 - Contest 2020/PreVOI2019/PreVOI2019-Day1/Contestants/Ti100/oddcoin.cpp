#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int dp[N];
int currency[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int main() {
	freopen("oddcoin.inp", "r", stdin);
	freopen("oddcoin.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) {
		int x, t;
		cin >> x >> t;
		vector <int> coin;
		coin.push_back(x);
		for(int i = 0; i < 15; i++) {
			coin.push_back(currency[i]);
		}
		sort(coin.begin(), coin.end());
		for(int i = 1; i < N; i++) {
			int best = i;
			for(auto x : coin) {
				if(i >= x) {
					best = min(best, dp[i - x] + 1);
				}
			}
			dp[i] = best;
		}

		int cnt = 0, ans = t;
		while(t > 0) {
			if(t < N) ans = min(ans, cnt + dp[t]);
			for(int i = 12; i >= 0; i--) {
				if(t >= coin[i]) t -= coin[i];
			}
			cnt++;
		}

		cout << ans << '\n';
	}
}