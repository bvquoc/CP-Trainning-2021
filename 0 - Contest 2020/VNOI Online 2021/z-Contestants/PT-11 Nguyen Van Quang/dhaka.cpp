#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define task "dhaka"
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & x )
#define C_BIT(x) ( __builtin_popcountll(x) )
#define ii pair<int, int>
#define fi first
#define sc second


const int MAXN = 100005;
const ll   oo  = 1e17;
int N, M, T, K, Q, L;
int A[MAXN];
vector< ii > G[MAXN];

void minimize(ll &x, const ll &y) { if (x > y) x = y; return; }

namespace SUBTASKFULL{
    ll d[MAXN][33];

    struct STATUS{
        ll u, w, mask;
        bool operator>(const STATUS& other) const{
            return w < other.w;
        }
    };

    void dijkstra(){
        for (int i = 1; i <= N; i ++)
        for (int k = 0; k < MASK(K); k ++)
            d[i][k] = oo;
        d[1][A[1]] = 0;
        priority_queue<STATUS, vector<STATUS>, greater<STATUS>> pq;
        pq.push( {1, 0, A[1]} );
        while (pq.size()){
            STATUS top = pq.top();
            pq.pop();
            ll u  = top.u;
            ll du = top.w;
            ll curMask = top.mask;
            if (du != d[u][curMask]) continue;
//            cout << u << ' ' << du << ' ' << curMask << '\n';
            for (int i = 0; i < G[u].size(); i ++){
                ll v  = G[u][i].sc;
                ll uv = G[u][i].fi;
                ll nxtMask = curMask | A[v];
                if (d[v][nxtMask] > d[u][curMask] + uv){
                    d[v][nxtMask] = d[u][curMask] + uv;
                    pq.push( {v, d[v][nxtMask], nxtMask} );
                }
            }
        }
    }
    void SOLVE(){
        dijkstra();
//        cout << sizeof(d) / 1024 / 1024 << '\n';
        ll ans = oo;
        for (int mask = 0; mask < MASK(K); mask ++){
            if (d[N][mask] != oo && C_BIT(mask) >= L)
                minimize(ans, d[N][mask]);
        }
        if (ans != oo) cout << ans;
        else cout << -1;
    }
}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> N >> M >> K >> L;
    for (int i = 1; i <= N; i ++){
        int u, x;
        cin >> u;
        for (int j = 1; j <= u; j ++){
            cin >> x;
            A[i] |= MASK(x - 1);
        }
    }
    for (int i = 1; i <= M; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb( {w, v} );
        G[v].pb( {w, u} );
    }

    SUBTASKFULL :: SOLVE();
}
