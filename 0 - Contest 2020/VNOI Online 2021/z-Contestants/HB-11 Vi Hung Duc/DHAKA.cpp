//  MASTER VI HUNG DUC
#include <bits/stdc++.h>

using namespace std;

// Data Type

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, ll> pil;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll > mll;
typedef unordered_map<ll, ll> umll;

// Funtions

#define fi first
#define se second
#define pb push_back
#define upper upper_bound
#define lower lower_bound
#define memset(a, x) memset(a, x, sizeof(a))

// Shortcut
#define TASK "DHAKA"
#define sz(x) int(x.size())
#define ALL(v) v.begin(), v.end()
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, r, l) for (int i = r; i >= l; i--)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, r, l) for (type i = r; i >= l; i--)

// BIT

#define BIT(x, i) (((x) >> (i)) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

// EDIT

constexpr ll maxn = 1e5 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

//o - o - o - o - o - o - o - o - o - MAIN - o - o - o - o - o - o - o - o - o

struct state
{
    int u, melon;
    state(int _u = 0, int _melon = 0)
    {
        u = _u, melon = _melon;
    }

    bool operator < (const state &a) const
    {
        return u < a.u;
    }
};



typedef pair<ll, state> pii;
int msk[maxn];
int n, m, k, l;
vector<vector<ll> > d;
vector<vector<pil> > adj;

void dijkstra(int source)
{
    d.assign(n + 5, vector<ll>(32, INFL));
    priority_queue<pii, vector<pii>, greater<pii> > q;

    d[source][msk[source]] = 0;
    q.push({0, state(source, msk[source])});

    while (q.size())
    {
        ll du = q.top().first;
        int u = q.top().second.u;
        int c = q.top().second.melon;
        q.pop();

        if (du != d[u][c]) continue;
        for (int i = 0; i < sz(adj[u]); i++)
        {
            int v = adj[u][i].first;
            ll w = adj[u][i].second;
            int newc = c | msk[v];

            if (d[v][newc] > d[u][c] + w)
            {
                d[v][newc] = d[u][c] + w;
                q.push({d[v][newc], state(v, newc)});
            }
        }
    }
}

void process()
{
    cin >> n >> m >> k >> l;
    adj.assign(n + 5, vector<pil>());
    FOR(i, 1, n)
    {
        int s;
        cin >> s;
        while (s--)
        {
            int tmp;
            cin >> tmp;
            msk[i] |= (1 << (tmp - 1));
        }
    }

    FOR(i, 1, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra(1);

    ll ans = INFL;
    for(int i = 0; i < 1 << k; i++)
        if (cntBit(i) >= l) ans = min(ans, d[n][i]);
    if (ans == INFL) cout << -1;
    else cout << ans;

}
int main()
{
    fast;
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    process();
}

