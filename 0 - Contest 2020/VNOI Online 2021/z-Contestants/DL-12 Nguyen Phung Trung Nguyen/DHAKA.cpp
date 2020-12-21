#include <bits/stdc++.h>
using namespace std;
typedef pair<long,long> ii;
typedef pair<long long,ii> iii;
long n,m,k,l,water[100005];
long long d[100005][50];
vector<ii> c[100005];
void dis(){
    for(long i = 1; i <= n; i++){
        for( long j = 0; j <= (1 << k) - 1; j++ ) d[i][j] = 1e18;
    }
    priority_queue< iii, vector<iii>, greater<iii> > pq;
    d[1][0] = 0;
    pq.push({0,{1,0}});
    while( pq.size() ){
        long long du = pq.top().first;
        long u = pq.top().second.first;
        long stage = pq.top().second.second;
        pq.pop();
        if( d[u][stage] != du ) continue;
        for(long i = 0; i < c[u].size(); i++){
            long v = c[u][i].first;
            long long dv = c[u][i].second;
            if( d[v][ stage | water[v] ] > du + dv ){
                d[v][ stage | water[v] ] = du + dv;
                pq.push({d[v][ stage | water[v] ],{v,stage | water[v]}});
            }
        }
    }
}
bool check(long x){
    long cnt = 0;
    for(long i = 0; i < k; i++){
        if( ( x & ( 1 << i ) ) != 0 ) cnt++;
    }
    return ( cnt >= l );
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin >> n >> m >> k >> l;
    for(long i = 1; i <= n; i++){
        long s;
        cin >> s;
        for(long j = 1; j <= s; j++){
            long x;
            cin >> x;
            water[i] |= x;
        }
    }
    while(m--){
        long u,v,w;
        cin >> u >> v >> w;
        c[u].push_back({v,w});
        c[v].push_back({u,w});
    }
    dis();
    long long res = 1e18;
    for(long i = 0; i <= ( 1 << k ) - 1; i++){
        if( check(i) ) res = min(res,d[n][i]);
    }
    if( res == 1e18 ) res = -1;
    cout << res;
}
/*
6 6 2 2
0
1 1
0
1 1
1 1
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
*/
/*
6 6 2 2
0
1 1
0
1 1
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
*/
/*
6 6 2 2
0
1 1
0
0
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
*/
