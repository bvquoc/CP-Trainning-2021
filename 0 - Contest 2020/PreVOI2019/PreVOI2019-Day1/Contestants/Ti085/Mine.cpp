#include <bits/stdc++.h>
#define task "mine"

using namespace std;

const int mod = 1e6 + 3, N = 2005;

int pw(int x, int y)
{
    if (y == 1) return x;
    long long cur = pw(x, y >> 1);
    cur = (cur * cur) % mod;
    return y & 1 ? (cur * x) % mod : cur;
}

int bonus(int k)
{
    if (k == 1) return 1;
    int ans = 1;
    long long cur = 1;
    for (int i = 1; ; ++i)
    {
        cur = (cur * i) % mod;
        if (i < k) continue;
        if (i == k << 1)
        {
            ans = (1LL * ans * cur) % mod;
            break;
        }
        if (i > k + 1) continue;
        ans = (1LL * ans * pw(cur, mod - 2)) % mod;
    }
    return ans;
}

int m, a[N << 1], dp[N << 1][N << 1];

int solve(int l, int r)
{
    if (l > r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    int cur = 0;
    for (int j = l + 1; j <= r; j += 2)
    {
        if (a[j] > a[l] + m) break;
        cur += (1LL * solve(l + 1, j - 1) * solve(j + 1, r)) % mod;
        if (cur >= mod) cur -= mod;
    }
    return dp[l][r] = cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    int n;
    cin >> n >> m;
    if (m >= mod - 4)
    {
        cout << bonus(n);
        return 0;
    }
    for (int i = 1; i <= n << 1; ++i) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n << 1);
	return 0;
}
