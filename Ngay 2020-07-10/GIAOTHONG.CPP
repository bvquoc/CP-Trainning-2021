#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long

struct pack {int u, l;};
typedef vector< vector<pack> > dsk;
int n, m;
dsk ke;
vector <int> d, f;
vector <bool> b;

int32_t main() {
    FastIO;
    freopen("GIAOTHONG.INP","r",stdin);
    freopen("GIAOTHONG.OUT","w",stdout);
    cin >> n >> m;
    ke.resize(n+1);
    for (int i=1;i<=m;i++) {
        int u, v, l;
        cin >> u >> v >> l;
        ke[u].push_back({v,l});
        ke[v].push_back({u,l});
    }
    d.resize(n+1,1e18);
    f.resize(n+1,0LL);
    b.resize(n+1,true);
    d[1] = 0LL; f[1] = 1ll;
    for (int tmp=n;tmp--;) {
        int u=-1;
        for (int v=1; v<=n; v++) if (b[v] && (u == -1 || d[u] > d[v])) u = v;
        if (u==-1 || u==n) break;
        b[u]=false;
        for (pack p:ke[u]) {
            int v = p.u, l = p.l;
            if (d[v]>d[u]+l) {
                d[v] = d[u]+l;
                f[v] = f[u];
            } else if (d[v]==d[u]+l) f[v] += f[u];
        }
    }
    cout<<d[n]<<" "<<f[n];
    return 0;
}