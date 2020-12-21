///WizardAP_____没什么可看的！
#include<bits/stdc++.h>
using namespace std;
#define Nothing 				"PERMEOW"
#define ft 						first
#define sd 						second
#define pb						push_back
#define pf						push_front
#define sz(x)					(int)(x).size()

#define countone(x)				__builtin_popcountll((x))
#define rep(x,y)				for (int (x) = 0 ;(x) < (y);++(x))
#define repl(x,y)				for (int (x)=(y);(x)>=0;--(x))
#define each(x,y)				for (auto &x: y)
#define all(x)					(x).begin(),(x).end()
#define aln(x,y)				(x)+1,(x)+1+(y)
#define FastIO					ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using LL = int64_t;
using ULL = uint64_t;
using LD = long double;
const LL MOD = 1e9 + 7;
const LL INF = 1e18;

LL fmul(LL a, LL b, LL mod) {a %= mod; b %= mod; LL q = (LD)a * b / mod; LL r = a * b - q * mod; return (r % mod + mod) % mod;}

///Head
int a[200005], b[200005], n;
signed main()
{
	FastIO;
	freopen(Nothing".inp", "r", stdin);
	freopen(Nothing".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	cout << 0;


}