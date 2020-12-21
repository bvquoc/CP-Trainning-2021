#include<bits/stdc++.h>
#define se second
#define fi first

using namespace std;
typedef long long LL;
typedef pair<LL,LL> I;

const int MAXN = 10 + 3e3;
const LL MOD = 998244353 ;
const LL oo = 1e18;

int n , m , k ;
int a[MAXN] , f[MAXN] , b[MAXN];

LL dp[12][2010][2010] , d[MAXN] , d1[MAXN] ;

LL s[MAXN] ;

I e[MAXN] ;

bool Check(int x) {
    int d = 0 ;
    while( x ) ++d , x /= 10;
return (d % 2 == 0);
}

void Solve1() {
    LL ans = 0;
    int cnt = 0 , Odd = 0 , Even = 0 ;

    for (int i = 1 ; i <= n ; ++i) {
        int x = a[i];
        vector<int> g;
        while( x ) {
            g.push_back( x % 10 );
            x /= 10;
        }
        for (int j = g.size() - 1 ;  j >= 0 ; --j) {
            ++cnt;
            if ( cnt & 1 ) Odd += g[j];
            else Even += g[j];
        }
    }
    if ( abs(Odd - Even) % 11 == 0 ) ++ans ;

    while( next_permutation( b + 1 , b + 1 + n ) ) {

        Odd = 0;    Even = 0;
        cnt = 0;

        for (int u = 1 ; u <= n ; ++u) {
            int i = b[u] ;
            int x = a[i];
            vector<int> g;
            while( x ) {
                g.push_back( x % 10 );
                x /= 10;
            }
            for (int j = g.size() - 1 ;  j >= 0 ; --j) {
                ++cnt;
                if ( cnt & 1 ) Odd += g[j];
                else Even += g[j];
            }
        }
        if ( abs(Odd - Even) % 11 == 0 ) ++ans ;
    }

    cout <<ans <<'\n';
}

LL ptich(LL x,LL i)
{

    LL cnt=0,cnt1=0,cnt2=0;
    while(x!=0)
    {
        LL res=x%10;
        ++cnt;
        if(cnt%2==1) cnt2+=res;
        else cnt1+=res;
        x/=10;
    }
    d[i]=cnt1-cnt2;
    d1[i]=cnt2-cnt1;
    return cnt;
}

void Solve2() {
    int cnt = 0 , Odd = 0 , Even = 0 ;
    for (int i = 1 ; i <= n ; ++i) {
        int x = a[i];
        vector<int> g;
        while( x ) {
            g.push_back( x % 10 );
            x /= 10;
        }
        for (int j = g.size() - 1 ;  j >= 0 ; --j) {
            ++cnt;
            if ( cnt & 1 ) Odd += g[j];
            else Even += g[j];
        }
    }

    if ( abs(Odd - Even) % 11 == 0 ) cout <<s[n] <<'\n';
    else cout <<0 <<'\n';
}

void Solve3(){
    dp[0][0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=10;++j){
            for(int k=0;k<=i;++k){
                int x=(d[i]+11)%11,x1=(d1[i]+11)%11;
                if(i-k>=1){
                dp[(x+j+11)%11][k][i-k]+=dp[j][k][i-k-1];
                dp[(x+j+11)%11][k][i-k]%=MOD;
                }
                if(k>=1){
                dp[(x1+j+11)%11][k][i-k]+=dp[j][k-1][i-k];
                dp[(x1+j+11)%11][k][i-k]%=MOD;
                }
            }
        }
    }
    if(n%2==0) cout<<(dp[0][n/2][n/2]*s[n/2])%MOD*s[n/2]%MOD<<'\n';
    else cout<<(dp[0][n/2+1][n/2]*s[n/2+1]%MOD)*s[n/2]%MOD<<'\n';
}

void Inout() {
    #define TASK "GIFT11"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
}

int main()
{
    Inout();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t ;
    cin >>t ;

    s[0] = 1;
    for (int i = 1 ; i <= 2000 ; ++i) s[i] = s[i - 1] * i % MOD;

    while( t-- ) {
        cin >>n;
        int cntl = 0 ,
            cntr = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            cin >>a[i] , b[i] = i;
            if ( Check(a[i]) ) ++cntl;
            else ++cntr;
            ptich( a[i] , i );
        }
        if ( n <= 8 ) { Solve1(); continue; }
        if ( cntl == n ) { Solve2(); continue; }
      //  if ( cntr == n ) { Solve3(); continue; }

        Solve3();
    }
return 0;
}
