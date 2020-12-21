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
int a[MAXN] , b[MAXN] , f[MAXN] , dp[MAXN];

LL gt[MAXN] ;

LL ans = 0 ;

vector <int> g[MAXN];

void update(int i , int val) {
    for ( ; i <= n ; i += i & -i ) f[i] += val;
}

int get(int i) {
    int ans = 0;
    for ( ; i ; i -= i & -i ) ans += f[i];
return ans ;
}

void Solve1() {
    for (int i = 1 ; i <= n ; ++i) f[i] = 0;
    for (int i = 1 ; i <= n ; ++i) {
        ans = (ans + get(n) - get( a[i] )) % MOD;
        update( a[i] , 1 );
    }
    if ( cnt == n ) cout <<ans;
}

void Solve2() {
    gt[0] = 1;
    for (int i = 1 ; i <= n ; ++i)
        if ( i == 2 ) gt[i] = gt[i - 1];
        else gt[i] = gt[i - 1] * i % MOD;

    dp[5] = 5;
    int val = 2;
    for (int i = 6 ; i <= n ; ++i) ++val , dp[i] = (i + dp[i - 1] - i + 1 + val) ;

    for (int i = 1 ; i <= n ; ++i) dp[i] += i ;
    cout <<(dp[n] % MOD) * gt[n] % MOD ;
}

void Inout() {
    #define TASK "PERMEOW"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n ;
    for (int i = 1 ; i <= n ; ++i) cin >>a[i] ;
    for (int i = 1 ; i <= n ; ++i) cin >>b[i] , cnt += (a[i] == b[i]);

    if ( cnt == n ) {
        Solve1();
        return 0;
    }

    if ( n <= 8 ) {
        Solve1();
        while( next_permutation( a + 1 , a + 1 + n ) ) {
            Solve1();
            int dem = 0 ;
            for (int i = 1 ; i <= n ; ++i) dem += (a[i] == b[i]);
            if ( dem == n ) {
                cout <<ans <<'\n';
                return 0 ;
            }
        }
    }

    Solve2();
return 0;
}
