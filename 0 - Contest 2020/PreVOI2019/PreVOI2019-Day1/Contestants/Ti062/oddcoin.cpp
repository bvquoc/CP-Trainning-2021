#include<bits/stdc++.h>
#define qwer "oddcoin"

using namespace std;

const int maxn = 1e6 ;
int f[maxn * 2 + 1];

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	vector<int> a;
	for (int i = 1;i <= 10000;i *= 10) {
		a.emplace_back(i);
		a.emplace_back(i * 3);
		a.emplace_back(i * 5);
	}
	memset(f,127,sizeof f);
	f[0] = 0;
	for (int i = 1;i <= maxn << 1;++i) {
		for (auto&x : a) {
			if (i < x) break;
			f[i] = min(f[i],f[i - x] + 1);
		}
	}
	auto down = [&](int&a,int b,int&add)
	{
		int need = max(0,a - maxn) / b;
		a -= need * b;
		add += need;
	};
	cin >> q;
	while (q--) {
		int x,n;
		cin >> x >> n;
		if (n <= (int)3e4) {
			a.emplace_back(x);
			vector<int> dp(n + 1,1e9);
			dp[0] = 0;
			for (int i = 1;i <= n;++i) {
				for (auto&x : a) {
					if (i < x) continue;
					dp[i] = min(dp[i],dp[i - x] + 1);
				}	
			}
			cout << dp[n] << "\n";
			a.pop_back();
		}
		else {
			int ans = 2e9;
			int can = 50000;
			if (can < x) can = x;
			int need = 0;
			down(n,can,need);
			if (n > maxn << 1) down(n,50000,need);
			assert(n <= maxn << 1) ;
			// n - q * can <= maxn
			// n - maxn / can <= q
			for (int i = 0;i <= (int)n;++i) {
				if (n >= x * i) ans = min(ans,f[n - x * i] + i);
				else break;
			}
			cout << ans + need <<"\n";
		}
	}
}
