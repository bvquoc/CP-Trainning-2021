#include<bits/stdc++.h>
#define se second
#define fi first

using namespace std;
typedef long long LL;
typedef pair<int , int> I;

const int MAXN = 10 + 1e6;
const int MOD = 1e9 + 7;
const LL oo = 1e18;
const int base = 251;

int n , m ;
int a[MAXN] , d[MAXN] ;

I e[MAXN] ;

set<I> s ;

vector<int> g ;

bool cmp(I x , I y ) {
    return x.fi == y.fi ? x.se > y.se : x.fi < y.fi;
}

void Inout() {
    #define TASK "COOLMAC"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>m ;
    for (int i = 1 ; i <= m ; ++i) cin >>e[i].fi >>e[i].se;
    sort( e + 1 , e + 1 + m , cmp ) ;

    cin >>n ;
    int mi = MOD;
    for (int i = 1 ; i <= n ; ++i) cin >>a[i] , mi = min( a[i] , mi );

    int ma = 0 ;
    for (int i = 1 ; i <= m ; ++i) {

       // cout <<e[i].fi <<' ' <<e[i].se <<'\n';

        if ( e[i].fi > ma + 1 )
            for (int j = ma + 1 ; j < e[i].fi ; ++j) g.push_back( j );
        ma = max( ma , e[i].se );
    }
    if ( ma < 100000)
        for (int i = ma + 1 ; ma <= 100000 ; ++i) g.push_back(i);

    if ( g.size() > 0 && g[ g.size() - 1 ] >= mi ) { cout <<-1 ; return 0 ; }

    for (int i = 1 ; i <= m ; ++i) {
        if ( s.empty() ) {
            s.insert( { e[i].se , i } );
            continue;
        }

        I pos = {0 , 0};
        while( !s.empty() && e[i].fi <= s.rbegin()->fi + 1 && e[i].se >= s.rbegin()->fi ) {
            pos = { s.rbegin()->fi , s.rbegin()->se };
            s.erase( --s.end() );
        }
        if ( pos.se ) s.insert( pos );
        if ( e[i].se > s.rbegin()->fi ) s.insert( {e[i].se , i} );

    }

//    cout <<s.size() <<' ' ;

    int cnt = 0 ;
    while( !s.empty() ) {
        d[++cnt] = e[ s.begin()->se ].fi ;
        s.erase( s.begin() );
    }

    int x = upper_bound( d + 1 , d + 1 + cnt , mi ) - d - 1;
    cout <<cnt - x + 1;
return 0;
}
