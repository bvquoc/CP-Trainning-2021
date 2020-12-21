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

const int N = 1e6 + 5;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
/* ---------- default ---------- */

int n;
int a[N], b[N];
bool T1 = true;
int ans = 0;
void inp()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
}
void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}
struct BinaryIndexTree
{
	int t[N];
	void init()
	{
		fill(t + 1, t + n + 1, 0);
	}
	int get(int x)
	{
		int res = 0;
		for (; x <= n; x += x & (-x))
			res += t[x];
		return res;
	}
	void upd(int x)
	{
		for (; x; x -= x & (-x))
			++t[x];
	}
} BIT;

int calc()
{
	int res = 0;
	BIT.init();
	for (int i = 1; i <= n; ++i)
	{
		add(res, BIT.get(a[i] + 1));
		BIT.upd(a[i]);
	}
	return res;
}

bool check()
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] > b[i])
			return false;
		if (a[i] < b[i])
			return true;
	}
	return true;
}
void trau()
{
	while (check())
	{
		add(ans, calc());
		if (!next_permutation(a + 1, a + n + 1))
			break;
	}
	cout << ans;
}

void Process()
{
	trau();
}

int main()
{
#define Task "PERMEOW"
	if (fopen(Task".inp", "r"))
	{
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	inp();
	Process();
	return 0;
}
