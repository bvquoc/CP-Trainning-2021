 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "DHAKA"
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
int prime(int n){ for(int i=2;i*i<=n;i++) if(n%i==0)return 0;return 1; }
void AddMOD(int &x, int y){x += y; if (x >= MOD) x -= MOD; }
ll tinh(ll a, ll b,ll c){ if(b == 1) return a%c; ll x = tinh(a,b/2,c); ll y = (1ll*x * x) % c; if ( b % 2 != 0) y = (1ll*y*a) % c; return y;}
ll tinh2(ll a,ll n,ll mod=MOD){a=a<0?(mod-(-a)%mod):(a%mod);ll r=1;while(n){if(n&1)r=r*a%mod;a=a*a%mod;n>>=1;}return r;}
//void rr(){ vector <int> v (a+1, a+n+1); sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());for (int i = 1; i <= n; i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;}
using namespace std;
ll n, m, k, l, tr[maxn], d[maxn], e[1005][1005], wt[maxn] ;
vector<pii> a[maxn] ;
vector<int> c[maxn] ;
struct data
{
    int u, v, w ;
}b[maxn] ;
namespace sub2
{
    void ijk(int s)
    {
        FOR(i, 1, n) d[i] = MOD;
        d[s] = 0;
        priority_queue <pii> Q;
        Q.push(mp(-d[s],s));
        while (!Q.empty())
        {
            pii u = Q.top();
            Q.pop();
            int x = u.S;
            if (d[x] < -u.F) continue;
            for( auto v : a[x])
                if( d[x] + v.S < d[v.F])
                {
                    d[v.F] = d[x] + v.S;
                    Q.push( mp( -d[v.F],v.F));
    //                tr[v.F]=x;
                }
        }
    }
    void solve()
    {
        ijk(1) ;
        if(d[n] == MOD) cout << -1 ;
        else cout << d[n] << endl;
    }
}
namespace sub1
{
    int p[maxn], cnt = 0, slg;
    bool dd[maxn] ;
    vector<pii> q, kq ;
    void solve()
    {
        FOR(i, 1, n) p[i] = i ;
        ll ans = MOD, res = 0 ;
        do
        {
//            p[1] = 3, p[2] = 4, p[3]= 5 ;
            cnt = 0 ;
            q.clear() ;
            FOR(i, 1, n) dd[i] = 0 ;
            int u = b[p[1]].u, v = b[p[1]].v ;
            ll res = b[p[1]].w, dem = 0 ;
            if(u != 1) continue;
            if(!e[u][v]) continue ;
            q.pb({u, v}) ;
            for(auto x: c[p[1]]) if(!dd[x]) dem ++, dd[x] = 1 ;
            bool fl = 0 ;
            FOR(i, 2, n)
            {
                int j = p[i] ;
                int u2 = b[j].u, v2 = b[j].v ;
                if(v == u2 && e[u2][v2])
                {
                    res += b[j].w ;
                    for(auto x: c[j]) if(!dd[x]) dem ++, dd[x] = 1 ;
                    u = u2 ; v = v2 ;
                    q.pb({u, v}) ;
                    if(v == n)
                    {
                        if(dem < l) fl = 1 ;
                        break ;
                    }
                }
                else {fl = 1; break;}
            }
            if(fl == 1) continue ;
//            ans = min(ans, res) ;
            if(ans > res)
            {
                ans = res, kq = q ;
            }
        }while(next_permutation(p + 1, p + n + 1)) ;
        if(ans == MOD) cout << -1;
        else cout << ans << endl ;
//        cout << kq.size() << endl ;
//        for(auto i: kq) cout << i.F << ' ' << i.S << endl ;
    }
}
namespace sub3
{
    int d1[maxn], dn[maxn] ;
    void ijk1()
    {
        FOR(i, 1, n) d1[i] = MOD;
        d1[1] = 0;
        priority_queue <pii> Q;
        Q.push(mp(-d[1],1));
        while (!Q.empty())
        {
            pii u = Q.top();
            Q.pop();
            int x = u.S;
            if (d1[x] < -u.F) continue;
            for( auto v : a[x])
                if( d1[x] + v.S < d1[v.F])
                {
                    d1[v.F] = d1[x] + v.S;
                    Q.push( mp( -d1[v.F],v.F));
                }
        }
    }
    void ijkn()
    {
        FOR(i, 1, n) dn[i] = MOD;
        dn[n] = 0;
        priority_queue <pii> Q;
        Q.push(mp(-d[n],n));
        while (!Q.empty())
        {
            pii u = Q.top();
            Q.pop();
            int x = u.S;
            if (dn[x] < -u.F) continue;
            for( auto v : a[x])
                if( dn[x] + v.S < dn[v.F])
                {
                    dn[v.F] = dn[x] + v.S;
                    Q.push( mp( -dn[v.F],v.F));
                }
        }
    }
    void solve()
    {
        ijk1() ; ijkn() ;
        ll ans = MOD ;
        FOR(i, 1, n)
        {
            if(!wt[i]) continue ;
            ans = min(ans, (ll)d1[i] + dn[i]) ;
        }
        if(ans == MOD) cout << -1 ;
        else cout << ans;
    }
}
int main()
{
    inpf; outf; fast;
    cin >> n >> m >> k >> l ;
    FOR(i, 1, n)
    {
        int x, y ;
        cin >> x ;
        if(x == 0) {wt[i] = 0 ; continue ;}
        FOR(j, 1, x) cin >> y, c[i].pb(y), wt[i] = y ;
    }
    FOR(i, 1, m)
    {
        int u, v, w ;
        cin >> u >> v >> w ;
        e[u][v] = w, e[v][u] = w ;
        b[i] = {u, v, w} ;
        a[u].pb({v, w}) ; a[v].pb({u, w}) ;
    }
    if(l == 0) sub2::solve() ;
    else if(l == 1) sub3::solve() ;
    else if(l <= 10) sub1::solve() ;

}
