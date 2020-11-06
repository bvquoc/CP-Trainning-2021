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
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

/*
struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define MAX 5001
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

const int oo = 1e9;

int n, k;
vi graph[MAX];
int c[MAX], d[MAX];
int f[MAX][MAX];

void Dijkstra(){
	//init
	FOR(int, i, 1, n)
		FOR(int, j, 0, n)
			f[i][j] = oo;
	//=========================

	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	f[1][d[1]] = c[1]; pq.push({c[1], {1, d[1]}});
	while (!pq.empty()){
		pipii curr = pq.top(); pq.pop();
		int node = curr.se.fi, remain = curr.se.se, cost = curr.fi;
		if (curr.fi != f[node][remain]) continue;
		// cerr << node << '/' << remain << ' ' << cost << '\n';

		for (int child: graph[node]){
			//case 1: use the old ticket
			if (remain){
				int c1 = cost, r1 = remain - 1;
				// cerr << "   case1: " << child << '/' << r1 << ' ' << c1 << '\n';
				if (c1 < f[child][r1])
					f[child][r1] = c1,
					pq.push({c1, {child, r1}});
			}
			//=========================
			//case 2: new ticket
			int c2 = cost + c[node], r2 = d[node] - 1;
				// cerr << "   case2: " << child << '/' << r2 << ' ' << c2 << '\n';
			if (c2 < f[child][r2])
				f[child][r2] = c2,
				pq.push({c2, {child, r2}});
			//=========================
		}
	}
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(int, i, 1, n) cin >> c[i] >> d[i];
	FOR(int, _, 1, k){
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	Dijkstra();
	int answer = oo;
	FOR(int, i, 0, n)
		answer = min(answer, f[n][i]);
	cout << answer;
}