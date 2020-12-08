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

inline read()
{
    char c = getchar();
    for( ; c < '0'; c = getchar() );
    int x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
    return x;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = 1e5+1;

int t,n,q;
int a[N];

void enter()
{
    n = in, q = in;
    foru( i, 1, n )
        a[i] = in;
}

struct sub1
{
    int c[1001];

    int calc( int l, int r )
    {
        if ( l > r )
            return 0;
        if ( l == r )
            return a[l];
        int i = min_element( a+l, a+r+1 ) - a, k = a[i];
        foru( j, l, r )
            a[j] -= k;
        return calc( l, i-1 ) + calc( i+1, r ) + k;
    }

    void solve()
    {
        int type,l,r,k;
        while ( q-- )
        {
            type = in, l = in, r = in;
            if ( type == 1 )
            {
                k = in;
                while ( l <= r )
                    a[l] += k, l++;
            }
            else
            {
                foru( i, 1, n )
                    c[i] = a[i];
                cout << calc( l, r ) << '\n';
                foru( i, 1, n )
                    a[i] = c[i];
            }
        }
    }
} sub1;

int main()
{
    #define haid "CONSTRUCT"

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    fr( haid".OUT", "w", stdout );
    #endif
    t = in;
    while ( t-- )
    {
        enter();
        sub1.solve();
    }
}
