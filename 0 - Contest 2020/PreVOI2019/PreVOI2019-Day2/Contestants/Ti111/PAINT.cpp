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
#define TASK "PAINT"
const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 30 ;

int n ;
char a[N] ;
int cnt = 0 ;
vector<int> g[N] ;
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> n ;
    int type ;
    char u, v ;
    For(i,1,n)
    {
        cin >> type ;
        if(type == 1)
        {
            cin >> u ;
            g[u-'a'].pb(++cnt) ;
        }
        else
        {
            cin >> u >> v ;
            for(auto x : g[u-'a'])
                g[v-'a'].pb(x) ;
            g[u-'a'].clear();
        }
    }
    For(i,0,26)
    {
        for(auto x : g[i])
            a[x] = char(i + 'a') ;
    }
    For(i,1,cnt) cout << a[i]  ;
    return 0;
}
