#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define PB push_back
using namespace std;
typedef long long ll;
const int N = 2001;
const int MOD = 998244353;
int n;
string a[N];
ll fact[N];
void sub1()
{
	ll ans = 0;
	vector <int> per(n, 0);
	iota(per.begin(), per.end(), 1);
	do
	{
		string s = "";
		for (auto i : per) s += a[i];
		int even = 0, odd = 0;
		for (int i = 0; i < s.size(); i++)
			if (i % 2 == 0) even += (s[i] - '0');
			else odd += (s[i] - '0');
		if ((even - odd) % 11 == 0) ans++;
		ans %= MOD;
	}
	while (next_permutation(per.begin(), per.end()));
	cout << ans << endl;
}
void sub2()
{
	int even = 0, odd = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < a[i].size(); i++)
			if (j % 2 == 0) even += (a[i][j] - '0');
			else odd += (a[i][j] - '0'); 
	if ((even - odd) % 11 == 0) cout << fact[n] << endl;
	else cout << 0 << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
	fact[1] = 1;
	for (int i = 2; i < N; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n <= 8) sub1();
		else sub2();
	}
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/

