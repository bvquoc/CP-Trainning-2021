#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
typedef pair<int, int> ii;

vector<vector <ii> >a; 
int n, m;
vector <int> d;

void dijkstra(){
    priority_queue <ii, vector<ii>, greater<ii> > pq;

    for (int i=1; i<=n; i++) d[i] = INF;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (int i=0; int v=a[u][i].second; i++) {
            int uv = a[u][i].first;
            if (d[v] > du+uv) {
                d[v] = du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int32_t main(void){
    freopen("Dijkstra.inp","r",stdin);
    freopen("Dijkstra.out","w",stdout);
    int p, q, m, w;
    scanf("%d%d", &n, &m);
    a.resize(n+1);
    d.resize(n+1);
    while (m--) {
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));
    }
    for (int i=1; i<=n; i++)
        a[i].push_back(ii(0,0));
    dijkstra();
    if (d[n]==INF) d[n] = -1;
    cout << d[n];
}