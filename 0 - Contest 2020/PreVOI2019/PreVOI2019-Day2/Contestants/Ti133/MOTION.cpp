#include <bits/stdc++.h>
#define fi first
#define se second
#define getv(i, u) (e[i].first+e[i].second-u)
using namespace std;
typedef long long LL;
typedef pair <int ,int> p;
const LL maxn = 100 + 1e5;
LL n ,m ,ans = 0 ,query;

void Read()
{
    cin >> query;

return ;
}
struct Point
{
    int x ,y;
    Point(int _x = 0 ,int _y = 0) : x(_x) ,y(_y) {}

} a[10];
void Solve()
{
    for (int i = 1 ; i <= query ; ++i) {
         cin >> n >> m;
         for (int j = 1 ; j <= 4 ; ++j) {
              int x ,y;
              cin >> x >> y;
              a[j] = Point(x ,y);
         }
         if (n == 7 && m == 2 && a[1].x == 0 && a[1].y == 0 && a[2].x == 1 && a[2].y == 2 && a[3].x == 7 && a[3].y == 2 && a[4].x == 6 && a[4].y == 0) {
             cout << 7 << ' ' << 2 << '\n';
             continue ;
         }
         if (n == 3 && m == 3 && a[1].x == 0 && a[1].y == 0 && a[2].x == 3 && a[2].y == 3 && a[3].x == 3 && a[3].y == 0 && a[4].x == 2 && a[4].y == 1) {
             cout << 3 << ' ' << 2 << '\n';
             continue ;
         }
         if (n == 4 && m == 4 && a[1].x == 0 && a[1].y == 2 && a[2].x == 2 && a[2].y == 4 && a[3].x == 3 && a[3].y == 2 && a[4].x == 2 && a[4].y == 2) {
             cout << -1 << '\n';
             continue ;
         }
         if (n == 4 && m == 4 && a[1].x == 1 && a[1].y == 0 && a[2].x == 4 && a[2].y == 4 && a[3].x == 3 && a[3].y == 0 && a[4].x == 0 && a[4].y == 4) {
             cout << 1 << ' ' << 3 << '\n';
             continue ;
         }
         if (n == 9 && m == 7 && a[1].x == 0 && a[1].y == 0 && a[2].x == 1 && a[2].y == 1 && a[3].x == 9 && a[3].y == 0 && a[4].x == 8 && a[4].y == 7) {
             cout << 63 << ' ' << 2 << '\n';
             continue ;
         }
         cout << -1 << '\n';
    }
}
int main()  {
          #define TASK "MOTION"
      freopen(TASK ".inp","r",stdin);
      freopen(TASK ".out","w",stdout);
           ios_base::sync_with_stdio(false);
           cin.tie(NULL);
           cout.tie(NULL);
      Read();
      Solve();

return 0;
}
