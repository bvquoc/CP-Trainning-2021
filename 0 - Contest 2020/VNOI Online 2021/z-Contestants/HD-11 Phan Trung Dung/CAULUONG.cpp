#include <bits/stdc++.h>
#define maxn 1505
#define maxm 5005
#define oo 2000000000
#define mod 998244353

using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;

int E[maxn][maxn];
int d[maxn], kc[maxn][maxn], Pd[maxn][maxn], Pdt[maxn], depth[maxn];
int dem[maxm], dd[maxn], sc[maxn];
II Ei[maxm];
set<II> s;
vector<II> g[maxn];
int m, n;

void Dij(int xp) {
    for(int i=1;i<=n;++i) {
        kc[xp][i] = oo;
        d[i] = 0;
    }
    s.clear();

    kc[xp][xp] = 0;
    d[xp] = 1;
    s.insert({kc[xp][xp], xp});
    while(!s.empty()) {
        II t = *s.begin(); s.erase(s.begin());

        int u = t.second;
        d[u] = 1;

        for(auto &i : g[u]) {
            int v = i.first, L = i.second;

            if(d[v] == 0) {
                d[v] = 1;
                kc[xp][v] = kc[xp][u] + L;
                Pd[xp][v] = u;
                s.insert({kc[xp][v], v});
            } else if(kc[xp][u] + L < kc[xp][v]) {
                s.erase({kc[xp][v], v});
                kc[xp][v] = kc[xp][u] + L;
                Pd[xp][v] = u;
                s.insert({kc[xp][v], v});
            }
        }
    }
}

void DFS(int u) {
    d[u] = 1;
    sc[u] = 1;
    int danhdau = 0;
    for(auto &i : g[u]) {
        int v = i.first;
        if(d[v] == 0) {
            depth[v] = depth[u] + 1;
            Pdt[v] = u;
            danhdau = 1;
            DFS(v);
            sc[u] += sc[v];
        }
    }

    if(danhdau == 0) dd[u] = 1;
}

void sub1() {
    for(int u=1;u<=n;++u) Dij(u);

    for(int u=1;u<=n;++u) {
        for(int v1=1;v1<=n;++v1) if(v1 != u && kc[u][v1] != oo) {
            int v = v1;
            while(v != u) {
                dem[E[Pd[u][v]][v]] = (dem[E[Pd[u][v]][v]] + 1) % mod;
                v = Pd[u][v];
            }
        }
    }

    for(int i=1;i<=m;++i) printf("%d\n", dem[i]);
}

void sub2() {
    DFS(1);
    //cout<<"?";

    for(int i=1;i<=m;++i) {
        int u = Ei[i].first, v = Ei[i].second;
        dem[i] = (sc[v] + depth[u]) % mod;
    }

    for(int i=1;i<=m;++i) printf("%d\n", dem[i]);
}

int main() {
    freopen("CAULUONG.inp", "r", stdin);
    freopen("CAULUONG.out", "w", stdout);

    int t;
    scanf("%d", &t);
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        g[u].push_back({v, w});
        g[v].push_back({u, w});
        E[u][v] = i;
        Ei[i] = {u, v};
    }

    if(t == 2) sub2();
    else sub1();
}
