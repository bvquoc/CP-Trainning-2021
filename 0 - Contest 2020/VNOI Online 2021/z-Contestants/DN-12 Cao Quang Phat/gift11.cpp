#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define LT "gift11"
#define maxn 2005
#define fi first
#define se second
#define For(i , a , b) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr(i , a , b) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn] , dem[2];
int mod = 998244353;
int kt[maxn] , tong = 0 , ans = 0 , tong_cs = 0;
pii b[maxn];

int f[maxn][1005][12];

void nhap()
{
    cin >> n;
    For(i , 1 , n) cin >> a[i];
}

pii chuyen( int s )
{
    dem[0] = dem[1] = 0;
    vector<int> st;
    while( s > 0 ) st.pb( s%10 ) , s/=10;
    int sl = st.size();
    For( i , 0 , sl - 1 ) dem[(sl - i)%2] += st[i];

    int res = ((dem[1] - dem[0]) % 11 + 11) % 11;
    return { sl % 2 , res };
}

void quaylui( int tam )
{
    if( tam > n )
    {
        if( tong % 11 == 0 ) ans++;
        return;
    }

    For(i , 1, n )
    {
        if( kt[i] ) continue;
        int tmp = tong_cs % 2;
        if( tmp == 0 ) tmp = 1;
        else tmp = -1;

        kt[i] = 1;
        tong += tmp * b[i].se;
        tong_cs += b[i].fi;

        quaylui(tam + 1);

        kt[i] = 0;
        tong -= tmp * b[i].se;
        tong_cs -= b[i].fi;
    }

}

int check_even()
{
    For( i , 1 , n ) if( b[i].fi % 2 == 1 ) return 0;
    return 1;
}

int check_odd()
{
    For( i , 1 , n ) if( b[i].fi % 2 == 0 ) return 0;
    return 1;
}

void solve1()
{
    int tong = 0;
    For( i , 1 , n ) tong += b[i].se;
    if( tong % 11 != 0 ) { cout << 0 << endl; return; }

    ll ans = 1;
    For( i , 1 , n ) ans = (ans * i) % mod;
    cout << ans << endl;
}

void solve2()
{
    int lim = n/2 + (n%2);

    For( i , 0 , n ) For( j , 0 , lim ) For(du , 0 , 10) f[i][j][du] = 0;

    f[0][0][0] = 1;
    For( i , 1, n )
    {
        For( j , 0 , lim )
        {
            For( du , 0 , 10 )
            {
                /// thằng i chọn 1
                if( j > 0 )
                {
                    int tam = (du - b[i].se + 11) % 11;
                    f[i][j][du] = ( f[i][j][du] + f[i - 1][j - 1][tam] ) % mod;
                }

                /// Thằng i chọn 0
                int tam = (du + b[i].se) % 11;
                f[i][j][du] = ( f[i][j][du] + f[i - 1][j][tam] ) % mod;
            }
        }
    }

    ll res = 1;
    For( i , 1 , lim ) res = (res * i) % mod;
    For( i , 1 , n - lim ) res = (res * i) % mod;

    cout << (f[n][lim][0] * res) % mod << endl;
}

void xuli()
{
    For(i , 1 , n) b[i] = chuyen(a[i]);

    if( n <= 8 )
    {
        ans = 0 , tong = 0 , tong_cs = 0;
        quaylui(1);
        cout << ans << endl;
    }
    else if( check_even()) solve1();
    else if( check_odd()) solve2();
    else cout << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    int t; cin >> t;
    while(t--)
    {
        nhap();
        xuli();
    }
}
