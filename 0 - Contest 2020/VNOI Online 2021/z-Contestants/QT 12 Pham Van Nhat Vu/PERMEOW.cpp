#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fi first
#define se second
#define ll long long

using namespace std;

const int MAXN = 2e3 + 7, MOD = 1e9 + 7;

int n, a[MAXN], res = 0, C[MAXN][MAXN], fac[MAXN], b[MAXN];
bool ok = 1;

int mul(int a, int b)
{
	return 1LL*a*b % MOD;
}

void add(int &a, const int &b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int sum(int a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int main()
{
	freopen("PERMEOW.INP","r",stdin);
	freopen("PERMEOW.OUT","w",stdout);
	io;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i], ok &= (a[i] == b[i]);
	
	if (ok)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <= n; ++j)
				if (a[j] == i)
				{
					for (int k = j; k > i; --k) swap(a[k], a[k - 1]), ++res;
					break;
				}
		}
		cout << res;
	}else
	{
		C[0][0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j) C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
		}
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) fac[i] = 1LL*i*fac[i - 1] % MOD;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = max(0, i - j); k < min(i, n - j); ++k)
				{
					int rpos = j + k;
					add(res, mul(C[i - 1][k], mul(C[n - j][k], mul(C[j][i - k], mul(fac[n - i], rpos)))));
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}