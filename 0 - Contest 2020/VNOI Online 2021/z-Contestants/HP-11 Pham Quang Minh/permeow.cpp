#define TASK "permeow"

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
const int maxn = 2001;
int tree[maxn], a[maxn], b[maxn];

const int mod = 1000*1000*1000+7;

inline void add(int& a, int b) {
   a = (a + 0ll + b >= mod ? a + 0ll + b - mod : a + b);
}

struct sum_bit{
   sum_bit(){
      memset(tree, 0, sizeof(tree));
   }
   int get_sum(int pos) {
      int val = 0;
      for (; pos <= n; pos += pos & (-pos))
         val += tree[pos];
      return val;
   }
   void update(int pos, int val = 1) {
      for (; pos > 0; pos -= pos & (-pos))
         tree[pos] += val;
   }
};

int ans = 0;

void solve_for_one(){
   sum_bit sum;

   for (int i = 1; i <= n; ++i) {
      add(ans, sum.get_sum(a[i] + 1));
      sum.update(a[i]);
   }
}

bool sub1() {
   for (int i = 1; i <= n; ++i) if (a[i] != b[i]) return false;

   solve_for_one();

   cout << ans;

   return true;
}

bool sub2() {
   for (int i = 1; i <= n; ++i) if (a[i] != i || b[i] != n-i+1) return false;
   int res=1;
   for(int i=1; i<=n;++i) res=res*1ll*i%mod;
   res = ((n*1ll*(n-1)/2)*1ll*res/2)%mod;
   cout << res;
   return true;
}

void sub3() {
   int cur = 1;
   do {
      solve_for_one();

      while (cur <= n && a[cur] == b[cur]) ++cur;
      if (cur > n) break;
   }while (next_permutation(a+1, a+n+1));


   cout << ans;
}

int main() {
   ios_base::sync_with_stdio(false);
#ifndef DBG
   cin.tie(nullptr); freopen(TASK".out", "w", stdout);
#endif // DBG
   freopen(TASK".inp", "r", stdin);

   cin >> n;

   for (int i=1; i<=n; ++i) cin >> a[i];
   for (int i=1; i<=n; ++i) cin >> b[i];

   if (sub1()) return 0;
   else if(sub2()) return 0;
   else sub3();

   return 0;
}
