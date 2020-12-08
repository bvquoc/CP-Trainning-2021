#include <bits/stdc++.h>

using namespace std;
const string filename = "ODDCOIN";

#define int long long

int q;
int f[50001];
vector<int> coins {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	for (int i=1;i<=50000;i++)
		f[i] = 1e9;

	for (int i=0;i<=50000;i++)
		for (int j=0;j<coins.size();j++)
			if (i + coins[j] <= 50000)
				f[i + coins[j]] = min(f[i + coins[j]],f[i] + 1);

	cin >> q;
	while(q--)
	{
		int x,t;
		cin >> x >> t;
		int res = 1e18;
		for (int i=0;i<=50000;i++)
		{
			int cur = t - x*i;
			if (cur >= 0)
			{
				int z = i;
				z += cur / 50000;
				cur %= 50000;
				res = min(res,f[cur] + z);
			}
		}
		cout << res << '\n';
	}
}