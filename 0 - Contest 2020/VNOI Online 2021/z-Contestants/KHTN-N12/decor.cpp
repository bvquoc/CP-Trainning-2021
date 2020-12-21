#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll beg[100005], cnt[100005], col[100005]; 
vll adj[100005];
bool vis[100005];
ll n, m, k; 
ll lmx = -1, rmx = -1, cneed = 0;
void dfs(ll u, ll c){
	if (vis[u]) return; vis[u] = 1; col[u] = c;
	for (auto v : adj[u]) dfs(v, c);
}
void add(ll sth){
	cnt[col[sth]]--;
	if (cnt[col[sth]] < 0) cneed++;
}
void del(ll sth){
	if (cnt[col[sth]] < 0) cneed--;
	cnt[col[sth]]++; 
}
bool check(ll len){
	for (ll i = 0; i < n; i++) cnt[i] = beg[i];
	cneed = 0;
	for (ll i = 0; i < len - 1; i++) add(i);
	for (ll i = len - 1; i < n; i++){
		add(i);
		if (cneed <= k){
			lmx = i - len + 1, rmx = i; return 1;
		}
		del(i - len + 1);
	}
}
void bs(){
	if (!check(1)){
		cout << -1 << "\n"; exit(0);
	}
	ll l = 1, r = n;
	while (l < r){
		ll mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	bool tmp = check(l);
	cout << lmx + 1 << " " << rmx + 1 << "\n";
}
int main(){
	freopen("decor.inp", "r", stdin);
	freopen("decor.out", "w", stdout);
	fastio;
	cin >> n >> m >> k;
	string s; cin >> s;
	for (ll i = 0; i < m; i++){
		ll u, v; cin >> u >> v; u--; v--;
		adj[u].eb(v); adj[v].eb(u);
	}
	for (ll i = 0; i < n; i++){
		if (!vis[i]) dfs(i, i);
	}
	for (ll i = 0; i < n; i++){
		if (s[i] == '1') beg[col[i]]++;
	}
	bs();
}