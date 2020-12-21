#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< int , int > ii;
const int maxn = 5e5 + 2 ;
const int mod = 1e9 + 7 ;
const int oo = 1e9 ;

void input() {
    #define name "decor"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n , m , k ;
string s ;
vector< int > g[maxn] ;

namespace subtask12 {
    int a[maxn] ;

    int bsearch (int p , int l , int r) {
        int ans = r ;
        while (l <= r) {
            int mid = (l + r) / 2 ;
            if (a[mid] <= p) {
                ans = min(ans , mid) ;
                r = mid - 1 ;
            }
            else
                l = mid + 1 ;
        }
        return ans ;
    }

    void solve() {
        int cur = 0 , ans = -1 , mx = 0 ;
        a[0] = 0 ;
        for (int i = 1 ; i <= n ; ++ i) {
            cur += int(s[i] - '0') ;
            a[i] = cur - i ;
            int p = bsearch(a[i] + k , 0 , i - 1) ;
            if (i - p > mx) {
                mx = i - p ;
                ans = i ;
            }
        }
        if (ans == -1) cout << "-1" ;
        else cout << ans - mx + 1 << " " << ans ;
    }
}

namespace subtask3 {

    int cur ;
    int r[maxn] , vis[maxn] , mark[maxn] ;
    vector< int > vtx[maxn] , vt[maxn] ;

    void dfs(int u) {
        r[u] = cur ;
        if (s[u] == '1') vtx[cur].push_back(u) ;
        vis[u] = 1 ;
        for (int i = 0 ; i < g[u].size() ; ++ i) {
            int v = g[u][i] ;
            if (vis[v] == 0)
                dfs(v) ;
        }
    }

    void solve() {
        cur = 0 ;
        memset(vis , 0 , sizeof(vis)) ;
        for (int i = 1 ; i <= n ; ++ i) {
            if (vis[i] == 0) {
                cur ++ ;
                dfs(i) ;
            }
        }

        for (int i = 1 ; i <= cur ; ++ i)
            sort(vtx[i].begin() , vtx[i].end()) ;

        int mx = 0 , ans = -1 ;
        for (int i = 1 ; i <= n ; ++ i) {
            int rem = k ;
            for (int j = 1 ; j <= cur ; ++ j)
                vt[j] = vtx[j] ;

            for (int j = 1 ; j <= n ; ++ j)
                mark[j] = 0 ;

            for (int j = i ; j <= n ; ++ j) {
                if (s[j] == '1' && mark[j] == 0) {
                    mark[j] = 1 ;
                    continue ;
                }

                mark[j] = 1 ;

                while (!vt[r[j]].empty() && mark[vt[r[j]].back()] == 1)
                    vt[r[j]].pop_back() ;
                if (!vt[r[j]].empty()) {
                    mark[vt[r[j]].back()] = 1 ;
                    vt[r[j]].pop_back() ;
                }
                else if (rem > 0) {
                    rem -- ;
                }
                else {
                    break ;
                }

                if (j - i + 1 > mx) {
                    mx = j - i + 1 ;
                    ans = i ;
                }
            }
        }

        if (ans == -1) cout << ans ;
        else cout << ans << " " << ans + mx - 1 ;
    }
}

namespace subtask4 {
    int cur ;
    int r[maxn] , vis[maxn] , mark[maxn] ;
    vector< int > vtx[maxn] , vt[maxn] ;

    void dfs(int u) {
        r[u] = cur ;
        if (s[u] == '1') vtx[cur].push_back(u) ;
        vis[u] = 1 ;
        for (int i = 0 ; i < g[u].size() ; ++ i) {
            int v = g[u][i] ;
            if (vis[v] == 0)
                dfs(v) ;
        }
    }

    int pre[maxn] ;

    void solve() {
        cur = 0 ;
        memset(vis , 0 , sizeof(vis)) ;
        for (int i = 1 ; i <= n ; ++ i) {
            if (vis[i] == 0) {
                cur ++ ;
                dfs(i) ;
            }
        }

        for (int i = 1 ; i <= cur ; ++ i)
            sort(vtx[i].begin() , vtx[i].end()) ;

        int mx = 0 , ans = -1 , rt = 1 , rem = k ;
        for (int i = 1 ; i <= n ; ++ i) {
            for (int j = 1 ; j <= cur ; ++ j)
                vt[j] = vtx[j] ;

            for (int j = rt ; j <= n ; ++ j) {
                if (s[j] == '1' && mark[j] == 0) {
                    mark[j] = 1 ;
                    pre[j] = -1 ;
                    continue ;
                }

                mark[j] = 1 ;

                while (!vt[r[j]].empty() && mark[vt[r[j]].back()] == 1)
                    vt[r[j]].pop_back() ;
                if (!vt[r[j]].empty()) {
                    mark[vt[r[j]].back()] = 1 ;
                    vt[r[j]].pop_back() ;
                    pre[j] = vt[r[j]].back() ;
                }
                else if (rem > 0) {
                    pre[i] = -2 ;
                    rem -- ;
                }
                else {
                    break ;
                }

                rt = j ;
                if (j - i + 1 > mx) {
                    mx = j - i + 1 ;
                    ans = i ;
                }
            }
            mark[i] = 0 ;
            if (pre[i] != -1) {
                if (pre[i] == -2) rem ++ ;
                else {
                    vt[r[i]].push_back(pre[i]) ;
                }
            }
        }

        if (ans == -1) cout << ans ;
        else cout << ans << " " << ans + mx - 1 ;
    }
}

int main() {
	input();
    cin >> n >> m >> k ;
    cin >> s ;
    s = " " + s ;
    int u , v ;
    for (int i = 1 ; i <= m ; ++ i) {
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    if (m == 0) {
        subtask12 :: solve() ;
    }
    else if (n <= 2000) {
        subtask3 :: solve() ;
    }
    else {
        subtask4 :: solve() ;
    }


	return 0;
}
