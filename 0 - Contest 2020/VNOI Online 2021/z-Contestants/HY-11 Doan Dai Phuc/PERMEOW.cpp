 /** Fucc :/
 - doanphuc : /
	** author: doanphuc. **
**/
#include <bits/stdc++.h>
#define TASK "PERMEOW"
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
int n, a[maxn], b[maxn] ;
namespace sub1
{
    int p[maxn] ;
    ll res = 0, ans = 0 ;
    void solve()
    {
       int i, j;
       bool swapped;
       for (i = 0; i < n-1; i++)
       {
         swapped = false;
         for (j = 0; j < n-i-1; j++)
         {
            if (a[j] > a[j+1])
            {
               swap(a[j], a[j+1]);
               ans ++ ;
               swapped = true;
            }
         }
        if (swapped == false) break;
        }
        cout << ans % MOD ;
    }
}
int so[] = {0, 1, 2, 3, 4, 5} ;
namespace sub2
{
    ll ans = 0, res = 0, temp = 1;
    void init()
    {
        temp = 1 ;
        FOR(i, 2, n)
        {
            temp = 1ll * temp * i ;
        }
    }
    void solve()
    {
        init() ;
        ll time = temp / 6 ;
        res = 9 ; ans = 9 ;
        FOR(i, 2, time)
        {
            ans += res + 6 ;
            res = res + 6 ;
        }
        cout << ans ;
    }
}
int main()
{
    inpf; outf; fast;
//    do
//    {
//        FOR(i, 1, 5) cout << so[i] << ' ' ;
//        cout << endl ;
//    }while(next_permutation(so + 1, so + 5 + 1)) ;
    cin >> n ;
    FORT(i, 0, n) cin >> a[i] ;
    FORT(i, 0, n) cin >> b[i] ;
    bool fl = 0 ;
    FORT(i, 0, n)
    {
        if(a[i] != b[i]) fl = 1  ;
    }
    if(fl == 0) sub1::solve() ;
    else  sub2::solve() ;
}
