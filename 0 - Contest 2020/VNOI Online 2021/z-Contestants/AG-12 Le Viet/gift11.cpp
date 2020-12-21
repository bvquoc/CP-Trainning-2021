#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

const int N = 2007;

bool flag[11] = {false};
int t, n, res, p[11], a[N], c[N];

void get() {
    int cur = 0, S = 0;
    for (int i = 1; i <= n; ++i) {
        if (cur & 1) S += a[p[i]];
        else S -= a[p[i]];
        cur = (cur + c[p[i]]) % 2;
    }
    if (S % 11 == 0) ++res;
}

void backtrack(int i) {
    if (i > n) {
        get();
        return;
    }

    for (int j = 1; j <= n; ++j)
    if (!flag[j]) {
        p[i] = j;
        flag[j] = true;
        backtrack(i + 1);
        flag[j] = false;
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        char ss[11];
        cin >> ss + 1;

        a[i] = 0;
        c[i] = strlen(ss + 1);
        for (int j = 1; j <= c[i]; ++j)
            if (j & 1) a[i] += ss[j] - '0';
            else a[i] -= ss[j] - '0';
    }

    res = 0;

    if (n < 11) backtrack(1);
    else {
        int S = 0, p = 1;
        for (int i = 1; i <= n; ++i) {
            S += a[i];
            p = (p * 1LL * i) % MOD;
        }
        if (S % 11 == 0) res = p;
    }

    cout << res << '\n';
}

void process() {
    cin >> t;

    while (t--) solve();
}

int main() {
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);

    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    process();
}
