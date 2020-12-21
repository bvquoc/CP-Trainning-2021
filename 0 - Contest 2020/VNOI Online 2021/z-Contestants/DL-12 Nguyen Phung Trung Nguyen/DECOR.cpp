#include <bits/stdc++.h>
using namespace std;
long n,m,k,pre[500005],cnt = 0,d[500005],f[500005];
string s;
vector<long> c[500005];
bool check(long x, long pos){
    if( pre[x] - pre[pos-1] + k < x - pos + 1 ) return false;
    return true;
}
void sub1(){
    long res = -1;
    for(long i = 1; i <= n; i++){
        long l = i + 1, r = n, mid = ( l + r ) / 2;
        while( r - l > 3 ){
            if( check(mid,i) ) l = mid;
            else r = mid;
            mid = ( l + r ) / 2;
        }
        for(long j = r; j >= l; j--){
            if( check(j,i) ){
                res = max(res, j - i + 1 );
                break;
            }
        }
    }
    if( res == -1 ){
        cout << res;
        exit(0);
    }
    for(long i = 1; i <= n; i++){
        long l = i, r = n, mid = ( l + r ) / 2;
        while( r - l > 3 ){
            if( check(mid,i) ) l = mid;
            else r = mid;
            mid = ( l + r ) / 2;
        }
        for(long j = r; j >= l; j--){
            if( check(j,i) ){
                if( j - i + 1 == res ){
                    cout << i << " " << j;
                    exit(0);
                }
            }
        }
    }
}
void dfs(long u){
    d[u] = cnt;
    f[cnt] += ( s[u] == '1' );
    for(long i = 0; i < c[u].size(); i++){
        long v = c[u][i];
        if( d[v] ) continue;
        dfs(v);
    }
}
long cc[500005];
bool CHECK(long x, long pos){
    for(long i = 1; i <= cnt; i++) cc[i] = 0;
    for(long i = pos; i <= x; i++) cc[ d[i] ]++;
    long dem = 0;
    for(long i = 1; i <= cnt; i++) dem += min( cc[i], f[i] );
    if( dem + k < x - pos + 1 ) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin >> n >> m >> k;
    cin >> s;
    s = '@' + s;
    pre[0] = 0;
    for(long i = 1; i <= n; i++) pre[i] = pre[i-1] + ( s[i] == '1' );
    if( m == 0 ){
        sub1();
        return 0;
    }
    while(m--){
        long u,v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    if( k >= n - pre[n] ){
        cout << 1 << " " << n;
        return 0;
    }
    for(long i = 1; i <= n; i++){
        if( !d[i] ){
            cnt++;
            dfs(i);
        }
    }
    long res = 0;
    for(long i = 1; i <= n; i++){
        long l = i + 1, r = n, mid = ( l + r ) / 2;
        while( r - l > 3 ){
            if( CHECK(mid,i) ) l = mid;
            else r = mid;
            mid = ( l + r ) / 2;
        }
        for(long j = r; j >= l; j--){
            if( CHECK(j,i) ){
                res = max(res, j - i + 1);
                break;
            }
        }
    }
    for(long i = 1; i <= n; i++){
        long l = i + 1, r = n, mid = ( l + r ) / 2;
        while( r - l > 3 ){
            if( CHECK(mid,i) ) l = mid;
            else r = mid;
            mid = ( l + r ) / 2;
        }
        for(long j = r; j >= l; j--){
            if( CHECK(j,i) ){
                if( j - i + 1 == res ){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
}
/*
10 6 3
1000101101
1 2
2 3
3 5
9 1
6 7
4 6
*/
