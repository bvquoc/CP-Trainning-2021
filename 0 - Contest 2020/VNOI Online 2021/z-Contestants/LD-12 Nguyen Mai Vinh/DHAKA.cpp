#include<bits/stdc++.h>
#define ll long long
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const ll siz = 1e5 + 10;
const ll mod = 1e9 + 9;
const ll base = 32;
const ll MAXX = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n, m, k, l;
ll melon[siz];

vector<ii> graph[siz];

ll dist[siz][(1 << 5)];

void init() {
    for (ll i = 0; i < siz; i++) {
        for (ll j = 0; j < (1 << 5); j++) {
            dist[i][j] = MAXX;
        }
    }
}

void djs() {
    init();
    priority_queue<iii, vector<iii>, greater<iii>> nxt;
    dist[1][melon[1]] = 0;
    nxt.push(iii(0, ii(1, melon[1])));
    while (!nxt.empty()) {
        ll d = nxt.top().first;
        ll u = nxt.top().second.first;
        ll mask = nxt.top().second.second;
        nxt.pop();
        if (dist[u][mask] != d) {
            continue;
        }
        for (ll i = 0; i < (int)graph[u].size(); i++) {
            ll v = graph[u][i].first;
            ll nMask = mask | melon[v];
            if (dist[v][nMask] > dist[u][mask] + graph[u][i].second) {
                dist[v][nMask] = dist[u][mask] + graph[u][i].second;
                nxt.push(iii(dist[v][nMask], ii(v, nMask)));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    con_meo_ngoo();
    cin >> n >> m >> k >> l;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        for (ll j = 0; j < x; j++) {
            ll val;
            cin >> val;
            melon[i] |= (1 << (val - 1));
        }
    }
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(ii(b, c));
        graph[b].push_back(ii(a, c));
    }
    djs();
    ll ans = MAXX;
    for (ll i = 0; i < (1 << 5); i++) {
        ll c = __builtin_popcount(i);
        if (c >= l) {
            ans = min(ans, dist[n][i]);
        }
    }
    if (ans >= MAXX) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}
