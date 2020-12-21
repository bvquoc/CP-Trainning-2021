#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;
int a[200010], b[200010];

int check_sub1() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) return 0;
    return 1;
}

int check_sub2() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != i || b[i] != n - i + 1) return 0;
    return 1;
}


void sub1() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j)
            res += a[i] < a[j];
    }
    cout << res;
    exit(0);
}

int fact[200010], cnt[200010], ff[200010];

void sub2() {
    int cur = 1, res = 0;
    for (int i = 3; i <= n; ++i) cur = 1ll * cur * i % mod;
    for (int i = 0; i < n; ++i) res = (0ll + res + 1ll * cur * i) % mod;
    cout << res;
    exit(0);
}

int main() {
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    if (check_sub1()) sub1();
    if (check_sub2()) sub2();
    sub2();
}
