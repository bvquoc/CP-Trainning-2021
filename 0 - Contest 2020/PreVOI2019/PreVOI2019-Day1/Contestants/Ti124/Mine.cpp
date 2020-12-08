#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
#define ii int
ll dp[500001],statt[21],ti[21],inn[11],outt[11], i, j, k, t, n, m, cur=0, minn;
vector<ll> mine;
void s1(ll u, ll d)
{
//	cout << u << ' ' << d << ' ' << endl;
	if (u + d > 2 * n) return;
	else if (u > n) return;
	else if (d > n) return;
	else if (d > u) return;
	else if (u + d == 2 * n)
	{
		ll i = 1,j=1,k;
//		for (i = 1; i <= 2 * n; i++)
//		{
//			cout << statt[i] << ' ';
//		}
		for (i = 1; i <= 2 * n; i++)
		{
			if (statt[i]) { mine.push_back(j); inn[j] = ti[i];  j++; }
			else { k = mine[mine.size() - 1]; outt[k] = ti[i]; mine.pop_back(); }
		}
//		cout << endl;
		for (i = 1; i <= 10; i++) if (outt[i] - inn[i] > m) return;
		cur++;
	}
	else
	{
		statt[u+d+1] = 0;
		s1(u, d + 1);
		statt[u+d+1] = 1;
		s1(u+1, d );
		statt[u+d+1] = 0;
	}
}
ll bow(ll a, ll x)
{
	if (x == 0) return 1;
	ll res = bow(a, x / 2);
	res *= res; res %= 1000003;
	if (x % 2) { res *= a; res %= 1000003; }
	return res;
}
int main()
{
	freopen("Mine.inp", "r", stdin);
	freopen("Mine.out", "w", stdout);
	cin >> n >> m;
	if (n <= 10)
	{
		for (i = 1; i <= 2 * n; i++) cin >> ti[i];
		s1(0,0);
		cout << cur%(1000003);
	}
	else if (m == 1000000)
	{
		dp[0] = 1;
		for (i = 1; i <= 2 * n; i++) { dp[i] = dp[i - 1] * i; dp[i] %= 1000003; }
		cur = dp[2*n];
		cur *= bow(dp[n], 1000001); cur %= 1000003;
		cur *= bow(dp[n], 1000001); cur %= 1000003;
		cur *= bow(n+1, 1000001); cur %= 1000003;
		cout << cur;
	}
	fclose(stdin);
	fclose(stdout);
}

