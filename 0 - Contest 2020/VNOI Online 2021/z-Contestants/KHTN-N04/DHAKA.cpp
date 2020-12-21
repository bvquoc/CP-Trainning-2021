#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5;
const ll infll = 1e18 + 7;

int n, m, k, l;
int a[N];
vpii adj[N];

void readTest(){
    cin >> n >> m >> k >> l;
    ForE(i, 1, n){
        int x; cin >> x;
        while (x--){
            int y; cin >> y; y--;
            a[i] |= (1 << y);
        }
    }
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
}

ll dist[N][32];

struct PqueElem{
    ll d; int u, msk;

    PqueElem(ll d, int u, int msk): d(d), u(u), msk(msk) {

    }
};

bool operator> (const PqueElem& PqueElem1, const PqueElem& PqueElem2){
    return PqueElem1.d > PqueElem2.d;
}

void solveTest(){
    memset(dist, 0x3f, sizeof(dist));
    priority_queue <PqueElem, vector <PqueElem>, greater <PqueElem>> pq;
    dist[1][a[1]] = 0;
    pq.push(PqueElem(0, 1, a[1]));
    while (!pq.empty()){
        PqueElem t = pq.top(); pq.pop();
        if (t.d != dist[t.u][t.msk]){
            continue;
        }
        Fora(&edge, adj[t.u]){
            int v = edge.fi, w = edge.se;
            if (dist[v][a[v] | t.msk] > t.d + w){
                dist[v][a[v] | t.msk] = t.d + w;
                pq.push(PqueElem(dist[v][a[v] | t.msk], v, a[v] | t.msk));
            }
        }
    }
    ll ans = infll;
    For(msk, 0, (1 << k)){
        if (__builtin_popcount(msk) >= l){
            ans = min(ans, dist[n][msk]);
        }
    }
    cout << (ans == infll ? -1 : ans) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    readTest();
    solveTest();
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|
6 6 2 2
0
1 1
0
1 1
1 1
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
--------------------------------------------------|
6 6 2 2
0
1 1
0
1 1
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
--------------------------------------------------|
6 6 2 2
0
1 1
0
0
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|
-1
--------------------------------------------------|
5
--------------------------------------------------|
6
--------------------------------------------------|
==================================================+
*/
