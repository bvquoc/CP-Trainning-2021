#include <bits/stdc++.h>
using namespace std;

int n;
int match[1005], vs[1005], a[1005][1005];
vector<int> adj[1005];

bool dfs(int u, int turn) {
    if (vs[u] == turn) return 0;
    vs[u] = turn;

    for (auto v: adj[u]) {
        if (match[v] == 0 || dfs(match[v], turn)) {
            match[v] = u;
            return 1;
        }
    }

    return 0;
}

bool solve(int x) {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        match[i] = 0;
        vs[i] = 0;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= x) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        res += dfs(i, i);
    }

    return (res == n);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;

    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }

    vector<int> v(s.begin(), s.end());

    int lower = 0, upper = v.size() - 1;
    while (lower < upper) {
        int mid = (lower + upper) / 2;

        if (solve(v[mid])) {
            lower = mid + 1;
        }
        else upper = mid;
    }

    if (!solve(v[lower])) lower--;
    cout << v[lower];

    return 0;
}