 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "SOCKS"
#define inpf freopen(TASK".inp", "r", stdin)
#define outf freopen(TASK".out", "w", stdout)
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define FOR(i,x,y) for(int i = x; i <= y ; i ++)
#define FORT(i,x,y) for(int i = x; i < y ; i ++)
#define FORD(i,x,y) for(int i = x; i >= y ; i --)
#define clean(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define maxn 200005
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define db double
#define mp make_pair
#define pb push_back
#define yes cout << "YES" << "\n"
#define no  cout << "NO" << "\n"
#define ct(x) cout << x << endl
//#define bit(p,x) ((x>>p) & 1)
#define all(x) (x).begin(), (x).end()
#define resized(x) (x).resize(unique(all(x)) - (x).begin())
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, c[maxn], tr[maxn], dd[maxn] ;
vector<int> a[maxn] ;
int q[maxn], cnt = 0 ;
pii b[maxn] ;
namespace sub1
{
    int res = 0 ;
    void solve()
    {
        FOR(i, 1, n) if(c[i] == 1) res ++ ;
        if(res > 0) cout << 1 << endl ;
        FOR(i, 1, m)
        {
            int x ;
            cin >> x ;
            c[x] = 1 - c[x] ;
            if(!c[x]) res -- ;
            else res ++ ;
            if(res == 0) cout << 0 << endl ;
            else cout << 1 << endl ;
        }
    }
}
void init()
{
    FOR(i, 1, n - 1)
    {
        int u = b[i].F, v = b[i].S ;
        dd[u] ++, dd[v] ++ ;
    }
}
namespace sub2
{
    int q[maxn ];
    int h[maxn];
    int p[maxn][18];
    void DFS(int u, int par = -1)
    {
        for (auto v : a[u])
            if(v != par&& p[u][0] != v)
            {
                h[v] = h[u] + 1;
                p[v][0] = u;
                FOR(i, 1, 17)
                    p[v][i] = p[p[v][i-1]][i-1];
                DFS(v, u);
            }
    }
    int bit(int v, int i)
    {
        return (v >> i)&1;
    }
    int LCA(int u, int v)
    {
        if (h[u] > h[v]) swap(u,v);
        int delta = h[v] - h[u];
        FOR(i,0,17)
                if(bit(delta,i) == 1)
                    v = p[v][i];
        FORD(i, 17, 0)
            if(p[v][i] != p[u][i])
            {
                u = p[u][i];
                v = p[v][i];
            }
        if(u!=v) return p[u][0];
        return u;
    }
    int root, pt, d1, d2, cnt = 0 ;
    void solve()
    {
        FOR(i, 1, n - 1)
        {
            int u = b[i].F, v = b[i].S ;
            if(dd[u] == 3) pt = u ;
            if(dd[v] == 3) pt = v ;
        }
        FOR(i, 1, n - 1)
        {
             int u = b[i].F, v = b[i].S ;
             if(v == pt) root = u ;
             if(u == pt)
             {
                if(d1 == 0) d1 = v ;
                else d2 = v ;
             }
        }
        DFS(root) ;
        int res = 0, f1 = 0, f2 = 0, f3 = 0 ;
        FOR(i, 1, n)
        {
            if(c[i])
            {
                res ++ ;
                if(i == root) f1 = 1 ;
            }
        }
        cnt = 0 ;
        FOR(i, 1, n)
        {
            if(c[i]) q[++cnt] = i ;
        }
        f2 = 0, f3 = 0 ;
        FOR(i, 1, cnt)
        {
            if(LCA(d1, q[i]) == d1) f2 = 1 ;
            if(LCA(d2, q[i]) == d2) f3 = 1 ;
        }
        if(f2 == 1 && f3 == 1 && f1 == 1) cout << 2 << endl ;
        else cout << 1 << endl ;
        FOR(i, 1, m)
        {
            cnt = 0 ;
            int x ;
            cin >> x ;
            c[x] = 1 - c[x] ;
            if(!c[x])
            {
                res -- ;
                if(x == root) f1 = 0 ;
            }
            else
            {
                res ++ ;
                if(x == root) f1 = 1 ;
            }
            FOR(i, 1, n)
            {
                if(c[i]) q[++cnt] = i ;
            }
            f2 = 0, f3 = 0 ;
            FOR(i, 1, cnt)
            {
                if(LCA(d1, q[i]) == d1) f2 = 1 ;
                if(LCA(d2, q[i]) == d2) f3 = 1 ;
            }
            if(f2 == 1 && f3 == 1 && f1 == 1) cout << 2 << endl ;
            else cout << 1 << endl ;
        }
    }
}
int main()
{
    inpf; outf; fast;
    cin >> n >> m ;
    FOR(i, 1, n) cin >> c[i] ;
    FOR(i, 1, n - 1)
    {
        int u, v ;
        cin >> u >> v ;
        a[u].pb(v) ; a[v].pb(u) ;
        b[i] = {u, v} ;
    }
    init() ;
    bool fk = 0 ;
    FOR(i, 1, n)
    {
        if(dd[i] > 2) fk = 1 ;
    }
    if(!fk) sub1::solve() ;
    else sub2::solve() ;

}
