#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

pair<int, int> a[N];

int l, x, n, m, f[N], pos[N], it[4 * N];

void read_input() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a + 1, a + 1 + n);

    cin >> m; l = 100000;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        l = min(l, x);
    }
}

void getpos(int id, int l, int r) {
    it[id] = n + 2;

    if (l == r) {
        pos[l] = id;
        return;
    }

    int m = (l + r) >> 1;
    getpos(id << 1, l, m);
    getpos((id << 1) + 1, m + 1, r);
}

int get(int id, int l, int r, int x, int y) {
    if (x <= l && y >= r) return it[id];
    if (y < l || r < x) return n + 2;

    int m = (l + r) >> 1;

    return min(get(id << 1, l, m, x, y), get((id << 1) + 1, m + 1, r, x, y));
}

void upd(int id, int val) {
    it[id] = min(it[id], val);

    while (id) {
        id >>= 1;
        it[id] = min(it[id << 1], it[(id << 1) + 1]);
    }
}

void solve() {
    int res = n + 1, r = 100000;

    getpos(1, 1, 100000);

    for (int i = 1; i <= n; ++i) {
        if (a[i].first <= l && a[i].second >= l) {
            f[i] = 1;
            upd(pos[a[i].second], 1);
            if (a[i].second == 100000)
                res = min(res, 1);
            continue;
        } else {
            f[i] = get(1, 1, 100000, a[i].first - 1, a[i].second) + 1;
            if (f[i] > n) continue;
            if (a[i].second == 100000)
                res = min(res, f[i]);
            else upd(pos[a[i].second], f[i]);
        }

    }

    if (res == n + 1) res = -1;

    cout << res;
}

int main() {
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);

    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    read_input();
    solve();
}
