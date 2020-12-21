 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "DECOR"
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
#define maxn 500005
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
ll n, m, k ;
string s ;
pii a[maxn];
namespace sub1
{
    void solve()
    {
        ll res = 0, ans = 0 ;
        for(int i = 0; i < n; i ++)
        {
            if(s[i] == '1') res ++, ans = max(ans, res) ;
            else res = 0 ;
        }
        cout << ans ;
    }
}
namespace sub2
{
    int gt[maxn] ;
    void init()
    {
        gt[0] = (s[0] - '0') ;
        FORT(i, 1, n) gt[i] = gt[i - 1] + (s[i] - '0') ;
    }
    void solve()
    {
        init() ;
        ll res = 0, ans = 0 ;
        FORT(i, 0, n)
        {
            res = 0 ;
            int l = i, r = i + k - 1 ;
            ll d1 = gt[r] - gt[l - 1] ;
            res += (r - l + 1) ;
            while(d1 > 0)
            {
                int l2 = i + 1 ;  r = i + d1 ;
                if(r > n - 1 || l2 > n - 1) break ;
                d1 = gt[r] - gt[l2 - 1] ;
                res += (r - l2 + 1) ;
            }
            ans = max(ans, res) ;
        }
        cout << ans ;
    }
}
int main()
{
    inpf; outf; fast;
    cin >> n >> m >> k >> s ;
    FOR(i, 1, m) cin >> a[i].F >> a[i].S ;
    if(m == 0 && k == 0) sub1::solve() ;
    else if(m == 0) sub2::solve() ;
}
