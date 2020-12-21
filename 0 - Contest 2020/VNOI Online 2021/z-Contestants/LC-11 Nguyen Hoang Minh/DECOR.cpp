#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e5 + 5;
typedef pair <int, int> ii;
#define foreach(i, c) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) 	((c).find(x) != (c).end())
#define reset(x) memset((x),0,sizeof(x))
#define endl '\n'
#define fortune "DECOR"
#define bit(i,x)  (((x)>>(i))&1ll)
#define onbit(i,x)  ((x)|(1ll<<(i)))
#define offbit(i,x)  ((x)^(1ll<<(i)))
#define 	Count1(x) 	__builtin_popcountll((x))
#define fi 				first
#define se 				second
#define pb 				push_back
int n, m, k, a[500005], ans, b[500005], Hav[500005], cha[500005];
ii ans1;
void sub1()
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1)
		{
			int j = i;
			while (a[j + 1] == 1)
				j++;
			if (ans < j - i + 1)
			{	ans = j - i + 1;
				ans1.fi = i;
				ans1.se = j;
			}
			i = j;
		}
	}
	cout << ans1.fi << " " << ans1.se;
}
bool check(int mid)
{
	for (int i = 1; i <= n - mid + 1; i++)
	{
		int hav = b[i + mid - 1] - b[i - 1];
		if (hav + k >= mid)
		{
			ans1.fi = i;
			ans1.se = i + mid - 1;
			return 1;
		}
	}
	return 0;
}
void sub2()
{
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	int l = 1, r = n, mid;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans1.fi << " " << ans1.se;
}

int tim(int u)
{
	if (cha[u] == 0)
		return u;
	return cha[u] = tim(cha[u]);
}
void join(int u, int v)
{
	int x = tim(u);
	int y = tim(v);
	if (x == y)
		return;
	cha[x] = y;
}
bool check1(int mid)
{
	for (int i = 1; i <= n - mid + 1; i++)
	{
		int hav = b[i + mid - 1] - b[i - 1];
		int s[500005];
		int hav2 = 0;
		for (int j = i; j <= i + mid - 1; j++)
		{
			int k = tim(j);
			s[k]++;
			if (s[k] == 1)
				hav2 += Hav[k];
			if (a[j] == 1)
				hav2--;
		}
		if (hav + k + hav2 >= mid)
		{
			ans1.fi = i;
			ans1.se = i + mid - 1;
			return 1;
		}
	}
	return 0;
}
void sub3()
{
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	int l = 1, r = n, mid;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check1(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans1.fi << " " << ans1.se;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(fortune".inp", "r", stdin);
	freopen(fortune".out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		join(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == 1)
			Hav[tim(a[i])]++;
	if (m == 0 && k == 0)
	{
		sub1();
	}
	else
	{
		if (m == 0)
			sub2();
		else
			sub3();
	}

	return 0;
}
