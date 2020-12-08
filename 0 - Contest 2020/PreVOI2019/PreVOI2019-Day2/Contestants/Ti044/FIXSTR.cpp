#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <numeric>
#include <limits.h>
#include <chrono>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define all( a ) a.begin(), a.end()
#define rall( a ) a.rbegin(), a.rend()
#define eb emplace_back
#define ep emplace

using namespace std;

template < class X, class Y >
bool mini( X& a, const Y& b )
{
    if ( a > b ) { a = b; return 1; } return 0;
}

template < class X, class Y >
bool maxi( X& a, const Y& b )
{
    if ( a < b ) { a = b; return 1; } return 0;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

struct data
{
    int mo,dong;

    data operator + ( const data& b ) const
    {
        return { max( 0, mo-b.dong )+b.mo, max( 0, b.dong-mo )+dong };
    }
};

const int N = 1e6+1;

int n,q;
char a[N];
data t[N<<1];

void enter()
{
    cin >> a+1 >> q;
    n = strlen( a+1 );
}

struct sub1
{
    char s[1001][1001];

    int qr( int l, int r )
    {
        stack < int > s;
        int res = 0;
        foru( i, l, r )
        {
            if ( a[i] == '(' )
                s.ep( i );
            else
                if ( s.empty() )
                    res++;
                else
                    s.pop();
        }
        return res + s.size();
    }

    void solve()
    {
        char t;
        int l,r;
        foru( i, 1, n )
            s[0][i] = a[i];
        foru( i, 1, q )
        {
            cin >> t >> l;
            if ( t == 'C' )
                a[l] ^= 1;
            else
                if ( t == 'Q' )
                    cin >> r, cout << qr( l, r ) << '\n';
                else
                    foru( j, 1, n )
                        a[j] = s[l-1][j];
            foru( j, 1, n )
                s[i][j] = a[j];
        }
    }
} sub1;

struct sub2
{

    void build()
    {
        foru( i, 1, n )
            if ( a[i] == '(' )
                t[i+n] = { 1, 0 };
            else
                t[i+n] = { 0, 1 };
        ford( i, n-1, 1 )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    void modify( int i )
    {
        if ( a[i] == '(' )
            t[i+n] = { 1, 0 };
        else
            t[i+n] = { 0, 1 };
        for( i += n; i >>= 1;  )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    data get( int l, int r )
    {
        data resl = { 0, 0 }, resr = { 0, 0 };
        for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
        {
            if ( l & 1 )
                resl = resl + t[l++];
            if ( r & 1 )
                resr = t[--r] + resr;
        }
        return resl + resr;
    }

    void solve()
    {
        build();
        char t;
        int l,r;
        foru( i, 1, q )
        {
            cin >> t >> l;
            if ( t == 'C' )
                a[l] ^= 1, modify( l );
            else
            {
                cin >> r;
                data res = get( l, r );
                cout << res.mo + res.dong << '\n';
            }
        }
    }

} sub2;

int main()
{
    #define haid "FIXSTR"

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    fr( haid".OUT", "w", stdout );
    #endif
    enter();
    if ( n <= 1000 && q <= 1000 )
        sub1.solve();
    else
        sub2.solve();
}
