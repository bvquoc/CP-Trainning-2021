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
#define Task "ODDCOIN"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int q, x, t;
int a[19] = {0,1, 3 , 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int f[maxn];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);


   cin >> q;
   while(q--)
   {
       cin >> x >> t;
       a[16] = x;
       for(int i = 1; i <= t; i ++)
       {
           f[i] = maxn;
        for(int j = 1; j <= 16; j++)
        if(a[j] <= i)
        {
            f[i] = min(f[i], f[i - a[j]] + 1);
            }
       }
       cout << f[t] << "\n";
   }

   return 0;
}
