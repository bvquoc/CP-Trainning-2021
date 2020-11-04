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

ll lenA, lenB, t, k;
ll a[MAX], b[MAX]; 

ll bs(ll *arr, ll &len, ll num){
	ll left = 0, right = len, ans = 0;
	while (left <= right){
		ll mid = (left + right) >> 1;
		if (arr[mid] <= num) ans = mid, left = mid + 1;
		else right = mid - 1;
	}
	return ans;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//input
	cin >> lenA >> lenB >> t >> k; k;
	FOR(int, i, 1, lenA) cin >> a[i]; a[0] = -k - 100;
	FOR(int, i, 1, lenB) cin >> b[i]; b[0] = -k - 100;
	//=========================
	#define A true
	#define B false
	ll currTime = 0; bool curr = A, force = false;
	ll aTime = 0, bTime = 0;
	while (currTime < t){
		// cerr << currTime << ' ' << (curr ? "A " : "B ") << aTime << '/' << bTime  << ' ' << (force ? "force" : "not") << '\n';
		ll *arr, len, *totalTime;
		if (curr == A) arr = a, len = lenA, totalTime = &aTime; 
		else arr = b, len = lenB, totalTime = &bTime;
		
		ll pos = bs(arr, len, currTime);
		// cerr << len << ' ' << pos << ' ' << arr[pos] << '\n';
		if (arr[pos] + k <= currTime){
			if (pos < len){
				*totalTime += arr[pos + 1] - currTime;
				currTime = arr[pos + 1];
				curr = !curr; force = true;
			} else {
				*totalTime += t - currTime;
				break;
			}
		} else {
			if (force){
				force = false;
				currTime = arr[pos] + k;
				continue;
			} else {curr = !curr, force = true;}
		}
	}
	cout << aTime << ' ' << bTime << '\n';
}