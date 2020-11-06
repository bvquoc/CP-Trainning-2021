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

string s;

pair<int, string> process(int left, int right){
	int change = 0; string ans;

	int pos = left;
	while (pos <= right)
		if (isalpha(s[pos]))
			ans += s[pos++];
		else if ('0' <= s[pos] && s[pos] <= '9'){
			change++;
			
			int cnt = 0;
			while ('0' <= s[pos] && s[pos] <= '9')
				cnt *= 10, cnt += s[pos++] - '0';
			
			int end = pos + 1;
			while (s[end] != ')') end++;
			pair<int, string> curr = process(pos + 1, end - 1);
			
			// cerr << "//" << pos << "=>" << end << ' ' << cnt << ' ' << curr.se << '\n';
			change += curr.fi; pos = end + 1;
			FOR(int, i, 1, cnt)
				ans += curr.se;
		} else {
			change++;
			int end = pos + 1;
			while (s[end] != ']') end++;
			
			if (s[pos + 1] == '*'){
				pair<int, string> curr = process(pos + 2, end - 1);
				
				change += curr.fi; int len = curr.se.length();
				FORR(int, i, len - 1, 0)
					curr.se += curr.se[i];
				ans += curr.se;
			} else {
				pair<int, string> curr = process(pos + 1, end - 2);
				
				change += curr.fi; int len = curr.se.length();
				FORR(int, i, len - 2, 0)
					curr.se += curr.se[i];
				ans += curr.se;
			}
			pos = end + 1;
		}
	// cerr << left << "=>" << right << ' ' << ans << ' ' << change << '\n';
	return {change, ans};
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	// FOR(int, i, 0, 25)
	// 	cerr << i % 10; cerr << '\n';
	// FOR(int, i, 0, 25)
	// 	if (i / 10 != (i - 1) / 10) cerr << i / 10;
	// 	else cerr << ' ';cerr << '\n';
	pair<int, string> ans = process(0, s.length() - 1);
	cout << ans.fi << '\n' << ans.se;
}