#include <bits/stdc++.h>

using namespace std;

int n, q, a[500010];
vector <int> adj[500010];

void sub1() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += a[i];
    if (cnt <= 1) cout << 0 << "\n";
    else cout << 1 << "\n";
    while (q--) {
        int x;
        cin >> x;
        if (a[x]) --cnt;
        else ++cnt;
        a[x] ^= 1;
        if (cnt <= 1) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}

int main() {
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sub1();
}
