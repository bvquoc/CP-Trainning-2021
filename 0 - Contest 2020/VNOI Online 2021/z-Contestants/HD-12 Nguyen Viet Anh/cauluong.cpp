#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 5005
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <int, ii>
#define mode (int) 998244353
#define inf (ll) 2e18

using namespace std;

int task;
int n, m, cl[N], kc[N], d[N], g[N][N], f[N], h[N];
int c[N];
int child[N], pd[N];
iii e[N];
vector <ii> Adj[N];
set <ii> s;

void bfs(int xp) {
    FOR(i, 1, n)
        kc[i] = cl[i] = 0;
    s.clear();
    cl[xp] = 1;
    kc[xp] = 0;
    h[xp] = 1;
    s.insert(ii(kc[xp], xp));
    while(!s.empty()) {
        ii x = *s.begin(); s.erase(x);
        int u = x.y; cl[u] = 2;
        for(auto &it : Adj[u]) {
            int v = it.x, w = it.y;
            if(cl[v] == 0) {
                cl[v] = 1;
                kc[v] = kc[u] + w;
                h[v] = h[u];
                s.insert(ii(kc[v], v));
            } else if(cl[v] == 1 && kc[v] > kc[u] + w) {
                s.erase(ii(kc[v], v));
                kc[v] = kc[u] + w;
                h[v] = h[u];
                s.insert(ii(kc[v], v));
            } else if(cl[v] == 1 && kc[v] == kc[u] + w) {
                h[v] = (h[v] + h[u]) % mode;
                s.insert(ii(kc[v], v));
            }
        }
    }
}

void dfs(int u, int pre) {
    child[u] = 1;
    for(auto &it : Adj[u]) {
         int v = it.x, w = it.y;
         if(v != pre) {
             pd[v] = u;
             dfs(v, u);
             child[u] += child[v];
         }
    }
}

void sub1() {
    if(m != n - 1) return;
    FOR(i, 1, n)
        if(child[i] == 0)
            dfs(i, 0);
    FOR(i, 1, m) {
        int u = e[i].y.x, v = e[i].y.y, w = e[i].x;
        if(pd[u] == v) swap(u, v);
        f[i] = (1ll * child[v] * (n - child[v])) % mode;
        printf("%d\n", f[i]);
    }
    exit(0);
}

void sub2() {
    FOR(i, 1, n)
        FOR(j, 1, n)
            g[i][j] = inf;
    FOR(i, 1, n) {
        bfs(i);
        FOR(j, 1, n) {
            g[i][j] = min(g[i][j], kc[j]);
            g[j][i] = min(g[j][i], kc[j]);
        }
    }
    FOR(k, 1, m) {
        int u = e[k].y.x, v = e[k].y.y, w = e[k].x;
        bfs(u);
        FOR(i, 1, n)
            d[i] = kc[i], c[i] = h[i];
        bfs(v);
        FOR(i, 1, n)
            FOR(j, 1, n)
                if(i != j)
                   if(d[i] + kc[j] + w == g[i][j])
                       f[k] = (f[k] + 1ll * c[i] * h[j]) % mode;
    }
    FOR(i, 1, m)
        printf("%d\n", f[i]);
}

int main() {
    //freopen("main.inp", "r", stdin);
    freopen("cauluong.inp", "r", stdin);
    freopen("cauluong.out", "w", stdout);
    scanf("%d ", &task);
    scanf("%d %d ", &n, &m);
    FOR(i, 1, m) {
        int u, v, w;
        scanf("%d %d %d ", &u, &v, &w);
        e[i] = iii(w, ii(u, v));
        Adj[u].push_back(ii(v, w));
        Adj[v].push_back(ii(u, w));
    }
    if(task == 2) sub1();
    else sub2();
}
