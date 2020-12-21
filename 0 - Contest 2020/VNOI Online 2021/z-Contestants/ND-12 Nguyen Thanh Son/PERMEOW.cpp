#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7, pw[200005];
int n, a[200005], b[200005], f[200005], check_1 = 1, check_2 = 1;
void sub_1() {
    long long res = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (i < j && a[i] > a[j]) res ++;
    cout << res % mod;
}
void sub_2() {
    pw[1] = 1;
    for (int i = 2; i <= n; ++ i) pw[i] = pw[i - 1] *  i % mod;
    cout << (pw[n] * (n * (n - 1) / 4)) % mod;
}
int main()
{
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    for (int i = 1; i <= n; ++ i)  {
        if (a[i] != b[i]) check_1 = 0;
        if (a[i] != i && b[i] != n - i + 1) check_2 = 0;
    }
    if (check_1) {
        sub_1(); return 0;
    }
    if (check_2) {
        sub_2(); return 0;
    }
    return 0;
}
