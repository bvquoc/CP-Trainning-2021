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
const ll INF = 1e18;
vpll adj[100005]; 
ll dist[100005][32];
ll mask[100005];
ll bit_count[32];
ll n, m, k, l;
void init_dist(){
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < (1LL << k); j++) dist[i][j] = INF;
	} 
}
void dijkstra(ll src){
	init_dist();
	priority_queue <pair <ll, pll>, vector <pair <ll, pll>>, greater <pair <ll, pll>>> pq; 
	dist[src][mask[src]] = 0; pq.push(mp(0, mp(src, mask[src])));
	while (!pq.empty()){
		pair <ll, pll> f = pq.top(); pq.pop();
		ll u = f.se.fi, cur_mask = f.se.se, d = f.fi;
		if (dist[u][cur_mask] == d){
			for (auto nx : adj[u]){
				ll v = nx.fi, w = nx.se;
				ll nmask = cur_mask | mask[v];
				if (dist[v][nmask] > dist[u][cur_mask] + w){
					dist[v][nmask] = dist[u][cur_mask] + w;
					pq.push(mp(dist[v][nmask], mp(v, nmask)));
				}
			}
		}
	}
}
int main(){
	freopen("dhaka.inp", "r", stdin);
	freopen("dhaka.out", "w", stdout);
	fastio;
	cin >> n >> m >> k >> l;
	for (ll i = 0; i < 32; i++) bit_count[i] = __builtin_popcountll(i);
	for (ll i = 0; i < n; i++){
		ll cnt; cin >> cnt;
		for (ll j = 0; j < cnt; j++){
			ll ip; cin >> ip; ip--; mask[i] ^= (1LL << ip);
		}
	}
	for (ll i = 0; i < m; i++){
		ll u, v, w; cin >> u >> v >> w; u--; v--;
		adj[u].eb(mp(v, w)); adj[v].eb(mp(u, w));
	}
	dijkstra(0);
	ll ans = INF;
	for (ll lmask = 0; lmask < (1LL << k); lmask++){
		if (bit_count[lmask] >= l) ans = min(ans, dist[n - 1][lmask]);
	}
	if (ans == INF) ans = -1;
	cout << ans << "\n";
}