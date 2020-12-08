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
#define Task "PAINT"
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int n, color[maxn];
int M[200];
int root[maxn];

int get_root(int u)
{
    return (root[u] ? u = get_root(root[u]) : u);
}

int cnt;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
   cin >> n;
   while(n--)
   {
       int type;
       cin >> type;
       if(type == 1)
       {
           char x;
           cin >> x;
//           cerr << x << "\n";
           if(M[x] == 0)M[x] = ++cnt, color[cnt] = x;
           else root[++cnt] = M[x];
       }
       if(type == 2)
       {
           char x, y;
           cin >> x >> y;
           if(M[y] == 0)M[y] = M[x], color[M[y]] = y, M[x] = 0;
           else root[M[x]] = M[y], M[x] = 0;
       }
   }
   for(int i = 1; i <= cnt; i++)
    cout << char(color[get_root(i)]);
   return 0;
}
