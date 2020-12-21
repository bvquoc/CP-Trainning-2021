#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define task "DHAKA"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n, m, k, l, p[maxn];
vector<pii> a[maxn];
ll d[maxn][55];

void IJK(){
    memset(d, 64, sizeof d);
    d[1][p[1]] = 0;
    priority_queue< pair< ll, pii> > q;
    q.push({0, {1, p[1]}});
    while(q.size()){
        pair<ll, pii> x = q.top();
        q.pop();
        int u = x.S.F;
        int tt = x.S.S;
        ll w = - x.F;
        if(w != d[u][tt]) continue;
        for(auto v: a[u]){
            if(d[v.F][tt | p[v.F]] <= w + v.S) continue;
            d[v.F][tt | p[v.F]] = w + v.S;
            q.push({-d[v.F][tt|p[v.F]], {v.F, tt | p[v.F]}});
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++ i){
        int c;
        cin >> c;
        for(int j = 1; j <= c; ++ j){
            int x;
            cin >> x;
            -- x;
            p[i] |= (1 << x);
        }
    }
    for(int i = 1; i <= m; ++ i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    IJK();
    ll ans = 1e18;
    for(int i = 0; i < (1 << k); ++ i){
        if(__builtin_popcount(i) >= l) {
            ans = min(ans, d[n][i]);
        }
    }
    cout << (ans == 1e18 ? - 1 : ans);
    return 0;
}

