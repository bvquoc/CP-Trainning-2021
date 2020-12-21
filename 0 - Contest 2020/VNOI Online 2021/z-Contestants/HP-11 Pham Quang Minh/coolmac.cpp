#include <iostream>
#include <cstring>
#include <algorithm>
#include <array>
#include <climits>

using namespace std;

const int MAXM = 100000+1;

int tree[MAXM];
const int& inf = tree[0];

struct bit {
   bit() {
      memset(tree, 0x3f, sizeof(tree));
   }
   int get_min( int pos) {
      int ret = inf;
      for (; pos < MAXM; pos += pos & (-pos))
         ret = min(ret, tree[pos]);
      return ret;
   }
   void update(int pos, int val) {
      for (; pos > 0; pos -= pos & (-pos))
         tree[pos] = min(tree[pos], val);
   }
};

int m;
array<int, 2> a[MAXM];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#define TASK "coolmac"
   freopen(TASK".inp", "r", stdin);
   freopen(TASK".out", "w", stdout);

   cin >> m;

   for (int i = 1; i <= m; ++i) cin >> a[i][0] >> a[i][1];

   int n;

   cin >> n;

   int T = 100000;

   for (int i = 1; i <= n; ++i) {
      int t;
      cin >> t;
      T = min(T, t);
   }

   sort(a + 1, a + m + 1, [&](const array<int, 2>& x, const array<int, 2>& y){
      return x[1] < y[1];
   });

   int l = 1;

   while (l <= m && a[l][1] < T) ++l;
   if (l > m) cout << -1, exit(0);

   bit b;

   b.update(T, 0);

   int ans = inf;

   for (int i = l; i <= m; ++i) {
      int f_i = b.get_min(a[i][0]);
      if (f_i < inf){
         f_i += 1;
         b.update(a[i][1], f_i);
      }
      if (a[i][1] == 100000)
         ans = min(ans, f_i);
   }

   if (ans == inf) ans = -1;

   cout << ans;

   return 0;
}
