#include <bits/stdc++.h>

#define TASK "GIFT11"

using namespace std;

const int maxn = 2005;
const int mod = 998244353;

int n, a[maxn], odd[maxn], even[maxn], d[maxn], f[maxn];
long long res, g[maxn][maxn][14];

void InitF()
{
    f[0] = 1;
    for (int i = 1; i <= 2000; i ++) f[i] = f[i - 1] * i % mod;
}

void Analyze(int i)
{
    int cnt = 0;
    int x = a[i];
    while (x)
    {
        if (cnt % 2) odd[i] += x % 10;
        else even[i] += x % 10;
        cnt ++;
        x /= 10;
    }
    d[i] = (even[i] - odd[i] + 19487171) % 11;
}

namespace Sub1
{
    vector <int> cur;
    bool mk[maxn];

    void Solve()
    {
        int pos = 0, s = 0;
        for (auto i : cur)
        {
            if (pos % 2) s += even[i] - odd[i];
            else s += odd[i] - even[i];
            pos += int(log10(a[i]) + 1);

        }
        res += (s % 11 == 0);

    }

    void Perm(int pos, int val)
    {
        cur.push_back(val);
        mk[val] = 1;
        if (pos == n) Solve();
        else
        {
            for (int i = 1; i <= n; i ++)
                if (!mk[i]) Perm(pos + 1, i);
        }
        cur.pop_back();
        mk[val] = 0;
    }

    void Main()
    {
        for (int i = 1; i <= n; i ++) Perm(1, i);
        cout << res << "\n";
    }
}

namespace Sub2
{
    void Main()
    {
        int pos = 0, s = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (pos % 2) s += even[i] - odd[i];
            else s += odd[i] - even[i];
            pos += int(log10(a[i]) + 1);
        }
        if (s % 11 != 0) cout << 0;
        else cout << f[n] << "\n";
    }
}

namespace Sub3
{
    void Main()
    {
        int lim = 0;
        if (n % 2 == 0) lim = n / 2;
        else lim = n / 2 + 1;
        memset(g, 0, sizeof(g));
        g[0][0][0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 0; j <= i; j ++)
            {
                for (int t = 0; t <= 10; t ++)
                {
                    g[i][j + 1][(t + d[i]) % 11] = (g[i][j + 1][(t + d[i]) % 11] + g[i - 1][j][t]) % mod;
                    g[i][j][(t - d[i] + 121) % 11] = (g[i][j][(t - d[i] + 121) % 11] + g[i - 1][j][t]) % mod;
                }

            }
        }
        long long p = g[n][lim][0] * f[lim] % mod;
        if (n % 2) lim --;
        p = p * f[lim] % mod;
        cout << p << "\n";
    }

}

void Solve()
{
    cin >> n;
    bool all_odd = 1, all_even = 1;
    res = 0;
    memset(odd, 0, sizeof(odd));
    memset(even, 0, sizeof(even));
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        Analyze(i);
        int x = int(log10(a[i]) + 1);
        if (x % 2) all_even = 0;
        else all_odd = 0;
    }
    if (all_even) Sub2::Main();
    else if (all_odd) Sub3::Main();
    else if (n <= 9) Sub1::Main();

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);

    int Test;
    cin >> Test;
    InitF();
    while (Test--)
    {
        Solve();
    }


	return 0;
}
