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

#define MAX 500005
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

struct DSU{
	int len;
	int dsu[MAX];

	int findRoot(int node){
		return (dsu[node] < 0) ? node : (dsu[node] = findRoot(dsu[node]));
	}

	bool join(int u, int v){
		u = findRoot(u), v = findRoot(v);
		if (u == v) return false;

		if (dsu[u] > dsu[v]) swap(u, v);
		dsu[u] += dsu[v], dsu[v] = u;
		return true;
	}

	DSU(int len): len(len){
		FOR(int, i, 1, len) dsu[i] = -1;
	}
};

int n, m, k;
char s[MAX] = {};
int group[MAX] = {};
DSU *dsu;

int grBulb[MAX] = {};
int currOn[MAX] = {};
int allOn = 0;
int add(int node){
	int gr = group[node];
	currOn[gr]++;
	if (currOn[gr] <= grBulb[gr]) allOn++;
}
int del(int node){
	int gr = group[node];
	currOn[gr]--;
	if (currOn[gr] < grBulb[gr]) allOn--;
}
int del(int left, int right){
	FOR(int, i, left, right) del(i);
}

int check(int len){
	FOR(int, i, 1, len) add(i);
	if (allOn + k >= len) {del(1, len); return 1;}
	// 
	FOR(int, i, 2, n - len + 1){
		del(i - 1);
		add(i + len - 1);
		
		if (allOn + k >= len) {del(i, i + len - 1); return i;}
	}
	del(n - len + 1, n);
	return 0;
}
void findAns(){
	int left = 1, right = n, ans = -1, start = 0;
	while (left <= right){
		int mid = (left + right) >> 1;
		int given = check(mid);
		if (given)
			ans = mid, start = given,
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (ans == -1) cout << ans;
	else cout << start << ' ' << start + ans - 1;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("decor.inp", "r", stdin);
	freopen("decor.out", "w", stdout);
	cin >> n >> m >> k >> s + 1;
	dsu = new DSU(n);
	FOR(int, i, 1, m){
		int u, v; cin >> u >> v;
		dsu -> join(u, v);
	}

	FOR(int, i, 1, n){
		group[i] = dsu -> findRoot(i);
		grBulb[group[i]] += s[i] == '1';
	}

	findAns();
}