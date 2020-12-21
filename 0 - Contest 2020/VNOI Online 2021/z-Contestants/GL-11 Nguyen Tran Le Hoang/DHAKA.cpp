#include <bits/stdc++.h>
using namespace std;

#define NAME "DHAKA"
#define N 100007
#define Times cout<<"\nTime: "<<clock()/(double)1000<<" sec"
#define fi first
#define se second
#define MASK(x) (1 << (x))
#define BIT(x, i) (((x) >> i) & 1)
#define int int64_t

int n, m, k, l;
int item[N];
int d[3][N], car[3][N];
vector<pair<int, int>> adj[N];

void dijkstra(int p)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
	int ii = 1; 
	if(p == n) ii = p, p = 0;
	d[p][ii] = 0;
	car[p][ii] = item[ii];
	q.push({0, ii});
	while(q.size())
	{
		int u = q.top().se, du = q.top().fi;
		q.pop();
		if(d[p][u] != du) continue;
		for(auto x: adj[u])
		{
			int v = x.se, uv = x. fi;
			if(d[p][v] > du + uv)
			{
				d[p][v] = du + uv;
				car[p][v] = car[p][u] | item[v];
				q.push({d[p][v], v});	
			}
			else 
				if(d[p][v] == du + uv)
				{
					int tmp1 = __builtin_popcount(car[p][v]);
					int tmp2 = __builtin_popcount((car[p][u] | item[v]));
					if(tmp1 < tmp2) car[p][v] = car[p][u] | item[v];
				}
		}
	}
}

signed main()
{
	memset(d, 0x3f, sizeof(d));
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);

	cin >> n >> m >> k >> l;
	
	for(int i = 1; i <= n; i++)
	{
		int s; cin >> s;
		while(s--)
		{
			int tmp; cin >> tmp;
			item[i] |= MASK(tmp - 1);
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[v].push_back({w, u});
		adj[u].push_back({w, v});
	}
	
	dijkstra(1);
	dijkstra(n);
	
	int res = 1e18, check = MASK(k) - 1;
	for(int i = 1; i <= n; i++)
	{
		int tmp = car[0][i] | car[1][i];
		if(tmp == check)
		{
				res = min(res, d[0][i] + d[1][i]);
		}
	}
	int res2 = 1e18;
	if(res == 1e18)
	{
		for(int i = 1; i <= n; i++)
		{
			int tmp = car[1][n] | car[0][i];
			if(tmp == check)
			{
				res2 = min(res2, d[0][i]*2 + d[1][n]);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			int tmp = car[1][n] | car[1][i];
			if(tmp == check)
			{
				res2 = min(res2, d[1][i]*2 + d[1][n]);
			}
		}		
	}	
	else
	{
		cout << res;
		return 0;
	}
	if(res2 != 1e18) cout << res2; else cout << -1;
//	Times;
}

/*  	                                   __      NaTyn <3
		                               _.-~  )
		                    _..--~~~~,'   ,-/     _
		                 .-'. . . .'   ,-','    ,' )
		               ,'. . . _   ,--~,-'__..-'  ,'
		             ,'. . .  (@)' ---~~~~      ,'
		            /. . . . '~~             ,-'
		           /. . . . .             ,-'
		          ; . . . .  - .        ,'
		         : . . . .       _     /
		        . . . . .          `-.:
		       . . . ./  - .          )
		      .  . . |  _____..---.._/ _______________
		~---~~~~----~~~~             ~~
*/

