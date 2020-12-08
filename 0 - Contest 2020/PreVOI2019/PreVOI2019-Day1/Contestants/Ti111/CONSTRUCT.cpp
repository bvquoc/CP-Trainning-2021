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
#define TASK "CONSTRUCT"

const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 5e4+7 ;

int t ;
int m, n ;
int a[N] ;
int b[N] ;

void Solve(int l,int r)
{
    int res = 0 ;
    int cnt = 0 ;
    For(i,l,r)
    {
        if(a[i] != 0) cnt++ ;
        b[i] = a[i] ;
    }
    while(1)
    {
        For(i,l,r)
        {
            if(b[i] > 0)
            {
                while(b[i] > 0)
                {
                    b[i]-- ;
                    if(b[i] == 0) cnt-- ;
                    i++ ;
                }
                res++ ;
                i-- ;
            }
            if(cnt == 0) goto fl ;
        }
    }
    fl: ;
    cout << res << "\n" ;
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> t ;
    int type ;
    while(t--)
    {
        cin >> n >> m  ;
        For(i,1,n) cin >> a[i] ;
        For(i,1,m)
        {
            cin >> type ;
            int l, r, x ;
            if(type == 1)
            {
                cin >> l >> r >> x ;
                For(i,l,r)
                    a[i] += x ;
            }
            else
            {
                cin >> l >> r ;
                Solve(l,r) ;
            }
        }
    }
    return 0;
}
