#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   5005
#define mod    1000000007
#define ii     pair<int, int>
#define ar3    array<int, 3>

int t, n, m;

int kc[maxn][5], f[maxn][5], d[maxn], dd[maxn][maxn];

vector<ii> g[maxn][5];

ar3 e[maxn];

priority_queue<ii, vector<ii>, greater<ii> > s;

void dij (int xp, int o, int id)
{
        for(int i = 1; i <= n; ++ i) {
            kc[i][id] = mod; f[i][id] = 0;
        }

        f[xp][id] = 1; kc[xp][id] = 0;
        s.push({0, xp});

        while(!s.empty()) {
            auto p = s.top(); s.pop();
            int u = p.y, d = p.x;
            if(kc[u][id] != d) continue;
            for(auto &vv : g[u][o])
            {
                int v = vv.x, w = vv.y;
                int dis = d + w;
                if(kc[v][id] > dis) {
                    kc[v][id] = dis;
                    f[v][id] = f[u][id];
                    s.push({dis, v});
                }
                else if(kc[v][id] == dis) {
                    f[v][id] = (f[v][id] + f[u][id]) % mod;
                }
            }
        }
}

void sub1()
{
         for(int i = 1; i <= n; ++ i)
         {
             dij(i, 0, 1);
             for(int j = 1; j <= n; ++ j)
                dd[i][j] = kc[j][1];
         }

         for(int z = 1; z <= m; ++ z) {
            int u = e[z][1], v = e[z][2], w = e[z][0];
            dij(u, 1, 1); dij(v, 0, 2);
            for(int i = 1; i <= n; ++ i) {
                for(int j = 1; j <= n; ++ j) {
                    if(kc[i][1] + kc[j][2] + w == dd[i][j])
                        d[z] = (d[z] + (ll) f[i][1] * f[j][2] % mod);
                }
            }
        }

        for(int i = 1; i <= m; ++ i)
            printf("%d\n", d[i]);
}

int main() {
        #ifndef ONLINE_JUDGE
            freopen(".inp","r",stdin);
        #endif // ONLINE_JUDGE

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        scanf("%d", &t);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; ++ i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            e[i] = {w, u, v};
            g[u][0].eb(ii{v, w});
            g[v][1].eb(ii{u, w});
        }

        sub1();
}

