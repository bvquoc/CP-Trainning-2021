#include <bits/stdc++.h>
#define f(u) f[(u).first][(u).second]

using namespace std;


typedef pair <long long, long long> ii;
typedef pair <long long, ii> iii;

const long long INF = 1e15 + 7;
const long long N = 5e3 + 5;
long long n, k;
long long c[N], d[N], f[N][N];
vector <long long> adj[N];

void dijkstra() {
    priority_queue <iii, vector<iii>, greater<iii>> pq;
    long long du;
    ii u;

    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
        f[i][j] = INF;
    pq.push(iii(0, ii(1, 0)));
    // cout << f[n][0] << "\n";
    f[1][0] = 0;

    while (pq.size()) {
        u = pq.top().second;
        du = pq.top().first;
        // cout << u.first << ' ' << u.second << "\n";
        pq.pop();
        if (du != f(u)) continue;

        for (int i = 0; i < adj[u.first].size(); i++) {
            ii v = ii(adj[u.first][i], 0);

            if (u.second > 0) {
                v.second = u.second - 1;
                if (f(v) > du) {
                    f(v) = du;
                    pq.push(iii(f(v), v));
                }
            }

            v.second = d[u.first] - 1;
            if (f(v) > du + c[u.first]) {
                f(v) = du + c[u.first];
                pq.push(iii(f(v), v));
            }
        }
    }
}


int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &c[i], &d[i]);
    }
    for (int i = 1; i <= k; i++) {
        long long u, v;
        scanf("%lld%lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dijkstra();
    long long res = INF;
    for (int i = 0; i <= n; i++) res = min(res, f[n][i]);
    // cout << f[5][1] << "\n";
    printf("%lld", res);
}