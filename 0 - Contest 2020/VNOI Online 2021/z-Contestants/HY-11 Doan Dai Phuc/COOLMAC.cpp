 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "COOLMAC"
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
#define bit(p,x) ((x>>p) & 1)
#define all(x) (x).begin(), (x).end()
#define resized(x) (x).resize(unique(all(x)) - (x).begin())
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll m, n, b[maxn], dem = 0 ;
pii a[maxn], q[maxn];
namespace sub1
{
    ll ans = MOD ;
    void solve()
    {
        sort(a + 1, a + n + 1) ;
        int x = b[1] ;
        for(int i = 0; i <= (1 << n); i ++)
        {
            dem = 0 ;
            FOR(j, 1, n)
            {
                if((i >> (j - 1)) & 1)
                {
                    q[++dem] = a[j] ;
                }
            }
            bool fl = 0, f2 = 0 ;
            if(q[1].F > x) continue ;
            int last = q[1].S ;
            FOR(i, 2, dem)
            {
                if(q[i].F > last) {fl = 1; break ;}
                last = q[i].F ;
                if(q[i].S == 1e5) f2 = 1 ;
            }
            if(fl == 1) continue ;
            if(f2 == 1) ans = min(ans, dem) ;
        }
        if(ans == MOD) cout << -1  ;
        else cout << ans ;
    }
}
namespace sub2
{
    int dem = 0 ;
    void solve()
    {
        int x = b[1] ;
        sort(a + 1, a + n + 1) ;
        int l = 1 ;
        bool f1 = 0, f2 = 0 ;
        while(true)
        {
            pii k = {x, 0} ;
            int p = lower_bound(a + 1, a + n + 1, k) - a ;
            ll res = 0, pos = 0 ;
            FOR(i, l, p)
            {
                if(a[i].F <= x)
                {
                    f1 = 1 ;
                    if(res < a[i].S) res = a[i].S, pos = i ;
                }
            }
            if(f1 == 0) {cout << -1; break ; }
            f1 = 0 ;
            dem ++ ;
            x = a[pos].S ;
            if(x == 1e5) f2 = 1 ;
            l = p  ;
            if(f2 == 1) {cout << dem ; break ;}
        }
    }
}
int main()
{
    inpf; outf; fast;
    cin >> n ;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S ;
    cin >> m ;
    FOR(i, 1, m)  cin >> b[i] ;
    sort(b + 1, b + m + 1) ;
    if(m <= 16 && m <= 16) sub1::solve() ;
    else sub2::solve() ;

}
