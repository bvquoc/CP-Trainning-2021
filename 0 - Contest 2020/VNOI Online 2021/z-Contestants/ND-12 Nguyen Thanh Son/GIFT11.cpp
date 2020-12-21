#include <bits/stdc++.h>

using namespace std;
long long mod = 998244353, pw[2005];
int t, s, ct, n[15], a[15][2005];
int calc(int a) {
    int val = 0;
    while (a != 0) {val ++; a /= 10;}
    return (val % 2 == 0);
}
void sub_1() {
    for (int k = 1; k <= t; ++ k) {
        long long res = 0; int b[2005];
        memset(b, 0, sizeof b);
        for (int i = 1; i <= n[k]; ++ i) b[i] = i;
        do {int pre = 1, du = 0;
            for (int i = 1; i <= n[k]; ++ i) {
                int c[2005], len = 0; int N = a[k][b[i]];
                while (N != 0) {c[++ len] = N % 10; N /= 10;}
                for (int j = len; j >= 1; -- j) {
                    if (pre) du += c[j]; else du -= c[j];
                    pre = 1 - pre;
                }
                du = (du + 11) % 11;
            }
            if (du % 11 == 0) res = (res + 1) % mod;
        } while (next_permutation(b + 1, b + n[k] + 1));
        cout << res << '\n';
    }
}
void sub_2() {
    pw[0] = 1;
    for (int i = 1; i <= 2000; ++ i) pw[i] = (pw[i - 1] * i) % mod;
    for (int k = 1; k <= t; ++ k) {
            int pre = 1, du = 0;
            for (int i = 1; i <= n[k]; ++ i) {
                int c[2005], len = 0; int N = a[k][i];
                while (N != 0) {c[++ len] = N % 10; N /= 10;}
                for (int j = len; j >= 1; -- j) {
                    if (pre) du += c[j]; else du -= c[j];
                    pre = 1 - pre;
                }
                du = (du + 11) % 11;
            }
            if (du % 11 == 0) cout << pw[n[k]] << '\n'; else cout << 0 << '\n';
    }
}
int main()
{
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++ i) {
        cin >> n[i];
        s += n[i]; int check = 1;
        for (int j = 1; j <= n[i]; ++ j) {
            cin >> a[i][j];
            if (!calc(a[i][j])) check = 0;
        }
        ct += check;
    }
    if (s <= 100) {sub_1(); return 0;}
    if (ct == t)  {sub_2(); return 0;}
    return 0;
}
