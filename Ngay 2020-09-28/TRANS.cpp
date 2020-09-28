#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005, INF = INT_MAX;
int n, m, d[N]; ll k;
vector <ii> a[N];

void dijkstra(){
    priority_queue <ii, vector<ii>, greater<ii> > pq;

    for (int i=1; i<=n; i++) d[i] = INF;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()){
        int u = pq.top().se, du = pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (ii ke: a[u]) {
            int v = ke.second, uv = ke.first;
            if (d[v] > du+uv) {
                d[v] = du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

bool check(ll t) {
    ll cur = 0;
    FOR(i,2,n) {
        cur += (t/d[i]);
    }
    return (cur >= k);
}

signed main(void) {
    FastIO;
    freopen("TRANS.INP","r",stdin);
    freopen("TRANS.OUT","w",stdout);
    cin >> n >> m >> k;
    FOR(i,1,m) {
        int u, v; cin >> u >> v;
        a[u].push_back({1,v});
        a[v].push_back({1,u});
    }
    dijkstra();

    ll res = LLONG_MAX;
    ll l = 0, r = 1e18, mid;
    while (l<=r) {
        mid = (l+r)/2;
        if (check(mid)) {
            r = mid-1;
            res = min(res,mid);
        } else l = mid+1;
    }
    cout << res;
    return 0;
}