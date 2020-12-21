#include <bits/stdc++.h>
#define fi "GIFT11.inp"
#define fo "GIFT11.out"
#define ii pair<int, int>
#define X first
#define Y second
#define MOD 998244353

using namespace std;

int n, a[2011];
bool visited[2011], sub2;
ii f[2011];

void INP()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int t = a[i], hs = 1;
        f[i] = ii(0, 0);
        while(t != 0)
        {
            f[i].X += hs * (t % 10);
            t /= 10;
            hs *= -1;
            f[i].Y++;
        }
        if (f[i].Y % 2 == 0) f[i].X = -f[i].X; else sub2 = 1;
    }
}

int Sub1(int k, int j, int s)
{
    int res = 0;
    if (k > n)
        if (s % 11 == 0) return 1; else return 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            visited[i] = 1;
            //cout << k << " " << j << " " << s << " " << i << endl;
            if (!j)
                res += Sub1(k + 1, (j + f[i].Y)%2, (s - f[i].X) % 11);
            else
                res += Sub1(k + 1, (j + f[i].Y)%2, (s + f[i].X) % 11);
            visited[i] = 0;
        }
    return res;
}

void Solve()
{
    //cout << n << endl;
    if (!sub2)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = (res + f[i].X) % 11;
        if (res == 0)
        {
            res = 1;
            for (int i = 1; i <= n; i++)
                res = (res * i) % MOD;
            cout << res << endl;
        } else cout << 0 << endl;
        return;
    }
    if (n <= 10)
        cout << Sub1(1, 1, 0) << endl;
}

int main()
{
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        INP();
        Solve();
    }
    return 0;
}


