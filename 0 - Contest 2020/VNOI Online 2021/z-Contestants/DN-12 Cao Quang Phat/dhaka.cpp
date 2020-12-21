#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define fi first
#define se second
#define For(i , a , b) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr(i , a , b) for(int i = int(a) ; i >= int(b) ; i--)
#define LT "dhaka"
#define maxn 100005

typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int i , j  , n , m , k , l;
int gt[maxn];
vii dsk[maxn];

struct ii
{
    int u , mask;
    ll w;
};
struct ss
{
    bool operator()( ii a , ii b )
    {
        return a.w > b.w;
    }
};
priority_queue < ii , vector<ii> , ss > heapmin;

ll f[maxn][35] , vc = 1e16;
int kt[maxn][35];

int get(int  k) { return 1 << k; }
bool get_bit(int s , int k) { return (s >> k) & 1; }

void nhap()
{
    cin >> n >> m >> k >> l;
    For( i , 1 , n )
    {
        int sl; cin >> sl;
        For( j , 1 , sl )
        {
            int x; cin >> x;
            gt[i] += get(x - 1);
        }
    }

    For( i , 1 , m )
    {
        int u , v , w;
        cin >> u >> v >> w;
        dsk[u].pb({v , w});
        dsk[v].pb({u , w});
    }
}

void dijkstra( int s , int mask )
{
    For( i , 1 , n ) For( j , 0 , 31 ) f[i][j] = vc, kt[i][j] = 0;
    f[s][mask] = 0;
    heapmin.push( {s , mask , f[s][mask]} );

    while( !heapmin.empty() )
    {
        ii tam = heapmin.top(); heapmin.pop();
        int u = tam.u , mask = tam.mask;

        if( tam.w > f[u][mask] ) continue;
        kt[u][mask] = 1;

        for( pii tmp : dsk[u] )
        {
            int v = tmp.fi;
            int mask_new = mask | gt[v];

            if( kt[v][mask_new] ) continue;

            if( f[v][mask_new] > f[u][mask] + tmp.se )
            {
                f[v][mask_new] = f[u][mask] + tmp.se;
                heapmin.push( {v , mask_new , f[v][mask_new]} );
            }
        }
    }
}

void xuli()
{
    dijkstra(1 , gt[1]);

    ll ans = vc;
    For( i , 0 , get(k) - 1 )
    {
        int dem = 0;
        For( j , 0 , k - 1 ) dem += get_bit(i , j);
        if( dem >= l ) ans = min(ans , f[n][i]);
    }

    if( ans == vc ) { cout << -1 << endl; return; }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
