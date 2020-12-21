#include <bits/stdc++.h>
using namespace std;
int n, q;
vector <int> adj[500001];
int red[500001], ans = 0, cnt = 0;

int main () {
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) {
        cin >> red[i];
        if (red[i] == 1) ++ cnt;
    }
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v;
//        cout << u << ' ' << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (cnt == 0 || cnt == 1) {
        cout << 0 << '\n';
    }else cout << 1 << '\n';
    while (q --) {
        int x; cin >> x;
        if (red[x] == 1) {
            red[x] = 0;
            -- cnt;
        }else {
            red[x] = 1;
            ++ cnt;
        }
        if (cnt == 0 || cnt == 1) {
            cout << 0 << '\n';
        }else cout << 1 << '\n';
    }
    return 0;
}
