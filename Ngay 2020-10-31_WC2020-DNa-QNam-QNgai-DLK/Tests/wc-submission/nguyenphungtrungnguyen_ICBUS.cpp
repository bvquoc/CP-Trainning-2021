#include <bits/stdc++.h>
using namespace std;
typedef pair<long,long> ii;
typedef pair<long,ii> iii;
struct data{
    long x,y;
}cost[5005];
long n,m,d[5005][5005];
vector<long> c[5005];
void dis(){
    for(long i = 1; i <= n; i++) for(long j = 0; j <= n; j++) d[i][j] = 1e9;
    priority_queue< iii, vector<iii>, greater<iii> > pq;
    d[1][ cost[1].y ] = cost[1].x;
    pq.push({cost[1].x,{1,cost[1].y}});
    while( pq.size() ){
        long u = pq.top().second.first;
        long du = pq.top().first;
        long left = pq.top().second.second;
        pq.pop();
        if( d[u][left] != du ) continue;
        for(long v : c[u]){
            if( left >= 1 ){
                if( d[v][left - 1] > du ){
                    //cout << u << " " << v << " " << du << " " << left - 1 << endl;
                    d[v][left - 1] = du;
                    pq.push({du,{v,left - 1}});
                }
                if( d[v][cost[v].y] > du + cost[v].x ){
                    d[v][cost[v].y] = du + cost[v].x;
                    //cout << u << " " << v << " " << du << " " << cost[v].x << " " << cost[v].y << endl;
                    pq.push({d[v][cost[v].y],{v,cost[v].y}});
                }
            }
            if( left == 0 ){
                if( d[v][cost[u].y - 1] > du + cost[u].x ){
                    d[v][cost[u].y - 1] = du + cost[u].x;
                    //cout << u << " " << v << " " << du << " " << cost[v].x << " " << cost[v].y << endl;
                    pq.push({d[v][cost[u].y - 1],{v,cost[u].y - 1}});
                }
            }
            //cout << u << " " << v << " " << d[n][0] << endl;
        }
    }
}
int main(){
    cin >> n >> m;
    for(long i = 1; i <= n; i++) cin >> cost[i].x >> cost[i].y;
    while(m--){
        long u,v;
        cin  >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dis();
    long res = 1e9;
    for(long i = 0; i <= n; i++) res = min(res,d[n][i]);
    cout << res;
}
/*
6 6
400 2
200 1
500 3
900 1
400 4
200 5
1 2
1 5
2 3
2 4
3 6
4 6
*/
