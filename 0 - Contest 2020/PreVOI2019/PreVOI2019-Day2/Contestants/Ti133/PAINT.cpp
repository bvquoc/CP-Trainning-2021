#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)
using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 10 + 1e6 ,INF = 1e18;
LL n ,m ,query;
LL a[maxn] ,center[maxn] ,root[maxn];
char res[maxn];
void Read()
{
    cin >> query;

return ;
}
int getroot(int u)
{
    return (u == root[u] ? u : (root[u] = getroot(root[u])));
}
void Solve1()
{
    for (int i = 1 ; i <= query ; ++i) {
         int type;
         char x ,y;
         cin >> type >> x;
         if (type == 1) {
             n ++;
             res[n] = x;
             continue ;
         }
         cin >> y;
         for (int j = 1 ; j <= n ; ++j)
              if (res[j] == x)   res[j] = y;
    }

    for (int i = 1 ; i <= n ; ++i)
         cout << res[i];
return ;
}
void Solve2()
{
    for (int i = 0 ; i <= 26 ; ++i)  center[i] = INF;

    for (int i = 1 ; i <= query ; ++i) {
         int type ;
         char x ,y;
         cin >> type >> x;
         if (type == 1) {
             n ++;
             a[n] = x - 'a';
             if (center[ a[n] ] == INF) {
                 center[ a[n] ] = n;
                 root[n] = n;
             }
             else
                 root[n] = center[ a[n] ];
        //     cout << root[n] << ' ' << center[ a[n] ] << '\n';
             continue ;
         }
         cin >> y;
         if (center[x - 'a'] == INF)  continue ;
         if (center[y - 'a'] < center[x - 'a'])
             root[center[x - 'a']] = center[y - 'a'];
         else {
             if (center[y - 'a'] != INF)   root[center[y - 'a']] = center[x - 'a'];
             center[y - 'a'] = center[x - 'a'];
             a[ center[x - 'a'] ] = y - 'a';
         }

         center[x - 'a'] = INF;
    }

    for (int i = 1 ; i <= n ; ++i) {
         int ru = getroot(i);
         cout << char(a[ru] + 'a');
    }

return ;
}
int main()  {
          #define TASK "PAINT"
      freopen(TASK ".inp","r",stdin);
      freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();
      if (n <= 10000)    Solve1();
      else
                         Solve2();

return 0;
}
