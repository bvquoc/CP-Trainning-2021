#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORV(v, H) for (auto &v: H)

#define ii pair <int, int>
#define fi first
#define se second
#define ll long long

#define vi vector <int>
#define vii vector <ii>
#define pb push_back

#define reset(f, val) memset(f, val, sizeof(f))

#define MASK(i) (1ll << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) ((mask) | (1ll << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1ll << (i)))

#define int long long

const int MAXN = 1e5 + 1005;
const int   oo = 1e18 + 7;

int N, M, K, L;
int S[MAXN], A[MAXN][8];
vii G[MAXN];
int mask[MAXN];

int dist[MAXN][105];

struct DATA {
    int du, u, mask;
};

struct cmp {
    bool operator () (const DATA &A, const DATA &B) {
        return A.du > B.du;
    }
};

void Dijkstra(int u) {
    FOR(i, 1, N)
        FOR(mask, 0, 100)
            dist[i][mask] = +oo;

    priority_queue <DATA, vector <DATA>, cmp> pq;

    dist[u][mask[u]] = 0;
    pq.push({0, u, mask[u]});

    while (pq.size()) {
        int u = pq.top().u;
        int du= pq.top().du;
        int curmask = pq.top().mask;
        pq.pop();
        if (du != dist[u][curmask]) continue;
        FORV(tmp, G[u]) {
            int uv = tmp.fi;
            int  v = tmp.se;
            int nxtmask = curmask | mask[v];
            if (dist[v][nxtmask] > du + uv) {
                dist[v][nxtmask] = du + uv;
                pq.push({dist[v][nxtmask], v, nxtmask});
            }
        }
    }
    int ANS = +oo;
    FOR(mask, 0, 100)
        if (__builtin_popcount(mask) >= L) {
            ANS = min(ANS, dist[N][mask]);
        }
    if (ANS == +oo) cout << -1 << '\n';
    else cout << ANS << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);

    cin >> N >> M >> K >> L;
    FOR(i, 1, N) {
        cin >> S[i];
        FOR(j, 1, S[i]) {
            cin >> A[i][j];
            mask[i] |= A[i][j];
        }
    }
    FOR(i, 1, M) {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].pb(ii(c, v));
        G[v].pb(ii(c, u));
    }

    Dijkstra(1);
    return 0;
}

//  Test 01
//6 6 2 2
//0
//1 1
//0
//1 1
//1 1
//0
//1 2 1
//2 3 2
//1 4 2
//4 5 2
//5 6 1
//3 6 1

//  Test 02
//6 6 2 2
//0
//1 1
//0
//1 1
//1 2
//0
//1 2 1
//2 3 2
//1 4 2
//4 5 2
//5 6 1
//3 6 1

//  Test 03
//6 6 2 2
//0
//1 1
//0
//0
//1 2
//0
//1 2 1
//2 3 2
//1 4 2
//4 5 2
//5 6 1
//3 6 1
