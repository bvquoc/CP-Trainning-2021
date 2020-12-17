#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

vector <int> adj[2][N];
int in[N], out[N], tim, bit[N];
long long same; int root[2], n;

void update(int i, int v) {
    for (; i <= n; i += i & -i)
        bit[i] += v;
}

void update(int l, int r, int v) {
    update(l, v); update(r + 1, -v);
}

int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

void dfs0(int u) {
    in[u] = ++tim;
    for (int v : adj[0][u]) dfs0(v);
    out[u] = tim;
}

void dfs1(int u) {
    same += query(in[u]);
    update(in[u], out[u], 1);
    for (int v : adj[1][u]) dfs1(v);
    update(in[u], out[u], -1);
}

int main() {
    freopen("cptrees.inp", "r", stdin);
    freopen("cptrees.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p) adj[0][p].push_back(i);
        else root[0] = i;
    }
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p) adj[1][p].push_back(i);
        else root[1] = i;
    }
    dfs0(root[0]); dfs1(root[1]);
    cout << same << '\n';
}