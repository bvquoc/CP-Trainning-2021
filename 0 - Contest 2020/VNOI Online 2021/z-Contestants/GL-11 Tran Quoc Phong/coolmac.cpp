#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define PB push_back
#define MASK(x) (1 << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;
typedef long long ll;
const int N = 1e5;
int m, n;
pi a[N + 1];
int t = N + 1, f[N + 1], ans = N;
void sub1()
{
	for (int mask = 0; mask < MASK(m); mask++)
	{
		vector <pi> pick;
		for (int i = 0; i < m; i++)
			if (BIT(mask, i) == 1)
				pick.PB({a[m - i].first, a[m - i].second});
		sort(pick.begin(), pick.end());
		if (pick.empty()) continue;
		pi cur = pick[0];
		if (cur.first > t) continue;
		int check = 1;
		for (int i = 1; i < pick.size(); i++)
			if (pick[i].first > cur.second)
			{
				check = 0;
				break;
			}
			else cur = pick[i];
		if (check && cur.second == N) ans = min(ans, __builtin_popcount(mask));
	}
	if (ans != N) cout << ans;
	else cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		t = min(t, x);
	}
	sub1();
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/

