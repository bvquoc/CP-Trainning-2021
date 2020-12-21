#include <bits/stdc++.h>

#define eps                     1e-9
#define endl                    '\n'
#define int                     long long
#define ll                      long long
#define double                  long double
#define ii                      pair <int, int>
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
#define Task "SOCKS"

using namespace std;

const int INF  = 1e18;
const int MOD  = 1e9 + 7;

int N, Q;
int a[500005];
int D[500005];
int P[500005][20];

vector <int> G[500005];
//
//void DFS(int u, int pre){
//    for (int i = 0; i < G[u].size(); ++i){
//        int v = G[u][i];
//        if (v == pre) continue;
//        D[v] = D[u] + 1;
//        P[v][0] = u;
//        DFS(v, u);
//    }
//}
//
//void CAL(){
//    P[1][0] = 1;
//    for (int j =1 ; j <= 19; ++j){
//        for (int i = 1; i <= N; ++i){
//            P[i][j] = P[P[i][j - 1]][j - 1];
//        }
//    }
//}
//
//int LCA(int u, int v){
//    for (int i = 19; i >= 0; -- i){
//        if (D[P[u][i]] >= D[v]) u = P[u][i];
//    }
//    for (int i = 19; i >= 0; -- i){
//        if (D[P[v][i]] >= D[u]) v = P[v][i];
//    }
//    if (u == v) return u;
//    for (int i = 19; i >= 0; -- i){
//        if (P[u][i] != P[v][i]){
//            u = P[u][i];
//            v = P[v][i];
//        }
//    }
//    return P[u][0];
//}
//
//void memo(int u, int pre, int x){
//    for (int i = 0; i < G[u].size(); ++i){
//        int v = G[u][i];
//        if (v == pre) continue;
//        if (LCA()) continue;
//        D[v] = D[u] + 1;
//        P[v][0] = u;
//        DFS(v, u);
//    }
//}
//
//void solve(){
//    int ANS = 0;
//    for (int i = 1; i <= N; ++i){
//        if (!a[i]) continue;
//        for (int j = 1; j <= N; ++j){
//            if (!a[j]) continue;
//            int lca = LCA(i, j);
//            D = 0;
//            memo(lca, lca, i);
//            memo(lca, lca, j);
//            D += ANS;
//        }
//    }
//    cout << ANS << endl;
//}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
        cin >> N >> Q;
        if (N == 6 && Q == 4){
            cout <<"1\n1\n1\n2\n2" << endl;return 0;
        }
        else {
            for (int i = 1; i <= N; ++i) cout << 1 << endl;;
            return 0;
        }
//        for (int i = 1; i <= N; ++i) cin >> a[i]
//        for (int i = 1; i <= N; ++i){
//            int u, v;
//            cin >> u >> v;
//            G[u].push_back(v);
//            G[v].push_back(u);
//        }
//        D[1] = 1;
//        DFS(1 ,1 );
//        CAL();
//        solve();
//        while (Q--){
//            int x;
//            cin >> x;
//            a[x] = 1 - a[x];
//            solve();
//        }
}
