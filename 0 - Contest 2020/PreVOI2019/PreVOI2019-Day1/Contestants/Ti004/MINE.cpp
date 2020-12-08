//DinoFromMar
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define Task "MINE"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int n, m, f[202][502];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
   cin >> n >> m;
   f[0][0] = 1;
//   f[0][1] = 1;
   for(int i = 1; i <= n; i++)
    for(int j = i* 2;j <=n * 2 ; j++)
    for(int k = (i-1)*2; k < j; k++)
    f[i][j] =(f[i][j] + f[i-1][k])%1000003;
//   for(int i = ; i <= n; i++)
cout << f[n][2*n];
   return 0;
}
