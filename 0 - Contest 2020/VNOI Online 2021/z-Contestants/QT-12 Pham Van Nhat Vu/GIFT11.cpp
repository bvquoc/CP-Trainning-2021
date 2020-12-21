#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int MAXN = 2007, MOD = 998244353;

int n, test, a[MAXN], e[MAXN], o[MAXN], dp[MAXN][MAXN][11], fac[MAXN], p[MAXN];
bool ise[MAXN];

void add11(int &a, const int &b)
{
	a += b;
	if (a >= 11) a -= 11;
}

void add(int &a, const int &b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int sum11(int a, const int &b)
{
	a += b;
	if (a >= 11) a -= 11;
	return a;
}

void sub11(int &a, const int &b)
{
	a -= b;
	if (a < 0) a += 11;
}

int min11(int a, const int &b)
{
	a -= b;
	if (a < 0) a += 11;
	return a;
}

int inv(int cur)
{
	return (cur == 0 ? 0 : (11 - cur));
}

int sum(int a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b)
{
	return 1LL*a*b % MOD;
}

int main()
{
	freopen("GIFT11.INP","r",stdin);
	freopen("GIFT11.OUT","w",stdout);
	io;
	cin >> test;
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = 1LL*fac[i - 1]*i % MOD;
	while (test--)
	{
		cin >> n;
		int ne = 0, no = 0;
		for (int i = 1; i <= n; ++i) 
		{
			int tmp;
			a[i] = 0;
			ise[i] = 1;
			cin >> tmp;
			while (tmp)
			{
				if (ise[i]) add11(a[i], tmp % 10); else sub11(a[i], tmp % 10);
				ise[i] ^= 1;
				tmp /= 10;
			}
			if (ise[i]) 
			{
				a[i] = inv(a[i]);
				e[++ne] = a[i];
			}else o[++no] = a[i];
		}
		
		if (no == 0)
		{
			int res = 0;
			for (int i = 1; i <= ne; ++i) add11(res, e[i]);
			cout << (res ? 0 : fac[ne]) << '\n';
		}else if (ne == 0)
		{
			int nm = (no >> 1), np = no - nm;
			dp[0][0][0] = 1;
			for (int i = 0; i < no; ++i)
				for (int j = 0; j <= min(i, np); ++j)
					for (int rem = 0; rem < 11; ++rem)
					{
						if (j < np) 
						{
							add(dp[i + 1][j + 1][sum11(rem, o[i + 1])], mul(np - j, dp[i][j][rem]));
						}
						add(dp[i + 1][j][min11(rem, o[i + 1])], mul(no - i - np + j, dp[i][j][rem]));
					}
			cout << dp[no][np][0] << '\n';
			for (int i = 0; i <= no; ++i)
				for (int j = 0; j <= np; ++j)
					for (int rem = 0; rem < 11; ++rem)
						dp[i][j][rem] = 0;
		}else
		{
			int res = 0;
			for (int i = 1; i <= n; ++i) p[i] = i;
			do
			{
				int add = 1, cur = 0;
				for (int j = 1; j <= n; ++j)
				{
					int i = p[j];
					if (add) add11(cur, a[i]); else sub11(cur, a[i]);
					add ^= (!ise[i]);
				}				
				if (cur == 0) ++res;
			}while (next_permutation(p + 1, p + 1 + n));
			cout << res << '\n';
		}
	}
	return 0;
}