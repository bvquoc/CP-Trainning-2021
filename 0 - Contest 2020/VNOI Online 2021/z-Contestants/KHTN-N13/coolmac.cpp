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

/*
Before coding, here is my algorithm:
- We can see that not all t[i] matters; in fact, only the minimum matters. Let's call the minimum x
- So we need to cover [x, 10^5]
=> We need to be able to cover 10^5. So there must be at least 1 segment with r = 10^5
- We can see that every equipment costs 1 VND, so we will choose the one with minimum l among the ones with r = 10^5. Call that le
- while le > x:
	+ Find the one with minimum l among the segments with r >= le (= temp)
	+ le = temp
	+ increase answer by 1
- The minimum one can be done with minimum suffix
- Complexity: O(n)
*/

int n, m, mini_temp, mini[N], min_suffix[N];

signed main(){
	freopen("coolmac.inp", "r", stdin);
	freopen("coolmac.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i <= 100000; i++) mini[i] = oo;
	for(int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		// only the minimum l among segments with same r matters
		mini[r] = min(mini[r], l);
	}
	// only minimum matters
	mini_temp = 100005;
	cin >> m;
	for(int i = 1; i <= m; i++){
		int t;
		cin >> t;
		mini_temp = min(mini_temp, t);
	}
	min_suffix[100001] = oo;
	for(int i = 100000; i >= 0; i--) min_suffix[i] = min(min_suffix[i + 1], mini[i]);
	int ans = 0, itr = 100000;
	while(itr > mini_temp && ans <= n){
		ans++;
		itr = min_suffix[itr];
	}
	if(ans > n) cout << -1;
	else cout << ans;
}

