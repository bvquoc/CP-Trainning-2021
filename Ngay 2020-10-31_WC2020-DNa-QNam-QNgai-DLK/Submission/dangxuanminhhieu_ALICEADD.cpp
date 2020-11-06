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

pll operator + (pll a, pll b){
	pll ans = {a.fi + b.fi, a.se + b.se};
	if (ans.se > 10000000000)
		ans.se -= 10000000000, ans.fi++;
	return ans;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	FOR(int, i, 1, t){
		string a, b; cin >> a >> b;
		while (a.length() < 20) a = '0' + a;
		while (b.length() < 20) b = '0' + b;

		pll A(0, 0), B(0, 0);
		FOR(int, i, 0, 9)
			A.fi *= 10, A.fi += a[i] - '0';
		FOR(int, i, 10, 19)
			A.se *= 10, A.se += a[i] - '0';
		FOR(int, i, 0, 9)
			B.fi *= 10, B.fi += b[i] - '0';
		FOR(int, i, 10, 19)
			B.se *= 10, B.se += b[i] - '0';
		
		A = A + B;
		int ans[20] = {};
		FORR(int, i, 9, 0)
			ans[i] = A.fi % 10, A.fi /= 10;
		FORR(int, i, 19, 10)
			ans[i] = A.se % 10, A.se /= 10;
		
		bool okay = false;
		FOR(int, i, 0, 19)
			if (ans[i]) {cout << ans[i]; okay = true;}
			else if (okay) cout << ans[i];
		if (!okay) cout << 0;
		cout << '\n';
	}
}