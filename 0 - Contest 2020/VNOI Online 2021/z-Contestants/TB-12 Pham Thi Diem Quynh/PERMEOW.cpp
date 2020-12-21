#include <bits/stdc++.h>

using namespace std;
int const N = 2e5 + 11;
int const mod = 1e9 + 7;
int n, okSub1 = 1, ans;
int a[N], b[N], pos[N], tmp[N], val[N];
void sub1(void)
{
    for(int i = 1; i <= n; ++i)
        pos[a[i]] = i, val[i] = a[i];
    for(int i = 1; i <= n; ++i)
    {
        ans += abs(pos[i] - i);
        for(int j = i; j <= pos[i] - 1; ++j)
            pos[val[j]]++;
        pos[i] = i;
        for(int j = 1; j <= n; ++j)
            tmp[pos[j]] = j;
        for(int j = 1; j <= n; ++j)
            val[j] = tmp[j];
    }
    cout << ans;
}
void sub2(void)
{
    int x = ((n - 1) / 2) * 2 + 1;
    ans = 1ll * x * x % mod * (n / 2) % mod * (n / 2) % mod;
    for(int i = 1; i <= n - 2; ++i)
        ans = 1ll * ans * i % mod;
    cout << ans;
}
int fact[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if(a[i] != b[i])
            okSub1 = 0;
    }
    if(okSub1)
    {
        sub1();
        return 0;
    }
    sub2();
    return 0;
}
