#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define se second
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 103, INF = 1e9;
int n, m, a[N][N];
vector <int> ke[N];
int d[N], T[N];
bool mark[N];
int s = 0, d_s = INF, t;
vector <int> ans;

void dfs(int root, int u, int cost, int cnt) {
    mark[u] = true;
    if (cnt >= 3) {
        if (d_s > cost+a[u][root]) {
            d_s = cost + a[u][root];
            s = root;
            t = u;
            ans.clear();
            int x = t;
            ans.push_back(x);
            while (T[x]!=0) {
                ans.push_back(T[x]);
                x = T[x];
            }
            return;
        }
    }
    for (int v: ke[u]) if (!mark[v]) {
        int tmp = T[v];
        T[v] = u;
        dfs(root, v, cost+a[u][v], cnt+1);
        mark[v] = false;
        T[v] = tmp;
    }
}

signed main() {
    FastIO;
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) a[i][j] = INF;
        a[i][i] = 0;
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].push_back(v);
        ke[v].push_back(u);
        w = min({w,a[u][v],a[v][u]});
        a[u][v] = a[v][u] = w;
    }
    for (int u=1; u<=n; u++) {
        for (int i=1; i<=n; i++) {
            d[i] = 0;
            T[i] = 0;
            mark[i] = false;
        }
        dfs(u,u,0,1);
    }
    if (d_s == INF) {
        cout << '0';
        return 0;
    }

    cout << "1\n" << d_s << endl;
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int x: ans) cout << x << endl;
    return 0;
}
