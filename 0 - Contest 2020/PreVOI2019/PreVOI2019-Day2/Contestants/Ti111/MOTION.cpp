#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define ull unsigned long long
#define ll long long
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define TASK "MOTION"
const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 1e6+7 ;

int tests ;
int m, n, xa, ya, xb, yb, xc, yc, xd, yd ;

int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> tests ;
    while(tests--)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd ;
        if(xa - xc == xb - xd)
            cout << -1 << "\n" ;
        else
            cout << 1 << " " << 1 << "\n" ;
    }
    return 0;
}

