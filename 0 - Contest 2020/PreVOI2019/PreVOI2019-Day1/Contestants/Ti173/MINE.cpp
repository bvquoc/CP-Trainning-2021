#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200005;
const long long Mod = 1000003;

int n, m;
long long gt[MaxN], igt[MaxN];
long long catalan[MaxN];
long long f[MaxN], a[MaxN];

long long luythua(long long a, long long b)
{
    if(b == 0)
    {
        return 1;
    }
    long long t = luythua(a, b / 2);
    t = (t * t) % Mod;
    if (b % 2 == 1)
    {
        t = (t * a) % Mod;
    }
    return t;
}

void InitPower()
{
    gt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        gt[i] = (gt[i - 1] * i) % Mod;
    }
    igt[n] = luythua(gt[n], Mod - 2);
    for (int i = n - 1; i >= 1; i--)
    {
        igt[i] = (igt[i + 1] * (i + 1)) % Mod;
    }
}

void Catalan()
{
    catalan[0] = 1;
    for (int i = 2; i <= n; i += 2)
    {
        catalan[i] = (gt[i] * igt[i/2] * igt[i/2 + 1]) % Mod;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
    cin >> n >> m;
    n = n * 2;
    InitPower();
    Catalan();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[n] - a[1] <= m)
    {
        cout << catalan[n];
        return 0;
    }
    f[0] = 1;
    for (int i = 2; i <= n; i += 2)
    {
        if (a[i] - a[i-1] > m)
        {
            cout << 0;
            return 0;
        }
        for (int j = i - 1; j >= 1 && a[i] - a[j] <= m; j -= 2)
        {
            f[i] = (f[i] + f[j - 1] * catalan[i - j - 1]) % Mod;
        }
    }
    cout << f[n];
    return 0;
}