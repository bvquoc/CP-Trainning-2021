#include <bits/stdc++.h>
using namespace std;
typedef pair<long,long> ii;
typedef pair<long,ii> iii;
long n,m,P,L,K;
vector<iii> c[100005];
long h[10005],visit[10005],timez = 0,d[10005][15];
vector<long> g[10005];
//bool g[10005][10005];
void BFS(long x){
    h[x] = 0;
    queue<long> q;
    q.push(x);
    visit[x] = timez;
    while( q.size() ){
        long u = q.front();
        q.pop();
        if( h[u] >= L ) continue;
        for(long i = 0; i < c[u].size(); ++i){
            long v = c[u][i].first;
            if( visit[v] != timez ){
                h[v] = h[u] + 1;
                if( h[v] <= L ) g[x].push_back(v);
                visit[v] = timez;
                q.push(v);
            }
        }
    }
}
void dis(){
    for(long i = 1; i <= n; ++i){
        for(long j = 0; j <= K; j++) d[i][j] = 1e9;
    }
    priority_queue< iii, vector<iii>, greater<iii> > pq;
    d[1][0] = 0;
    pq.push({0,{1,0}});
    while( pq.size() ){
        long du = pq.top().first;
        long u = pq.top().second.first;
        long k = pq.top().second.second;
        pq.pop();
        if( d[u][k] != du ) continue;
        for(long i = 0; i < c[u].size(); ++i){
            long v = c[u][i].first;
            long dv = c[u][i].second.first;
            long type = c[u][i].second.second;
            if( k + type > K ) continue;
            if( d[v][k+type] > du + dv ){
                d[v][k+type] = du + dv;
                pq.push({du+dv,{v,k+type}});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> P >> L >> K;
    while(m--){
        long u,v,w;
        cin >> u >> v >> w;
        c[u].push_back({v,{w,0}});
        c[v].push_back({u,{w,0}});
    }
    for(long i = 1; i <= n; ++i){
        ++timez;
        BFS(i);
    }
    for(long u = 1; u <= n; u++){
        for(long v : g[u] ){
            c[u].push_back({v,{P,1}});
        }
    }
    dis();
    long res = 1e9;
    for(long i = 0; i <= K; ++i) res = min(res,d[n][i]);
    cout << res;
}
