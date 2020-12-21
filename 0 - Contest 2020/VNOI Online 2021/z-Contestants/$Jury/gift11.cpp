#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 998244353;

void add(int& a, int b) { a += b; if (a >= MOD) a -= MOD; if (a < 0) a += MOD; }
int mul(int a, int b) { return 1LL * a * b % MOD; }
int pow(int a, int n)
{
    int t = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) t = mul(t, a);
        a = mul(a, a);
    }
    return t;
}

const int N = 2e3;
int ft[N + 2], invft[N + 2];
int P(int n, int k)
{
    if (n < 0 || k < 0) return 1;
    return mul(ft[n], invft[n - k]);
}

int solve(vector<int> even, vector<int> odd)
{
    vector<int> dp[2][11];
    int n = odd.size();
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 11; ++j)
            dp[i][j].resize(n + 1);

    int cur = 1, pre = 0;
    dp[cur][0][0] = 1;          // dp[considered so far][sum mod 11][positive count]
    for (int x : odd) {
        swap(cur, pre);
        for (int i = 0; i < 11; ++i)
            fill(dp[cur][i].begin(), dp[cur][i].end(), 0);
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < n; ++j)
                if (dp[pre][i][j]) {
                    add(dp[cur][(i + x) % 11][j + 1], dp[pre][i][j]);
                    add(dp[cur][(i + 11 - x) % 11][j], dp[pre][i][j]);
                }
    }

    vector<int> sum_odd(11, 0);
    int pos_pos = (n + 1) / 2;
    int neg_pos = n / 2;
    for (int i = 0; i < 11; ++i)
        sum_odd[i] = mul(dp[cur][i][(n + 1) / 2], mul(ft[pos_pos], ft[neg_pos]));

    int m = even.size();
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 11; ++j)
            dp[i][j].assign(m + 1, 0);
    dp[cur][0][0] = 1;          // dp[considered so far][sum mod 11][positive count]
    for (int x : even) {
        swap(cur, pre);
        for (int i = 0; i < 11; ++i)
            fill(dp[cur][i].begin(), dp[cur][i].end(), 0);
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < m; ++j)
                if (dp[pre][i][j]) {
                    add(dp[cur][(i + x) % 11][j + 1], dp[pre][i][j]);
                    add(dp[cur][(i + 11 - x) % 11][j], dp[pre][i][j]);
                }
    }

    pos_pos = n / 2 + 1;
    neg_pos = (n + 1) / 2;

    int ans = 0;
    for (int i = 0; i < 11; ++i)
        for (int j = 0; j <= m; ++j)
            if (dp[cur][i][j]) {
                add(ans, mul(dp[cur][i][j], mul(sum_odd[(11 - i) % 11], mul(P(j + pos_pos - 1, j), P(m - j + neg_pos - 1, m - j)))));
            }
    return ans;
}

int main()
{
#define TASK "GIFT11"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ft[0] = invft[0] = 1;
    for (int i = 1; i <= N; ++i) ft[i] = mul(ft[i - 1], i);
    invft[N] = pow(ft[N], MOD - 2);
    for (int i = N - 1; i > 0; --i)
        invft[i] = mul(invft[i + 1], i + 1);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int s = 0, l = 0;
            for (; x > 0; l ^= 1, x /= 10)
                if (l) s -= x % 10;
                else s += x % 10;
            s = (s % 11 + 11) % 11;
            if (l) odd.push_back(s);
            else even.push_back(s);
        }
        cout << solve(even, odd) << '\n';
    }
    return 0;
}