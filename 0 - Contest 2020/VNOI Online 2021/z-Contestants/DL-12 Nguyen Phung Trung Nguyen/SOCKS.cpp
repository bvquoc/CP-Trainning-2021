#include <bits/stdc++.h>
using namespace std;
long n,q,a[500005],par[500005],cnt = 0;
vector<long> c[500005],child[500005];
void dfs(long u, long p){
    for(long i = 0; i < c[u].size(); i++){
        long v = c[u][i];
        if( v == p ) continue;
        child[u].push_back(v);
        par[v] = u;
        if( a[u] + a[v] == 2 ) cnt++;
        dfs(v,u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    cin >> n >> q;
    for(long i = 1; i <= n; i++) cin >> a[i];
    for(long i = 1; i < n; i++){
        long u,v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    long cnt = 0;
    for(long i = 1; i <= n; i++) if( a[i] == 1 ) cnt++;
    if( cnt >= 2 ) cout << 1 << '\n';
    else cout << 0 << '\n';
    while(q--){
        long x;
        cin >> x;
        if( a[x] == 1 ){
            cnt--;
            a[x] = 0;
        }
        else{
            cnt++;
            a[x] = 1;
        }
        if( cnt < 2 ) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}
/*
6 4
1 0 0 0 0 1
1 3
3 2
3 4
4 5
4 6
3
3
2
5
*/
