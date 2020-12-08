#include <bits/stdc++.h>

using namespace std;

const vector<int> vals = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int dp[50000];

void precalc() {
   for (int z = 0; z < 14; ++z) {
      for (int i = vals[z]; i < vals[z + 1]; ++i) {
         dp[i] = dp[i - vals[z]] + 1;
      }
   }
}

int go(int x) {
   return (x / 50000) + dp[x % 50000];
}

int main() {
#ifndef KienVu
   freopen("oddcoin.inp", "r", stdin);
   freopen("oddcoin.out", "w", stdout);
#endif // KienVu
   precalc();
   int Q;
   scanf("%d", &Q);
   while (Q--) {
      int X, T;
      scanf("%d %d", &X, &T);
      int ans = T;
      for (int z = 0; z <= min(50000, T / X); ++z) {
         ans = min(ans, z + go(T - z * X));
      }
      printf("%d\n", ans);
   }
   return 0;
}
