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

#define MAX 1001
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

class Match{
	private:
		int n1, n2;
		vector<vi> edge;
		vi match, visited;
		int currTime;

		bool dfs(int i1){
			if (visited[i1] == currTime) return false;
			visited[i1] = currTime;

			for (int i2: edge[i1])
				if (match[i2] == 0 || dfs(match[i2])){
					match[i2] = i1;
					return true;
				}

			return false;
		}

	public:
		Match();
		Match(int n1, int n2){
			this -> n1 = n1;
			this -> n2 = n2;

			edge = vector<vi>(n1);
		}

		void addRelationship(int u, int v){edge[u].push_back(v);}

		int doIt(){
			match = vi(n2, 0);
			visited = vi(n1, 0);
			
			vi thutu(n1);
			FOR(int, i, 0, n1 - 1) thutu[i] = i;
			random_shuffle(thutu.begin(), thutu.end());

			int answer = 0;
			FOR(int, i, 0, n1 - 1){
				currTime++;
				answer += dfs(thutu[i]);
			}

			return answer;
		}

		vi getConfig(){return match;}
};
Match *match;

int n;
int s[MAX][MAX];

bool check(int prod){
	match = new Match(n + 1, n + 1);
	FOR(int, i, 1, n)
		FOR(int, j, 1, n)
			if (s[i][j] >= prod)
				match->addRelationship(i, j);
	bool okay = (match -> doIt()) == n;
	delete match; 
	return okay;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(int, i, 1, n)
		FOR(int, j, 1, n) cin >> s[i][j];
	
	// cerr << "okay\n";
	int left = 1, right = 1e9, ans = 1;
	while (left <= right){
		int mid = (left + right) >> 1;
		// cerr << mid << '\n';
		if (check(mid)) ans = mid, left = mid + 1;
		else right = mid - 1;
	}
	cout << ans;
}