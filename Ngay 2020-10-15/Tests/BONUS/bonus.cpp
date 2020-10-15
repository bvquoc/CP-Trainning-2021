#include <bits/stdc++.h>
using namespace std;

#define a(i, j) aa[(i - 1) * n + j]
#define sum(i, j) sumsum[(i - 1) * n + j]

long long sumsum[1010101];
long long aa[1010101];

int main() {
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int m, n, q;
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a(i, j);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            sum(i, j) = sum(i - 1, j) + sum(i, j - 1) - sum(i - 1, j - 1) + a(i, j);

    while (q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        cout << sum(x, y) - sum(u - 1, y) - sum(x, v - 1) + sum(u - 1, v - 1) << endl;
    }

    return 0;
}
