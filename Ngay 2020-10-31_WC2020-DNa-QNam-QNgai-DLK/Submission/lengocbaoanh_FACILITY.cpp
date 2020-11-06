#include<bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 500;
pair<long long, pair<long long, long long> > a[maxN];
long long dp[maxN];
int main()
{
	long long n,k,l,r,mid,pos;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].second.first >> a[i].first >> a[i].second.second;
		a[i].first += k + a[i].second.first;
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) swap(a[i].first, a[i].second.first);
//	for(int i = 1; i <= n; i++) {
//		cout << "*****TANGAYLOYEUSAICONGMINHNGU*******" << endl;
//		cout << a[i].first << " " << a[i].second.first << " " << a[i].second.second << endl;
//	}
	for(int i = 1; i <= n; i++) {
//		cout << i << endl;
		l = 1;
		r = i - 1;
		pos = 0;
		dp[i] = a[i].second.second;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid].second.first <= a[i].first) {
				pos = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		dp[i] = max(dp[i], max(dp[i - 1], dp[pos] + a[i].second.second));
	}
	cout << dp[n];
}
