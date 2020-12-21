#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define endl '\n'
#define int ll
#define file "DHAKA"
#define W first
#define V second
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define D(p) D[p.V][p.mask]

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxN = 1e5;

struct State
{
	int W, V, mask;
	State(int w, int v, int m): W(w), V(v), mask(m) {};
};

struct cmp
{
	operator()(State &a, State &b)
	{
		return a.W > b.W;
	}
};

ifstream fi(file".inp");
ofstream fo(file".out");
int n, m, k, l, A[maxN+1], D[maxN+1][MASK(5)];
vector<ii> Adj[maxN+1];

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		fill(D[i], D[i]+MASK(5), INT_MAX);
	priority_queue<State, vector<State>, cmp> Q;
	D[1][A[1]] = 0;
	Q.push({0, 1, A[1]});
	while (!Q.empty())
	{
		State p = Q.top();
		Q.pop();
		for (auto q: Adj[p.V])
		{
			State f(D(p)+q.W, q.V, p.mask|A[q.V]);
			if (D(f) > f.W)
			{
				D(f) = f.W;
				Q.push(f);
			}
		}
	}
}

signed main()
{
	fi >> n >> m >> k >> l;
	for (int i = 1; i <= n; i++)
	{
		int s;
		fi >> s;
		for (int j = 1; j <= s; j++)
		{
			int x;
			fi >> x;
			A[i] |= MASK(x-1);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		fi >> u >> v >> w;
		Adj[u].push_back({w, v});
		Adj[v].push_back({w, u});
	}
	dijkstra();
	int res = INT_MAX;
	for (int mask = 0; mask < MASK(k); mask++)
		if (__builtin_popcount(mask) >= l) res = min(res, D[n][mask]);
	fo << (res == INT_MAX ? -1 : res);
	// cin.get()
}
/*
((_,...,_))    
   |o o|
   \   /
    ^_^   
*/
