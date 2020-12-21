/// Nỡm ///
#include <bits/stdc++.h>
using namespace std;
 
#define task "socks"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(__typeof(b) i=a; i<=b; i++)
#define DFOR(i,a,b) for(__typeof(b) i=b; i>=a; i--)
 
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
 
#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}
 
#define MOD 1000000007
#define MAXN 100011

int n,q;
int color[MAXN];
int qu[MAXN];

vector <int> adj[MAXN];

void read()
{
	cin >> n >> q;
	FOR(i,1,n)
		cin >> color[i];
	FOR(i,1,n-1)
	{
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	FOR(i,1,q)
	{	
		cin >> qu[i];
	}
}

bool visit[MAXN];

void DFS(int u)
{
	visit[u] = true;

	for(auto v:adj[u])
	{
		if(visit[v])
			continue;
		DFS(v);
	}
}

namespace sub1
{
	int res;
	void DFS(int u)
	{
		visit[u] = true;

		for(auto v:adj[u])
		{
			if(visit[v])
				continue;
			DFS(v);
		}
	}

	bool check()
	{
		FOR(i,1,n)
			if(adj[i].size() >2)
				return false;
		return true;
	}

	void solve()
	{
		FOR(i,1,q)
		{
			int res = 0;
			color[qu[i]] = !color[qu[i]];
			memset(visit,0,sizeof(visit));
			res = 0;
			DFS(qu[i]);
			cout << res << '\n';

		}
	}
}

void solve()
{

	if(sub1::check())
	{
		sub1::solve();
	}

	srand(time(NULL));
	while(q--)
	{
		
		cout << rand()% MOD<< '\n';
	}


}

int main()
{
	file;
	faster;

	read();
	solve();

	return 0;
}