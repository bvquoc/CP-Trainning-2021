///WizardAP_____没什么可看的！
#include<bits/stdc++.h>
using namespace std;
#define Nothing 				"DHAKA"
#define ft 						first
#define sd 						second
#define pb						push_back
#define pf						push_front
#define sz(x)					(int)(x).size()

#define countone(x)				__builtin_popcountll((x))
#define rep(x,y)				for (int (x) = 0 ;(x) < (y);++(x))
#define repl(x,y)				for (int (x)=(y);(x)>=0;--(x))
#define each(x,y)				for (auto &x: y)
#define all(x)					(x).begin(),(x).end()
#define aln(x,y)				(x)+1,(x)+1+(y)
#define FastIO					ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using LL = int64_t;
using ULL = uint64_t;
using LD = long double;
using ii = pair<int, LL>;
const LL MOD = 1e9 + 7;
const LL inf = 1e18;

LL fmul(LL a, LL b, LL mod) {a %= mod; b %= mod; LL q = (LD)a * b / mod; LL r = a * b - q * mod; return (r % mod + mod) % mod;}

///Head
vector<ii> adj[100005];
vector<int> p[100005];
int n, m, k, l;
bool vs[100005];
namespace sub1
{
int d[10];
LL res = inf;
void dfs(int u, LL W, int wtml)
{
	if (u == n)
	{
		//cout << wtml << "\n";
		if (wtml < l)
		{
			int nwt = wtml;
			for (int mask = 0; mask < (1 << sz(p[u])); mask++)
			{
				vector<int> bit;
				for (int i = 0; i < sz(p[u]); i++)
					if (((mask >> i) & 1) == 1 && d[p[u][i]] == 0)
					{
						d[p[u][i]] = 1;
						nwt++;
					}
				if (nwt >= l) res = min(res, W);
				for (int x : bit)
					d[p[u][x]] = 0;
				bit.clear();
			}
		}
		else res = min(res, W);
		return;
	}
	vs[u] = 1;
	for (ii k : adj[u])
	{
		int v = k.ft;
		if (vs[v]) continue;
		LL w = k.sd;
		int nwt = wtml;
		if (sz(p[u]) == 0) dfs(v, W + w, wtml);
		else
		{

			for (int mask = 1; mask < (1 << sz(p[u])); mask++)
			{
				vector<int> bit;
				for (int i = 0; i < sz(p[u]); i++)
					if (((mask >> i) & 1) == 1 && d[p[u][i]] == 0)
					{
						d[p[u][i]] = 1;
						bit.pb(i);
						nwt++;
					}
				dfs(v, W + w, nwt);
				for (int x : bit)
					d[p[u][x]] = 0;
				bit.clear();
			}
		}
	}
	vs[u] = 0;
}
void solve()
{
	dfs(1, 0, 0);
	cout << (res == inf ? -1 : res);

}
}
namespace sub2
{
LL d[100005];
struct Edge
{
	int to;
	LL w;
	bool operator<(const Edge &o) const
	{
		return (w > o.w);
	}
};
priority_queue<Edge> pq;
LL dijkstra(int root)
{
	if (sz(p[root]) > 0) return inf;
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[root] = 0;
	pq.push({root, 0});
	while (!pq.empty())
	{
		int u = pq.top().to;
		LL W = pq.top().w;
		pq.pop();
		if (W != d[u]) continue;
		for (ii k : adj[u])
		{
			int v = k.ft;
			LL w = k.sd;
			if (sz(p[v]) > 0) continue;
			else
			{
				if (d[v] > d[u] + w)
				{
					d[v] = d[u] + w;
					pq.push({v, d[v]});
				}
			}
		}
	}
	return d[n];
}
void solve()
{
	LL res = dijkstra(1);
	cout << (res == inf ? -1 : res);
}
}
namespace sub3
{
LL d[100005];
struct Edge
{
	int to;
	LL w;
	bool operator<(const Edge &o) const
	{
		return (w > o.w);
	}
};
priority_queue<Edge> pq;
LL dijkstra(int root, int dich)
{
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[root] = 0;
	pq.push({root, 0});
	while (!pq.empty())
	{
		int u = pq.top().to;
		LL W = pq.top().w;
		pq.pop();
		if (W != d[u]) continue;
		for (ii k : adj[u])
		{
			int v = k.ft;
			LL w = k.sd;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				pq.push({v, d[v]});
			}

		}
	}
	return d[dich];
}
void solve()
{
	int chosen;
	for (int i = 1; i <= n; i++)
		if (sz(p[i]) == 1) {
			chosen = i;
			break;
		}
	LL r1 = dijkstra(1, chosen);
	LL r2 = dijkstra(chosen, n);
	cout << (r1 == inf || r2 == inf ? -1 : r1 + r2	) << "\n";
}
}
signed main()
{
	FastIO;
	freopen(Nothing".inp", "r", stdin);
	freopen(Nothing".out", "w", stdout);
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		while (t--)
		{
			int x;
			cin >> x;
			p[i].pb(x);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		LL w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	if (l == 0) sub2::solve();
	else if (k == 1) sub3::solve();
	else if (n <= 10) sub1::solve();
	else cout << -1;

}