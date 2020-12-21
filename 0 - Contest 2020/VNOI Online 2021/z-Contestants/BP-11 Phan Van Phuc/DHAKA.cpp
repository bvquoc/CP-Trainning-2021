#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define se second

const ll mod = 1e9 + 7;
const ll INF = 1e18;
const ll nmax = 1e5 + 1;

typedef vector<ll> ve;
typedef vector<ve> vve;
typedef pair<ll, ll> pa;
typedef vector<pa> vpa;

ifstream fi ( "DHAKA.INP" );
ofstream fo ( "DHAKA.OUT" );

ll n, m, k, l;
vector<vpa> dsk;
vve lemon;
ll kq = INF;
vector<ll> ds, mem;
bool kt ( vector<ll> ds ) {
     set<ll> res;
     for ( ll i = 0; i < ds.size(); ++i )
          for ( ll j = 0; j < lemon[ds[i]].size(); ++j )
               res.insert ( lemon[ds[i]][j] );
     if ( res.size() >= l )
          return true;
     return false;
}
void dfs ( ll u, ll t, vector<ll> ds ) {
     if ( u == n ) {
          if ( kt ( ds ) )
               kq = min ( kq, t );
          return;
     }
     for ( ll i = 0; i < dsk[u].size(); ++i ) {
          ll v = dsk[u][i].ff;
          ll w = dsk[u][i].se;

          if ( !mem[v] ) {
               mem[v] = 1;
               ds.push_back ( v );
               dfs ( v, t + w, ds );
               mem[v] = 0;
          }
     }
}
void get() {
     set<pa> s;
     ve dist;
     dist.assign ( n + 1, INF );
     s.insert ( {0, 1} );
     dist[1] = 0;
     while ( !s.empty() ) {
          pa W = *s.begin();
          s.erase ( s.begin() );
          for ( ll i = 0; i < dsk[W.se].size(); ++i ) {
               ll v = dsk[W.se][i].ff;
               ll d = dsk[W.se][i].se;
               if ( dist[v] > dist[W.se] + d ) {
                    dist[v] = dist[W.se] + d;
                    s.insert ( {dist[v], v} );
               }
          }
     }
     fo << dist[n];
}
int main() {
     ios_base::sync_with_stdio ( 0 ), fi.tie ( 0 ), fo.tie ( 0 );
     fi >> n >> m >> k >> l;
     dsk.assign ( n + 1, vpa() );
     lemon.assign ( n + 1, ve() );
     mem.assign ( n + 1, 0 );
     for ( ll i = 1; i <= n; ++i ) {
          ll s;
          fi >> s;
          for ( ll j = 1; j <= s; ++j ) {
               ll a;
               fi >> a;
               lemon[i].push_back ( a );
          }
     }
     for ( ll i = 1; i <= m; ++i ) {
          ll u, v, c;
          fi >> u >> v >> c;
          dsk[u].push_back ( {v, c} );
          dsk[v].push_back ( {u, c} );
     }
     if ( l > k ) {
          fo << -1;
          return 0;
     }
     if ( n <= 10 ) {
          dfs ( 1, 0, ds );
          if ( kq != INF )
               fo << kq;
          else
               fo << -1;
          return 0;
     }
      get ( );
}
