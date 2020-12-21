#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define LT "coolmac"
#define maxn 100005
#define fi first
#define se second
#define For(i , a , b) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr(i , a , b) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii a[maxn];
int maxx = 100000;
int minn = 100005;

multiset <int> st;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i].fi >> a[i].se;

    cin >> m;
    For(i , 1 , m)
    {
        int x; cin >> x;
        minn = min(minn , x);
    }
}

void xuli()
{
    sort(a+1 , a+n+1);

    int r = minn - 1 , ct = 1 , ans = 0;
    while( r < maxx )
    {
        r++;
        while( ct <= n && a[ct].fi <= r )
        {
            st.insert( -a[ct].se );
            ct++;
        }

        if( st.empty() ) { cout << -1 << endl; return; }

        int tam = *st.begin(); tam = -tam;
        if( tam < r )
        {
            cout << -1 << endl;
            return;
        }

        ans++;
        r = tam;
    }

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
