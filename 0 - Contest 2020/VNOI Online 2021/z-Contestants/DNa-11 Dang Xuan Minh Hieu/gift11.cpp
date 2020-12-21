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

#define MAX 2002
#define MOD 998244353
const int M11 = 11;

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
	ll fact[MAX + 1] = {};
	Math(){
		fact[0] = 1;
		FOR(ll, i, 1, MAX)
			fact[i] = (fact[i - 1] * i) % MOD;
	}
} math;

struct Data{
	int num = 0, dig = 0, diff = 0;
	Data(){num = dig = diff = 0;}
	Data(int num): num(num){
		int tmp = num;
		int mul = 1;
		while (tmp){
			dig++; diff += (M11 + mul) * (tmp % 10), diff %= M11;
			mul *= -1; tmp /= 10;
		}
	}
};

int n;
Data num[MAX];

int checkSubtask(){
	if (n <= 8) return 1;
	
	bool allOdd = true, allEven = true;
	FOR(int, i, 1, n){
		bool odd = num[i].dig & 1;
		allOdd &= odd;
		allEven &= !odd;
	}
	if (allEven) return 2;
	if (allOdd) return 3;
	return 4;
}

struct Sub1{
	int answer = 0;
	bool done[MAX] = {};
	void test(int pos, int mod){
		if (pos > n){
			answer += (mod == 0);
			return;
		}
		
		FOR(int, i, 1, n){
			if (done[i]) continue;
			done[i] = true;

			Data curr = num[i];
			if (curr.dig & 1) test(pos + 1, (curr.diff + M11 - mod) % M11);
			else test(pos + 1, (curr.diff + mod) % M11);

			done[i] = false;
		}
	}
	Sub1(){
		test(1, 0);
		cout << answer << '\n';

		answer = 0;
		memset(done, false, sizeof(done));
	}
};

struct Sub2{
	Sub2(){
		int mod = 0;
		FOR(int, i, 1, n){
			mod += num[i].diff;
			mod %= M11;
		}
		if (mod) cout << 0 << '\n';
		else cout << math.fact[n] << '\n';
	}
};

struct Sub3{
	int f[MAX][MAX][M11];
	void dp(){
		f[1][0][M11 - num[1].diff] = 1;
		f[1][1][num[1].diff] = 1;
		FOR(int, i, 1, n - 1){
			Data nxt = num[i + 1];
			FOR(int, j, 0, i)
				FOR(int, mod, 0, M11 - 1){
					int cur = f[i][j][mod];
					if (!cur) continue;
					int &caseAdd = f[i + 1][j + 1][(mod + nxt.diff) % M11];
					int &caseNon = f[i + 1][j][(mod + M11 - nxt.diff) % M11];
					caseAdd += cur, caseAdd %= MOD;
					caseNon += cur, caseNon %= MOD;
				}
		}
		ll nega = n / 2, posi = n - nega;
		ll answer = f[n][posi][0];
		answer *= math.fact[posi], answer %= MOD;
		answer *= math.fact[nega], answer %= MOD;
		cout << answer << '\n';
	}
	Sub3(){
		dp();
		memset(f, 0, sizeof(f));
	}
};

struct Sub4{
	vector<Data> odd, even;
	int oddSize, evenSize;
	int f[MAX][MAX][M11];
	int ansOdd[M11] = {};

	void dpOdd(){
		if (oddSize == 0){
			ansOdd[0] = 1;
			return;
		}
		f[1][0][M11 - odd[1].diff] = 1;
		f[1][1][odd[1].diff] = 1;
		FOR(int, i, 1, oddSize - 1){
			Data nxt = odd[i + 1];
			FOR(int, j, 0, i)
				FOR(int, mod, 0, M11 - 1){
					int cur = f[i][j][mod];
					if (!cur) continue;
					int &caseAdd = f[i + 1][j + 1][(mod + nxt.diff) % M11];
					int &caseNon = f[i + 1][j][(mod + M11 - nxt.diff) % M11];
					caseAdd += cur, caseAdd %= MOD;
					caseNon += cur, caseNon %= MOD;
				}
		}
		ll nega = oddSize / 2, posi = oddSize - nega;
		ll mul = math.fact[posi] * math.fact[nega] % MOD;
		FOR(int, i, 0, M11 - 1)
			ansOdd[i] = mul * f[oddSize][posi][i] % MOD;
	}

	void dpEven(){
		int gap = oddSize + 1;
		int nega = gap / 2, posi = gap - nega;
		FOR(int, i, 0, M11 - 1)
			f[0][posi][i] = ansOdd[i];
		
		ll ans = 0;
		FOR(int, i, 0, evenSize - 1){
			int cntGap = gap + i;
			Data nxt = even[i + 1];

			FOR(int, posiPos, posi, n){
				int negaPos = cntGap - posiPos;
				FOR(int, mod, 0, M11 - 1){
					int cur = f[i][posiPos][mod];
					if (!cur) continue;

					f[i + 1][posiPos + 1][(mod + nxt.diff) % M11] += (1ll * cur * posiPos) % MOD;
					f[i + 1][posiPos + 1][(mod + nxt.diff) % M11] %= MOD;

					f[i + 1][posiPos][(mod + M11 - nxt.diff) % M11] += (1ll * cur * negaPos) % MOD;
					f[i + 1][posiPos][(mod + M11 - nxt.diff) % M11] %= MOD;
				}
			}
		}
		FOR(int, posiPos, posi, n + 1)
			ans += f[evenSize][posiPos][0], ans %= MOD;
		cout << ans << '\n';
	}
	Sub4(){
		odd.push_back(Data(0));
		even.push_back(Data(0));
		FOR(int, i, 1, n)
			if (num[i].dig & 1)
				oddSize++,
				odd.push_back(num[i]);
			else
				evenSize++,
				even.push_back(num[i]);
		//=================================
		dpOdd();
		memset(f, 0, sizeof(f));
		dpEven();

		oddSize = evenSize = 0;
		odd.clear(), even.clear();
		memset(f, 0, sizeof(f));
		memset(ansOdd, 0, sizeof(ansOdd));
	}
};

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("gift11.inp", "r", stdin);
	freopen("gift11.out", "w", stdout);
	int tests; cin >> tests;
	FOR(int, _, 1, tests){
		cin >> n;
		FOR(int, i, 1, n){
			int x; cin >> x;
			num[i] = Data(x);
		}

		int subtask = checkSubtask();
		if (subtask == 1) Sub1 sub1;
		else if (subtask == 2) Sub2 sub2;
		else if (subtask == 3) Sub3 sub3;
		else Sub4 sub4;
	}
}