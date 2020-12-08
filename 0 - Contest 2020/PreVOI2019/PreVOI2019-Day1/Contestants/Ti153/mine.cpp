///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "mine"
#define maxn 200005
#define MOD 1000003
#define pii pair<int, int>
#define endl "\n"
int n,m,a[2*maxn];
long long f[4005][4005],g[4005][4005];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=2*n; ++i)
        cin >> a[i];
    if(n <= 2000)
    {
       for(int i=2*n-1; i>=1; --i)
       {
           if(a[i+1] - a[i] <= m)
              f[i][i+1]=g[i][i+1]=1;
           long long sum=f[i][i+1];
           for(int j=i+3; j<=2*n; j+=2)
              {
                  if(a[j]-a[i]<=m) g[i][j]=f[i+1][j-1] % MOD;
                  sum=(sum + g[i][j]) % MOD;
                  f[i][j]=(f[i][j] + sum) % MOD;
              }
       }
       cout<<f[1][2*n] % MOD;
    }
}
