#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) (mask^(1ll << i))
#define OFFBIT(mask, i) (mask &~ (1ll << i))
#define countBIT(x) __builtin_popcountll(x)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;

template<class T> inline void Write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x *= -1;
	}
	if (x > 9) Write(x / 10);
	putchar(x % 10 + '0');
}

template<class T>inline void Read(T &x)
{
	char c;
	for (c = getchar(); (c > '9' || c < '0') && c != '-'; c = getchar());
	T y;
	if (c == '-')x = 0, y = -1;
	else x = c - '0', y = 1;
	for (c = getchar(); c >= '0' && c <= '9'; c = getchar())x = x * 10 + c - '0';
	x *= y;
}


template <class X, class Y> bool minimize(X &x, const Y &y)
{
	X eps = 1e-9;
	if (x > y + eps)
	{
		x = y;
		return true;
	}
	else return false;
}

template <class X, class Y> bool maximize(X &x, const Y &y)
{
	X eps = 1e-9;
	if (x + eps < y)
	{
		x = y;
		return true;
	}
	else return false;
}

template <class T> T Abs(const T &x)
{
	return (x < 0 ? -x : x);
}

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e3 + 5;
const int oo = 1e9 + 7;
const int mod = 998244353;
/* ---------- default ---------- */
int numTest;
int n;
int val[N];
string a[N];
int ans = 0;
int odd, even;
void inp()
{
	cin >> n;
	forr(i, 1, n)
	{
		cin >> a[i];
		val[i] = 0;
		for (int j = 0; j < a[i].size(); ++j)
		{
			if (j & 1)
				val[i] += (a[i][j] - '0');
			else
				val[i] -= (a[i][j] - '0');
		}
		val[i] %= 11;
		odd += ((a[i].size()) & 1);
		even += (!((a[i].size()) & 1));
	}
}
void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}
struct Sub1
{
	int pos[11];
	int sum[2];
	bool check()
	{
		sum[0] = sum[1] = 0;
		int i = 0;
		for (int j = 1; j <= n; ++j)
		{
			int id = pos[j];
			forr(k, 0, a[id].size() - 1)
			{
				sum[i & 1] += (a[id][k] - '0');
				++i;
			}
		}
		return (sum[0] - sum[1]) % 11 == 0;
	}
	void solve()
	{
		ans = 0;
		for (int i = 1; i <= n; ++i)
			pos[i] = i;
		do
		{
			add(ans, check());
		}
		while (next_permutation(pos + 1, pos + n + 1));
		cout << ans << "\n";
	}
} sub1;
int gt[N];
void giaithua()
{
	gt[0] = 1;
	for (int i = 1; i <= 2000; ++i)
		gt[i] = 1ll * i * gt[i - 1] % mod;
}
struct Sub2
{
	void solve()
	{
		int res = 0;
		int i = 0;
		for (int j = 1; j <= n; ++j)
			res += val[j];
		if (res % 11)
		{
			cout << 0 << "\n";
			return;
		}
		cout << gt[n] << "\n";
	}
} sub2;
void Process()
{
	if (even == n)
	{
		sub2.solve();
		return;
	}
	if (n <= 9)
	{
		sub1.solve();
		return;
	}
}
int main()
{
#define Task "GIFT11"
	freopen(Task".inp", "r", stdin);
	freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	giaithua();
	cin >> numTest;
	while (numTest--)
	{
		inp();
		Process();
	}
	return 0;
}
