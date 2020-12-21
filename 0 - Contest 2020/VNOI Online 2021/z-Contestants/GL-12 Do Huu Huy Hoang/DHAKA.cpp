/*          _
         __(.)< (cocc)
        \____)
    ~~~~~~~~~~~~~~~~
*/

#include <bits/stdc++.h>

#define FASTCIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define DEBUG freopen("_inp.inp", "r", stdin);
#define FILE(name) freopen(name".inp","r", stdin); freopen(name".out", "w", stdout);
#define runTime(num) cout << "\nTime: " << fixed << setprecision(num) << (double)(clock() - time)/CLOCKS_PER_SEC << "s\n";

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i >= a; i--)
#define PB push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define BIT(x) (1LL << (x))
#define GET(S, x) ((S >> x) & 1LL)

#define INF (int)(1e9+7)
#define LLINF (ll)(1e18+7)
#define N (ll)(1e5+3)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct Dat {
    int u, w, picked;

    bool operator < (const Dat& other) const {
        return w > other.w;
    }
};

int n, m, k, l;
int melon[N];
int d[N];
int d2[N][34];
vector<pi> g[N];

bool mini(int &a, int b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

void sub2() {
    FOR(i, 1, n) d[i] = INF;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    d[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().se;
        int curw = pq.top().fi;
        pq.pop();
        for (auto p : g[u]) {
            int v = p.fi;
            int w = p.se;
            if (mini(d[v], curw + w)) {
                pq.push({curw + w, v});
            }
        }
    }
    if (d[n] == INF) cout << -1 << "\n";
    else cout << d[n];
}

void dij(int s, int sp, int startingCost) {
    FOR(i, 1, n) d2[i][0] = d2[i][1] = INF;
    priority_queue<Dat> pq;
    pq.push({s, startingCost, sp});
    d2[s][sp] = startingCost;

    while (!pq.empty()) {
        int u = pq.top().u;
        int curw = pq.top().w;
        int bit = pq.top().picked;
        //cout << u << ' ' << curw << ' ' << bit << "\n";
        pq.pop();

        for (auto p : g[u]) {
            int v = p.fi;
            int w = p.se;
            int nbit = bit | melon[v];
            if (mini(d2[v][nbit], curw + w)) {
                pq.push({v, curw + w, nbit});
            }
        }
    }
}

void sub3() {
    dij(1, 0, 0);
    int init = d2[n][1];
    int cst = d2[n][0];

    dij(n, 0, 0);
    int mn = init;
    FOR(i, 1, n-1) {
        if (d2[i][1] != INF && cst + d2[i][1] < mn) {
            mn = cst + 2*d2[i][1];
            //cout << cst + 2 * d2[i][1] << "WUT" << "\n";
        }
    }
    if (mn == INF) {
        cout << -1 << "\n";
    }
    else cout << mn << "\n";
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("DHAKA")

    cin >> n >> m >> k >> l;
    FOR(i, 1, n) {
        int t;
        cin >> t;
        FOR(j, 1, t) {
            int tt;
            cin >> tt;
            melon[i] |= BIT(tt-1);
        }
        //cout << tmp << ' ';
    }
    FOR(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].PB({v, w});
        g[v].PB({u, w});
    }
    if (l == 0) sub2();
    else if (k == 1) sub3();
    else cout << -1 << "\n";
    //runTime(5);
    return 0;
}


