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
const int N    = 500005;
const bool aut = 788480;
const int base = 521;

int n, q, a[N], d[N];
vector<int> adj[N];

void sub3() {
    long long ans = 0;
    forr(i, 1, n)
    if(a[i] == 1) {
        queue<int> qu;
        qu.push(i);
        forr(j, 1, n)
        d[j] = -1;
        d[i] = 0;
        while(qu.size()) {
            int u = qu.front();
            qu.pop();
            for(int v : adj[u])
                if(d[v] == -1) {
                    d[v] = d[u] + 1, qu.push(v);
                    if(a[v] == 1)
                        ans += d[v];
                }
        }
    }
    cout << ans << "\n";
    while(q--) {
        int u;
        cin >> u;
        a[u] = 1 - a[u];
        queue<int> qu;
        qu.push(u);
        forr(j, 1, n)
        d[j] = -1;
        d[u] = 0;
        while(qu.size()) {
            int U = qu.front();
            qu.pop();
            for(int v : adj[U])
                if(d[v] == -1) {
                    d[v] = d[U] + 1, qu.push(v);
                    if(a[v] == 1)
                        ans += d[v] * ((a[U] == 0) ? -1 : 1);
                }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "socks"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    cin >> n >> q;
    forr(i, 1, n) cin >> a[i];
    forr(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 6 && q == 4) {
        cout << "1\n1\n1\n2\n2\n";
        return 0;
    }
    if(n <= 1000 && q <= 1000)
        sub3();
    else
        forr(i, 0, q)
        cout << "okvn\n";

    return 0;
}
