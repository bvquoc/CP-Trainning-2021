#include <bits/stdc++.h>

using namespace std;
const string filename = "MINE";

#define int long long

const int mod = 1e6+3;

int n,m;
int a[400001];
int dp[4001][4001];
int fact[400001];
int re_fact[400001];

int p(int a,int b)
{
	if (b == 0) return 1;
	int tmp = p(a,b/2);
	if (b%2 == 0) return (tmp * tmp)%mod;
	return ((tmp * tmp)%mod * a)%mod;
}

int comb(int n,int k)
{
	if (k > n) return 0;
	return ((fact[n] * re_fact[k])%mod * re_fact[n-k])%mod;
}

int f(int l,int r)
{
	if (l > r) return 1;
	if (dp[l][r] != -1)
		return dp[l][r];
	int cur = 0;
	for (int i=r-1;i>=l;i-=2)
		if (a[r] - a[i] <= m)
			cur = ((f(l,i-1) * f(i+1,r-1))%mod + cur)%mod;
	return dp[l][r] = cur;				 
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	fact[0] = 1;
	for (int i=1;i<=400000;i++)
		fact[i] = (fact[i-1] * i)%mod;
	re_fact[400000] = p(fact[400000],mod-2);
	for (int i=400000;i>=1;i--)
		re_fact[i-1] = (re_fact[i] * i)%mod;

	cin >> n >> m;

	for (int i=1;i<=2*n;i++)
		for (int j=1;j<=2*n;j++)
			dp[i][j] = -1; 

	for (int i=1;i<=2*n;i++)
		cin >> a[i];
	if (n <= 200) // Sub 1 + 2 + 3
		cout << f(1,2*n);	
	else if (m == 1000000 || (a[2*n] - a[1] <= m)) // Sub 5
		cout << (comb(2*n,n) * p(n+1,mod-2))%mod; 
	else // Sub 4 (Hopefully ...)
		cout << f(1,2*n);
}