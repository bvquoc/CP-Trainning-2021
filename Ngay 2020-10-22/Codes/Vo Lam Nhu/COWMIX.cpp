#include <bits/stdc++.h>
#define N 17
#define ll long long
using namespace std;
 
int n, k, s[N];
ll dp[1 << N][N];
void nhap()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
}
bool bit(ll x, int i)
{
    return (x >> i) & 1;
}
void solve()
{
    sort(s, s+n);
    for (int i = 0; i < n; i++) dp[1<<i][i] = 1;
    for (int x = 0; x < (1 << n); x++)
        for (int i = 0; i < n; i++)
        {
            if (bit(x, i) == 0) continue;
            for (int j = 0; j < n; j++)
                if (bit(x, j) && abs(s[i] - s[j]) > k)
                    dp[x][i] += dp[x ^ (1 << i)][j];
        }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += dp[(1 << n)-1][i];
    cout <<res;
}
int main()
{
    freopen("COWMIX.INP", "r", stdin);
    freopen("COWMIX.OUT", "w", stdout);
    nhap();
    solve();
}
