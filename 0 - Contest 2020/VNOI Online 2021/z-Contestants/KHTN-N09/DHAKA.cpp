#include<bits/stdc++.h>

using namespace std;

#define int long long

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define vi vector<int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define ii pair<int, int> 
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll

#define iii pair<int, ii> 

const int maxN = 1e5 + 5, maxMask = 1ll << 6, inf = LLONG_MAX / 2;

int N, M, K, L, dp[maxN][maxMask];
int wMask[maxN];
vector<ii> G[maxN];
signed main()
{
	freopen("DHAKA.inp", "r",stdin);
	freopen("DHAKA.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K >> L;
	loop(i, 1, N)
	{
		loop(mask, 0, maxMask - 1)
		{
			dp[i][mask] = inf;
		}
	}
	loop(i, 1, N)
	{
		int s; cin >> s;
		loop(j, 1, s)
		{
			int k;
			cin >> k;
			wMask[i] |= 1ll << (k - 1);
		}
	}
	loop(id, 1, M)
	{
		int u, v, c;
		cin >> u >> v >> c;
		G[u].eb(v, c);
		G[v].eb(u, c);
	}
	priority_queue<iii, vector<iii>, greater<iii> > q;
	dp[1][wMask[1]] = 0;
	q.push({0, {1, wMask[1]}});
	while(!q.empty())
	{
		int dist = q.top().fi, u = q.top().se.fi, mask = q.top().se.se;
		q.pop();
		if(dist != dp[u][mask]) continue;
		for(ii e: G[u])
		{
			int v = e.fi, c = e.se;
			int nmask = mask | wMask[v];
			if(dp[v][nmask] > dp[u][mask] + c)
			{
				dp[v][nmask] = dp[u][mask] + c;
				q.push({dp[v][nmask], {v, nmask}});
			}
		}
	}
	int ans = inf;
	loop(mask, 0, (1ll << K) - 1)
	{
		if(bitCnt(mask) >= L)
		{
			ans = min(ans, dp[N][mask]);
		}
	}
	if(ans == inf) cout << -1;
	else cout << ans;
}