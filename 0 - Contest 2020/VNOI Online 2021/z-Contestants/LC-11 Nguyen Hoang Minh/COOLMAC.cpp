#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e5 + 5;
typedef pair <int, int> ii;
#define foreach(i, c) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) 	((c).find(x) != (c).end())
#define reset(x) memset((x),0,sizeof(x))
#define endl '\n'
#define fortune "COOLMAC"
#define bit(i,x)  (((x)>>(i))&1ll)
#define onbit(i,x)  ((x)|(1ll<<(i)))
#define offbit(i,x)  ((x)^(1ll<<(i)))
#define 	Count1(x) 	__builtin_popcountll((x))
#define fi 				first
#define se 				second
#define pb 				push_back
int n, m, need = 1e9, ans = 1e9;
pair<int, int>a[100005];
int b[100005], f[100005], st[500005];
int lowbit(int x)
{
	return x & (-x);
}
void sub1()
{
	for (int i = 1; i <= (1 << m) - 1; i++)
	{
		vector<pair<int, int>>x;
		int bit1 = 0;
		for (int j = 0; j < m; j++)
			if (bit(j, i))
			{	x.push_back(a[j + 1]);
				bit1++;
			}
		int mi = x[0].first, ma = x[0].second;
		if (mi > need)
			continue;
		for (int j = 1; j < bit1; j++)
		{
			if (x[j - 1].second < x[j].first)
				break;
			ma = max(ma, x[j].second);
		}
		if (ma == 1e5)
			ans = min(ans, bit1);
	}
}
void sub2()
{
	f[1] = 1;
	if (a[1].first > need)
	{	cout << -1;
		return;
	}
	int imax = 0;
	for (int i = 1; i <= m; i++)
		if (a[i].first <= need)
		{	f[i] = 1;
			imax = max(i, imax);
		}
	for (int i = imax + 1; i <= m; i++)
	{
		f[i] = 1e9;
		for (int j = 1; j <= i - 1; j++)
			if (a[i].first <= a[j].second && a[i].second > a[j].second)
				f[i] = min(f[i], f[j] + 1);
	}
	for (int i = 1; i <= m; i++)
		if (a[i].second == 1e5)
		{
			ans = min(ans, f[i]);
		}
	if (ans == 1e9)
		cout << -1;
	else
		cout << ans;
}
void add(int p, int val)
{
	for (int i = p; i > 0; i -= lowbit(i))
		st[i] = min(st[i], val);
}
int get(int p)
{
	int res = 1e6;
	for (int i = p; i <= 100000; i += lowbit(i))
		res = min(res, st[i]);
	return res;
}
void sub3()
{
	f[1] = 1;
	if (a[1].first > need)
	{	cout << -1;
		return;
	}
	for (int i = 1; i <= 100000; i++)
		st[i] = INT_MAX;
	int imax = 0;
	for (int i = 1; i <= m; i++)
		if (a[i].first <= need)
		{	f[i] = 1;
			add(a[i].second, 1);
			imax = max(i, imax);
		}
	for (int i = imax + 1; i <= m; i++)
	{
		f[i] = 1e6;
		f[i] = min(f[i], get(a[i].first) + 1);
		add(a[i].second, f[i]);
	}
	for (int i = 1; i <= m; i++)
		if (a[i].second == 1e5)
			ans = min(ans, f[i]);
	if (ans == 1e6)
		cout << -1;
	else
		cout << ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(fortune".inp", "r", stdin);
	freopen(fortune".out", "w", stdout);
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + m + 1);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{	cin >> b[i];
		need = min(need, b[i]);
	}
	if (n <= 10 && m <= 16)
	{	sub1();
		if (ans == 1e9)
			cout << -1;
		else
			cout << ans;
	}
	else
	{
		if (n <= 3000 && m <= 3000)
			sub2();
		else
			sub3();
	}

	return 0;
}
