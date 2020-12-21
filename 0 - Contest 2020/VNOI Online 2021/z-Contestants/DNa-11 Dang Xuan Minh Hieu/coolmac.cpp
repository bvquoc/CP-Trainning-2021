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

#define MAX 100001
#define LIM 100000
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

struct Data{int l, r;};
bool cmp(Data a, Data b){
	return (a.l != b.l) ? (a.l < b.l) : (a.r > b.r);
}

int m, n;
Data resist[MAX];
int t = INT32_MAX;

priority_queue<int> pq;

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// #ifndef HIEU
	freopen("coolmac.inp", "r", stdin);
	freopen("coolmac.out", "w", stdout);
	// #endif
	cin >> m;
	FOR(int, i, 1, m) {
		int l, r; cin >> l >> r;
		resist[i] = {l, r};
	}
	cin >> n;
	FOR(int, i, 1, n){
		int x; cin >> x;
		t = min(t, x);
	}

	resist[++m] = {LIM + 1, LIM + 1};
	sort(resist + 1, resist + 1 + m, cmp);
	int cP = t, ans = 0;
	FOR(int, i, 1, m){
		Data curr = resist[i];
		if (curr.l >= cP){
			bool addNow = curr.l == cP;
			if (addNow) pq.push(curr.r);

			int best = pq.top();
			if (pq.empty() || (best < cP) || (best + 1 < curr.l)){cout << -1; return 0;}
			
			cP = best + 1, pq.pop(); ans++;
			if (!addNow) pq.push(curr.r);
			if (cP == LIM + 1) break;
		}
		else pq.push(curr.r);
	}
	cout << ans;
}