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

const int maxN = 5e5 + 5, rmost = 5e5 + 1;

int N, M, K;
vector<int> cc; int onCnt; bool vs[maxN], on[maxN], cont[maxN];
vector<int> G[maxN];
ii ans = {1, 0};
int rPtr = 0, nowOff = 0;
int nxt[maxN];
void dfs(int u)
{
	vs[u] = 1;
	cc.eb(u);
	onCnt += on[u];
	for(int v: G[u])
	{
		if(!vs[v])
		{
			dfs(v);
		}
	}
}
signed main()
{
	freopen("DECOR.inp", "r",stdin);
	freopen("DECOR.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	loop(i, 1, N)
	{
		char c;
		cin >> c;
		on[i] = (c == '1');
	}
	loop(id, 1, M)
	{
		int u, v;
		cin >> u >> v;
		G[u].eb(v);
		G[v].eb(u);
	}
	loop(u, 1, N)
	{
		if(!vs[u])
		{
			cc.clear();
			onCnt = 0;
			dfs(u);
			sort(all(cc));
			loop(i, 0, (int)cc.size() - 1)
			{
				if(i + onCnt >= cc.size()) nxt[cc[i]] = rmost;
				else nxt[cc[i]] = cc[i + onCnt];
			}
			loop(i, 0, onCnt - 1)
			{
				on[cc[i]] = 1;
			}
			loop(i, onCnt, (int)cc.size() - 1)
			{
				on[cc[i]] = 0;
			}
		}
	}
	loop(i, 1, N)
	{
		if(i - 1 >= 1) 
		{
			if(cont[i - 1]) nowOff -= (!on[i]);
			if(nxt[i - 1] <= N and on[i - 1]) on[nxt[i - 1]] = 1;
			on[i - 1] = 0;
		}
		rPtr = max(rPtr, i - 1);
		while(rPtr < Na and nowOff + (!on[rPtr + 1]) <= K)
		{	
			nowOff += (!on[rPtr + 1]);
			cont[rPtr + 1] = 1;
			rPtr++;
		}
		if(ans.se - ans.fi + 1 < rPtr - i + 1)
		{
			ans = {i, rPtr};
		}
		if(ans.se - ans.fi + 1 == rPtr - i + 1)
		{
			if(ans.fi > i)
			{
				ans = {i, rPtr};
			}
		}
	}
	if(ans.fi > ans.se) cout << -1;
	else cout << ans.fi << " " << ans.se;
}