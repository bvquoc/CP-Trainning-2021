#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define PB push_back
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
int n, m, k;
pi sw[N];
string s;
void sub1()
{
	int i = 0, cnt = 0, mx = 0, L = 0, R = 0;
	while (i < n)
	{
		int l = i;
		while (s[i] == '1') cnt++, i++;
		int r = i - 1;
		if (cnt > mx)
		{
			mx = cnt;
			L = l;
			R = r;
		}
		cnt = 0;
		i++;
	}
	if (mx == 0) cout << -1;
	else cout << L + 1 << " " << R + 1;
}
void sub2()
{
	map <int, int> mark;
	int cur = 0, R = 0, mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
			cur++, mark[cur] = i;
		int len;
		if (cur <= k) len = i + 1;
		else len = i - mark[cur] + 1;
		if (len > mx)
		{
			mx = len;
			R = i + 1;
		}
	}
	cout << R - mx + 1 << " " << R;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= m; i++)
		cin >> sw[i].first >> sw[i].second;
	if (m == 0 && k == 0) sub1();
	else sub2();
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/

