#include <bits/stdc++.h>

using namespace std;
int f[500005], n, m, k;
char s[500005];
void sub_1() {
    for (int i = 1; i <= n; ++ i)
        if (s[i] == '0') f[i] = 0; else if (s[i] == '1') f[i] = f[i - 1] + 1;
    int vt = 0, res = 0;
    for (int i = 1; i <= n; ++ i)
        if (f[i] > res) {res = f[i]; vt = i - res + 1;}
    cout << vt << ' ' << vt + res - 1;
}
void sub_2() {
    for (int i = 1; i <= n; ++ i)
        if (s[i] == '0') f[i] = f[i - 1]; else if (s[i] == '1') f[i] = f[i - 1] + 1;
    int vt = 0, res = 0;
    for (int i = 1; i <= n; ++ i) {
        int l = i, r = n, val = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f[mid] - f[i - 1] + k >= (mid - i + 1)) val = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (val - i + 1 > res) {vt = i; res = val - i + 1;}
    }
    cout << vt << ' ' << vt + res - 1;
}
int main()
{
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i) cin >> s[i];
    if (m == 0 && k == 0) {
        sub_1();
        return 0;
    }
    if (m == 0) {
        sub_2();
        return 0;
    }
    return 0;
}
