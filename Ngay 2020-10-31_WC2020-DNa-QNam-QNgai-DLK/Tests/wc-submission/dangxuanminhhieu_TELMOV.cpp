#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;

#define MAX 10001
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

struct Data{ll node, channel, test, ex;};
bool operator > (Data a, Data b){return a.ex > b.ex;}
bool operator < (Data a, Data b){return a.ex < b.ex;}
typedef pair<ll, Data> Planet;

const ll oo = 1e17;
ll n, m, p, l, k;
vg graph[MAX];
ll f[MAX][11][11];

void init(ll n){
	FOR(int, l, 1, n)
		FOR(int, m, 0, l + 1)
			FOR(int, h, 0, k)
				f[l][m][h] = oo;
}

priority_queue<Planet, vector<Planet>, greater<Planet>> pq;
void Dijkstra(){
	init(n);
	
	pq.push({0, {1, 0, 0, 0}}); f[1][0][0] = 0;
	while (!pq.empty()){
		Planet curr = pq.top(); pq.pop();
		ll len = curr.fi; Data dat = curr.se;
		if (len != f[dat.node][dat.channel][dat.test]) continue;
		cerr << dat.node << ' ' << dat.channel << ' ' << dat.test << '=' << len << '\n';

		for (Node child: graph[dat.node]){
			// cerr << "// " << child << '\n'; 
			ll case1 = len + child.len;
			Data d1 = {child.node, min(l + 1, dat.channel + 1), dat.test, dat.ex};
			if (f[d1.node][d1.channel][d1.test] > case1)
				f[d1.node][d1.channel][d1.test] = case1, 
				pq.push({case1, d1});
			
			if (dat.channel > l || dat.test == k) continue;

			ll case2 = dat.ex + p;
			Data d2 = {child.node, 0, dat.test + 1, case2};
			if (f[d2.node][d2.channel][d2.test] > case2){
				f[d2.node][d2.channel][d2.test] = case2, 
				pq.push({case2, d2});
			}
		}
	}
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//input
	cin >> n >> m >> p >> l >> k;
	FOR(int, i, 1, m){
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back(Node(v, w));
		graph[v].push_back(Node(u, w));
	}
	//=========================
	Dijkstra();
	ll ans = oo;
	FOR(int, i, 0, l + 1)
		FOR(int, j, 0, k)
			ans = min(ans, f[n][i][j]);
	cout << ans;
}