#include <bits/stdc++.h>
using namespace std;
long n,m,t[100005],d[30],res,f[3000005],fen[1000005];
struct data{
    long l,r;
}a[100005];
vector<long> c;
void check(){
    c.clear();
    for(long i = 1; i <= m; i++){
        if( !d[i] ) continue;
        c.push_back(i);
    }
    if( c.size() == 0 ) return;
    if( c.size() == 1 ){
        if( a[ c[0] ].l <= t[1] && a[ c[0] ].r >= 1e5 ){
            res = 1;
        }
        return;
    }
    if( a[ c[0] ].l > t[1] ) return;
    for(long i = 0; i < c.size() - 1; i++){
        if( a[ c[i] ].r < a[ c[i+1] ].l ) return;
    }
    if( a[ c[ c.size() -1 ] ].r < 1e5 ) return;
    res = min(res, (long) c.size());
}
void dq(long i){
    for(long j = 0; j <= 1; j++){
        d[i] = j;
        if( i == m ) check();
        else dq( i + 1 );
    }
}
void sub1(){
    res = 1e9;
    dq(1);
    if(res == 1e9) res = -1;
    cout << res;
}
bool xet(data u, data v){
    if( u.l == v.l ) return u.r < v.r;
    return u.l < v.l;
}
void update(long i, long s){
    for( ; i >= 1; i -= i & (-i) ) fen[i] = min(fen[i],s);
}
long get(long i){
    long tmp = 1e9;
    for( ; i <= 1e5; i += i & (-i) ) tmp = min(tmp,fen[i]);
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    cin >> m;
    for(long i = 1; i <= m; i++) cin >> a[i].l >> a[i].r;
    sort( a + 1, a + 1 + m, xet );
    cin >> n;
    for(long i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + 1 + n);
    if( n <= 10 && m <= 16 ){
        sub1();
        return 0;
    }
    if( m <= 3000 ){
        for(long i = 1; i <= m; i++) f[i] = 1e9;
        for(long i = 1; i <= m; i++){
            if( a[i].l <= t[1] ) f[i] = 1;
            for(long j = 1; j < i; j++){
                if( a[j].r >= a[i].l ) f[i] = min( f[i], f[j] + 1 );
            }
        }
        long res = 1e9;
        for(long i = 1; i <= m; i++) if( a[i].r >= 1e5 ) res = min(res,f[i]);
        if( res == 1e9 ) res = -1;
        cout << res;
        return 0;
    }
    for(long i = 1; i <= m; i++) f[i] = 1e9;
    for(long i = 1; i <= 1e5; i++) fen[i] = 1e9;
    for(long i = 1; i <= m; i++){
        if( a[i].l <= t[1] ){
            f[i] = 1;
            update( a[i].r, f[i] );
            continue;
        }
        f[i] = get(a[i].l) + 1;
        update( a[i].r, f[i] );
    }
    long res = 1e9;
    for(long i = 1; i <= m; i++) if( a[i].r >= 1e5 ) res = min(res,f[i]);
    if( res == 1e9 ) res = -1;
    cout << res;
}
/*
3
250 100000
150 200
10 300
2
1000 200
*/
/*
2
250 100000
90 248
1
100
*/
/*
5
100 100000
100 100000
100 100000
100 100000
100 100000
1
15
*/
