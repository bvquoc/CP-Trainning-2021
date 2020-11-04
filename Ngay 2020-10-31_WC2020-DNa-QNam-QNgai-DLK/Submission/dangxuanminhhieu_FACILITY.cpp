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

#define MAX 2000001
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

int n, k;
pair<pii, int> data[MAX];

pair<int, pii> save[MAX]; int len = 0;
void compress(){
	FOR(int, i, 1, n)
		save[++len] = {data[i].fi.fi, {i, 1}},
		save[++len] = {data[i].fi.se, {i, 2}};
	sort(save + 1, save + 1 + len);

	int tmp = 0;
	FOR(int, i, 1, len){
		if (i == 1 || save[i].fi != save[i - 1].fi) tmp++;
		if (save[i].se.se == 1)
			data[save[i].se.fi].fi.fi = tmp;
		else
			data[save[i].se.fi].fi.se = tmp;
	}
}

ll bit[MAX];

void update(ll ind, ll num){
	while (ind < MAX)
		bit[ind] = max(bit[ind], num), ind += ind & -ind;
}

ll get(ll ind){
	ll ans = 0;
	while (ind)
		ans = max(ans, bit[ind]), ind -= ind & -ind;
	return ans;
}

bool cmp(pair<pii, int> a, pair<pii, int> b){return a.fi.se < b.fi.se;}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(int, i, 1, n){
		cin >> data[i].fi.fi >> data[i].fi.se >> data[i].se;
		data[i].fi.se += data[i].fi.fi + k;
	}
	compress();
	sort(data + 1, data + 1 + n, cmp);

	ll ans = 0;
	FOR(int, i, 1, n){
		// cerr << i << '\n';
		int st = data[i].fi.fi, en = data[i].fi.se, c = data[i].se;

		ll cost = c + get(st); ans = max(ans, cost);
		update(en, cost);
	}
	cout << ans;
}