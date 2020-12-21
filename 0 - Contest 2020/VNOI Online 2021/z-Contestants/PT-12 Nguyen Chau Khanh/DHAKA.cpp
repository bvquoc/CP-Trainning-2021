#include <bits/stdc++.h>

#define eps                     1e-9
#define endl                    '\n'
#define int                     long long
#define ll                      long long
#define double                  long double
#define ii                      pair <int, int>
#define zz                      pair <ii, int>
#define fi                      first
#define se                      second
#define all(x)                  (x).begin(), (x).end()
#define BIT(mask, i)            ((mask) & (1ll << (i)))
#define ONBIT(mask, i)          ((mask) | (1ll << (i)))
#define OFFBIT(mask, i)         ((mask) &~ (1ll << (i)))
#define a(i, j)                 aa[((i) - 1) * (NumRow) + (j)]
#define ID(i, j)                (((i) - 1) * (NumRow) + (j))
#define CIDx(i)                 ((i) / (NumRow)) + ((i) % (NumRow) != 0)
#define CIDy(i)                 ((i) % (NumRow)) + ((i) % (NumRow) == 0) * (numRow)
#define Task "DHAKA"

using namespace std;

const int INF  = 1e18;
const int MOD  = 1e9 + 7;
const int MAXN = 1e5 + 7;

int N, M, K, L;
int Mask[MAXN];
vector <ii> G[MAXN];

void COUT(int mask){
    for (int i = 0; i < 5; ++i) cout << bool(BIT(mask, i));cout << endl;
}

namespace Sub {
    int D[MAXN][35];
    priority_queue <zz, vector <zz>, greater <zz> > qu;

    void DIJ(){
        for (int i = 1; i <= N; ++i){
//                COUT(Mask[i]);
            for (int mask = 0; mask < (1 << 5); ++mask){
                D[i][mask] = INF;
            }
        }

        D[1][Mask[1]] = 0;
        qu.push(zz(ii(0, Mask[1]), 1));
        while (!qu.empty()){
            int u  = qu.top().se;
            int du = qu.top().fi.fi;
            int mu = qu.top().fi.se;
            qu.pop();
            if (du != D[u][mu]) continue;
            for (int i = 0; i < G[u].size(); ++i){
                int v  = G[u][i].se;
                int dv = G[u][i].fi;
                int mv = (mu | Mask[v]);
                if (D[v][mv] > dv + du){
                    D[v][mv] = dv + du;
                    qu.push(zz(ii(dv + du, mv), v));
                }
            }
        }
    }

    void solve(){
        DIJ();
        int ans = INF;
        for (int mask = 0; mask < (1 << 5); ++mask){
            if (__builtin_popcount(mask) < L) continue;
            ans = min(ans, D[N][mask]);
        }
        if (ans >= INF) cout << -1;
        else cout << ans;
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    cin >> N >> M >> K >> L;
    for (int i = 1; i <= N; ++i){
        int s; cin >> s;
        while (s--){
            int a; cin >> a;
            Mask[i] = ONBIT(Mask[i], a - 1);
        }
    }
    for (int i = 1; i <= M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(ii(w, v));
        G[v].push_back(ii(w, u));
    }
    Sub :: solve();
}
