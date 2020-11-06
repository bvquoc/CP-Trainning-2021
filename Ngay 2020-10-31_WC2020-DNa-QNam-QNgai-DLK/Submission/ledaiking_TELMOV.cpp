#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long oo = 1e18;
typedef pair<int, int> ii;
vector<ii> a[10309];
int n, m;
long long d[10309];
void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    int p, q, m, w,x,y,z;
    cin>>n>>m>>x>>y>>z;
    while (m--) {
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    dijkstra();
   cout<<d[n];
}
