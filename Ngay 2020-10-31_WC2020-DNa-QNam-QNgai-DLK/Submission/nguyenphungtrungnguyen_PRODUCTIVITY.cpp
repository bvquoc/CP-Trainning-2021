#include <bits/stdc++.h>
using namespace std;
long n,a[1005][1005],visit[1005],timez,match[1005];
vector<long> c[1005];
bool DFS(long u){
    if( visit[u] == timez ) return 0;
    visit[u] = timez;
    for( long v : c[u] ){
        if( match[v] == 0 || DFS( match[v] ) ){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
bool check(long x){
    timez = 0;
    for(long i = 1; i <= n; i++){
        c[i].clear();
        match[i] = 0;
        visit[i] = 0;
    }
    for(long i = 1; i <= n; i++){
        for(long j = 1; j <= n; j++) if( a[i][j] >= x ) c[i].push_back(j);
    }
    long res = 0;
    for( long i = 1; i <= n; i++ ){
        timez++;
        res += DFS(i);
    }
    return ( res == n );
}
int main(){
    cin >> n;
    for(long i = 1; i <= n; i++){
        for(long j = 1; j <= n; j++) cin >> a[i][j];
    }
    long l = 1, r = 1e9, mid = ( l + r ) / 2;
    while( r - l > 1 ){
        if( check(mid) ) l = mid;
        else r = mid;
        mid = ( l + r )/2;
    }
    if( check(l) ) cout << l;
    else cout << r;
}
