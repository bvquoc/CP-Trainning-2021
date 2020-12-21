#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
#define cntBit __builtin_popcount

struct Flight {
    long long edge;
    int vert;
    bool used1, used2, used3, used4, used5;
};

struct CMP {
    bool operator() (Flight &a, Flight &b) {
        return a.edge < b.edge;
    }
};

int a[100005];
vector<int> group[100005];
long long d[100005][2][2][2][2][2];

struct Dijkstra {
    typedef pair<long long, long long> II;
    vector<vector<II>> adj;
    int n, k, l;

    Dijkstra(int n, int k, int l): n(n), k(k), l(l) {
        adj.resize(n + 1);
    }

    void addEdge(int u, int v, long long c) {
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void dijkstra(int a) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int j1 = 0; j1 <= 1; j1++) {
                    for (int j2 = 0; j2 <= 1; j2++) {
                        for (int j3 = 0; j3 <= 1; j3++) {
                            for (int j4 = 0; j4 <= 1; j4++) {
                                d[i][j][j1][j2][j3][j4] = INF;
                            }
                        }
                    }
                }
            }
        }
        d[a][1][1][1][1][1] = 0;

        priority_queue<Flight, vector<Flight>, CMP> pq;
//        priority_queue<II, vector<II>, greater<II>> pq;
        pq.push({0, a, 1, 1, 1, 1, 1});

        if (l == 0) {
            while (!pq.empty()) {
                long long du = pq.top().edge;
                int u = pq.top().vert;
//                long long du = pq.top().first;
//                int u = pq.top().second;
                pq.pop();

                if (du != d[u][1][1][1][1][1]) continue;

                for (auto i: adj[u]) {
                    long long uv = i.second;
                    int v = i.first;

                    if (d[v][1][1][1][1][1] > du + uv) {
                        d[v][1][1][1][1][1] = du + uv;
                        pq.push({d[v][1][1][1][1][1], v});
                    }
                }
            }
        }
        else {
            while (!pq.empty()) {
                long long du = pq.top().edge;
                int u = pq.top().vert;
                int used1 = pq.top().used1;
                int used2 = pq.top().used2;
                int used3 = pq.top().used3;
                int used4 = pq.top().used4;
                int used5 = pq.top().used5;
                pq.pop();

                if (du != d[u][used1][used2][used3][used4][used5]) continue;

                for (auto i: adj[u]) {
                    long long uv = i.second;
                    int v = i.first;

                    for (auto q: group[v]) {
                        if (q == 1) {
                            if (used1 == 0) {
                                if (d[v][0][used2][used3][used4][used5] > du + uv) {
                                    d[v][0][used2][used3][used4][used5] = du + uv;
                                    pq.push({d[v][0][used2][used3][used4][used5], v, 0, used2, used3, used4, used5});
                                }

                                if (d[v][1][used2][used3][used4][used5] > du + uv) {
                                    d[v][1][used2][used3][used4][used5] = du + uv;
                                    pq.push({d[v][1][used2][used3][used4][used5], v, 0, used2, used3, used4, used5});
                                }
                            }
                            else {
                                d[v][0][used2][used3][used4][used5] = d[v][1][used2][used3][used4][used5];
                                pq.push({d[v][1][used2][used3][used4][used5], v, 0, used2, used3, used4, used5});

                                if (d[v][0][used2][used3][used4][used5] > du + uv) {
                                    d[v][0][used2][used3][used4][used5] = du + uv;
                                    pq.push({du + uv, v, 0, used2, used3, used4, used5});
                                }
                            }
                        }

                        if (q == 2) {
                            if (used2 == 0) {
                                if (d[v][used1][0][used3][used4][used5] > du + uv) {
                                    d[v][used1][0][used3][used4][used5] = du + uv;
                                    pq.push({d[v][used1][0][used3][used4][used5], v, used1, 0, used3, used4, used5});
                                }

                                if (d[v][used1][1][used3][used4][used5] > du + uv) {
                                    d[v][used1][1][used3][used4][used5] = du + uv;
                                    pq.push({d[v][used1][1][used3][used4][used5], v, used1, 0, used3, used4, used5});
                                }
                            }
                            else {
                                d[v][used1][0][used3][used4][used5] = d[v][used1][1][used3][used4][used5];
                                pq.push({d[v][used1][1][used3][used4][used5], v, used1, 0, used3, used4, used5});

                                if (d[v][used1][0][used3][used4][used5] > du + uv) {
                                    d[v][used1][0][used3][used4][used5] = du + uv;
                                    pq.push({du + uv, v, used1, 0, used3, used4, used5});
                                }
                            }
                        }

                        if (q == 3) {
                            if (used3 == 0) {
                                if (d[v][used1][used2][0][used4][used5] > du + uv) {
                                    d[v][used1][used2][0][used4][used5] = du + uv;
                                    pq.push({d[v][used1][used2][0][used4][used5], v, used1, used2, 0, used4, used5});
                                }

                                if (d[v][used1][used2][1][used4][used5] > du + uv) {
                                    d[v][used1][used2][1][used4][used5] = du + uv;
                                    pq.push({d[v][used1][used2][1][used4][used5], v, used1, used2, 0, used4, used5});
                                }
                            }
                            else {
                                d[v][used1][used2][0][used4][used5] = d[v][used1][used2][1][used4][used5];
                                pq.push({d[v][used1][used2][1][used4][used5], v, used1, used2, 0, used4, used5});

                                if (d[v][used1][used2][0][used4][used5] > du + uv) {
                                    d[v][used1][used2][0][used4][used5] = du + uv;
                                    pq.push({du + uv, v, used1, used2, 0, used4, used5});
                                }
                            }
                        }

                        if (q == 4) {
                            if (used4 == 0) {
                                if (d[v][used1][used2][used3][0][used5] > du + uv) {
                                    d[v][used1][used2][used3][0][used5] = du + uv;
                                    pq.push({d[v][used1][used2][used3][0][used5], v, used1, used2, used3, 0, used5});
                                }

                                if (d[v][used1][used2][used3][1][used5] > du + uv) {
                                    d[v][used1][used2][used3][1][used5] = du + uv;
                                    pq.push({d[v][used1][used2][used3][1][used5], v, used1, used2, used3, 0, used5});
                                }
                            }
                            else {
                                d[v][used1][used2][used3][0][used5] = d[v][used1][used2][used3][1][used5];
                                pq.push({d[v][used1][used2][used3][1][used5], v, used1, used2, used3, 0, used5});

                                if (d[v][used1][used2][used3][0][used5] > du + uv) {
                                    d[v][used1][used2][used3][0][used5] = du + uv;
                                    pq.push({du + uv, v, used1, used2, used3, 0, used5});
                                }
                            }
                        }

                        if (q == 5) {
                            if (used5 == 0) {
                                if (d[v][used1][used2][used3][used4][0] > du + uv) {
                                    d[v][used1][used2][used3][used4][0] = du + uv;
                                    pq.push({d[v][used1][used2][used3][used4][0], v, used1, used2, used3, used4, 0});
                                }

                                if (d[v][used1][used2][used3][used4][1] > du + uv) {
                                    d[v][used1][used2][used3][used4][1] = du + uv;
                                    pq.push({d[v][used1][used2][used3][used4][1], v, used1, used2, used3, used4, 0});
                                }
                            }
                            else {
                                d[v][used1][used2][used3][used4][0] = d[v][used1][used2][used3][used4][1];
                                pq.push({d[v][used1][used2][used3][used4][1], v, used1, used2, used3, used4, 0});

                                if (d[v][used1][used2][used3][used4][0] > du + uv) {
                                    d[v][used1][used2][used3][used4][0] = du + uv;
                                    pq.push({du + uv, v, used1, used2, used3, used4, 0});
                                }
                            }
                        }
                    }

                    if (d[v][used1][used2][used3][used4][used5] > du + uv) {
                        d[v][used1][used2][used3][used4][used5] = du + uv;
                        pq.push({du + uv, v, used1, used2, used3, used4, used5});
                    }
                }
            }
        }

    }
};

