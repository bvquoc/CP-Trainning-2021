#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
struct Node {
    int u, mask;
    ll du;
    bool operator < (const Node &o) const {
        return du > o.du;
    }
};
int n, m, k, l;
int msk[100002];
ll d[100002][33], ans;
vii a[100002];
void dijk() {
    priority_queue<Node> pq;
    for(int i = 1; i <= n; ++ i) {
        for(int mask = 0; mask < (1 << k); ++ mask) {
            d[i][mask] = 1e18;
        }
    }
    d[1][msk[1]] = 0ll;
    pq.push({1, msk[1], 0ll});
    while(!pq.empty()) {
        int u = pq.top().u;
        int mask = pq.top().mask;
        ll du = pq.top().du;
        pq.pop();
        if(du != d[u][mask]) continue;
        for(ii i : a[u]) {
            int v = i.fi;
            ll uv = i.se;
            if(d[v][mask | msk[v]] > du + uv) {
                d[v][mask | msk[v]] = du + uv;
                pq.push({v, mask | msk[v], d[v][mask | msk[v]]});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //if(fopen("test.inp", "r"))
    //    freopen("test.inp", "r", stdin);
    //else {
        #define file "DHAKA"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    //}
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++ i) {
        int x, y;
        msk[i] = 0;
        cin >> x;
        for(int j = 1; j <= x; ++ j) {
            cin >> y;
            msk[i] |= (1 << (y - 1));
        }
    }
    for(int i = 1; i <= m; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v, w));
        a[v].push_back(ii(u, w));
    }
    dijk();
    ans = 1e18;
    for(int i = 0; i < (1 << k); ++ i) {
        if(__builtin_popcount(i) >= l) {
            ans = min(ans, d[n][i]);
        }
    }
    if(ans == 1e18) cout << -1;
    else cout << ans;
    return 0;
}

