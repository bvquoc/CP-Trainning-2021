#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define uu first
#define ll second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

const int N = 5003;
using ii = pair<int,int>;
using ll = long long;

vector<ii> ke[N];
int d[N];
ll f[N];
bool b[N];

signed main() {
    FastIO;
    freopen("SCHOOL.INP","r",stdin);
    freopen("SCHOOL.OUT","w",stdout);
    int n, m; cin >> n >> m;
    while (m--) {
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        ke[u].push_back({v, l});
        if (k == 2) ke[v].push_back({u, l});
    }

    FOR(i,1,n) {
        d[i] = 1e9;
        f[i] = 0LL;
        b[i] = true;
    }
    d[1] = 0; f[1] = 1LL;
    for (int _=n; _--;) {
        int u = -1;
        FOR(v,1,n) if (b[v]) {
            if (u == -1 || d[u] > d[v]) u = v;
        }
        if (u == -1 || u == n) break;
        b[u] = false;
        for (ii p: ke[u]) {
            int v = p.uu, l = p.ll;
            if (d[v] > d[u] + l) {
                d[v] = d[u] + l;
                f[v] = f[u];
            } else if (d[v] == d[u] + l) {
                f[v] += f[u];
            }
        }
    }
    cout << d[n] << ' ' << f[n];
    return 0;
} 