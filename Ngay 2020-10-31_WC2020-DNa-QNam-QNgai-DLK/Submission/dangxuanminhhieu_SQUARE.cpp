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

#define MAX 1000001
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

const pll NaN = {INT64_MAX, INT64_MAX};

pll calculate(ll mi, ll pl){
	if ((pl + mi) & 1) return NaN;
	if (mi > pl) swap(pl, mi);
	return {(pl + mi) / 2, (pl - mi) / 2};
}

ll sq(ll scp){
	ll left = 0, right = 1000001;
	while (left <= right){
		ll mid = (left + right) >> 1;
		ll prod = mid * mid;

		if (prod == scp) return mid;
		else if (prod < scp) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll k; cin >> k;
	if (sq(k) != -1){cout << sq(k); return 0;}

	bool flip = false; if (k < 0) flip = true, k = -k;
	pll ans = NaN;
	FOR(ll, i, 1, k){
		if (i * i > k) break;
		if (k % i) continue;

		ll diff = i, sum = k / i;
		pll curr = calculate(diff, sum);
		
		if (curr == NaN) continue;
		if (flip) swap(curr.fi, curr.se);
		ans = min(ans, curr);
	}
	if (ans == NaN) cout << "none";
	else cout << ans.fi;
}