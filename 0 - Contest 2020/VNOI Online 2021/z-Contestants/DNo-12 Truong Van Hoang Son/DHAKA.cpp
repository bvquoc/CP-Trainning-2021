#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair <int, int> ii;
const int oo = 1e18;

int n, m, k, l;
int s[100005];
vector <ii> a[100005];
vector <int> c[100005];
int d[100005];
int dn[100005];
int ans = oo;

void Dijkstra(int x) {
    priority_queue <ii, vector <ii>, greater <ii> > pq;
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[x] = 0;
    int u, du, v, uv;
    pq.push(ii(d[x], x));
    while (pq.size()) {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < a[u].size(); i++) {
            v = a[u][i].second;
            uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int A[106][106];
bool cx[15];

vector <int> vt[100005];

void TSP(int i, int u, int S) {
    if (i > l) {
        ans = min(ans, S + A[u][n]);
        return;
    }
    for (int j = 1; j <= 5; j++) {
        if (cx[j]) continue;
        cx[j] = true;
        for (int k = 0; k < vt[j].size(); k++) {
            if (S + A[u][vt[j][k]] >= ans) continue;
            TSP(i + 1, vt[j][k], S + A[u][vt[j][k]]);
        }
        cx[j] = false;
    }
}

void TrauBo() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) A[i][j] = oo;
    for (int i = 1; i <= n; i++) {
        A[i][i] = 0;
        for (int j = 0; j < a[i].size(); j++)
            A[i][a[i][j].second] = a[i][j].first;
    }

    for (int k = 1; k <= n; k++)
    for (int u = 1; u <= n; u++)
    for (int v = 1; v <= n; v++)
    if (A[u][v] > A[u][k] + A[k][v]) A[u][v] = A[u][k] + A[k][v];
    TSP(1, 1, 0);
    if (ans >= oo) cout << -1;
    else cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1, x; j <= s[i]; j++) {
            cin >> x;
            c[i].push_back(x);
            vt[x].push_back(i);
        }
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        a[u].push_back(ii(w, v));
        a[v].push_back(ii(w, u));
    }
    Dijkstra(n);
    if (l == 0) {
        if (d[1] >= oo) cout << -1;
        else cout << d[1];
        return 0;
    }
    if (l == 1) {
        int res = oo;
        for (int i = 1; i <= n; i++) dn[i] = d[i];
        Dijkstra(1);
        for(int i = 1; i <= n; i++) {
            if (s[i] != 0) {
                res = min(res, d[i] + dn[i]);
            }
        }
        if (res >= oo) cout << -1;
        else cout << res;
        return 0;
    }
    if (n <= 100) {
        TrauBo();
        return 0;
    }

    cout << d[1];
    return 0;
}
