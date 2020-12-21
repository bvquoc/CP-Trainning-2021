#include <bits/stdc++.h>
#define pb push_back
using namespace std; 

int n, m, k; 

int p[500005], sz[500005]; 
int cnt[500005]; 
deque<int> s[500005]; 

int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]); 
}

void Merge(int u, int v) {
	u = Find(u), v = Find(v); 
	if(u == v) return; 
	if(sz[u] > sz[v]) swap(u, v); 
	p[u] = v; 
	sz[v] += sz[u]; 
}

// fenwick

int fen[500005]; 

void Update(int i) {
	while(i <= n) {
		fen[i]++;
		i += (i & (-i)); 
	}
}

int Query(int i) {
	int ret = 0; 
	while(i) {
		ret += fen[i]; 
		i -= (i & (-i)); 
	}	
	return ret; 
}
 
signed main() {
	freopen("decor.inp", "r", stdin); 
	freopen("decor.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m >> k; 
	for(int i = 1; i <= n; i++) {
		p[i] = i; 
		sz[i] = 1;
	}
	string ok; 
	cin >> ok; 
	for(int i = 1; i <= m; i++) {
		int u, v; 
		cin >> u >> v; 
		Merge(u, v); 
	}
	for(int i = 1; i <= n; i++) {
		int pi = Find(i); 
		cnt[pi] += (ok[i - 1] == '1'); 
		s[pi].pb(i); 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= cnt[i]; j++) {
			Update(s[i].front()); 
			s[i].pop_front(); 
		} 
	}
	int ans_l = 0, ans_r = -1;
	int r_ptr = 1;  
	for(int i = 1; i <= n; i++) {
		int sum_l = Query(i - 1);  
		while(r_ptr <= n) {
			int ones = Query(r_ptr) - sum_l;  
			if(r_ptr - i + 1 - ones > k) {
				break; 
			}
			r_ptr++; 
		}
		if(i < r_ptr and ans_r - ans_l + 1 < r_ptr - i) {
			ans_l = i; 
			ans_r = r_ptr - 1; 
		}
		int pi = Find(i); 
		if(!s[pi].empty()) {
			Update(s[pi].front()); 
			s[pi].pop_front(); 
		}
	}
	if(ans_r == -1) {
		cout << -1; 
	}
	else cout << ans_l << ' ' << ans_r; 
}