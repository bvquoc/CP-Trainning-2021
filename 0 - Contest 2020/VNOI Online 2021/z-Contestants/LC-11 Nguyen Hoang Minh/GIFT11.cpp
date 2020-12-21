#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;
typedef pair <int, int> ii;
#define foreach(i, c) 	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) 	((c).find(x) != (c).end())
#define reset(x) memset((x),0,sizeof(x))
#define endl '\n'
#define fortune "GIFT11"
#define bit(i,x)  (((x)>>(i))&1ll)
#define onbit(i,x)  ((x)|(1ll<<(i)))
#define offbit(i,x)  ((x)^(1ll<<(i)))
#define 	Count1(x) 	__builtin_popcountll((x))
#define fi 				first
#define se 				second
#define pb 				push_back
int t, n, d[100], x[105];
string a[2000];
long long ans;
void ghinghiem()
{
	string s = "";
	for (int i = 1; i <= n; i++)
		s += a[x[i]];
	int t = 0;
	for (int i = 0; i < s.size(); i++)
		if (i % 2 == 0)
			t += (s[i] - '0');
		else
			t -= (s[i] - '0');
	if (t % 11 == 0)
		ans++;
}
void sinh(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (d[j] == 0)
			x[i] = j, d[j] = 1;
		else
			continue;
		if (i == n)
			ghinghiem();
		sinh(i + 1);
		d[j] = 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(fortune".inp", "r", stdin);
	freopen(fortune".out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ans = 0;
		sinh(1);
		cout << ans % MOD << endl;
	}


	return 0;
}
