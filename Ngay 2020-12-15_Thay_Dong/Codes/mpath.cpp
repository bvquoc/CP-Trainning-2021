#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int s[N], t[N], cnt[N], dp[N];
vector <int> vals, adj[N];

int dfs(int u) {
    if (~dp[u]) return dp[u];
    dp[u] = 0;
    for (int v : adj[u])
        dp[u] = max(dp[u], dfs(v) + 1);
    return dp[u] += cnt[u];
}

int main() {
    freopen("mpath.inp", "r", stdin);
    freopen("mpath.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> t[i];
        if (s[i] > t[i])
            swap(s[i], t[i]);
        vals.push_back(s[i]);
        vals.push_back(t[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(),
    vals.end()), vals.end());
    for (int i = 0; i < m; i++) {
        s[i] = lower_bound(vals.begin(),
        vals.end(), s[i]) - vals.begin();
        t[i] = lower_bound(vals.begin(),
        vals.end(), t[i]) - vals.begin();
        if (s[i] == t[i]) cnt[s[i]]++;
        else adj[s[i]].push_back(t[i]);
    }
    int res = 0;
    for (int u = 0; u < vals.size(); u++) {
        dp[u] += cnt[u];
        res = max(res, dp[u]);
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << res << '\n';
}