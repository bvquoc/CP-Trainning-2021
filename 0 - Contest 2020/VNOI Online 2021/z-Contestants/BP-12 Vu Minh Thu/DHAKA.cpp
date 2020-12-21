#include<bits/stdc++.h>
using namespace std;

ifstream fi("DHAKA.inp");
ofstream fo("DHAKA.out");

int const N = 1e5 + 5;
int64_t const INF = 1e18;

int n, m, k, l;
int s[N];
int mask[N];

int64_t dist[N];
int64_t distN[N];
int wmelon[N];
int wmelonN[N];

typedef pair<int64_t, int64_t> ii;
typedef pair<ii, int> iii;

vector <vector<ii> > adj;

struct Data {int64_t u, v, w;} e[N];;

void dijkstra(){
    for(int i = 1; i <= n; ++i) dist[i] = INF;
    dist[1] = 0;
    priority_queue <iii, vector<iii>, greater<iii> > qu;
    qu.push({{0, 1}, mask[1]});
    wmelon[1] = mask[1];
    while(!qu.empty()){
        int u = qu.top().first.second;
        int64_t du = qu.top().first.first;
        int masku = qu.top().second;
        qu.pop();
        if(du != dist[u]) continue;
        for(int i = 0; i < adj[u].size(); ++i){
            int v = adj[u][i].first;
            int64_t w = adj[u][i].second;
            if(dist[v] > du + w){
                dist[v] = du + w;
                wmelon[v] = masku | mask[v];
                qu.push({{dist[v], v}, wmelon[v]});
            }
        }
    }
}

void dijk(){
    for(int i = 1; i <= n; ++i) distN[i] = INF;
    distN[n] = 0;
    priority_queue<iii, vector<iii>, greater<iii> > qu;
    qu.push({{0, n}, mask[n]});
    wmelonN[n] = mask[n];
    while(!qu.empty()){
        int u = qu.top().first.second;
        int64_t du = qu.top().first.first;
        int masku = qu.top().second;
        qu.pop();
        if(du != distN[u]) continue;
        for(int i = 0; i < adj[u].size(); ++i){
            int v = adj[u][i].first;
            int64_t w = adj[u][i].second;
            if(distN[v] > du + w){
                distN[v] = du + w;
                wmelonN[v] = masku | mask[v];
                qu.push({{distN[v], v}, wmelonN[v]});
            }
        }
    }
}

void sub2(){
    dijkstra();
    dijk();
    if(dist[n] == INF) fo << -1;
    else fo << dist[n];
}

int64_t ans = INF;

void sub3(){
    dijkstra();
    dijk();
    for(int i = 1; i <= m; ++i){
        int64_t u = e[i].u;
        int64_t v = e[i].v;
        int64_t w = e[i].w;
        if(dist[u] == INF || distN[v] == INF) continue;
        if(!s[u] && !s[v]) continue;
        ans = min(ans, dist[u] + w + distN[v]);
    }
    if(ans == INF) fo << -1;
    else fo << ans;
}

void All(){
    dijk();
    dijkstra();
    for(int i = 1; i <= m; ++i){
        int64_t u = e[i].u;
        int64_t v = e[i].v;
        int64_t w = e[i].w;
        if(dist[u] == INF || distN[v] == INF) continue;
        int tmp = wmelon[u] | wmelonN[v];
        int cnt = 0;
        for(int i = 6; i >= 0; --i)
            if(((tmp >> (i - 1)) & 1) == 1) ++cnt;
        if(cnt >= l) ans = min(ans, dist[u] + w + distN[v]);
    }
    if(ans == INF) fo << -1;
    else fo << ans;
}

int main(){
    fi >> n >> m >> k >> l;
    adj.resize(n + 1);
    int wm = 0;
    for(int i = 1; i <= n; ++i) {
        fi >> s[i];
        for(int j = 1; j <= s[i]; ++j) {
            int64_t x;
            fi >> x;
            mask[i] = mask[i] | (1 << (x - 1));
        }
        wm |= mask[i];
        //cout << mask[i] << "\n";
    }
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        fi >> u >> v >> w;
        e[i] = {u, v, w};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    //----
    int cnt = 0;
    for(int i = 0; i <= 6; ++i)
        if(((wm >> i) & 1) == 1) ++cnt;
    if(cnt < l) {fo << -1; return 0;}
    //----
    if(l == 0){
        sub2();
        return 0;
    }
    if(k == 1){
        sub3();
        return 0;
    }
    All();
}
