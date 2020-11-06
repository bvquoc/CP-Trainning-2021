#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
struct TOrder {
	int l, r;
	Int profit;
	TOrder(int st = 0, int len = 0, int p = 0) : l(st), r(st + len), profit(p) {
	}
	bool operator< (const TOrder& other) const {
		return r < other.r;
	}  
};

const int maxN = 1e6 + 500;
TOrder ord[maxN];
Int dp[maxN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, dist;
	cin >> n >> dist;
	for (int s, d, r, i = 1; i <= n; i++) {
		cin >> s >> d >> r;
		ord[i] = TOrder(s, d, r);
	}
	sort(ord + 1, ord + 1 + n);
	ord[0].r = -2e9;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int lo = 0, hi = i - 1, pos = 0;
		while (lo <= hi) {
			int mid = lo + hi >> 1;
			if (ord[mid].r + dist > ord[i].l) hi = mid - 1;
			else pos = mid, lo = mid + 1;
		}
		dp[i] = max(dp[i - 1], dp[pos] + ord[i].profit);
//		cerr << "dp[" << i << "] = " << dp[i] << "\n";
	}
	cout << dp[n];
}
