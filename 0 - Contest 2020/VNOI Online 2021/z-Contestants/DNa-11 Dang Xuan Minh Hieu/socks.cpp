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

/*
struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define MAX 500001
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

int n, q;
bool color[MAX]; int cntRed = 0;
int flag[MAX];
int cnt4[MAX];
vi graph[MAX];

int checkSub(){
	int ma = 0, cnt = 0;
	FOR(int, i, 1, n)
		if (graph[i].size() > ma)
			ma = graph[i].size(), cnt = 1;
		else if (graph[i].size() == ma)
			cnt++;
	if (ma > 3){
		if (n <= 1000 && q <= 1000) return 3;
		else return 4;
	} else if (ma == 3 && cnt == 1) return 2;
	else if (ma == 2) return 1;
	else return 4;
}

void dfs(int node, int parent, int val){
	flag[node] = val;
	if (color[node]) cnt4[val]++;

	for (int child: graph[node]){
		if (parent == child) continue;
		dfs(child, node, val);
	}
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("socks.inp", "r", stdin);
	freopen("socks.out", "w", stdout);

	cin >> n >> q;
	FOR(int, i,1, n){
		int x; cin >> x;
		color[i] = x; cntRed += x;
	}
	FOR(int, i, 1, n - 1){
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int subtask = checkSub();
	if (subtask == 1){
		FOR(int, i, 1, q){
			int node; cin >> node;
			if (color[node]) cntRed--;
			else cntRed++;
			color[node] = !color[node];
			cout << (!!cntRed) << '\n';
		}
	} 
	else if (subtask == 2){
		int root;
		FOR(int, i, 1, n)
			if (graph[i].size() == 3) {root = i; break;}
		
		FOR(int, i, 0, 2)
			dfs(graph[root][i], root, i + 1);
		
		FOR(int, i, 1, q){
			int node; cin >> node;
			int curFlag = flag[node];

			if (color[node]) cnt4[curFlag]--;
			else cnt4[curFlag]++;

			color[node] = !color[node];
			
			int ans = (!!cnt4[1]) + (!!cnt4[2]) + (!!cnt4[3]);
			if (ans == 0) cout << color[root] << '\n';
			else if (ans == 3) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	} 
	else {
		cout << "danh dau bai :P";
	}
}