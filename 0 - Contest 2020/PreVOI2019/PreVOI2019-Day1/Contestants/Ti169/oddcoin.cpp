#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 150007;

vector<int> vt = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int dp[150007];

void Solve()
{
    int x, t, ans = 0, newans = 1e15;
    cin >> x >> t;
    if(t == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if(x == t)
    {
        cout << 1 << '\n';
        return;
    }
    int MaxPrice = max(x, 50000ll);
    if(t > 150000)
    {
        ans += (t - 150000) / MaxPrice;
        t -= MaxPrice * ans;
    }
    if(t > 150000)
    {
        if(t >= MaxPrice) t -= MaxPrice, ans++;
        else
        {
            ans += (t - 150000 + 50000 - 1) / 50000;
            t -= 50000 * ((t - 150000 + 50000 - 1) / 50000);
        }
    }
    for(int i = 0; i * x <= t; i++)
    {
        newans = min(newans, i + dp[t - i * x] + ans);
    }
    cout << newans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("oddcoin.inp", "r")) freopen("oddcoin.inp", "r", stdin), freopen("oddcoin.out", "w", stdout);
    fill_n(dp, maxn, 1e15);
    dp[0] = 0;
    for(int i = 0; i < vt.size(); i++)
    {
        for(int j = vt[i]; j <= 150006; j++)
        {
            dp[j] = min(dp[j], dp[j - vt[i]] + 1);
        }
    }
    int sotest;
    cin >> sotest;
    while(sotest--) Solve();
}
