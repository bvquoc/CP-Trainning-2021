///WizardAP_____没什么可看的！
#include<bits/stdc++.h>
using namespace std;
#define Nothing 				"DECOR"
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
const LL inf = 1e18;
const int mxn = 5e5 + 5;
LL fmul(LL a, LL b, LL mod) {a %= mod; b %= mod; LL q = (LD)a * b / mod; LL r = a * b - q * mod; return (r % mod + mod) % mod;}

///Head
int n, m, k, le[mxn], ri[mxn];
string s;
namespace sub1
{
void solve()
{
	int liml, limr;
	int res = 0;
	int l = 1, r = 0;
	while (l <= n)
	{
		while (s[l] != '1') l++, r++;
		while (s[r + 1] == '1') r++;
		if (r - l + 1 > res)
		{
			res = r - l + 1;
			liml = l;
			limr = r;
		}
		l++;
	}
	if (res == 0 ) cout << -1;
	else cout << liml << " " << limr << "\n";
}
}
namespace sub2
{
int v[mxn], d[mxn], c = 0;
int cnp(int pos)
{
	int l = 1, r = c, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (v[mid] < pos) l = mid + 1;
		else if (v[mid] - pos + 1 - (d[v[mid]] - d[pos] - 1) <= k)
			l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return v[ans];
}
void solve()
{
	int limr, liml, ma = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
			v[++c] = i, d[i] = c;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') {
			int t = cnp(i);
			if (t - i + 1 > ma)
			{	ma = t - i;
				liml = i, limr = t;
			}
		}
	if (liml > limr) cout << -1;
	else
	{
		int l = liml, r = limr;
		if (liml == limr) k -= 1;
		else k -= (limr - liml + 1) - (2 + d[limr] - d[liml] - 1);
		while (k > 0)
		{
			while (liml - 1 > 0 && k > 0) liml--, k--;
			while (limr + 1 <= n && k > 0) limr++, k--;
			if (liml == 1 && limr == n) break;
		}
		cout << liml << " " << limr << "\n";
	}
}
}
signed main()
{
	FastIO;
	freopen(Nothing".inp", "r", stdin);
	freopen(Nothing".out", "w", stdout);
	cin >> n >> m >> k;
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= m; i++)
	{
		cin >> le[i] >> ri[i];
	}
	if (m == 0 && k == 0) sub1::solve();
	else if (m == 0) sub2::solve();
	else cout << -1;
}