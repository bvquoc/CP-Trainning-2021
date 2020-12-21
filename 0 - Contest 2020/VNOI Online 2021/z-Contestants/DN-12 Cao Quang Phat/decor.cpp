//Nhận xét :
//- Ta có thể sử dụng dsu để xét duyệt thành phàn liên thông.
//- Và các đèn trong thành phần liên thông này chắc chắn sẽ nối được với nhau hay trao đổi đèn cho nhau
//- Như vậy ta sẽ có được danh sách số lượng đèn trong mỗi nhóm và thành phần trong mỗi nhóm
//- Sort thành phần này lại để tìm đoạn dài nhất có thể.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define fi first
#define se second
#define For(i , a , b) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr(i , a , b) for(int i = int(a) ; i >= int(b) ; i--)
#define LT "decor"
#define maxn 500005

typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int i , j  , n , m , k;
int gt[maxn];
vii E;
int nhan[maxn] , sl[maxn];

int group[maxn]; /// Nhóm hiện tại mà i đang ở
int num[maxn]; /// Số lượng đèn 1 hiện có ở nhóm thứ i
int vt[maxn]; /// Vị trí của i trong nhóm chứa nó
int cur[maxn]; /// Con trỏ của nhóm thứ i hiện tại
int cnt = 0; /// Số lượng nhóm hiện tại
vi g[maxn]; /// Danh sách thành viên của nhóm

void nhap()
{
    cin >> n >> m >> k;
    For( i , 1 , n )
    {
        char x; cin >> x;
        gt[i] = x - '0';
    }
    For( i , 1 , m )
    {
        int u ,  v;
        cin >> u >> v;
        E.pb({u , v});
    }
}

void sub1()
{
    int L = 0 , dem = 0;
    pii ans;

    int ct = 0;
    For( i , 1 , n )
    {
        if( ct < i ) ct = i - 1 , dem = 0;

        while( ct < n && (dem + 1 - gt[ct + 1] <= k )  )
        {
            ct++;
            dem += 1 - gt[ct];
        }

        if( ct - i + 1 > L )
        {
            L = ct - i + 1;
            ans = {i , ct};
        }

        dem -= 1 - gt[i];
    }

    if( L == 0 ) { cout << -1 << endl; return; }
    cout << ans.fi << ' ' << ans.se << endl;
}

int root( int s )
{
    if( s != nhan[s] ) nhan[s] = root(nhan[s]);
    return nhan[s];
}

void Union( int u , int v )
{
    u = root(u);
    v = root(v);
    if( u == v ) return;
    if( sl[u] > sl[v] ) sl[u] += sl[v] , nhan[v] = u;
    else sl[v] += sl[u] , nhan[u] = v;
}

void Build_graph()
{
    vi dd(n+1 , 0);
    cnt = 0;   For( i , 1 , n ) if( nhan[i] == i ) dd[i] = ++cnt;

    For( i , 1 , n )
    {
        int u = root(i);
        group[i] = dd[u];
        num[dd[u]] += gt[i];
        g[dd[u]].pb(i);
    }

    For( i , 1 , cnt )
    {
//        cout << num[i] << endl;
        For( j , 0 , g[i].size() - 1 )
        {
            vt[g[i][j]] = j + 1;
//            cout << g[i][j] << ' ';
        }
//        cout << endl;
    }
}

void sub3()
{
    For( i , 1 , n ) nhan[i] = i , sl[i] = 1;
    for( pii tam : E )
    {
        int u = tam.fi , v = tam.se;
        Union(u , v);
    }
    Build_graph();

    int ct = 0 , L = 0 , dem = 0;
    pii ans;

    For( i , 1 , n )
    {
        if( ct < i ) ct = i - 1 , dem = 0;

        while( ct < n )
        {
            int cp;
            int tam = group[ct +  1];
            int tmp = vt[ct + 1];
            if( tmp - cur[tam] <= num[tam] ) cp = 0;
            else cp = 1;

            if( dem + cp > k ) break;
            ct++;
            dem += cp;
        }

        if( ct - i + 1 > L )
        {
            L = ct - i + 1;
            ans = {i , ct};
        }

        int tam = group[i];
        if( num[tam] == 0 ) dem--;
        else
        {
            if( cur[tam] + num[tam] < g[tam].size() )
            {
                int res = g[tam][ cur[tam] + num[tam] ];
                if( res <= ct ) dem--;
            }
        }
        cur[tam] = vt[i];
    }

    if( L == 0 ) { cout << -1 << endl; return; }
    cout << ans.fi << ' ' << ans.se << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
//    if( m == 0 ) sub1();
//    else sub3();
    sub3();
}
