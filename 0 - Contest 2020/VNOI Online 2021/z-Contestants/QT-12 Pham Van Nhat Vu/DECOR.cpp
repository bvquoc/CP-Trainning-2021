#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fi first
#define se second
#define ll long long

using namespace std;

const int MAXN = 1e5 + 7;

int n, m, k, fa[MAXN], one[MAXN], cur_one[MAXN], s[MAXN];
char c[MAXN];

int root(int u)
{
	if (fa[u] < 0) return u;
	return fa[u] = root(fa[u]);
}

int main()
{
	freopen("DECOR.INP","r",stdin);
	freopen("DECOR.OUT","w",stdout);
	io;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> c[i], fa[i] = -1, one[i] = (c[i] - '0');
	
	if (m == 0)
	{
		int ans = 0, al = -1;
		s[0] = 0;
		for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (c[i] == '0');
		for (int i = 1; i <= n; ++i)
		{
			int lo = i, hi = n, res = -1;
			while (lo <= hi)
			{
				int mid = (lo + hi) >> 1;
				if (s[mid] - s[i - 1] <= k) res = mid, lo = mid + 1; else hi = mid - 1;
			}
			if (res - i + 1 > ans) ans = res - i + 1, al = i;
		}
		if (ans == 0) cout << -1; else cout << al << ' ' << al + ans - 1;
		return 0;
	}
	
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		u = root(u), v = root(v);
		if (u != v) one[v] += one[u], fa[u] = v;
	}
	int res = 0, rl = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j) cur_one[j] = one[j];
		
		int add = 0;
		for (int j = i; j <= n; ++j)
		{
			int u = root(j);
			--cur_one[u];
			if (cur_one[u] < 0) ++add;
			if (add <= k) 
			{
				if (j - i + 1 > res) res = j - i + 1, rl = i;
			}else break;
		}
	}
	
	if (res == 0) cout << -1;
	else cout << rl << ' ' << rl + res - 1;
	return 0;
}