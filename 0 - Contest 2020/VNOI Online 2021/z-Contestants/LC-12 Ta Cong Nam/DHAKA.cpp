#include <bits/stdc++.h>

#define task                "DHAKA"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)          for(auto (a) : (u))

#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)       ((a) & (~mask(i)))

#define ft                  first
#define sd                  second
#define pb                  push_back
#define mp                  make_pair

#define sz(a)		        (int(a.size()))
#define all(a)		        a.begin(),a.end()

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double eps = 0.0000001;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

/** End of template **/

struct Dist {
    ll w;
    int id, mel;
    bool operator > (const Dist &P) const {
        return w > P.w;
    }
};

priority_queue <Dist, vector<Dist>, greater<Dist>> pq;
ll d[maxn][mask(5)];
int n, m, k, l, melon[maxn];
vector<pair<int,ll>> adj[maxn];

void dijkstra() {
    rep(i, 1, n)
        rep(j, 0, mask(k) - 1)
            d[i][j] = 1e18;

    d[1][melon[1]] = 0;
    pq.push({d[1][melon[1]], 1, melon[1]});

    while(sz(pq) > 0) {
        Dist u = pq.top();
        pq.pop();
        if(d[u.id][u.mel] != u.w)
            continue;
        repa(v, adj[u.id]) {
            if(d[v.ft][u.mel | melon[v.ft]] > u.w + v.sd) {
                d[v.ft][u.mel | melon[v.ft]] = u.w + v.sd;
                pq.push({d[v.ft][u.mel | melon[v.ft]], v.ft, u.mel | melon[v.ft]});
            }
        }
    }

    return ;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n >> m >> k >> l;
    rep(i, 1, n) {
        int s; cin >> s;
        rep(j, 1, s) {
            int type; cin >> type;
            melon[i] |= mask(type - 1);
        }
    }

    rep(i, 1, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }

    dijkstra();

    ll ans = 1e18;
    rep(i, 0, mask(k) - 1)
        if(__builtin_popcount(i) >= l)
            ans = min(ans, d[n][i]);

    cout << ((ans >= 1e18) ? (-1) : ans);
    return 0;
}
