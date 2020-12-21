#include <bits/stdc++.h>

using namespace std;

int n, m, t = 1e5;
struct clothes {
    int l, r;
    int operator < (const clothes& other) const {
        if (r != other.r) return r < other.r;
        return l < other.l;
    }
} a[100010];

int dp[100010];
int st[400010];

void update(int id, int l, int r, int i, int val) {
    if (i > r || i < l) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u < 0) return 0;
    if (u > r || l > v) return 1e9;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void sub1() {
    for (int i = 0; i < t; ++i) dp[i] = 0;
    for (int i = t; i <= 1e5; ++i) dp[i] = 1e9;
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i].l - 1; j < a[i].r; ++j)
            dp[a[i].r] = min(dp[a[i].r], dp[j] + 1);
    }
    int res = 0;
    if (dp[100000] > n) cout << -1;
    else cout << dp[100000];
    exit(0);
}

int main() {
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
    }
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        t = min(t, c);
    }
    sort(a + 1, a + n + 1);

    if (n <= 3000 && m <= 3000) sub1();

    for (int i = 0; i < t; ++i) dp[i] = 0;
    for (int i = t; i <= 1e5; ++i) dp[i] = 1e9;
    for (int i = 0; i <= 1e5; ++i) update(1, 0, 1e5, i, dp[i]);

    for (int i = 1; i <= n; ++i) {
        dp[a[i].r] = min(dp[a[i].r], get(1, 0, 1e5, a[i].l - 1, a[i].r) + 1);
        update(1, 0, 1e5, a[i].r, dp[a[i].r]);
    }
    int res = 0;
    if (dp[100000] > n) cout << -1;
    else cout << dp[100000];
}
