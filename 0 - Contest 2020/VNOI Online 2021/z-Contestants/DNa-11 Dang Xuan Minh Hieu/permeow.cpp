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

#define MAX 200005
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

struct Math{
	ll f[MAX];
	ll fact[MAX];
	Math(){
		fact[0] = 1, f[0] = 0;
		FOR(ll, i, 1, MAX - 1){
			fact[i] = (fact[i - 1] * i) % MOD;
			f[i] = ((f[i - 1] * i % MOD) + ((i * (i - 1) / 2) * fact[i - 1] % MOD)) % MOD;
		}
	}
} math;
struct BIT{
	int len = 0;
	int bit[MAX];

	void clear(){
		memset(bit, 0, sizeof(bit));
	}

	void update(int num){
		while (num <= len)
			bit[num]++, num += num & -num;
	}

	int get(int num){
		int ans = 0;
		while (num)
			ans += bit[num], num -= num & -num;
		return ans;
	}

	BIT(){clear();}
	BIT(int len): len(len){clear();}
} bit;

int n, a[MAX], b[MAX];

ll cal(ll idx, ll len){
	idx--;
	ll ans = idx * math.f[len - 1] % MOD;
	ans += ((idx * (idx - 1) / 2) % MOD) * math.fact[len - 1] % MOD;
	return ans;
}

ll calTotal(int *arr){
	ll ans = 0; bit.clear();
	ll mul[MAX] = {};
	ll add[MAX] = {};
	FORR(int, i, n, 1){
		ll currNum = arr[i];
		ll idx = currNum - bit.get(currNum);
		
		ans += cal(idx, i), ans %= MOD;
		mul[i] = idx - 1;
		add[i + 1] = (idx - 1) * math.fact[i - 1] % MOD;

		bit.update(currNum);
	}
	FOR(int, i, 1, n){
		add[i] += add[i - 1], add[i] %= MOD;
		ans += mul[i] * add[i] % MOD, ans %= MOD;
	}
	return ans;
}

ll calPerm(int *arr){
	ll ans = 0; bit.clear();
	FORR(int, i, n, 1){
		int currNum = arr[i];
		ans += currNum - 1 - bit.get(currNum);
		bit.update(currNum);
	}
	return ans;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("permeow.inp", "r", stdin);
	freopen("permeow.out", "w", stdout);
	cin >> n; FORR(int, i, n, 1) cin >> a[i]; FORR(int, i, n, 1) cin >> b[i];
	bit = BIT(n);
	
	ll answer = calTotal(b) + MOD - calTotal(a); answer %= MOD;
	answer += calPerm(b), answer %= MOD;
	cout << answer;
}