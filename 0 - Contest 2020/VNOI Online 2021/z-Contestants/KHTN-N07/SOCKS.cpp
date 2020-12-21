#include <bits/stdc++.h>
using namespace std;

int n, q, cur;
int color[500005];
vector <int> Adj[500005];

int main()
{
	freopen("SOCKS.INP", "r", stdin);
	freopen("SOCKS.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> color[i];
		cur += color[i];
	}		
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		Adj[u].emplace_back(v);
		Adj[v].emplace_back(u);
	}
	cout << (cur > 0) << '\n';
	for(int i = 1; i <= q; i++)
	{
		int x;
		cin >> x;
		cur -= color[x];
		color[x] ^= 1;
		cur += color[x];
		cout << (cur > 0) << '\n';
	}
}