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
#define TASK "ODDCOIN"

const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 1e5+10 ;
const int maxn = 1e5+7 ;

ll a[25] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000} ;
int q ;
ll x, t ;
ll f[25][N] ;

void Solve(ll sum)
{
    ll maxx = 0 ;
    For(i,0,15)
    {
        if(sum == a[i])
        {
            cout << 1 << "\n" ;
            return ;
        }
        f[i][1] = a[i] ;
        maxx = max(maxx , a[i]) ;
    }
    int dem = 0 ;
    while(sum > 50000000)
    {
        sum = sum - maxx ;
        ++dem ;
    }
    For(j,2,maxn)
    {
        For(i,0,15)
        {
            For(k,0,15)
            {
                if(f[k][j-1] + a[i] <= sum)
                    f[i][j] = max(f[k][j-1] + a[i] , f[i][j]) ;
                if(f[i][j] == sum)
                {
                    cout << j + dem << "\n" ;
                    For(i,0,16) For(j,0,maxn+1) f[i][j] = 0 ;
                    return ;
                }
            }
        }
    }
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> q ;
    while(q--)
    {
        cin >> x >> t ;
        a[15] = x ;
        Solve(t) ;
    }
    return 0;
}
