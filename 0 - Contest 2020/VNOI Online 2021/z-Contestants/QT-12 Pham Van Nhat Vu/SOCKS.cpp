#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int MAXN = 5e5 + 7;

int n, q, sz[MAXN], s[5], pos[MAXN];
bool col[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p, int k)
{
	pos[u] = k;
	for (auto v: adj[u])
		if (v != p) dfs(v, u, k);
}

void dfs(int u, int p)
{
	sz[u] = col[u];
	for (auto v: adj[u])
		if (v != p) 
		{
			dfs(v, u);
			sz[u] += sz[v];
		}
}

int main()
{
	freopen("SOCKS.INP","r",stdin);
	freopen("SOCKS.OUT","w",stdout);
	io;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) 
	{
		cin >> col[i];
	}
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int mx = 0, cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		int deg = (int)adj[i].size();
	 	if (mx < deg) mx = deg, cnt = 1;
	 	else if (mx == deg) ++cnt;
	}
	
	if (mx <= 2)
	{
		int sum = 0;
		for (int i = 1; i <= n; ++i) sum += col[i];
		cout << (sum > 1) << '\n';
		while (q--)
		{
			int u;
			cin >> u;
			if (col[u]) --sum; else ++sum;
			col[u] ^= 1;
			cout << (sum > 1) << '\n';
		}
	}else if (mx <= 3 && cnt == 1)
	{
		int root = 1;
		for (int i = 1; i <= n; ++i)
			if ((int)adj[i].size() == 3) root = i;
		int now = 0;
		for (auto v: adj[root])
			++now, dfs(v, root, now);
		pos[root] = 1;
		for (int i = 1; i <= n; ++i) 
		{
			s[pos[i]] += col[i];
		}
		int tt = 0, vv = 0;
		for (int i = 1; i <= 3; ++i)
		{
			if (s[i]) ++tt;
			if (s[i] > 1) ++vv;
		}
		if (tt == 0) cout << 0 << '\n';
		else if (tt == 1) cout << vv << '\n';
		else if (tt == 2) cout << 1 << '\n';
		else if (tt == 3) cout << 2 << '\n';
		while (q--)
		{
			int u;
			cin >> u;
			if (col[u]) --s[pos[u]]; else ++s[pos[u]];
			col[u] ^= 1;
			int tt = 0, vv = 0;
			for (int i = 1; i <= 3; ++i)
			{
				if (s[i]) ++tt;
				if (s[i] > 1) ++vv;
			}
			if (tt == 0) cout << 0 << '\n';
			else if (tt == 1) cout << vv << '\n';
			else if (tt == 2) cout << 1 << '\n';
			else if (tt == 3) cout << 2 << '\n';
		}
	}else
	{
		int res = 0;
		dfs(1, 0);
		for (int i = 1; i <= n; ++i) res += (sz[i] == 1 && col[i]);
		if (sz[1] < 2) cout << 0 << '\n';
		else if (sz[1] == 2) cout << 1 << '\n';
		else cout << res << '\n';
		while (q--)
		{
			int u, res = 0;
			cin >> u;
			col[u] ^= 1;
			dfs(1, 0);
			for (int i = 1; i <= n; ++i) res += (sz[i] == 1 && col[i]);
			if (sz[1] < 2) cout << 0 << '\n';
			else if (sz[1] == 2) cout << 1 << '\n';
			else cout << res << '\n';
		}
	}
	return 0;
}