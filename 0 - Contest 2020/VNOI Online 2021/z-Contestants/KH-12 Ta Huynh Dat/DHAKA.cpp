#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define II pair<int,int>
#define III pair<int, II>
#define int long long

const int N = 1e5 + 7;
const int oo = 1e15;

int n, m, k, l;
int f[N][1<<5];
vector <II> g[N];
int num[N];

signed main()
{
	freopen("DHAKA.inp","r",stdin);
	freopen("DHAKA.out","w",stdout);

	cin >> n >> m >> k >> l;
	for(int i = 1; i <= n; ++i){
		int s; cin >> s;
		num[i] = 0;
		for(int j = 0; j < s; ++j){
			int x; cin >> x; --x;
			num[i] |= (1 << x);
		}
	}

	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}

	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < (1 << k); ++j) f[i][j] = oo;

	priority_queue <III, vector<III>, greater<III> > pq;
	pq.push({0, {1, num[1]}});
	f[1][num[1]] = 0;

	while(!pq.empty())
	{
		int fumask = pq.top().fi;
		int u = pq.top().se.fi;
		int mask = pq.top().se.se;
		pq.pop();

		for(int s = 0; s < g[u].size(); ++s){
			int v = g[u][s].fi;
			int c = g[u][s].se;
			int nxt = (mask | num[v]); 
			if(f[v][nxt] > fumask + c){
				f[v][nxt] = fumask + c;
				pq.push({f[v][nxt],{v,nxt}});
			}
		}
	}

	int ans = oo;
	for(int j = 0; j < (1 << k); ++j) if(__builtin_popcount(j) >= l) ans = min(ans, f[n][j]);
	cout << (ans == oo ? -1LL : ans);
}