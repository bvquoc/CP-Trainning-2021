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

const int N = 2e5+1, M = 1e6+1, mod = 1e6+3;

int n,m;
int a[N<<1];

void enter()
{
    cin >> n >> m;
    foru( i, 1, n << 1 )
        cin >> a[i];
}

struct sub1
{
    int x[30], cnt[30];
    int last[30];
    int res = 0;

    void update()
    {
        int Max = 0;
        fill( last+1, last+n*2+1, 0 );
        stack < int > s;
        foru( i, 1, n << 1 )
            if ( !last[x[i]] )
            {
                if ( Max > x[i] )
                    return;
                s.ep( x[i] ), last[x[i]] = a[i];
                maxi( Max, x[i] );
            }
            else
                if ( s.empty() || s.top() != x[i] || a[i] - last[x[i]] > m )
                    return;
                else
                    s.pop();
        /*foru( i, 1, 2*n )
            cout << x[i] << " ";
        cout << endl;*/
        res++;
        if ( res >= mod )
            res -= mod;
    }

    void Try( int i )
    {
        foru( j, 1, n )
        {
            if ( cnt[j] == 2 )
                continue;
            x[i] = j, cnt[j]++;
            if ( i == 2*n )
                update();
            else
                Try( i+1 );
            cnt[j]--;
        }
    }

    void solve()
    {
        x[1] = 1, cnt[1] = 1;
        Try( 2 );
        cout << res;
    }

} sub1 ;

int main()
{
    #define haid "MINE"

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    fr( haid".OUT", "w", stdout );
    #endif
    enter();
    sub1.solve();
}
