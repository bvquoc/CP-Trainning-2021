#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1000000007
#define task "DHAKA"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define bit(x, i) (x >> i)&1
using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n, m, k, l, a[maxn];
vector<pii> ke[maxn];
void Input(){
    cin >> n >> m >> k >> l;
    for (int s, x, i=1; i<=n; ++i){
        a[i] = 0;
        cin >> s;
        for (int j=0; j<s; ++j){
            cin >> x; x--;
            a[i] |= (1 << x);
        }
    }
    for (int u, v, w, i=1; i<=m; ++i){
        cin >> u >> v >> w;
        ke[u].pb({v, w}); ke[v].pb({u, w});
    }
}
ll d[maxn][35];
priority_queue<pair<ll, pii>> P;
void Init(){
    for (int i=1; i<=n; ++i)
        for (int x=0; x<(1<<k); ++x)
            d[i][x] = MM;
    d[1][a[1]] = 0;
    P.push({0, {a[1], 1}});
}
void Solve(){
    while (P.size()){
        int u = P.top().S.S, tt = P.top().S.F;
        ll l = -P.top().F;
        P.pop();
        if (l > d[u][tt]) continue;
        for (auto &p : ke[u]){
            int v = p.F, w = p.S;
            int st = tt | a[v];
            if (d[v][st] > d[u][tt] + w) {
                d[v][st] = d[u][tt] + w;
                P.push({-d[v][st], {st, v}});
            }
        }
    }
    ll ans = MM;
    for (int x=0; x<(1<<k); ++x){
        int t = __builtin_popcount(x);
        if (t < l) continue;
        ans = min(ans, d[n][x]);
    }
    if (ans == MM) cout << -1; else cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    Input();
    Init();
    Solve();
    return 0;
}
