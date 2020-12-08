#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
#define ii int
ii dp[50000001],i,j,k,t,n,m,pay[10]={0,1,2,1,2,1,2,3,2,3},cur,minn;
int solve(int x)
{
	int res;
	res = x / 50000;
	x %= 50000;
	while (x > 0)
	{
		res += pay[x % 10];
		x /= 10;
	}
	return res;
}
int main()
{
	freopen("Oddcoin.inp", "r", stdin);
	freopen("Oddcoin.out", "w", stdout);
	for (i = 1; i <= 50000000; i++) dp[i] = solve(i);
	dp[0] = 0;
	cin >> t;
	for (k = 1; k <= t; k++)
	{
		cin >> m >> n;
		i = 0;
		minn = 1000000001;
		while (n >= 0)
		{
			cur = i + solve(n);
			if (minn > cur) minn = cur;
			i++;
			n -= m;
		}
		cout << minn << endl;
	}
	fclose(stdin);
	fclose(stdout);
}

