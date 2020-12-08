#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
const int coins[15] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
const int maxq = 55;
const int maxn = 1e5 + 5;
const int lim = 1e5 + 5;
const int INF = 1e9 + 19;
int q;
int x[maxq], t[maxq];
bool ok = true;

int dp[maxn];

void ReadInput()
{
    cin >> q;
    for(int i = 1; i <= q; ++i)
        cin >> x[i] >> t[i];
}

void Solve_trau(int new_coin, int tot)
{
    dp[0] = 0;
    for(int i = 1; i <= tot; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j < 15; ++j)
            if(i >= coins[j]) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        if(i >= new_coin) dp[i] = min(dp[i], dp[i - new_coin] + 1);
    }
    cout << dp[tot] << '\n';
}

void Solve(int new_coin, lli tot)
{
    int ans = INF;
    for(int uses = 0; uses <= lim; ++uses)
    {
        lli temp = 1LL * new_coin * uses;
        lli cur = tot - temp;
        if(cur < 0) continue;
        int cnt = uses;
        for(int j = 14; j >= 0; --j)
            if(cur >= coins[j])
            {
                cnt += cur / coins[j];
                cur %= coins[j];
            }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    ReadInput();
    for(int i = 1; i <= q; ++i)
    {
        if(t[i] <= 1e5)
            Solve_trau(x[i], t[i]);
        else
            Solve(x[i], t[i]);
    }
}
