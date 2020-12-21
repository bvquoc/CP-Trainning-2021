#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fi first
#define se second
#define ll long long

using namespace std;

const ll INF = 1e18 + 7;
const int MAXN = 1e5 + 7, MASK = 32;

int f[MAXN], n, m, k, l;;
ll d[MAXN][MASK];
vector< pair<int,int> > adj[MAXN];

int main()
{
	freopen("DHAKA.INP","r",stdin);
	freopen("DHAKA.OUT","w",stdout);
	io;
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; ++i)
	{
		int s, x;
		cin >> s;
		while (s--) 
		{
			cin >> x, f[i] |= (1 << (x - 1));
		}
	}
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	int maxs = (1 << k);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < maxs; ++j) d[i][j] = INF;
	priority_queue< pair< ll, pair<int,int> > > pq;
	d[1][f[1]] = 0;
	pq.push({0, {1, f[1]}});
	while (pq.size())
	{
		ll w = -pq.top().fi;
		int u = pq.top().se.fi, mask = pq.top().se.se;
		pq.pop();
		if (w > d[u][mask]) continue;
		if (u == n && __builtin_popcount(mask) >= l)
		{
			cout << w;
			return 0;
		}
		for (auto it: adj[u])
		{
			int v = it.fi, nwmask = (mask | f[v]);
			ll cost = d[u][mask] + it.se;
			if (d[v][nwmask] > cost)
			{
				d[v][nwmask] = cost;
				pq.push({-cost, {v, nwmask}});
			}
		}
	}
	cout << -1;
	return 0;
}