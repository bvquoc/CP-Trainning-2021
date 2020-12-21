#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 2005;
const int mod = 998244353;

pair <int, int> a[N];

int f[11];
int g[11];
int dp[N][N][11];
int n,m;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

/** at the ith odd card, we have j pos spot, k neg spot and sum of s(mod 11) */
int calc(int i, int j, int k, int s)
{
    int &res = dp[i][j][s];
    if (i > m)
        return (s == 0);
    if (res != -1)
        return res;
    res = 0;

    if (j > 0)
        add(res, (long long) j * calc(i + 1, j - 1, k, (s + a[i].se) % 11) % mod);
    if (k > 0)
        add(res, (long long) k * calc(i + 1, j, k - 1, (s - a[i].se + 11) % 11) % mod);
    return res;
}

/** at the ith even card, we have j pos spot, k neg spot and sum of s(mod 11) */
int solve(int i, int j, int k, int s)
{
    int &res = dp[i][j][s];
    if (i > n)
        return (s == 0);
    if (res != -1)
        return res;
    res = 0;

    add(res, (long long) j * solve(i + 1, j + 1, k, (s + a[i].se) % 11) % mod);

    add(res, (long long) k * solve(i + 1, j, k + 1, (s - a[i].se + 11) % 11) % mod);
    return res;
}

void reset()
{
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n + 1; j++)
    for (int s = 0; s < 11; s++)
    {
        dp[i][j][s] = -1;
    }
}

void proc()
{
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    reset();
    int cnt = 0;
    m = 0;
    for (int i = 1; i <= n; i++) if (a[i].fi == 1)
    {
        m = i;
    }
    for (int i = 0; i < 11; i++)
    {
        f[i] = calc(1, (m + 1) >> 1, m >> 1, (11 - i) % 11);
    }

    reset();
    for (int i = 0; i < 11; i++)
    {
        g[i] = solve(m + 1, (m + 1 + 1) >> 1, (m + 1) >> 1, (11 - i) % 11);
    }

    int ans = 0;
    for (int i = 0; i < 11; i++)
    {
        add(ans, (long long) f[i] * g[(11 - i) % 11] % mod);
    }
    cout << ans << "\n";
    reset();
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        int sum = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (j & 1)
                sum -= s[j] - '0';
            else
                sum += s[j] - '0';
        }
        sum = (sum % 11 + 11) % 11;

        a[i] = mp((int)s.size() % 2, sum);
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
}

int main()
{
    preproc();
    int t; cin >> t;
    while (t--)
    {
        enter();
        proc();
    }
    return 0;
}
