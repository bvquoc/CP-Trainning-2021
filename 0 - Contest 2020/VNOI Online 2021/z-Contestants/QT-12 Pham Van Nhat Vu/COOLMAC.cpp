#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int MAXN = 1e5 + 7, LIM = 1e5 + 1;

int bit[MAXN], dp[MAXN], fir = LIM, m, n;
vector<int> adj[MAXN];

void upd(int pos, int val)
{
	for (int i = pos; i <= LIM + 1; i += (i & -i))
		bit[i] = min(bit[i], val);
}

int get(int pos)
{
	int ret = MAXN;
	for (int i = pos; i; i -= (i & -i))
		ret = min(ret, bit[i]);
	return ret;
}

int main()
{
	freopen("COOLMAC.INP","r",stdin);
	freopen("COOLMAC.OUT","w",stdout);
	io;
	fill(bit + 1, bit + 2 + LIM, MAXN);
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		cin >> l >> r;
		++l, ++r;
		adj[l].push_back(r);
	}
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int t;
		cin >> t;
		++t;
		fir = min(fir, t);
	}
	
	for (int i = 1; i <= fir; ++i) 
	{
		dp[i] = 0;
		for (auto r: adj[i]) upd(LIM - r + 1, dp[i] + 1);
	}
	for (int i = fir + 1; i <= LIM; ++i)
	{
		if (adj[i].size())
		{
			dp[i] = get(LIM - i + 2);
			for (auto r: adj[i]) upd(LIM - r + 1, dp[i] + 1);
		}
	}
	int res = get(1);
	cout << (res == MAXN ? -1 : res);
	return 0;
}