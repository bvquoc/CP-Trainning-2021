#include <bits/stdc++.h>
#define task "oddcoin"

using namespace std;

const int N = 1e5 + 5;

int x, t, c[15] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000}, dp[N];

int solve()
{
    cin >> x >> t;
    for (int i = 1; i <= t; ++i)
    {
        dp[i] = i < x ? N : dp[i - x] + 1;
        for (int j = 0; j < 15; ++j)
        {
            if (i < c[j]) break;
            dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    return dp[t];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int q; cin >> q;
	while (q--)
        cout << solve() << '\n';
	return 0;
}
