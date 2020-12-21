#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target ("avx")
#pragma GCC target ("avx2")
#pragma GCC target ("fma")
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI acos(-1)
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vpll endpoints; 
bool keep[100005], open[100005];
ll m, n;
pll seg[100005], kseg[100005];
ll t[100005];
ll dp[100005];
ll st[400005];
void build(ll root, ll l, ll r){
	st[root] = 1e9;
	if (l == r) return;
	ll mid = (l + r) / 2;
	build(root * 2 + 1, l, mid);
	build(root * 2 + 2, mid + 1, r);
}
void update(ll root, ll l, ll r, ll id, ll val){
	if ((id < l) || (r < id)) return;
	if (l == r){
		st[root] = val; return;
	}
	ll mid = (l + r) / 2;
	update(root * 2 + 1, l, mid, id, val);
	update(root * 2 + 2, mid + 1, r, id, val);
	st[root] = min(st[root * 2 + 1], st[root * 2 + 2]);
}
ll query(ll root, ll l, ll r, ll x, ll y){
	if ((y < l) || (r < x)) return 1e9;
	if ((x <= l) && (r <= y)) return st[root];
	ll mid = (l + r) / 2;
	return min(query(root * 2 + 1, l, mid, x, y), query(root * 2 + 2, mid + 1, r, x, y));
}
int main(){
	freopen("coolmac.inp", "r", stdin);
	freopen("coolmac.out", "w", stdout);
	fastio;
	cin >> m;
	for (ll i = 0; i < m; i++) cin >> seg[i].fi >> seg[i].se;
	sort(seg, seg + m);
	for (ll i = 0; i < m; i++) keep[i] = 1;
	for (ll i = 0; i < m; i++){
		endpoints.eb(mp(seg[i].fi, i));
		endpoints.eb(mp(seg[i].se, i));
	}
	sort(endpoints.begin(), endpoints.end());
	multiset <ll> ms;
	for (auto e : endpoints){
		ll id = e.se, pos = e.fi;
		if (!open[id]){
			ms.insert(pos); open[id] = 1;
		}
		else{
			ll rpos = seg[id].fi;
			if (rpos != (*ms.begin())) keep[id] = 0;
			open[id] = 0; ms.erase(ms.find(rpos));
		}
	}
	ll cm = 0;
	for (ll i = 0; i < m; i++){
		if (keep[i]){
			kseg[cm] = seg[i]; cm++;
		}
	}
	cin >> n;
	ll mint = 1e5 + 1;
	for (ll i = 0; i < n; i++){
		cin >> t[i]; mint = min(mint, t[i]);
	}
	ll ans = 1e9;
	if (kseg[cm - 1].se == 100000) dp[cm - 1] = 1;
	else dp[cm - 1] = 1e9;
	build(0, 0, cm - 1);
	update(0, 0, cm - 1, cm - 1, dp[cm - 1]);
	for (ll i = cm - 2; i >= 0; i--){
		if (kseg[i + 1].fi > kseg[i].se + 1) dp[i] = 1e9;
		else if (kseg[i].se == 100000) dp[i] = 1;
		else{
			ll l = i + 1, r = cm - 1; 
			while (l < r){
				ll mid = (l + r + 1) / 2;
				if (kseg[mid].fi <= kseg[i].se + 1) l = mid;
				else r = mid - 1;
			}
			dp[i] = query(0, 0, cm - 1, i + 1, l) + 1;
		}
		update(0, 0, cm - 1, i, dp[i]);
	}
	for (ll i = 0; i < cm; i++){
		if (kseg[i].fi <= mint) ans = min(ans, dp[i]);
	}
	if (ans == 1e9) ans = -1;
	cout << ans << "\n";
}
/*
3
250 100000
90 248
90 249
1
100
*/