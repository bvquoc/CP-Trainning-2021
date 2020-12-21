#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<ll, ll>
#define PB push_back
#define MASK(x) (1 << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcount
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
ll n, m, k, l;
ll d[2][N], curwm[2][N], wm[N];
vector <pi> adj[N];
void dijkstra(int u, int type)
{
	priority_queue <pi, vector<pi>, greater<pi>> q;
	memset(d[type], 0x3f, sizeof d[type]);
	q.push({0, u});
	d[type][u] = 0;
	curwm[type][u] |= wm[u];
	while (!q.empty())
	{
		ll dv = q.top().first, v = q.top().second;
		q.pop();
		if (dv != d[type][v]) continue;
		for (auto p : adj[v])
		{
			ll wp = p.first, wv = p.second;
			if (dv + wp < d[type][wv])
			{
				d[type][wv] = dv + wp;
				curwm[type][wv] |= wm[wv];
				q.push({d[type][wv], wv});
			}
			else
				if (dv + wp == d[type][wv])
					if (bp(curwm[type][v]) < bp(curwm[type][wv] | wm[wv]))
						curwm[type][v] = curwm[type][wv] | wm[wv];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
	cin >> n >> m >> k >> l;
	l = MASK(l);
	for (int i = 1; i <= n; i++)
	{
		int si;
		cin >> si;
		while (si--)
		{
			int x;
			cin >> x;
			wm[i] |= MASK(x - 1);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].PB({w, v});
		adj[v].PB({w, u});
	}
	dijkstra(1, 0);
	dijkstra(n, 1);
	ll ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		if (bp(curwm[0][i] | curwm[0][n]) >= bp(l)) ans = min(ans, d[0][n] + d[0][i] * 2);
		if (bp(curwm[1][i] | curwm[0][n]) >= bp(l)) ans = min(ans, d[0][n] + d[1][i] * 2);
	}
	if (ans == 1e18) cout << -1;
	else cout << ans;
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/

