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

ll fibo[100], fLen = 74;
ll sl[100][100];
ll sum[100][100];

void initFibo(){
	fibo[0] = fibo[1] = 1;
	FOR(ll, i, 2, fLen)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	
	sl[0][0] = 1;
	FOR(ll, i, 1, fLen){
		FOR(ll, j, 0, i - 1) sl[i][j] = sl[i - 1][j];
		FOR(ll, j, 1, i)
			sl[i][j] += sl[i - 2][j - 1];
	}
	FOR(ll, i, 1, fLen)
		FORR(ll, j, i, 0){
			sum[i][j] = sl[i][j] * j + sum[i][j + 1];
			sl[i][j] += sl[i][j + 1];
		}
}

ll cal(ll num){
	//edge
	if (num == 0) return 0;
	if (num == 1) return 1;
	if (num == 2) return 2;
	//=========================

	int left = 1, right = fLen, pos = 0;
	while (left <= right){
		int mid = (left + right) >> 1;
		if (fibo[mid] <= num)
			pos = mid, left = mid + 1;
		else
			right = mid - 1;
	}

	ll answer = sum[pos][0];
	ll remain = num - fibo[pos] + 1;
	// cerr << num << "->" << answer + remain + cal(remain - 1) << '\n';
	return answer + remain + cal(remain - 1);
}

pll getSum(ll n, ll k){
	//edge case
	if (k == 0) return {n + 1, cal(n)};
	if (n == 0){
		if (k == 0) return {1, 0};
		return {0, 0};
	}
	if (n == 1){
		if (k == 0) return {2, 1};
		if (k == 1) return {1, 1};
		return {0, 0};
	}
	//=========================

	int left = 1, right = fLen, pos = 0;
	while (left <= right){
		int mid = (left + right) >> 1;
		if (fibo[mid] <= n)
			pos = mid, left = mid + 1;
		else
			right = mid - 1;
	}

	int currFibo = fibo[pos];
	pll answer = {sl[pos][k], sum[pos][k]};

	ll remain = n - fibo[pos] + 1;
	if (k == 0) answer.fi = n + 1, answer.se += n;
	else {
		pll curr = getSum(remain - 1, k - 1);
		curr.se += curr.fi;
		
		answer.fi += curr.fi, answer.se += curr.se;
	}
	return answer; 
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	initFibo();

	ll t; cin >> t;
	FOR(ll, _, 1, t){
		ll n, k; cin >> n >> k; 
		if (k > fLen) cout << "0\n";
		else cout << getSum(n, k).se << '\n';
	}
}