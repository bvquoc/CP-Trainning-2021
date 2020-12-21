#include <bits/stdc++.h>
#define Task "DHAKA"
#define MAX_N 100005

using namespace std;

typedef long long ll;
const ll inf = 1e18 + 77777777;

struct {
    int u, v, w;
} e[MAX_N << 1];

int link[MAX_N << 1], head[MAX_N], A[MAX_N];
ll D[MAX_N], d[MAX_N];
int n, m, l, k;

void Dij() {
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    fill_n(D + 1, n, inf);
    D[1] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        ll du = -q.top().first;
        q.pop();
        if (D[u] != du)
            continue;
        for (int i = head[u]; i; i = link[i]) {
            int v = e[i].v;
            int w = e[i].w;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                q.push({-D[v], v});
            }
        }
    }
}

void dij() {
    priority_queue<pair<int, int>> q;
    q.push({0, n});
    fill_n(d + 1, n, inf);
    d[n] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        ll du = -q.top().first;
        q.pop();
        if (d[u] != du)
            continue;
        for (int i = head[u]; i; i = link[i]) {
            int v = e[i].v;
            int w = e[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

void Reverse() {
    for (int i = 1; i <= (m << 1); i++)
        e[i] = {e[i].v, e[i].u, e[i].w};
    fill_n(head + 1, n, 0);
    for (int i = (m << 1); i >= 1; i--) {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
}

void sub2() {
    Dij();
    cout << (D[n] == inf ? -1 : D[n]);
    exit(0);
}

void sub3() {
    Dij();
    Reverse();
    dij();
    ll res = inf;
    for (int i = 1; i <= n; i++)
        if (A[i])
            res = min(res, D[i] + d[i]);
    cout << (res == inf ? -1 : res);
    exit(0);
}

struct lab {
    int u;
    ll w;
    int mask;
};

struct cmp {
    bool operator () (lab a, lab b) {
        return a.w > b.w;
    }
};

ll Dist[MAX_N][100];
bool avail[MAX_N][100];

void Dijkstra() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << k); j++)
            Dist[i][j] = inf, avail[i][j] = 1;
    priority_queue<lab, vector<lab>, cmp> q;
    q.push({1, 0, A[1]});
    Dist[1][A[1]] = 0;
    while(!q.empty()) {
        int u = q.top().u;
        int mask = q.top().mask;
        q.pop();
        if (!avail[u][mask])
            continue;
        avail[u][mask] = 0;
        for (int i = head[u]; i; i = link[i]) {
            int v = e[i].v;
            int w = e[i].w;
            int newmask = (A[v] | mask);
            if (Dist[v][newmask] > Dist[u][mask] + w) {
                Dist[v][newmask] = Dist[u][mask] + w;
                q.push({v, Dist[v][newmask], newmask});
            }
        }
    }
}

void Solve() {
    Dijkstra();
    ll res = inf;
    for (int i = 0; i < (1 << k); i++)
        if (__builtin_popcount(i) >= l)
            res = min(res, Dist[n][i]);
    cout << (res == inf ? -1 : res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int s, a, i = 1; i <= n; i++) {
        cin >> s;
        while(s--) {
            cin >> a;
            A[i] |= (1 << (a - 1));
        }
    }
    for (int u, v, w, i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        e[i + m] = {v, u, w};
    }
    fill_n(head + 1, n, 0);
    for (int i = (m << 1); i >= 1; i--) {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
    if (l == 0)
        sub2();
    if (k == 1)
        sub3();
    Solve();
}
