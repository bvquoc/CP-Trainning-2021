#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int Add(int x, int y)
{
	return x + y >= mod ? x + y - mod : x + y;
}

int Sub(int x, int y)
{
	return x - y < 0 ? x - y + mod : x - y;
}

int Mul(int x, int y)
{
	return 1ll * x * y % mod;
}

int n;
int fact[200005], c[200005];
vector <int> A, B;

int BIT[200005];

void Update(int x, int val)
{
	for(x; x <= n; x += x & -x)
	{
		BIT[x] += val;
	}
}

int Get(int x)
{
	int ans = 0;
	for(x; x > 0; x -= x & -x)
	{
		ans += BIT[x];
	}
	return ans;
}

int Solve(vector <int> &A)
{
	for(int i = 0; i <= n; i++)
	{
		BIT[i] = 0;
	}
	int cur = 0;
	for(int i = 0; i < A.size(); i++)
	{
		cur += fact[n - i - 1] * (A[i] - Get(A[i]) - 1);
		Update(A[i], 1);
	}
	cur++;
	for(int i = 0; i <= n; i++)
	{
		BIT[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < A.size(); i++)
	{
		ans = Add(ans, Mul(A[i] - Get(A[i]) - 1, c[(int)A.size() - i - 1]));
		cur -= (fact[n - 1 - i]) * (A[i] - Get(A[i]) - 1);
		ans = Add(ans, Mul(A[i] - Get(A[i]) - 1, Mul(A[i] - Get(A[i]) - 2, Mul((mod + 1) / 2, fact[(A.size() - i - 1)]))));
		ans = Add(ans, Mul(A[i] - Get(A[i]) - 1, cur));
		Update(A[i], 1);
	}
	return ans;
}

int main()
{
	freopen("PERMEOW.INP", "r", stdin);
	freopen("PERMEOW.OUT", "w", stdout);
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++)
	{
		fact[i] = Mul(fact[i - 1], i);
		if(i != 1)
		{
			c[i] = Mul(fact[i], Mul((mod + 1) / 2, Mul(i, Mul(i - 1, (mod + 1) / 2))));
		}
	}
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	A.resize(n);
	for(auto &x : A)
	{
		cin >> x;
	}
	B.resize(n);
	for(auto &x : B)
	{
		cin >> x;
	}
	int ans = Solve(B);
	if(prev_permutation(A.begin(), A.end()))
	{
		ans = Sub(ans, Solve(A));
	}
	cout << ans;
}