#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int t;
int n;
int f[11][11], g[11][11];
int dp[2005][11], dp2[2005][11];
int pw[2005][2005], fact[2005];
int cc[11][2], as;

int Add(int x, int y)
{
	return x + y >= mod ? x + y - mod : x + y;
}

int Mul(int x, int y)
{
	return 1ll * x * y % mod;
}

void Solve()
{
	cin >> n;
	for(int i = 0; i <= 10; i++)
	{
		cc[i][0] = 0;
		cc[i][1] = 0;
	}
	as = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int cnt = 0, sum = 0;
		while(x)
		{
			if(cnt & 1)
			{
				sum = f[sum][x % 10];
			}
			else
			{
				sum = g[sum][x % 10];
			}
			cnt++;
			x /= 10;
		}
		if(cnt & 1)
		{
			sum = 11 - sum;
			if(sum == 11)
			{
				sum = 0;
			}
			cc[sum][1]++;	
			as++;
		}
		else
		{
			sum = 11 - sum;
			if(sum == 11)
			{
				sum = 0;
			}
			cc[sum][0]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			dp[i][j] = 0;
			dp2[i][j] = 0;
		}
	}
	dp2[0][0] = 1;
	dp[0][0] = 1;
	int AllB = 0, temp = 0, AllA;
	for(int i = 0; i <= 10; i++)
	{
		for(int j = 1; j <= cc[i][0]; j++)
		{
			AllB = f[AllB][i];
			for(int k = temp; k >= 0; k--)
			{
				for(int l = 0; l <= 10; l++)
				{
					dp2[k + 1][f[l][i]] = Add(dp2[k + 1][f[l][i]], dp2[k][l]);
				}
			}
			temp++;
		}	
	}
	temp = 0;
	for(int i = 0; i <= 10; i++)
	{
		for(int j = 1; j <= cc[i][1]; j++)
		{
			AllA = f[AllA][i];
			for(int k = temp; k >= 0; k--)
			{
				for(int l = 0; l <= 10; l++)
				{
					dp[k + 1][f[l][i]] = Add(dp[k + 1][f[l][i]], dp[k][l]);
				}
			}
			temp++;
		}
	}
	int ans = 0, ad = (as + 2) / 2, su = (as + 1) / 2;
	for(int i = 0; i <= 10; i++)
	{
		int j = g[AllA][i];
		int tmp = dp[(as + 1) / 2][i];
		int rem = g[i][j];
		for(int k = 0; k <= n - as; k++)
		{
			for(int l = 0; l <= 10; l++)
			{
				int r = g[AllB][l];
				if(g[r][l] == rem)
				{
					ans = Add(ans, Mul(tmp, Mul(dp2[n - as - k][l], Mul(fact[n - as - k], Mul(fact[k], Mul(pw[ad][k], pw[su][n - as - k]))))));
				}
			}
		}	
	}
	cout << Mul(ans, Mul(fact[(as + 1) / 2], fact[as / 2])) << '\n';
}

int main()
{
	freopen("GIFT11.INP", "r", stdin);
	freopen("GIFT11.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i <= 10; i++)
	{
		for(int j = 0; j <= 10; j++)
		{
			f[i][j] = i + j;
			g[i][j] = i - j;
			if(f[i][j] >= 11)
			{
				f[i][j] -= 11;
			}
			if(g[i][j] < 0)
			{
				g[i][j] += 11;
			}
		}
	}
	for(int i = 0; i <= 2000; i++)
	{
		if(i == 0)
		{
			fact[0] = 1;
		}
		else
		{
			fact[i] = Mul(fact[i - 1], i);
		}
		pw[i][0] = min(i, 1);
		for(int j = 1; j <= 2000; j++)
		{
			pw[i][j] = Mul(pw[i][j - 1], i);
		}
	}
	cin >> t;
	while(t--)
	{
		Solve();
	}
}