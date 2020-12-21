#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int n, m, k, l;
int Mask[100005];
long long Dist[100005][32];
vector <pair <int, int> > Adj[100005];
priority_queue <pair <long long, pair <int, int> >, vector <pair <long long, pair <int, int> > >, greater <pair <long long, pair <int, int> > > > pq;

int main()
{
	freopen("DHAKA.INP", "r", stdin);
	freopen("DHAKA.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> l;
	for(int i = 1; i <= n; i++)
	{
		int s;
		cin >> s;
		while(s--)
		{
			int id;
			cin >> id;
			id--;
			Mask[i] |= (1 << id);
		}
		for(int j = 0; j < 1 << k; j++)
		{
			Dist[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		Adj[u].emplace_back(v, c);
		Adj[v].emplace_back(u, c);
	}
	Dist[1][Mask[1]] = 0;
	pq.push(make_pair(0ll, make_pair(1, Mask[1])));
	while(pq.empty() == false)
	{
		long long dis = pq.top().first, pos = pq.top().second.first, msk = pq.top().second.second;
		pq.pop();
		if(dis == Dist[pos][msk])
		{
			for(auto x : Adj[pos])
			{
				if(Dist[x.first][msk | Mask[x.first]] > dis + x.second)
				{
					Dist[x.first][msk | Mask[x.first]] = dis + x.second;
					pq.push(make_pair(dis + x.second, make_pair(x.first, msk | Mask[x.first])));
				}
			}
		}
	}
	long long ans = INF;
	for(int i = 0; i < (1 << k); i++)
	{
		if(__builtin_popcount(i) >= l)
		{
			ans = min(ans, Dist[n][i]);
		}
	}
	if(ans == INF)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
}