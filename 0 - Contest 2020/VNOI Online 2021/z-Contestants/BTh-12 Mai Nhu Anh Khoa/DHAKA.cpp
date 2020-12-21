#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int maxN=1e5+5;
const ll oo=1e17;

int n, m, k, l;
int base;
int col[maxN];
ll d[maxN][(1<<5)+5];
vector<pii> h[maxN];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii> > qu;
    for (int i=1; i<=n; ++i){
        for (int T=0; T<(1<<k); ++T){
            d[i][T]=oo;
        }
    }
    d[1][col[1]]=0;
    qu.push({0, 1*base+col[1]});
    while (qu.size()){
        int u=qu.top().se/base, cl=qu.top().se%base;
        ll du=qu.top().fi;
        qu.pop();

        if (du!=d[u][cl]) continue;

        for (int i=0; i<h[u].size(); ++i){
            int v=h[u][i].fi;
            ll w=h[u][i].se;
            int New=(cl|col[v]);
            if (d[v][New]>du+w){
                d[v][New]=du+w;
                qu.push({d[v][New], v*base+New});
            }
        }

    }
}

int main()
{
    ifstream cin("DHAKA.INP");
    ofstream cout("DHAKA.OUT");
    cin >> n >> m >> k >> l;
    base=(1<<k);
    for (int i=1; i<=n; ++i){
        int x;
        cin >> x;
        for (int j=1; j<=x; ++j){
            int y;
            cin >> y;
            col[i]^=(1<<(y-1));
        }
    }
    for (int i=1; i<=m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        h[u].pb({v, w});
        h[v].pb({u, w});
    }

    dijkstra();

    ll res=oo;
    for (int T=0; T<(1<<k); ++T){
        if (__builtin_popcount(T)<l) continue;
        res=min(res, d[n][T]);
    }
    if (res>=oo) cout << -1;
    else cout << res;
    return 0;
}
