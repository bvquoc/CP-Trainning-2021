#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

const int N = 5e5 + 100;
const int LG = 19;
int tin[N], tout[N], TIME, trace[N];
int n, q, color[N];
vector<int> e[N];
vector<pair<int, int> > e_tin[N];

int cnt = 0, numRed = 0;
void dfs(int u, int p) {
    tin[u] = ++TIME;
    trace[TIME] = u;
    for (int v : e[u]) if (v != p) {
        dfs(v, u);
        e_tin[u].push_back({tin[v], v});
    }
    tout[u] = TIME;
}

int BIT[N];
void UpBIT(int u, int val) {
    for (; u < N; u += u & -u) BIT[u] += val;
}

int QueryBIT(int u) {
    int ans = 0;
    for (; u > 0; u -= u & -u) ans += BIT[u];
    return ans;
}

int WalkOnBIT(int val) {
    int sum = 0, pos = 0;
    for (int i = LG - 1; i >= 0; --i) {
        if (pos + (1 << i) < N && sum + BIT[pos + (1 << i)] < val) {
            sum += BIT[pos + (1 << i)];
            pos += (1 << i);
        }
    }
    return pos + 1;
}

bool isLeaf1(int u) {
    // No v such that u is ancestor of v.
    int between = QueryBIT(tout[u]) - QueryBIT(tin[u]);
    return (between == 0) ;
}

bool isLeaf2(int u) {
    //
    int v = trace[WalkOnBIT(QueryBIT(tin[u]) + 1)];
    if (!v || tin[v] > tout[u]) return false;
    int w = (upper_bound(e_tin[u].begin(), e_tin[u].end(), make_pair(tin[v] + 1, -1)) - e_tin[u].begin()) - 1;
    if (w == -1) return false;
    w = e_tin[u][w].second;
    int val = QueryBIT(tout[w]) - QueryBIT(tin[w] - 1);
    return (val == numRed - 1);
}

void Add(int u) {
    //

    if (numRed <= 1) {
        ++cnt;
        ++numRed;
        UpBIT(tin[u], 1);
        return;
    }

    int val = QueryBIT(tin[u]);
    // (tin[p]...tin[u].. tout[u]... tin[p])
    int p = trace[WalkOnBIT(val)];
    if (p != u && color[p] && tin[p] <= tin[u] && tin[u] <= tout[p]) {
        if (isLeaf1(p)) --cnt;    
    } else p = -1;

    // tin[u],tin[v],...,tout[v],tout[u]
    int v = trace[WalkOnBIT(val + 1)];
    if (tin[u] <= tin[v] && tin[v] <= tout[u]) {
        if (isLeaf2(v)) --cnt;
    } else v = -1;
    
    int p2 = trace[WalkOnBIT(1)];
    if (p2 == v) p2 = -1;
    else if (isLeaf2(p2)) --cnt;

    UpBIT(tin[u], 1);
    ++numRed;
    if (isLeaf1(u)) ++cnt;
    if (isLeaf2(u)) ++cnt;
    if (p2 != -1 && isLeaf2(p2)) ++cnt;  
}

void Remove(int u) {
    //
    if (numRed <= 2) {
        --numRed;
        --cnt;
        UpBIT(tin[u], -1);
        return;
    }

    if (isLeaf1(u)) --cnt;
    if (isLeaf2(u)) --cnt;

    UpBIT(tin[u], -1);
    --numRed;
    
    int val = QueryBIT(tin[u]);
    // (tin[p]...tin[u].. tout[u]... tin[p])
    int p = trace[WalkOnBIT(val)];
    if (p != u && color[p] && tin[p] <= tin[u] && tin[u] <= tout[p]) {
        if (isLeaf1(p)) ++cnt;    
    } else p = -1;

    // tin[u],tin[v],...,tout[v],tout[u]
    int v = trace[WalkOnBIT(val + 1)];
    if (tin[u] <= tin[v] && tin[v] <= tout[u]) {
        if (isLeaf2(v)) ++cnt;
    } else v = -1;
    
    int p2 = trace[WalkOnBIT(1)];
    if (p2 == v) p2 = -1;
    UpBIT(tin[u], 1);
    ++numRed;
    if (p2 != -1 && isLeaf2(p2)) --cnt;

    --numRed;
    UpBIT(tin[u], -1);
    
    if (p2 != -1 && isLeaf2(p2)) ++cnt;

    
}

int main() {
#define TASK "SOCKS"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) if (color[i] == 1) Add(i);
    if (cnt == 1) cout << 0 << '\n';
    else cout << (cnt + 1) / 2 << '\n';
    while (q--) {
        int x;
        cin >> x;
        if (color[x]) Remove(x);
        else Add(x);    
        color[x] ^= 1;
        if (cnt == 1) cout << 0 << '\n';
        else cout << (cnt + 1) / 2 << '\n';
    
    }
    
}
