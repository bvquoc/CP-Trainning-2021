#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

int n, m, k;
string s;

namespace sub1
{
	void solve()
	{
		int ans = -1;
		int cnt = 0;
		int l = 1, r = 1;
		for(int i = 1; i <= n; ++i){
			if(s[i] == '1') ++cnt;
			else cnt = 0;
			if(cnt && ans < cnt){
				ans = cnt;
				l = i - cnt + 1;
				r = i;
			}
		}
		if(ans == -1) cout << ans;
		else cout << l << ' ' << r;
	}
}

namespace sub2
{
	void solve()
	{
		int ans = -1, cnt0 = 0, lf = 1;
		int l, r;
		for(int i = 1; i <= n; ++i){
			if(s[i] == '0') ++cnt0;
			while(cnt0 > k){
				if(s[lf++] == '0') --cnt0;
			}
			if(ans < i - lf + 1){
				ans = i - lf + 1;
				l = lf;
				r = i;
			}
		}
		if(ans == -1) cout << ans;
		else cout << l << ' ' << r;
	}
}

const int Nm3 = 2001;

vector <int> g[N];
int color[N];
int cntNode[N];
int lighted[N];
int curColor = 0;
int cnt[N];
int pre[Nm3][Nm3];

namespace sub3
{
	void dfs(int u){
		color[u] = curColor;
		++cntNode[curColor];
		if(s[u] == '1') ++lighted[curColor];
		for(size_t s = 0; s < g[u].size(); ++s){
			int v = g[u][s];
			if(!color[v]) dfs(v);
		}
	}

	void solve(){
		for(int i = 1; i <= n; ++i) if(color[i] == false){++curColor; dfs(i);}

		int ans = -1, ll, rr;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= curColor; ++j) pre[i][j] = pre[i-1][j];
			++pre[i][color[i]];
		}
		lighted[0] = -N;
		for(int r = 1; r <= n; ++r){
			int on = 0;
			for(int c = 1; c <= curColor; ++c){
				cnt[c] = pre[r][c];
				on += min(lighted[c], pre[r][c]);
			}
			//cerr << on << ' ';
			for(int l = 1; l <= r; ++l){
				if(on + k >= r - l + 1){
					if(r - l + 1 > ans){
						ans = r - l + 1;
						ll = l;
						rr = r;
					}
				} 
				if(--cnt[color[l]] < lighted[color[l]]) --on;
			} 	
		}

		if(ans == -1) cout << ans;
		else cout << ll << ' ' << rr;
	}
}

namespace sub4
{
	void dfs(int u){
		color[u] = curColor;
		++cntNode[curColor];
		if(s[u] == '1') ++lighted[curColor];
		for(size_t s = 0; s < g[u].size(); ++s){
			int v = g[u][s];
			if(!color[v]) dfs(v);
		}
	}

	void solve()
	{
		for(int i = 1; i <= n; ++i) if(color[i] == false){++curColor; dfs(i);}

		int l = 1;
		int on = 0;
		int ans = -1, ll, rr;
		for(int r = 1; r <= n; ++r){
			if(lighted[color[r]])
			  if(cnt[color[r]] < lighted[color[r]]) ++cnt[color[r]], ++on;
			while(r - l + 1 > on + k && l < r){
				if(lighted[color[l]])
					if(--cnt[color[l]] < lighted[color[l]]) --on;
				++l;
			}
			if(r - l + 1 > ans){
				ans = r - l + 1;
				ll = l;
				rr = r;
			}
		}

		if(ans == -1) cout << -1;
		else cout << ll << ' ' << rr;
	}
}

int main()
{
	freopen("DECOR.inp","r",stdin);
	freopen("DECOR.out","w",stdout);

	cin >> n >> m >> k;
	cin >> s;
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	s = " " + s;
	
	//sub4::solve();
	if(m == 0 && k == 0) sub1::solve();
	else if(m == 0) sub2::solve();
	else if(n <= 2000) sub3::solve();
	else sub4::solve();

	return 0;
}