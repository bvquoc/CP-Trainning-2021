#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   1000005
#define mod    1000000007
#define ii     pair<int, int>

int n, q, top = 0, cnt = 0, leaf = 0;

int st[maxn], fi[maxn], d[maxn], dep[maxn], pr[maxn];

int f[maxn][25], bit[maxn];

int l[maxn], root[maxn];

vector<int> g[maxn];

void dfs (int u) {
        st[u] = ++ top;
        for(auto &v : g[u])
        {
            if(pr[u] == v) continue;
            pr[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
        fi[u] = ++ top;
}

void upd (int u, int v) {
        for(; u > 0; u -= u & (-u))
            bit[u] += v;
}

int get (int u) {
        int r = 0;
        for(; u <= top; u += u & (-u))
            r += bit[u];
        return r;
}

int child (int u) {
        return get(st[u]) - get(fi[u]+1);
}

void ins (int x)
{
        d[x] = 1; ++ cnt;
        upd(st[x], 1);
        int o = child(x);

        if(cnt == 1)
        {
            l[x] = root[x] = 1; ++ leaf;
        }
        else if(o == cnt)
        {
            int ok = 0;
            for(auto &v : g[x])
                if(l[v] && root[v]) {
                    l[v] = root[v] = 0;
                    leaf --;
                    ok = 1;
                    break;
                }
            if(ok) { l[x] = root[x] = 1; leaf ++; }
        }
        else if(o == 1)
        {
            int u = x;
            int k = (int) log2(dep[u]);
            while(k >= 0) {
                int v = f[u][k];
                if(v && child(v) == 1) u = f[v][0];
                -- k;
            }
            if(child(u) == 1) u = f[u][0];
            if(l[u] == 1) {
                int ok = 0;
                for(auto &v : g[u])
                    if(child(v) == (cnt - 1)) {ok = 1; break;}
                if(!ok) { l[u] = root[u] = 0; -- leaf; }
            }

            l[x] = 1; leaf ++;
        }
}

void era (int x)
{
        d[x] = 0; -- cnt;
        upd(st[x], -1);
        int o = child(x);

        if(l[x]) -- leaf;
        l[x] = root[x] = 0;

        if(o == cnt)
        {
            int ok = 0;
            for(auto &v : g[x])
                if(child(v) == cnt && d[v]) {
                    int ok = 0;
                    for(auto &w : g[v])
                        if(child(w) == (cnt - 1)) {ok = 1; break;}
                    if(ok) { l[v] = root[v] = 1; leaf ++; }
                    break;
                }
        }
        else if(o == 0)
        {
            int u = x;
            int k = (int) log2(dep[u]);
            while(k >= 0) {
                int v = f[u][k];
                if(v && child(v) == 0) u = f[v][0];
                -- k;
            }
            if(child(u) == 0) u = f[u][0];
            if(!l[u] && d[u]) {
                int ok = 0;
                for(auto &v : g[u])
                    if(child(v) == (cnt - 1)) {ok = 1; break;}
                if(ok || child(u) == 1) {
                    l[u] = 1; ++ leaf;
                    if(ok) root[u] = 1;
                }
            }
        }
}

int main() {
        #define task "SOCKS"
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        scanf("%d %d", &n, &q);

        for(int i = 1; i <= n; ++ i)
            scanf("%d", &d[i]);

        for(int i = 1; i < n; ++ i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1);

        for(int i = 1; i <= n; ++ i)
            f[i][0] = pr[i];

        for(int j = 1; j < 20; ++ j)
        for(int i = 1; i <= n; ++ i)
            f[i][j] = f[f[i][j-1]][j-1];

        leaf = 0;
        for(int i = 1; i <= n; ++ i) {
            if(d[i]) ins(i);
        }

        printf("%d\n", (leaf + 1) / 2);

        while(q --> 0) {
            int x;
            scanf("%d", &x);

            if(d[x] == 0)
                ins(x);
            else
                era(x);

            printf("%d\n", (leaf + 1) / 2);
        }
}



