#include <bits/stdc++.h>

using namespace std;

int T, n, p[2010], mod = 998244353;
int per[2010];
int fact[2010];

int check() {
    int odd = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x = p[per[i]];
        vector <int> digit;
        while (x) {
            digit.push_back(x % 10);
            x /= 10;
        }
        reverse(digit.begin(), digit.end());
        for (int i = 0; i < digit.size(); ++i) {
            odd ^= 1;
            if (odd) sum += digit[i];
            else sum -= digit[i];
        }
    }
    if (sum % 11 == 0) return 1;
    return 0;
}

int check_sub2() {
    int odd = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x = p[i];
        int cnt = 0;
        while (x) {
            x /= 10;
            ++cnt;
        }
        if (cnt % 2 == 1) return 0;
    }
    return 1;
}

void sub1() {
    int res = 0;
    do {
        if (check()) ++res;
    } while (next_permutation(per + 1, per + n + 1));
    cout << res << "\n";
}

int f[2020][1010][11];
int g[2020][2010][11];
int s[2010];

void sub4() {
    vector <int> odd = {0}, even = {0};
    for (int i = 1; i <= n; ++i) {
        int o = 0;
        int x = p[i];
        vector <int> digit;
        while (x) {
            digit.push_back(x % 10);
            x /= 10;
        }
        reverse(digit.begin(), digit.end());
        int rem = 0;
        for (int j = 0; j < digit.size(); ++j) {
            o ^= 1;
            if (o) rem = (rem + digit[j]) % 11;
            else rem = (rem + 11 - digit[j]) % 11;
        }
        if (digit.size() % 2) odd.push_back(rem);
        else even.push_back(rem);
    }
    int o = odd.size() - 1, e = even.size() - 1;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[0][0][0] = 1;
    for (int i = 1; i <= o; ++i) {
        for (int j = 0; j <= o / 2; ++j) {
            for (int rem = 0; rem < 11; ++rem) {
                f[i][j][rem] = f[i - 1][j][(rem + odd[i] + 11) % 11];
                if (j) f[i][j][rem] += f[i - 1][j - 1][(rem - odd[i] + 11) % 11];
                if (f[i][j][rem] >= mod) f[i][j][rem] -= mod;
            }
        }
    }
    for (int i = 0; i < 11; ++i)
        g[0][0][i] = 1ll * f[o][o / 2][i] * (1ll * fact[o / 2] * fact[o - o / 2] % mod) % mod;
    int cnt = (o + 1) / 2;
    int cc = o + 1 - (o + 1) / 2;
    for (int i = 0; i < e; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            for (int rem = 0; rem < 11; ++rem) {
                g[i + 1][j][(rem + 11 - even[i + 1]) % 11] = (0ll + g[i + 1][j][(rem + 11 - even[i + 1]) % 11] + 1ll * g[i][j][rem] * (i - j + cc)) % mod;
                g[i + 1][j + 1][(rem + 11 + even[i + 1]) % 11] = (0ll + g[i + 1][j + 1][(rem + 11 + even[i + 1]) % 11] + 1ll * g[i][j][rem] * (j + cnt)) % mod;
           }
        }
    }
    long long res = 0;
    for (int i = 0; i <= n; ++i)
        res = (res + g[e][i][0]) % mod;
    cout << res << "\n";
}

void sub2() {
    if (!check()) cout << 0 << "\n";
    else cout << fact[n] << "\n";
}

int main() {
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= 2000; ++i) fact[i] = 1ll * fact[i - 1] * i % mod;

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= 2000; ++i) per[i] = i;
        for (int i = 1; i <= n; ++i) cin >> p[i];
        if (n <= 8) sub1();
        else if (check_sub2()) sub2();
        else sub4();
    }
}
