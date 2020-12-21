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

int n , m , k , cnt = 0 ;
int a[MAXN] , c[MAXN] , vis[MAXN] , id[MAXN] , L[MAXN] , R[MAXN] , deg[MAXN] ;

int ansl = -1 , ansr = -1;

string s;

vector <int> g[MAXN] , f[MAXN] ;

void Dfs(int u) {
    vis[u] = 1 ;
    id[u] = cnt ;
    for (auto v : g[u] )
        if ( !vis[v] ) Dfs(v);
}

void Solve1() {
    int l = 0 ,
        r = n ;
    int u , v ;
    while( l < r ) {
        int mid = l + r + 1 >> 1 ,
            kt = 0 ;

        for (int i = mid ; i <= n ; ++i) {
            int res = a[i] - a[i - mid] ;
           // cout <<l <<' ' <<r <<' ' <<res + k <<'\n';
            if ( res + k >= mid ) {
                u = i - mid + 1;
                v = i ;
                kt = 1;
                break;
            }
        }
        if ( kt ) l = mid ;
        else r = mid - 1 ;
    }

    if ( l == 0 ) cout <<-1 ;
    else cout <<u <<' ' <<v;
}

void Solve3() {
    for (int i = 1 ; i <= n ; ++i)
    if ( !vis[i] ) {
        ++cnt;
        Dfs(i);
    }
    for (int i = 1 ; i <= n ; ++i) {
        f[ id[i] ].push_back(i);
        deg[ id[i] ] += c[i];
    }

    for (int i = 1 ; i <= n ; ++i) cout <<id[i] <<' ' ; cout <<'\n';

    for (int l = 1 ; l <= n ; ++l) {
        for (int i = 1 ; i <= cnt ; ++i) L[i] = R[i] = -1;

        int res = 0;
        for (int r = l; r <= n; ++r) {
            int id = vis[r];
            int pos = lower_bound(f[id].begin() , f[id].end(), r) - f[id].begin();
            if (L[id] == -1) {
                L[id] = pos;
                R[id] = pos;
                res += min(deg[id] , 1);
            }
            else {
                res -= min(deg[id], R[id] - L[id] + 1);
                R[id] = pos;
                res += min(deg[id], R[id] - L[id] + 1);
            }
            if (res + k >= r - l + 1) {
                if (ansl == -1) { ansl = l ; ansr = r; continue; }
                if (ansr - ansl + 1 < r - l + 1) { ansl = l ; ansr = r; continue; }

                if (ansr - ansl + 1 == r - l + 1 && ansl > l ) {
                    ansl = l; ansr = r;
                    continue;
                }
            }
        }
    }

    if ( ansl == -1 ) cout <<-1;
    else cout <<ansl <<' ' <<ansr;
}

void Inout() {
    #define TASK "DECOR"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n >>m >>k;
    cin >>s;
    s = " " + s ;

    for (int i = 1 ; i <= n ; ++i) a[i] = a[i - 1] + s[i] - '0' , c[i] = s[i] - '0' ;
    for (int i = 1 ; i <= m ; ++i) {
        int u , v ;
        cin >>u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if ( m == 0 ) {
        Solve1();
        return 0;
    }
    Solve3();
return 0;
}
