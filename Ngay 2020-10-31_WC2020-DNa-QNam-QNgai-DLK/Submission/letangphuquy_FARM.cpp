#include<bits/stdc++.h>
using namespace std;

const int oo = 1e9;
const int minN = 105;
const int maxN = 1e4 + 500;

int n, k, Q, P, a[maxN];

#define INIT -1
int** cache;
int solve(int i, int q) {
	if (i < 1) return 0;
	
	int& res = cache[i][q];
	if (res != INIT) return res;
	
	res = solve(i - 1, q);
	int qty = min(q, P);
	res = max(res, solve(i - k, q - qty) + qty * a[i]);
	
	qty = q % P;
	res = max(res, solve(i - k, q - qty) + qty * a[i]);
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> Q >> P;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	if (max(n, Q) < minN) {
//		int dp[n + 1][Q + 1];
//		for (int q = 0; q <= Q; q++) dp[0][q] = (q == 0) ? 0 : -oo;
//		for (int i = 1; i <= n; i++) {
//			for (int q = 0; q <= Q; q++) {
//				dp[i][q] = dp[i - 1][q];
//				for (int p = 1; p <= min(P, q); p++)
//					dp[i][q] = max(dp[i][q], ((i >= k) ? dp[i - k][q - p] : 0) + p * a[i]);
//			}
//		}
//		int answer = -oo;
//		for (int q = 0; q <= Q; q++) answer = max(answer, dp[n][q]);
//		cout << answer;
//	}
//	else 
	{
		cache = new int*[n + 1];
		for (int i = 0; i <= n; i++) {
			cache[i] = new int[Q + 1];
			for (int q = 0; q <= Q; q++) cache[i][q] = INIT;	
		}
		cout << solve(n, Q);
 	}
}
