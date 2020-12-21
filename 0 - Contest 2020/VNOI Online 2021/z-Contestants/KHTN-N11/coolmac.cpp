#include <bits/stdc++.h>
#define ii pair<int, int> 
#define fi first
#define se second
using namespace std;

int m, n; 
vector<ii> seg; 

priority_queue<int> pq; 

signed main() {
	freopen("coolmac.inp", "r", stdin); 
	freopen("coolmac.out", "w", stdout); 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> m; 
	for(int i = 1; i <= m; i++) {
		int l, r; 
		cin >> l >> r; 
		seg.push_back({l, r}); 	
	}
	sort(seg.begin(), seg.end()); 
	cin >> n; 
	int lef = 100000; 
	for(int i = 1; i <= n; i++) {
		int t; 
		cin >> t; 
		lef = min(lef, t); 
	}
	int ans = 0; 
	int ptr = 0, r = lef - 1; 
	while(r < 100000) {
		while(ptr < (int)seg.size() and seg[ptr].fi <= r + 1) {
			pq.push(seg[ptr].se); 
			ptr++; 
		}
		if(pq.empty()) {
			cout << -1; 
			return 0; 
		}
		int mx_r = pq.top(); 
		pq.pop(); 
		if(mx_r <= r) {
			cout << -1; 
			return 0; 
		}
		r = mx_r; 
		ans++; 
	}
	cout << ans; 
}