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

ifstream fi ( "DECOR.INP" );
ofstream fo ( "DECOR.OUT" );

ll n, m, k;
pa tt[5 * nmax];
string s;
void sub1() {
     ll len = 0;
     ll kq = 0;
     ll x, y;
     for ( ll i = 0; i < s.size(); ++i )
          if ( s[i] == '1' ) {
               len++;
               if ( i + 1 < s.size() && s[i + 1] == '0' ) {
                    if ( kq < len ) {
                         kq = len;
                         y = i + 1, x = y - len + 1;
                    }
                    len = 0;
               }
          }
     if ( kq < len ) {
          kq = len;
          y = s.size(), x = s.size() - len + 1;
     }
     fo << x << ' ' << y;
}
int main() {
     ios_base::sync_with_stdio ( 0 ), fi.tie ( 0 ), fo.tie ( 0 );
     fi >> n >> m >> k;
     fi >> s;
     for ( ll i = 1; i <= m; ++i )
          fi >> tt[i].ff >> tt[i].se;
     ll vt0 = 0;
     for ( ll i = 0; i < s.size(); ++i )
          if ( s[i] == '0' )
               vt0++;
     if ( vt0 <= k ) {
          fo << 1 << ' ' << s.size();
          return 0;
     }
     if ( m == 0 && k == 0 ) {
          sub1();
          return 0;
     }
     fo<<1<<' '<<s.size();
}
