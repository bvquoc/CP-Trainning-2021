#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ii = pair <int,int>;
const int N = 102, INF = INT_MAX;
int n, m, d[N][N];
int ans = INF, ans_id = 1;

int32_t main(void) {
    FastIO;
    freopen("TRUNGTAM.INP","r",stdin);
    freopen("TRUNGTAM.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            d[i][j] = INF;
            if (i==j) d[i][j] = 0;
        }
    }
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }

    // Floyd
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    // Solve
    for (int i=1;i<=n;i++) {
        int cur = 0;
        for (int j=1; j<=n; j++) {
            cur += d[i][j];
        }
        if (ans > cur) {
            ans = cur;
            ans_id = i;
        }
    }
    cout << ans_id << '\n' << ans;
    return 0;
}