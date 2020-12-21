#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< ll , ll > ii;
const int maxn = 1e5 + 3 ;
const int mod = 1e9 + 7 ;
const ll oo = 1e18 ;

void input() {
    #define name "dhaka"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n , m , k , l ;
int s[maxn] , a[maxn][9] ;
vector< ii > g[maxn] ;

namespace subtask23 {
    ll d[maxn][2] ;
    void dijkstra(int s , int t) {
        for (int i = 1 ; i <= n ; ++ i) d[i][t] = oo ;
        d[s][t] = 0 ;
        priority_queue< ii , vector< ii > , greater< ii > > q ;
        q.push(ii(d[s][t] , s)) ;
        while (!q.empty()) {
            ll du = q.top().st , u = q.top().nd ;
            q.pop() ;
            if (du != d[u][t]) continue ;
            for (int i = 0 ; i < g[u].size() ; ++ i) {
                ll v = g[u][i].st , w = g[u][i].nd;
                if (d[v][t] > d[u][t] + w) {
                    d[v][t] = d[u][t] + w ;
                    q.push(ii(d[v][t] , v)) ;
                }
            }
        }
    }
    void solve() {
        dijkstra(1 , 0) ;
        dijkstra(n , 1) ;
        if (l == 0) {
            if (d[n][0] < oo) cout << d[n][0] ;
            else cout << "-1" ;
        }
        else {
            ll res = oo ;
            for (int i = 1 ; i <= n ; ++ i) {
                if (s[i] > 0) {
                    res = min(res , d[i][0] + d[i][1]) ;
                }
            }
            if (res < oo) cout << res ;
            else cout << "-1" ;
        }
    }
}

namespace subtask5 {
    ll d[maxn] , dp[maxn][35] ;
    int msk[maxn] ;
    void solve() {
        for (int i = 1 ; i <= n ; ++ i) d[i] = oo ;
        d[1] = 0 ;
        priority_queue< ii , vector< ii > , greater< ii > > q ;
        q.push(ii(d[1] , 1)) ;
        while (!q.empty()) {
            ll du = q.top().st , u = q.top().nd ;
            q.pop() ;
            if (du != d[u]) continue ;
            for (int i = 0 ; i < g[u].size() ; ++ i) {
                ll v = g[u][i].st , w = g[u][i].nd;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w ;
                    q.push(ii(d[v] , v)) ;
                }
            }
        }
        for (int i = 1 ; i <= n ; ++ i) {
            for (int mask = 0 ; mask < (1 << k) ; ++ mask)
                dp[i][mask] = oo ;
            msk[i] = 0 ;
            for (int j = 1 ; j <= s[i] ; ++ j)
                msk[i] |= (1 << a[i][j]) ;
            dp[i][msk[i]] = d[i] ;
        }
        for (int mask = 0 ; mask < (1 << k) ; ++ mask) {
            for (int u = 1 ; u <= n ; ++ u) {
                for (int i = 0 ; i < g[u].size() ; ++ i) {
                    ll v = g[u][i].st , w = g[u][i].nd ;
                    int nmask = (mask | msk[v]) ;
                    dp[v][nmask] = min(dp[v][nmask] , dp[u][mask] + w) ;
                }
            }
        }
        ll res = oo ;
        for (int mask = 0 ; mask < (1 << k) ; ++ mask) {
            if (__builtin_popcount(mask) >= l) {
                res = min(res , dp[n][mask]) ;
//                cout << mask << "\n" ;
            }
        }
        if (res < oo) cout << res ;
        else cout << "-1" ;
    }
}

int main() {
	input();
    cin >> n >> m >> k >> l ;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> s[i] ;
        for (int j = 1 ; j <= s[i] ; ++ j) {
            cin >> a[i][j] ;
            a[i][j] -- ;
        }
    }
    ll u , v , w ;
    for (int i = 1 ; i <= m ; ++ i) {
        cin >> u >> v >> w ;
        g[u].push_back(ii(v , w)) ;
        g[v].push_back(ii(u , w)) ;
    }
    if (k == 1 || l == 0) {
        subtask23 :: solve() ;
    }
    else {
        subtask5 :: solve() ;
    }

	return 0;
}
