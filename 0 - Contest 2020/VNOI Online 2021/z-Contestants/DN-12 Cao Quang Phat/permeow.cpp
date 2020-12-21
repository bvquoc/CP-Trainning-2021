#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define fi first
#define se second
#define For(i , a , b) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr(i , a , b) for(int i = int(a) ; i >= int(b) ; i--)
#define LT "permeow"
#define maxn 200005

typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int i , j  , n , m , k;
int a[maxn] , b[maxn];
int Fen[maxn];
int mod = 1e9 + 7;

ll gt[maxn];

ll ans = 0;
int st[maxn] , kt[maxn];

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i];
    For( i , 1 , n ) cin >> b[i];
}

void update( int i )
{
    while( i <= n )
    {
        Fen[i]++;
        i += i&-i;
    }
}

int get( int i )
{
    int ans = 0;
    while( i > 0 )
    {
        ans += Fen[i];
        i -= i & -i;
    }
    return ans;
}

ll Calc( int a[] )
{
    ll ans = 0;
    For( i , 1 , n ) Fen[i] = 0;
    FOr(i , n , 1)
    {
        ans += get(a[i] - 1);
        update(a[i]);
        ans = ans % mod;
    }
    return ans;
}

bool check_sub1()
{
    For( i , 1 , n )  if( a[i] != b[i] ) return false;
    return true;
}

void vet(int tam)
{
    if( tam > n )
    {
        ans = ans + Calc(st);
        return;
    }

    For(i , 1 , n)
    {
        if( kt[i] ) continue;
        kt[i] = 1;
        st[tam] = i;
        vet(tam + 1);
        kt[i] = 0;
    }
}

void xuli()
{
    gt[0] = 1;
    For( i , 1 , n ) gt[i] = (gt[i - 1] * i ) % mod;
    ll res = n * (n - 1) / 2;
    res = res % mod;

    ll ans = 0;
    For( i , 1 , n - 1 ) ans = ( ans + (res*gt[i]) % mod ) % mod;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
    if( check_sub1() ) cout << Calc(a) << endl;
    else xuli();
}

