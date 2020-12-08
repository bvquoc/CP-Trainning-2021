#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
const int MOD = 1000003;

void add(int &x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
}

int mul(int x, int y) {
   return (long long) x * y % MOD;
}

int inv[MAXN * 2];
int fact[MAXN * 2];
int ifact[MAXN * 2];
int catalan[MAXN];

void precalc() {
   inv[1] = 1;
   for (int i = 2; i < MAXN * 2; ++i) {
      inv[i] = mul(MOD - (MOD / i), inv[MOD % i]);
   }
   fact[0] = 1;
   ifact[0] = 1;
   for (int i = 1; i < MAXN * 2; ++i) {
      fact[i] = mul(fact[i - 1], i);
      ifact[i] = mul(ifact[i - 1], inv[i]);
   }
   for (int i = 0; i < MAXN; ++i) {
      catalan[i] = mul(fact[2 * i], mul(ifact[i], ifact[i + 1]));
   }
}

int N, M;
int A[MAXN * 2];
int dp[MAXN * 2];

int main() {
#ifndef KienVu
   freopen("mine.inp", "r", stdin);
   freopen("mine.out", "w", stdout);
#endif // KienVu
   precalc();
   scanf("%d %d", &N, &M);
   if (N > 2000) {
      printf("%d\n", catalan[N]);
      return 0;
   }
   for (int i = 1; i <= 2 * N; ++i) {
      scanf("%d", A + i);
   }
   dp[0] = 1;
   for (int i = 2; i <= 2 * N; ++i) {
      for (int j = i - 2; j >= 0; j -= 2) {
         if (A[i] - A[j + 1] <= M) {
            add(dp[i], mul(dp[j], catalan[(i - j - 2) / 2]));
         }
      }
   }
   printf("%d\n", dp[2 * N]);
   return 0;
}
