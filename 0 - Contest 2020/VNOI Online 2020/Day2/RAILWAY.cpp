#include <bits/stdc++.h>

using namespace std;

constexpr int inf=INT_MAX;
constexpr long long linf=LLONG_MAX;

struct edge {
    int from;
    int to;
    int cost;
};

struct node {
    int v;
    int f;
    long long d;
    inline bool operator<(const node& rhs) const {
        return d>rhs.d;
    }
};

int main() {
    freopen("railway.inp", "r", stdin);
    freopen("railway.out", "w", stdout);
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s), s--;
    vector<int> w(n);
    for (int& x : w) {
        scanf("%d", &x), x += inf;
    }
    vector<vector<int>> g(n);
    vector<edge> edges(m);
    for (int i=0; i<m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c), u--, v--;
        edges[i]={u, v, c};
        g[u].push_back(i);
    }
    vector<vector<int>> trace(n, vector<int>(2));
    vector<vector<long long>> d(n, vector<long long>(2, linf));
    priority_queue<node> pq;
    d[s][0]=0, pq.push({s, 0, 0});
    while (pq.size()) {
        node from=pq.top();
        pq.pop();
        if (from.d!=d[from.v][from.f]) {
            continue;
        }
        if (from.f==0 && d[from.v][1]>from.d+w[from.v]) {
            trace[from.v][1]=-1;
            d[from.v][1]=from.d+w[from.v];
            pq.push({from.v, 1, d[from.v][1]});
        }
        for (int i : g[from.v]) {
            edge& e=edges[i];
            if (d[e.to][from.f]>from.d+e.cost) {
                trace[e.to][from.f]=i;
                d[e.to][from.f]=from.d+e.cost;
                pq.push({e.to, from.f, d[e.to][from.f]});
            }
        }
    }
    int t=s;
    for (int i=0; i<n; ++i) {
        if (d[i][1]!=linf && d[i][1]>d[t][1]) {
            t=i;
        }
    }
    printf("%lld %d\n", d[t][1]-inf, t+1);
    vector<int> path;
    int f=1;
    while (!(t==s && f==0)) {
        if (trace[t][f]!=-1) {
            path.push_back(trace[t][f]);
            t=edges[trace[t][f]].from;
        } else {
            f--;
        }
    }
    reverse(path.begin(), path.end());
    printf("%d\n", (int)path.size());
    for (int e : path) {
        printf("%d ", e+1);
    }
    return 0;
}