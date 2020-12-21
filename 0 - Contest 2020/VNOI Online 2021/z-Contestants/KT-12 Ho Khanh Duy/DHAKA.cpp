#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll N = 1e5+5;
const ll INF = 1e9;

typedef pair <ll, ll> ii;

ll n, m, k, l;
vector <ii> a[N];
vector <ll> duong[N];

ll ktra[N], duahau[N];

ll turnOn(ll mask, ll k){
    return mask | (1 << (k));
}

vector <ll> dijkstra_sub2(ll s){
    vector <ll> d;
    d.resize(n+1);
    priority_queue <ii, vector <ii>, greater <ii> > qu;

    for (ll i=1; i<=n; i++) d[i] = INF;

    qu.push({0, s});
    d[s] = 0;

    while (qu.size()){
        ll u = qu.top().se;
        ll du = qu.top().fi;
        qu.pop();

        if (du != d[u]) continue;

        for (ll i=0; i<a[u].size(); i++){
            ll v = a[u][i].se;
            ll uv = a[u][i].fi;
            if (d[v] > du + uv){
                d[v] = du + uv;
                qu.push({d[v], v});
            }
        }
    }

    return d;
}

void sub2(){
    for (ll i=1; i<=n; i++){
        ll x; cin >> x;
        for (ll j=1; j<=x; j++){
            ll y; cin >> y;
        }
    }

    for (ll i=1; i<=m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    vector <ll> ans = dijkstra_sub2(1);

//    for (auto v : ans) cout << v << " ";

    cout << ans[n];
}

void sub3(){
    for (ll i=1; i<=n; i++){
        ll s; cin >> s;
        for (ll j=1; j<=s; j++){
            ll x; cin >> x;
        }
        if (s != 0)
            duahau[i] = 1;
    }

    if (l > 1){
        cout << -1;
        exit(0);
    }

    for (ll i=1; i<=m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    vector <ll> d1 = dijkstra_sub2(1);
    vector <ll> dn = dijkstra_sub2(n);

//    for (auto v : dn) cout << v << " ";
    ll ans = INF;

    for (ll i=1; i<=n; i++){
        if (duahau[i] == 1){
            ans = min(ans, d1[i] + dn[i]);
        }
    }

    cout << ans;
}

int main()
{
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k >> l;
    if (k == 1)
        sub3();
    else
        sub2();
    return 0;
}
