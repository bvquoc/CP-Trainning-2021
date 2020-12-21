#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e5 + 5;
typedef pair <int, int> ii;
#define foreach(i, c) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) 	((c).find(x) != (c).end())
#define reset(x) memset((x),0,sizeof(x))
#define endl '\n'
#define fortune "DHAKA"
#define bit(i,x)  (((x)>>(i))&1ll)
#define onbit(i,x)  ((x)|(1ll<<(i)))
#define offbit(i,x)  ((x)^(1ll<<(i)))
#define Count1(x) 	__builtin_popcountll((x))
#define fi 			first
#define se 		second
#define pb 		push_back
vector<ii>a[100005];
vector<int> dua[100005];
int mark[100005], count;
long long d[100005];
int n, ans, m, k, l;
void dijkstra(int s)
{
	for (int i = 1; i <= n; i++)
		d[i] = 1e15;
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>>pq;
	pq.push({0, s});
	while (pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if (d[u] != du)
			continue;
		for (int i = 0; i < a[u].size(); i++)
		{
			int v = a[u][i].fi;
			int uv = a[u][i].se;
			if (du + uv < d[v])
			{
				d[v] = du + uv;
				pq.push({d[v], v});
			}
		}
	}
}
void sub2()
{
	dijkstra(1);
	if (d[n] != 1e15)
		cout << d[n];
	else
		cout << -1;
	exit(0);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(fortune".inp", "r", stdin);
	freopen(fortune".out", "w", stdout);
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; i++)
	{	int x, y;
		cin >> x;
		for (int j = 0; j < x; j++)
			cin >> y, dua[i].push_back(y);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	if (l == 0)
		sub2();
	else
		cout << -1;
	return 0;
}
