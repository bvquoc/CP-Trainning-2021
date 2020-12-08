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
#define in read()

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

int q,t,x;
int a[20];

void enter()
{

}

struct sub1
{
    int res = 1e9, tmp = 0;
    int x[10];

    void update()
    {
        mini( res, accumulate( x+1, x+6, 0 ) );
    }

    void Try( int i )
    {
        foru( j, 0, t )
            if ( j*a[i] <= t )
            {
                x[i] = j;
                if ( i == 5 )
                    update();
                else
                    Try( i+1 );
            }
    }

    /*void solve()
    {
        int k = a[5];
        a[5] = x;
        Try( 1 );
        cout << res << '\n';
        a[5] = k;
    }*/
};

struct sub2
{
    int f[(int)1e6+1];

    void solve()
    {
        foru( i, x, t )
        {
            f[i] = 1e9;
            foru( j, 1, 16 )
                if ( i >= a[j] )
                    mini( f[i], f[i-a[j]] + 1 );
        }
        cout << f[t] << '\n';
    }

    void init()
    {
        f[0] = 0;
        foru( i, 1, 1e6 )
        {
            f[i] = 1e9;
            foru( j, 1, 15 )
                if ( i >= a[j] )
                    mini( f[i], f[i-a[j]] + 1 );
        }
    }
} sub2;

int main()
{
    #define haid "ODDCOIN"

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    fr( haid".OUT", "w", stdout );
    #endif
    cin >> q;
    a[1] = 1, a[2] = 3, a[3] = 5;
    foru( i, 4, 15 )
        a[i] = a[i-3] * 10;
    sub2.init();
    while ( q-- )
    {
        cin >> x >> t;
        if ( x <= 1e6 && t <= 1e6 )
        {
            a[16] = x;
            sub2.solve();
        }
    }
}
