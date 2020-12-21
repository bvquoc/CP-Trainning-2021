#include <bits/stdc++.h>
#define fore(it,a)       for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define forr(i, a, b)    for(int i = (a); i <= (b); ++i)
#define ford(i, a, b)    for(int i = (a); i >= (b); --i)
#define repp(i, a, b)    for(int i = (a); i < (b); ++i)
#define repd(i, a, b)    for(int i = (a); i > (b); --i)
#define mem(a, x)        memset(x, (a), sizeof(x))
#define bitcount(x)      __builtin_popcountll((x))
#define OFFBIT(mask, i)  ((mask) &~ (1ll << (i)))
#define ONBIT(mask, i)   ((mask) | (1ll << (i)))
#define reset(x)         memset(x, 0, sizeof(x))
#define all(a)           (a).begin(), (a).end()
#define BIT(x, i)        (((x) >> (i)) & 1)
#define ii               pair<int, int>
#define MASK(i)          (1LL << (i))
#define mp               make_pair
#define se               second
#define fi               first

using namespace std;

mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD  = 1000000007;
const int inf  = 2000000000;
const int mod  = 1007050321;
const double e = 0.000001;
const int N    = 100005;
const bool aut = 788480;
const int base = 521;

int n, m, k, l, a[N];
long long d[N][MASK(5)+5];
vector<ii> adj[N];
struct Node {
    int u, mask;
    long long dist;
    bool friend operator < (Node a, Node b) {
        return a.dist < b.dist;
    }
};
priority_queue<Node> hp;

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "dhaka"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    cin >> n >> m >> k >> l;
    forr(i, 1, n) {
        int si;
        cin >> si;
        forr(j, 1, si) {
            int ai;
            cin >> ai;
            a[i] = ONBIT(a[i], ai-1);
        }
    }
    forr(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
    forr(i, 1, n)
    repp(j, 0, MASK(k))
    d[i][j] = 1e18;
    d[1][a[1]] = 0;
    hp.push({1, a[1], 0});
    while(hp.size()) {
        int u = hp.top().u;
        int mask = hp.top().mask;
        long long du = -hp.top().dist;
        hp.pop();
        if(du != d[u][mask])
            continue;
        for(auto E : adj[u])
            if(d[E.fi][(mask|a[E.fi])] > du + E.se) {
                d[E.fi][(mask|a[E.fi])] = du + E.se;
                hp.push({E.fi, (mask|a[E.fi]), -du-E.se});
            }
    }
    long long ans = -1;
    repp(j, 0, MASK(k))
    if(bitcount(j) >= l && d[n][j] != 1e18) {
        if(ans == -1 || ans > d[n][j])
            ans = d[n][j];
    }
    cout << ans;

    return 0;
}
