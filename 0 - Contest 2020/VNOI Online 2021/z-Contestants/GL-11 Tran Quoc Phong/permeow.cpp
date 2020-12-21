#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define PB push_back
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
int n;
int a[N], b[N], p[N], fact[N], f[N];
void sub1()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) p[a[i]] = i;
	for (int i = 1; i <= n; i++)
		while (p[i] != i)
			if (i < p[i]) p[i]--, p[a[p[i]]]++, swap(a[p[i]], a[p[i] + 1]), cnt++;
			else p[i]++, p[a[p[i]]]--, swap(a[p[i]], a[p[i] - 1]), cnt++;
	cout << cnt;
}
void sub2()
{
	for (int i = 2; i <= n; i++)
		f[i] = (f[i - 1] * i % MOD) + ((fact[i - 1] * i % MOD) * ((i - 1) % MOD)) / 2;
	cout << f[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
	int ok = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if (b[i] != a[i]) ok = 0;
	}
	if (ok) sub1();
	else sub2();
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/

