#include <bits/stdc++.h>
using namespace std;

int n, m;
int t;
int f[20][100005];
int ans;

int main()
{
	freopen("COOLMAC.INP", "r", stdin);
	freopen("COOLMAC.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i <= 100000; i++)
	{
		f[0][i] = i;
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		f[0][r] = min(f[0][r], l);
	}
	for(int i = 99999; i >= 0; i--)
	{
		f[0][i] = min(f[0][i], f[0][i + 1]);
	}
	for(int i = 1; i <= 19; i++)
	{
		for(int j = 0; j <= 100000; j++)
		{
			f[i][j] = f[i - 1][f[i - 1][j]];
		}
	}
	cin >> n;
	t = 100000;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		t = min(t, a);
	}
	int cur = 100000;
	for(int i = 19; i >= 0; i--)
	{
		if(f[i][cur] > t)
		{
			ans |= (1 << i);
			cur = f[i][cur];
		}
	}
	if(f[0][cur] > t)
	{
		cout << -1;
		return 0;
	}
	cout << ans + 1;
}