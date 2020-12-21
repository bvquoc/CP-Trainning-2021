#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

int n, m, k, ll, rr, d[N], pre[N], pos[N], cnt[N], root[N];

int findroot(int x) {
    if (x == root[x]) return x;
    return root[x] = findroot(root[x]);
}

void __union(int x, int y) {
    if (x == y) return;
    if (x > y) swap(x, y);
    root[y] = x;
    d[x] += d[y];
    d[y] = d[x];
}

void read_input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        root[i] = i;
        d[i] = (c == '1');
        if (d[i] > 0 && ll == 0) {
            ll = i; rr = i;
        }
    }

    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        int x = findroot(u), y = findroot(v);
        __union(x, y);
    }

    for (int i = 1; i <= n; ++i)
        root[i] = findroot(root[i]);
}

void process() {
    for (int i = 1; i <= n; ++i) {
        pre[i] = pos[root[i]];
        pos[root[i]] = i;
    }

    int l = 1, res = 1, cur = 0;
    for (int r = 1; r <= n; ++r) {
        ++cnt[root[r]];

        if (cnt[root[r]] <= d[root[r]]) ++cur;

        while (cur + k < r - l + 1 && l <= r) {
            if (cnt[root[l]] <= d[root[l]]) --cur;
            --cnt[root[l]];
            ++l;
        }

        while (l > 1 && r - l + 2 <= cur + k + (cnt[root[l - 1]] + 1 <= d[root[l - 1]])) --l;

        if (l <= r && r - l + 1 > res) {
            res = r - l + 1;
            ll = l;
            rr = r;
        }
    }

    if (ll == 0) {
        cout << -1; return;
    }

    cout << ll << ' ' << rr << '\n';
}

int main() {
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);

    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    read_input();
    process();
}
