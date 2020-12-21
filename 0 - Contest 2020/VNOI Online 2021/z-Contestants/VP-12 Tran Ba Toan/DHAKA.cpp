#include<bits/stdc++.h>
#define se second
#define fi first

using namespace std;
typedef long long LL;
typedef pair<LL,int> I;
typedef pair<I , int> II;

const int MAXN = 10 + 1e6;
const LL MOD = 1e9 + 7;
const LL oo = 1e18;

int n , m , k , L ;
int a[MAXN] , c[MAXN] ;

LL dp[1 << 5][MAXN] , f[1 << 5][MAXN] ;

LL ans = oo;

vector<I> g[MAXN] ;

void Dijkstra() {
    priority_queue< II , vector<II> , greater<II> > q;

    f[a[1]][1] = 0;
    q.push( {{0 , 1} , a[1]} );

    while( !q.empty() ) {
        LL du = q.top().fi.fi ;
        int u = q.top().fi.se ,
            it = q.top().se ;
        q.pop();

        if ( f[it][u] < du ) continue;
        for (auto i : g[u] ) {
            int v = i.fi ,
                l = i.se ;
            int mask = it | a[v] ;
            if ( f[mask][v] > du + l ) {
                f[mask][v] = du + l;
                q.push( {{f[mask][v] , v} , mask} );
            }
        }
    }

}

void Inout() {
    #define TASK "DHAKA"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n >>m >>k >>L;
    for (int i = 1 ; i <= n ; ++i) {
        int x , y , res = 0 ;
        cin >>y;
        if ( y )
        for (int j = 1 ; j <= y ; ++j) {
            cin >>x ; x--;
            res |= (1 << x);
        }
        a[i] = res;
    }

    for (int i = 1 ; i <= m ; ++i) {
        int u , v , l;
        cin >>u >>v >>l;
        g[u].push_back( {v , l} );
        g[v].push_back( {u , l} );
    }

    for (int it = 0 ; it < (1 << k) ; ++it)
        for (int i = 1 ; i <= n ; ++i) f[it][i] = oo;
    Dijkstra();

    for (int it = 0 ; it < (1 << k) ; ++it)
        if ( __builtin_popcount(it) >= L ) ans = min(ans , f[it][n] );

    cout <<( ans == oo ? -1 : ans );
return 0;
}
