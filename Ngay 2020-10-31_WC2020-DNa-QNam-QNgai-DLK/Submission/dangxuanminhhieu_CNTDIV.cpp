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

#define MAX 1000010
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

ll check[MAX];
mii save;

void sieve(){
	FOR(ll, i, 2, MAX - 1){
		if (check[i]) continue;
		check[i] = i;
		for (ll j = i * i; j < MAX; j += i)
			if (!check[j])
				check[j] = i;
	}
}

void factor(ll num){
	while (num > 1){
		ll p = check[num];
		save[p]++;
		num /= p;
	}
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	ll q; cin >> q;
	FOR(ll, _, 1, q){
		ll n; cin >> n;
		factor(n), factor(n + 1), factor(n + 2);

		ll d2 = 1, d1 = 1;
		for (auto i: save){
			d2 *= i.se * 2 + 1;
			d1 *= i.se + 1;
		}
		cout << d2 / 2 - d1 + 1 << '\n';
		save.clear();
	}
}