#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int dp[N], leaf; bool col[N];
vector <int> adj[N];

void dfs(int u) {
    if (adj[u].size() == 0) {
        dp[u] = 1; leaf++; return;
    }
    if (col[u]) {
        dp[u] = N;
        for (int v : adj[u]) {
            dfs(v);
            dp[u] = min(dp[u], dp[v]);
        }
    }
    else {
        for (int v : adj[u]) {
            dfs(v); dp[u] += dp[v];
        }
    }
}

int main() {
    freopen("ptree.inp", "r", stdin);
    freopen("ptree.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    cout << leaf - dp[1] + 1 << '\n';
}