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
typedef double db;

struct pt
{
    double x,y;
};

const int N = 100;

int t,m,n;
int xa,ya,xb,xy,xc,yc,xd,yd;

void enter()
{
    cin >> m >> n >> xa >> ya >> xb >> yb;
    cin >> xc >> yc >> xd >> yd;
}

struct sub1
{
    int ccw( pt& p0, pt& p1, pt& p2 )
    {
        db dx1 = p1.x - p0.x, dx2 = p2.x - p0.x;
        db dy1 = p1.y - p0.y, dy2 = p2.y - p0.y;
        db e = dx1*dy2 - dx2*dy1;
        return e ? ( e < 0 ? 1 : -1 ) : 0;
    }

    int giao( pt& a, pt& b, pt& c, pt& d, pt& res )
    {

    }
} sub1;

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    enter();
    solve();
}
