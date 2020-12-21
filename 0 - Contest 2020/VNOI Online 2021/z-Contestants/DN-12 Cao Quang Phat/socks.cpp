#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define LT "socks"
#define maxn 500005
#define fi first
#define se second
#define For(i , a , b) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr(i , a , b) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k , q;
int deg[maxn];
vi ke[maxn];
int a[maxn] , nhan[maxn];
int u , res;
int dem[5];

void nhap()
{
    cin >> n >> q;
    For( i , 1 , n ) cin >> a[i];

    For( i , 1 , n - 1 )
    {
        int u , v; cin >> u >> v;
        deg[u]++; deg[v]++;
        ke[u].pb(v);
        ke[v].pb(u);
    }
}

int check_dt()
{
    int maxx = 0;
    For( i , 1 , n ) maxx = max( maxx , deg[i] );
    if( maxx <= 2 ) return 1;
    return 0;
}

void solve1()
{
    int dem = 0;
    For( i , 1 , n ) dem += a[i];

    if( dem <= 1 ) cout << 0 << endl;
    else cout << 1 << endl;

    For( i , 1 , q )
    {
        int x; cin >> x;

        if( a[x] ) dem-- , a[x] = 0;
        else dem++ , a[x] = 1;

        if( dem <= 1 ) cout << 0 << endl;
        else cout << 1 << endl;
    }
}

int check_T()
{
    int maxx = 0 , dem = 0 , u;
    For( i , 1 , n )
    {
        maxx = max( maxx , deg[i] );
        if( deg[i] == 3 ) dem++ , u = i;
    }

    if( maxx < 3 || maxx > 3 ) return 0;
    if( dem == 1 ) return u;
    return 0;
}

void dfs( int u , int p , int gt )
{
    nhan[u] = gt;
    for( int v : ke[u] )
    {
        if( v == p ) continue;
        dfs( v , u , gt );
    }
}

void xuat()
{
    if( res <= 1 ) cout << 0 << endl;
    else if( res == 2 ) cout << 1 << endl;
    else
    {
        int gt = 0;
        For( i , 1 , 3 ) if( dem[i] > 0 ) gt++;
        cout << max( 1 , gt - 1 ) << endl;
    }
}

void solve2()
{
    u = check_T();

    dfs( ke[u][0] , u , 1 );
    dfs( ke[u][1] , u , 2 );
    dfs( ke[u][2] , u , 3 );

    For( i , 0 , 3 ) dem[i] = 0;

    res = 0;
    For( i , 1 , n ) res += a[i];
    For( i , 1 , n ) dem[nhan[i]] += a[i];

    xuat();

    For( i , 1 , q )
    {
        int x; cin >> x;
        if( a[x] )
        {
            a[x] = 0;
            res--;
            dem[nhan[x]]--;
        }
        else
        {
            a[x] = 1;
            res++;
            dem[nhan[x]]++;
        }
        xuat();
    }
}

void xuli()
{
    if( check_dt() ) solve1();
    else if( check_T() ) solve2();
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
