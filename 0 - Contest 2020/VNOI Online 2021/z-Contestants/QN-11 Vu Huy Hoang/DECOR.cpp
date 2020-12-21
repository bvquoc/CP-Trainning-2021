#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[500010];
int l[500010], h[500010], total[500010];
int cnt[500010], sum;

int Find(int u) {
    return (u == l[u] ? u : l[u] = Find(l[u]));
}

void Union(int u, int v) {
    if ((u = Find(u)) == (v = Find(v))) return;
    if (h[u] < h[v]) swap(u, v);
    h[u] += h[v];
    total[u] += total[v];
    l[v] = u;
}

void sub2() {
    int len = 0, lhs = -1, rhs = -1;
    int sum = k;
    for (int l = 1, r = 1; l <= n; ++l) {
        while (r <= n && sum - (!a[r]) >= 0) sum -= (!a[r]), ++r;
        if (r - l > len) {
            lhs = l, rhs = r - 1;
            len = r - l;
        }
        sum += (!a[l]);
    }
    if (len == 0) cout << -1;
    else cout << lhs << ' ' << rhs << '\n';
    exit(0);
}

int check(int l, int r) {
    int sum = k;
    for (int i = 1; i <= n; ++i) cnt[i] = 0;
    for (int i = l; i <= r; ++i) ++cnt[Find(i)];
    for (int i = 1; i <= n; ++i)
        if (Find(i) == i) sum -= max(0, cnt[i] - total[i]);
    return sum >= 0;
}

void sub3() {
    int len = 0, lhs = -1, rhs = -1;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && check(i, j)) ++j;
        if (j - i > len) {
            lhs = i, rhs = j - 1;
            len = j - i;
        }
    }
    if (len == 0) cout << -1;
    else cout << lhs << " " << rhs << "\n";
    exit(0);
}


int newcost(int id) {
    id = Find(id);
    return sum - ((total[id] - cnt[id] - 1) < 0);
}

int main() {
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; ++i) l[i] = i, h[i] = 1, total[i] = a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    if (m == 0) sub2();
    if (n <= 2000) sub3();
    sum = k;
    int len = 0, lhs = -1, rhs = -1;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && newcost(j) >= 0) {
            ++cnt[Find(j)];
            sum -= (total[Find(j)] < cnt[Find(j)]);
            ++j;
        }
        if (j - i > len) {
            len = j - i;
            lhs = i, rhs = j - 1;
        }
        sum += (total[Find(i)] < cnt[Find(i)]);
        --cnt[Find(i)];
    }
    if (len == 0) cout << -1;
    else cout << lhs << ' ' << rhs << '\n';
}
