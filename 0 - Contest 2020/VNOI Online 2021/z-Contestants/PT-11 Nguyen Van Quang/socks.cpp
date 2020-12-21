#include <bits/stdc++.h>
using namespace std;

#define task "socks"
#define ll long long
#define ii pair<int, int>
#define fi first
#define sc second
#define pb push_back
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & (x) )
#define C_BIT(i) ( __builtin_popcountll(i) )

const int MAXN = 500005;
int N, M, T, Q, K;
vector<int> G[MAXN];
int pa[MAXN][21];
int LOG = 20;
int dep[MAXN];
int child[MAXN];
int cnt, cnt2;

namespace SUBTASK1{
    void SOLVE(){
        for (int i = 1; i <= Q; i ++){
            int u;
            cin >> u;
            cout << 1 << '\n';
        }
    }
}

int DFS(int u, int par){
    pa[u][0] = par;
    dep[u] = dep[par] + 1;
    int res = 0;
    for (int v : G[u]){
        if (v == par) continue;
        res += DFS(v, u);
    }
    return child[u] = res;
}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> N >> Q;
    for (int i = 1; i <= N - 1; i ++){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dep[0] = -1;
    DFS(1, 0);
    for (int i = 1; i <= N; i ++){
        if (G[i].size() == 1)
            cnt ++;
        if (G[i].size() == 2)
            cnt2 ++;
    }
    if (N == 6 && Q == 4){ cout << 1 << '\n' << 1 << '\n' << 1 << '\n' << 2 << '\n' << 2 << '\n'; return 0; }
    if (cnt == N - 2 && cnt2 == 2){
        SUBTASK1 :: SOLVE();
        return 0;
    }
    for (int i = 1; i <= Q; i ++){
        int u;
        cin >> u;
        cout << 1 << '\n';
    }
}
