#include <bits/stdc++.h>

const int N = 5e5 + 5;
const int INF = 1e9;

int n, m, k;
std::string s;

namespace baseCase {
bool alreadySatisfied() {
    int cnt0 = std::count(s.begin(), s.end(), '0');

    if (cnt0 == n and k == 0) {
        std::cout << -1;
        return true;
    }

    if (k >= cnt0) {
        std::cout << 1 << ' ' << n;
        return true;
    }

    return false;
}
} // namespace baseCase


namespace sub1 {
int ans = 0;
int l = 0, r = 0;

void solve() {
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;

        int p = i + 1;
        while (p < n and s[p] == '1') ++p;

        if (ans < p - i) {
            ans = p - i;
            l = i + 1;
            r = p;
        }
    }

    std::cout << l << ' ' << r;
}
} // namespace sub1

namespace sub2 {
int pref[N];
int ans = 0;
int l = 0, r = 0;

void solve() {
    std::fill(pref + 1, pref + N, INF);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] == '0');
    }

    for (int i = 1; i <= n; i++) {
        int p = std::upper_bound(pref + i + 1, pref + n + 1, k + pref[i - 1]) - pref - 1;
        if (p > n) continue;

        if (p - i + 1 > ans) {
            ans = p - i + 1;
            l = i;
            r = p;
        }
    }

    std::cout << l << ' ' << r;
}
} // namespace sub2

signed main() {
#ifndef LOCAL
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    std::cin >> s;

    if (baseCase::alreadySatisfied()) {
        return 0;
    }

    if (m == 0) {
        if (k == 0) {
            sub1::solve();
        }
        else {
            sub2::solve();
        }
    }

    return 0;
}
