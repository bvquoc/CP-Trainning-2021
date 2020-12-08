#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 4e5 + 7;
const int somod = 1000003;

int fac[maxn], invfac[maxn], n, m, a[maxn], dp[maxn], ctl[maxn];

int Pow(int a, int b)
{
    if(b == 0) return 1;
    int mid = Pow(a, b / 2);
    mid = mid * mid % somod;
    if(b & 1) mid = mid * a % somod;
    return mid;
}

void Prepare()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % somod;
    invfac[maxn - 1] = Pow(fac[maxn - 1], somod - 2);
    for(int i = maxn - 2; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1) % somod;
}

int Catalan(int x)
{
    return fac[2 * x] * invfac[x] % somod * invfac[x + 1] % somod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("mine.inp", "r")) freopen("mine.inp", "r", stdin), freopen("mine.out", "w", stdout);
    Prepare();
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    if(m == 1000000)
    {
        cout << Catalan(n);
    }
    else
    {
        for(int i = 0; i <= 2 * n; i++) ctl[i] = Catalan(i);
        for(int i = 1; i <= 2 * n; i++)
        {
            if(i & 1) continue;
            for(int j = i - 1; j >= 1; j-= 2)
            {
                if(a[i] - a[j] > m) break;
                dp[i] += dp[j - 1] * ctl[(i - j - 1) / 2];
            }
            dp[i] %= somod;
        }
        cout << dp[2 * n] << '\n';
    }
}
