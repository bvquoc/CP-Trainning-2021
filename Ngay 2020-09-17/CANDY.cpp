#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

const int INF = 1e9;

signed main(void) {
    FastIO;
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
	int n; cin >> n;
	int c[n], sum = 0;
	for (int i = 0; i < n; i++)
		cin >> c[i], sum += c[i];
	int cur[sum + 1], last[sum + 1];
	last[0] = 0;
	for (int s = 1; s <= sum; s++)
		last[s] = -INF;
	for (int i = 0; i < n; i++) {
		for (int s = 0; s <= sum; s++)
			cur[s] = -INF;
		for (int s = 0; s <= sum; s++) {
//			if (last[s] == -INF) continue;
			cur[s] = max(cur[s], last[s]);
			if (s + c[i] <= sum) 
				cur[s + c[i]] = max(cur[s + c[i]], last[s] + c[i]);
			int newDif = abs(s - c[i]);
			if (newDif <= sum) 
				cur[newDif] = max(cur[newDif], last[s] + c[i]);
		}
		for (int s = 0; s <= sum; s++) 
			last[s] = cur[s];
	}
//	for (int s = 0; s <= sum; s++)
//		cerr << "dp[" << s << "] = " << last[s] << " | ";
//	cerr << "dif = "<< dif << "\n";
	cout << last[0] / 2 + sum - last[0];
}