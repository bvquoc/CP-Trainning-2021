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

// /*
struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
// */

#define MAX 100005
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) (((n) >> (bit)) & 1)
#define flipBit(n, bit) ((n) ^ (1ll << (bit)))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k, l;
int s[MAX];
vg graph[MAX];

void input(){
	cin >> n >> m >> k >> l;
	FOR(int, i, 1, n){
		int cnt; cin >> cnt;
		int mask = 0;
		FOR(int, _, 1, cnt){
			int type; cin >> type;
			mask |= 1 << (type - 1);
		}
		s[i] = mask;
	}
	FOR(int, _, 1, m){
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
}

struct Data{
	int node = 0, mask = 0; ll len = 0;
	Data(){node = mask = len = 0;}
	Data(int node, int mask, ll len): node(node), mask(mask), len(len){}
};
bool operator < (Data a, Data b){
	return a.len > b.len;
}

priority_queue<Data> pq;
ll f[MAX][32];
void Dijkstra(){
	FOR(int, i, 1, n)
		FOR(int, j, 0, 31) f[i][j] = INT64_MAX;
	
	f[1][s[1]] = 0;
	pq.push(Data(1, s[1], 0));
	while (!pq.empty()){
		Data curr = pq.top(); pq.pop();
		if (curr.len != f[curr.node][curr.mask]) continue;

		for (Node child: graph[curr.node]){
			Data now = {child.node, curr.mask | s[child.node], curr.len + child.len};
			if (now.len < f[now.node][now.mask])
				f[now.node][now.mask] = now.len,
				pq.push(now);
		}
	}

	ll answer = INT64_MAX;
	FOR(int, mask, 0, 31)
		if (cntBit(mask) >= l)
			answer = min(answer, f[n][mask]);
	if (answer == INT64_MAX) answer = -1;
	cout << answer;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dhaka.inp", "r", stdin);
	freopen("dhaka.out", "w", stdout);
	input();
	Dijkstra();
}