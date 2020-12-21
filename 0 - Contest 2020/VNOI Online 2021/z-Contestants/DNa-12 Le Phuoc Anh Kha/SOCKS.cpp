#include<bits/stdc++.h>
using namespace std;

int a[500005];
vector<int> adj[500005];
int deg[500005];

int main() {
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) cnt++;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    bool sub1 = 1;
    bool sub2 = 1;
    int cnt3 = 0;
    int deg3 = 0;
    for (int i = 1; i <= n ; i++) {
        if (deg[i] > 2) sub1 = 0;

        if (deg[i] == 3) {
            cnt3++;
            deg3 = i;
        }
        else if (deg[i] > 2) sub2 = 0;
    }

    if (cnt3 != 1) sub2 = 0;

    int l = 0, r = 0;
    for (auto i: adj[deg3]) {
        if (deg[i] == 1) {
            if (l == 0) l = i;
            else r = i;
        }
    }

    int other = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] && i != l && i != r && i != deg3) {
            other++;
        }
    }

    for (int i = 0; i <= q; i++) {
        if (i > 0) {
            int x;
            cin >> x;
            if (a[x] == 1) {
                cnt--;
                a[x] = 0;
                if (x != l && x != deg3 && x != r) other--;
            }
            else {
                cnt++;
                a[x] = 1;
                if (x != l && x != deg3 && x != r) other++;
            }
        }

        if (sub1) {
            if (cnt >= 2) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (sub2) {
            if (cnt >= 2) {
                if (a[l] == 0 || a[r] == 0) {
                    cout << 1 << "\n";
                }
                else {
                    if (other > 0) cout << 2 << "\n";
                    else cout << 1 << "\n";
                }
            }
            else cout << 0 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }


    return 0;
}
