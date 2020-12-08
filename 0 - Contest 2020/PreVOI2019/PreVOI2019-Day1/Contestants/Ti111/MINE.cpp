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
#define TASK "MINE"
const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 2e2+7 ;

int n, m ;
int a[N] ;

int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> n >> m ;
    For(i,1,n*2) cin >> a[i] ;
    cout << n ;
    return 0;
}
