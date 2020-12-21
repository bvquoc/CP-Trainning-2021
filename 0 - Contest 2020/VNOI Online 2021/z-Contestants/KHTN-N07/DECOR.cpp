#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dsu[500005], cnt[500005];
int r[500005];
string s;

int Root(int x)
{
	return dsu[x] == x ? x : dsu[x] = Root(dsu[x]);
}

void Union(int x, int y)
{
	x = Root(x);
	y = Root(y);
	if(x != y)
	{
		dsu[x] = y;
	}
}

int main()
{
	freopen("DECOR.INP", "r", stdin);
	freopen("DECOR.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
	}
	cin >> s;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		Union(a, b);
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
		{
			cnt[Root(i)]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		r[i] = i - 1;
		if(i != 0 and r[i - 1] != -1)
		{
			r[i] = r[i - 1];
			++cnt[Root(i - 1)];
			if(cnt[Root(i - 1)] <= 0)
			{
				++k;
			}
		}
		while(r[i] != n - 1)
		{
			int need = (cnt[Root(r[i] + 1)] <= 0);
			if(k - need >= 0)
			{
				cnt[Root(r[i] + 1)]--;
				k -= need;
				r[i]++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans, r[i] - i + 1);
	}
	if(ans == 0)
	{
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		if(ans == r[i] - i + 1)
		{
			cout << i + 1 << ' ' << r[i] + 1;
			return 0;
		}
	}
}