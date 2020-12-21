#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e5 + 5;
typedef pair <int, int> ii;
#define foreach(i, c) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) 	((c).find(x) != (c).end())
#define reset(x) memset((x),0,sizeof(x))
#define endl '\n'
#define fortune "SOCKS"
#define bit(i,x)  (((x)>>(i))&1ll)
#define onbit(i,x)  ((x)|(1ll<<(i)))
#define offbit(i,x)  ((x)^(1ll<<(i)))
#define 	Count1(x) 	__builtin_popcountll((x))
#define fi 				first
#define se 				second
#define pb 				push_back
int n, d, ans, dep = 1;
vector<int>a[100005];
int f[100005][20], depth[100005], mark[100005], q, m;
void dfs(int u)
{
	for (int i = 1; i <= 17; i++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (depth[v] == 0)
		{
			depth[v] = depth[u] + 1;
			dep = max(dep, depth[v]);
			f[v][0] = u;
			dfs(v);
		}
	}
}
int Lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = 17; i >= 0; i--)
		if (depth[f[u][i]] >= depth[v])
			u = f[u][i];
	if (u == v)
		return u;
	for (int i = 17; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(fortune".inp", "r", stdin);
	freopen(fortune".out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> mark[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	depth[1] = 1;
	dfs(1);
	if (dep == n)
	{	int dem = 0;
		for (int i = 1; i <= n; i++)
			if (mark[i] == 1)
				dem++;
		for (int i = 1; i <= n; i++)
			if (mark[i] == 1)
			{
				cout << 1 << endl;
				break;
			}
		while (q--)
		{
			int x;
			cin >> x;
			if (mark[x] == 0)
			{
				dem++;
				mark[x] = 1;
			}
			else
			{
				dem--;
				mark[x] = 0;
			}
			if (dem > 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
