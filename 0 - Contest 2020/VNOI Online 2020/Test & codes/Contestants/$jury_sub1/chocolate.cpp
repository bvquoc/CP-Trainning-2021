#include <bits/stdc++.h>

using namespace std;
vector<int> adj[16];
int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("chocolate.inp", "r", stdin);
    freopen("chocolate.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    int n, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = i;
    do {
        bool ok = 1;
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) 
                if (ans[v] <= ans[u]) {
                    ok = false;
                    break;
                }
            if (!ok) break;
        }
        k -= ok;
        if (k == 0) {
            for (int i = 0; i < n; ++i)
                cout << ans[i] + 1<< ' ';
            return 0;
        }
    } while(next_permutation(ans.begin(), ans.end()));
    cout << "poor professor";
    return 0;
}
