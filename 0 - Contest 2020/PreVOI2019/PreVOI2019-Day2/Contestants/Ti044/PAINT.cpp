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

inline int read()
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

const int N = 1e6+5, A = 30;

int n;
bool flag[(int) 1e6+5];
int pa[(int) 1e6+5], c[30];
char res[(int) 1e6+5];

void enter()
{
    n = in;
}

struct sub1
{
    //vector < int > id[30];
    char res[10001] = {};
    priority_queue < int, vector < int >, greater < int > > q;

    void solve()
    {
        int t;
        char a,b;
        foru( i, 1, n )
            q.ep( i );
        foru( i, 1, n )
        {
            t = in, a = getchar();
            if ( t == 1 )
            {
                res[q.top()] = a;
                q.pop();
            }
            else
            {
                getchar(), b = getchar();
                foru( i, 1, n )
                    if ( res[i] == a )
                        res[i] = b;
            }
        }
        foru( i, 1, n )
            if ( res[i] )
                cout << res[i];
    }
} sub1;

struct sub2
{
    int inf = 1 << 30;

    int find( int u )
    {
        return pa[u] == u ? u : pa[u] = find( pa[u] );
    }

    void solve()
    {
        foru( i, 1, n )
            pa[i] = i, flag[i] = false;
        foru( i, 0, 29 )
            c[i] = inf;
        int t, cnt = 0;
        char a,b;
        foru( i, 1, n )
        {
            t = in, a = getchar();
            if ( t == 1 )
            {
                int pos = ++cnt;
                pa[pos] = ( c[a-'a'] == inf ? pos : find( c[a-'a'] ) );
                res[pa[pos]] = a;
                mini( c[a-'a'], pos );
            }
            else
            {
                getchar(), b = getchar();
                a -= 'a', b -= 'a';
                if ( c[a] != inf && a != b )
                {
                    if ( c[b] != inf )
                        pa[find(c[a])] = find( c[b] );
                    mini( c[b], c[a] );
                    res[find(c[b])] = b+'a';
                    c[a] = 1 << 30;
                }
            }
        }
        foru( i, 1, cnt )
            cout << res[find(i)];
    }
} sub2;


int main()
{
    #define haid "PAINT"

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    fr( haid".OUT", "w", stdout );
    #endif
    enter();
    if ( n <= 1e4 )
        sub1.solve();
    else
        sub2.solve();
}
