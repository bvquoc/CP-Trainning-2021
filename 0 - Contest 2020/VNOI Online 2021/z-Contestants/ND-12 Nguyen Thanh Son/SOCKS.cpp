#include <bits/stdc++.h>

using namespace std;
int n, q, color[100005], f[100005];
vector<int> a[100005];
void dfs(int u, int pa) {
    f[u] = 0;
    for (auto v : a[u]) {
        if (v == pa) continue;
        dfs(v, u);
        f[u] += f[v];
    }
    if (f[u] == 0) f[u] = color[u];
}
void sub() {
    dfs(1, 0);
    cout << f[1] << '\n';
    while (q --) {
        int u;
        cin >> u;
        color[u] = 1 - color[u];
        dfs(1, 0);
        cout << f[1] << '\n';
    }
}
int main()
{
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> color[i];
    for (int i = 1; i < n; ++ i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    sub();
    return 0;
}
