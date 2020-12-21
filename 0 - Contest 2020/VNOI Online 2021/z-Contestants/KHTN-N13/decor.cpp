#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

const int N = 1e5 + 5;

int n, m, k, comp[N], itr[N], cnt, countt[N], nxt[N];
ii answer;
vector<int> vc[N], Adj[N];
bool arr[N], vis[N];

void dfs(int u){
	//cout << u << "\n";
	vis[u] = 1;
	comp[u] = cnt;
	countt[cnt] += arr[u];
	vc[cnt].pb(u);
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v]) continue;
		dfs(v);
	}
}

signed main(){
	freopen("DECOR.inp", "r", stdin);
	freopen("DECOR.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		arr[i] = c - '0';
	}
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		Adj[x].pb(y);
		Adj[y].pb(x);
	}
	//return 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cnt++;
			dfs(i);
			sort(vc[cnt].begin(), vc[cnt].end());
			for(int j = 0; j < vc[cnt].size() - countt[cnt]; j++){
				nxt[vc[cnt][j]] = vc[cnt][j + countt[i]];
				//arr[vc[cnt][j]] = 1;
			}
			for(int j = 0; j < vc[cnt].size(); j++){
				if(j < countt[cnt]) arr[vc[cnt][j]] = 1;
				else arr[vc[cnt][j]] = 0;
			}
		}
	}
	//return 0;
	int itr = 0, cntk = 0;
	answer = {0, -1};
	for(int i = 1; i <= n; i++){
		while(itr <= n && cntk <= k){
			itr++;
			cntk += 1 - arr[itr];
		}
		itr--;
		if(itr - i > answer.se - answer.fi) answer = {i, itr};
		if(nxt[i] != -1 && arr[i]) arr[nxt[i]] = 1;
	}
	cout << answer.fi << " " << answer.se;
}


