#include<bits/stdc++.h>

#define ll long long
#define st first
#define nd second

using namespace std;

typedef pair< int , int > ii;
const int maxn = 1e5 + 2 ;
const int mod = 1e9 + 7 ;
const int oo = 1e9 ;

void input() {
    #define name "socks"
	if (fopen(name".inp" , "r") ) {
        freopen(name".inp" , "r" , stdin) ;
        freopen(name".out" , "w" , stdout) ;
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n , q , u , v ;
int a[maxn] ;
vector< int > g[maxn] ;

void subtask1() {
    int cur = 0 ;
    for (int i = 1 ; i <= n ; ++ i) cur += a[i] ;
    if (cur > 0) cout << "1\n" ;
    else cout << "0\n" ;
    while (q -- ) {
        cin >> u ;
        if (a[u] == 0) cur ++ ;
        else cur -- ;
        a[u] = 1 - a[u] ;
        if (cur > 0) cout << "1\n" ;
        else cout << "0\n" ;
    }
}

int cnt[5] , f[maxn] ;

void dfs_sub2 (int u , int p , int t) {
    cnt[t] += a[u] ;
    f[u] = t ;
    for (int i = 0 ; i < g[u].size() ; ++ i) {
        int v = g[u][i] ;
        if (v != p) {
            dfs_sub2(v , u , t) ;
        }
    }
}

void subtask2() {
    int sp = 0 ;
    for (int i = 1 ; i <= n ; ++ i) {
        if (g[i].size() == 3) {
            sp = i ;
            break ;
        }
    }
    for (int i = 0 ; i < 3 ; ++ i)
        dfs_sub2(g[sp][i] , sp , i) ;
    f[sp] = 0 ;
    cnt[0] += a[sp] ;
    int cur = (cnt[0] > 0) + (cnt[1] > 0) + (cnt[2] > 0) ;
    cout << cur << "\n" ;
    while (q -- ) {
        cin >> u ;
        if (a[u] == 0) cnt[f[u]] ++ ;
        else cnt[f[u]] -- ;
        a[u] = 1 - a[u] ;
        int cur = (cnt[0] > 0) + (cnt[1] > 0) + (cnt[2] > 0) ;
        cout << cur << "\n" ;
    }
}

int h[maxn] , anc[maxn][20] ;

void dfs (int u , int p) {
    for (int i = 0 ; i < g[u].size() ; ++ i) {
        int v = g[u][i] ;
        if (v != p) {
            h[v] = h[u] + 1 ;
            anc[v][0] = u ;
            dfs(v , u) ;
        }
    }
}

int jump (int u , int d) {
    for (int i = 17 ; i >= 0 ; -- i)
        if (d & (1 << i))
            u = anc[u][i] ;
    return u ;
}

int lca (int u , int v) {
    if (h[u] < h[v]) swap(u , v) ;
    u = jump(u , h[u] - h[v]) ;
    if (u == v) return u ;
    for (int i = 17 ; i >= 0 ; -- i) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i] ;
            v = anc[v][i] ;
        }
    }
    return anc[u][0] ;
}

vector< int > vtx ;
int mark[maxn] ;

void solve() {
    vtx.clear() ;
    for (int i = 1 ; i <= n ; ++ i) {
        mark[i] = 0 ;
        if (a[i] == 1)
            vtx.push_back(i) ;
    }
//    cout << vtx.size() << " " ;
    int r = 0 ;
    if (vtx.size() <= 2) {
        if (vtx.size() == 0) cout << "0\n" ;
        else cout << "1\n" ;
        return ;
    }
    for (int i = 0 ; i < vtx.size() ; ++ i) {
        for (int j = 0 ; j < i ; ++ j) {
            int uv = lca(vtx[i] , vtx[j]) ;
            if (r == 0 || h[uv] < h[r])
                r = uv ;
        }
    }
    for (int i = 0 ; i < vtx.size() ; ++ i) {
        int u = vtx[i] ;
        mark[u] = 1 ;
        while (u != r && u != 1) {
            u = anc[u][0] ;
            mark[u] = 1 ;
        }
    }
    int ans = 0 ;
    for (int i = 1 ; i <= n ; ++ i) {
//        cout << i << " " << mark[i] << "\n" ;
        if (mark[i] == 0 || i == r) continue ;
        int cnt = 0 ;
        for (int j = 0 ; j < g[i].size() ; ++ j) {
            if (g[i][j] != anc[i][0])
                cnt += mark[g[i][j]] ;
        }
////        cout << n << " " << i << " " << cnt << "\n" ;
        if (cnt == 0) ans ++ ;
    }
    int ok = 0 ;
    while (1) {
        int cnt = 0 , u = 0 ;
        for (int i = 0 ; i < g[r].size() ; ++ i) {
            int v = g[r][i] ;
            if (v != anc[u][0] && mark[v]) {
                cnt ++ ;
                u = v ;
            }
        }
        if (cnt == 1) {
            r = u ;
            ok = 1 ;
        }
        else
            break ;
    }
    if (ok) {
        cout << ans / 2 + 1 << "\n" ;
    }
    else {
        cout << (ans + 1) / 2 << "\n" ;
    }
}

void subtask3() {
    anc[1][0] = 0 ;
    dfs(1 , 0) ;
    for (int j = 1 ; j <= 17 ; ++ j)
        for (int i = 1 ; i <= n ; ++ i)
            anc[i][j] = anc[anc[i][j - 1]][j - 1] ;
    solve() ;
    while (q -- ) {
        cin >> u ;
        a[u] = 1 - a[u] ;
        solve() ;
    }
}

int main() {
	input();
    cin >> n >> q ;
    for (int i = 1 ; i <= n ; ++ i) cin >> a[i] ;
    for (int i = 1 ; i < n ; ++ i) {
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    int check = 0 ;
    for (int i = 1 ; i <= n ; ++ i) {
        if (g[i].size() == 3) check ++ ;
    }
    if (check == 0) {
        subtask1() ;
    }
    else if (check == 1) {
        subtask2() ;
    }
    else {
        subtask3() ;
    }


	return 0;
}
