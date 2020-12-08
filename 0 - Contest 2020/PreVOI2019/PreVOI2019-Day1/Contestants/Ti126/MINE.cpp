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
const int maxn = 4e5 + 5;
const int lim = 4005;
const int MOD = 1e6 + 3;
int n, m;
int a[maxn * 2];

int gt[maxn], igt[maxn];

int dp[lim][lim];

inline void Add(int&tar, int val)
{
    tar += val;
    if(tar >= MOD) tar -= MOD;
}

void ReadInput()
{
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; ++i)
        cin >> a[i];
}

int Pow(int x, int n)
{
    if(n == 0) return 1;
    int t = Pow(x, n / 2);
    if(n % 2 == 0) return 1LL * t * t % MOD;
    else return 1LL * t * t % MOD * x % MOD;
}

void Prep()
{
    gt[0] = 1;
    for(int i = 1; i < maxn; ++i)
        gt[i] = 1LL * gt[i - 1] * i % MOD;
    igt[maxn - 1] = Pow(gt[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 0; --i)
        igt[i] = 1LL * igt[i + 1] * (i + 1) % MOD;
}

inline int C(int k, int n)
{
    return 1LL * gt[n] * igt[k] % MOD * igt[n - k] % MOD;
}

void Solve1()
{
    int ans = (C(n, 2 * n) - C(n - 1, 2 * n) + MOD) % MOD;
    cout << ans << '\n';
}

void Solve2()
{
    fill_n(&dp[0][0], sizeof(dp) / sizeof(dp[0][0]), 0);
    dp[0][0] = 1;
    for(int i = 1; i <= 2 * n; i += 2)
    {
        int index = (i - 1) / 2 + 1;
        int p = upper_bound(a + 1, a + 2 * n + 1, a[i] + m) - a - 1;
        int temp = 0;
        for(int j = 0; j < index; ++j)
            Add(temp, dp[i - 1][j]);
        for(int k = i + 1; k <= p; k += 2)
        {
            int in = k - i - 1;
            in /= 2;
            int Cin = (C(in, 2 * in) - C(in - 1, 2 * in) + MOD) % MOD;
            int add = 1LL * Cin * temp % MOD;
            Add(dp[k][index], add);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        Add(ans, dp[2 * n][i]);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
    Prep();
    ReadInput();
    if(m == 1e6)
        Solve1();
    else
        Solve2();
}