int getBit(int bit, int k) {
    return bit & (1 << k);
}

int main() {
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, k, l;
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) {
            int x;
            cin >> x;
            group[i].push_back(x);
        }
    }

    Dijkstra dijkstra(n, k, l);

    for (int i = 1; i <= m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        dijkstra.addEdge(u, v, c);
    }

    if (l == 0) {
        dijkstra.dijkstra(1);

        long long res = d[n][1][1][1][1][1];
        if (res == INF) res = -1;
        cout << res;
    }
    else if (k == 1) {
        dijkstra.dijkstra(1);

        long long res = d[n][0][1][1][1][1];

        if (res == INF) res = -1;
        cout << res;
    }
    else {
        dijkstra.dijkstra(1);

        long long res = INF;
        if (l == 1) {
            res = min({d[n][0][1][1][1][1], d[n][0][0][1][1][1], d[n][0][0][0][1][1], d[n][0][0][0][0][1], d[n][0][0][0][0][0]});
        }
        else if (l == 2) {
            res = min({d[n][0][0][1][1][1], d[n][0][0][0][1][1], d[n][0][0][0][0][1], d[n][0][0][0][0][0]});
        }
        else if (l == 3) {
            res = min({d[n][0][0][0][1][1], d[n][0][0][0][0][1], d[n][0][0][0][0][0]});
        }
        else if (l == 4) {
            res = min({d[n][0][0][0][0][1], d[n][0][0][0][0][0]});
        }
        else res = d[n][0][0][0][0][0];

        if (res == INF) res = -1;
        cout << res;
    }


    return 0;
}

