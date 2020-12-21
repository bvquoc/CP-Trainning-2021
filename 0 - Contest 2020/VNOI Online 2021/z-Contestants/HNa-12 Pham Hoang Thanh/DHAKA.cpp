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
typedef pair<ll, int> ii;
typedef pair<ii, int> pi;

const int N = 1e5 + 5;
const ll oo = 1e15 + 7;
/* ---------- default ---------- */
int numNode, numEdge, numDiff, numBuy;
vector<ii> g[N];
int Mask[N];

void inp()
{
	cin >> numNode >> numEdge >> numDiff >> numBuy;
	forr(i, 1, numNode)
	{
		int Size, Type;
		cin >> Size;
		while (Size--)
		{
			cin >> Type;
			Mask[i]  |= (1 << (Type - 1));
		}
	}

	forr(i, 1, numEdge)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(ii(v, c));
		g[v].push_back(ii(u, c));
	}
}

priority_queue<pi, vector<pi>, greater<pi>> pq;

ll d[1 << 5][N];

void init()
{
	forr(x, 0, (1 << numDiff) - 1)
	forr(i, 1, numNode)
	d[x][i] = oo;
}

void Dijkstra(int root)
{
	d[Mask[root]][root] = 0;
	pq.push(pi(ii(d[Mask[root]][root], root), Mask[root]));
	while (pq.size())
	{
		int u = pq.top().fi.se;
		ll du = pq.top().fi.fi;
		int mask = pq.top().se;
		pq.pop();
		if (du != d[mask][u]) continue;
		for (auto p : g[u])
		{
			int v = p.fi;
			ll dv = 1ll * p.se;
			int newMask = (mask | Mask[v]);
			if (minimize(d[newMask][v], d[mask][u] + dv))
			{
				pq.push(pi(ii(d[newMask][v], v), newMask));
			}
		}
	}
}

void Output()
{
	init();
	Dijkstra(1);
	ll ans = oo;
	forr(mask, 0, (1 << numDiff) - 1)
	if (countBIT(mask) >= numBuy)
		ans = min(ans, d[mask][numNode]);

	cout << ((ans == oo) ? (-1) : (ans));
}

int main()
{
#define Task "DHAKA"
	if (fopen(Task".inp", "r"))
	{
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	inp();
	Output();
	return 0;
}
