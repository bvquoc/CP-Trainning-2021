 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "GIFT11"
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
#define maxn 100005
#define MOD 998244353
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
int t ; // , n[12], a[12][maxn] ;
int n, a[maxn] ;
namespace sub1
{
    int p[maxn] ;
    ll ans = 0 ;
    void solve()
    {
        ans = 0 ;
        FOR(i, 1, n) p[i] = i ;
        FOR(i, 1, n) cin >> a[i] ;
        do
        {
            string s = "" ;
            FOR(i, 1, n)
            {
                std::string t = std::to_string(a[p[i]]);
                s += t ;
            }
            ll d1 = 0, d2 = 0 ;
            for(int i = 0; i < s.length(); i ++)
            {
                if((i + 1) % 2 == 0) d1 += (s[i] - 48) ;
                else d2 += (s[i] - 48) ;
            }
            if((d1 - d2) % 11 == 0) ans ++ ;
        }while(next_permutation(p + 1, p + n + 1)) ;
        cout << ans % MOD << endl ;
    }
}
ll gt[maxn] ;
void init()
{
    gt[1] = 1 ;
    FOR(i, 2, 100) gt[i] = 1ll * gt[i - 1] * i ;
}
namespace sub2
{
    ll d1 = 0, d2 = 0;
    string s ;
    void solve()
    {
        FOR(i, 1, n)
        {
            cin >> s ;
            for(int i = 0; i < s.length(); i += 2)
            {
                if(i >= s.length()) break ;
                d1 += (s[i] - 48) ;
            }
            for(int i = 1; i < s.length(); i += 2)
            {
                if(i >= s.length()) break ;
                d2 += (s[i] - 48) ;
            }
        }
        if((d1 - d2) % 11 == 0) cout << gt[n] % MOD << endl ;
        else cout << 0 << endl ;
    }
}
namespace sub3
{
    void solve()
    {

    }
}
int main()
{
    inpf; outf; fast;
    cin >> t ;
    int s1 = 0 ;
    FOR(i, 1, t)
    {
        cin >> n ;
        if(n <= 8) sub1::solve() ;
        else sub2::solve() ;
    }
}
