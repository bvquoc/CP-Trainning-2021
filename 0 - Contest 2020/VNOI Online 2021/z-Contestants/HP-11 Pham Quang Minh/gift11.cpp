#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <cstring>
using namespace std;
#define DBG
template<typename A, typename B>ostream& operator<<(ostream& os, const pair<A,B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream& operator<<(ostream& os, const T_container& v) { os << '('; string sep; for (const T& x :v) os << sep << x, sep = ", "; return os << ")\n"; }
#ifdef DBG
void dbgout() {cerr << endl;} template<typename Head, typename... Tail>void dbgout(const Head& h, Tail... t) {cerr << ' ' << h; dbgout(t...);}
#define dbg(...) cerr<<'('<<#__VA_ARGS__<<"):",dbgout(__VA_ARGS__)
#else
#define dbg(...)
#endif // DBG

const int maxn = 2020;
int t, test[10][maxn], sum[2];

const int mod = 998244353;

void read_input(){
   cin >> t;
   for (int i = 0; i < t; ++i) {
      int n; cin >> n;
      test[i][0] = n;
      for (int j = 1; j <= n; ++j) cin >> test[i][j];
   }
}

bool sub1(int i) {
   int n = test[i][0];
   vector<int> per(n);
   iota(per.begin(), per.end(), 1);
   int ans = 0;
   do{
      sum[0] = sum[1] = 0;
      int cur = 0;
      for(int j : per){
         for (int x = test[i][j]; x > 0; x /= 10){
            ++cur;
            sum[cur & 1] += x % 10;
         }
      }
      if((sum[1] - sum[0]) % 11 == 0)
         ans++;
   } while(next_permutation(per.begin(), per.end()));
   cout << ans << '\n';

   return true;
}

bool sub2(int itst) {
   int *a = test[itst];

   sum[0] = sum[1] = 0;

   int cur = 0;
   for (int i = 1; i <= a[0]; ++i) {
      int n = 0;
      for (int x = a[i]; x > 0; x /= 10) {
         ++n;
         cur ^= 1;
         sum[cur] += x % 10;
      }
      if (n & 1) return false;
   }

   if ((sum[1] - sum[0]) % 11 == 0) {
      int ans = 1;

      for (int i = 1; i <= a[0]; ++i)
         ans = ans * 1ll * i % mod;

      cout << ans << '\n';
   }
   else cout << 0 << '\n';

   return true;
}

inline int normal(int x) {
   x %= 11;
   (x < 0) && (x += 11);
   return x;
}

inline void add(int& x, int y) { x = (x + 0ll + y >= mod ? int(x + 0ll + y - mod) : x + y); }

inline int mul(int x, int y) { return int(x * 1ll * y % mod); }

bool sub3(int itst){
   int *a = test[itst];

   static int d[maxn];

   for (int i = 1; i <= a[0]; ++i) {
      int cur = 0;
      d[i] = 0;
      for(int x = a[i]; x > 0; x /= 10){
         ++cur;
         if (cur & 1) d[i] += x % 10;
         else d[i] -= x % 10;
      }
      if (!(cur & 1)) return false;
   }

   static int f[maxn][maxn][11];

   memset(f, 0, sizeof(f));

   f[1][0][normal(-d[1])] += 1;
   f[1][1][normal(d[1])] += 1;

   for (int i = 2; i <= a[0]; ++i){
      for (int m = 0; m < 11; ++m)
         for (int x = 0; x <= i; ++x){
            f[i][x][m] = mul(f[i-1][x][normal(m - d[i])], (i-x));
            if (x > 0)
               add(f[i][x][m], mul(f[i-1][x-1][normal(m + d[i])], x));
         }
   }

   cout << f[a[0]][a[0] - (a[0] >> 1)][0] << '\n';

   return true;
}

void solve(){

   for (int i = 0; i < t; ++i) {
      if(test[i][0] <= 5) sub1(i);
      else if (sub2(i)) continue;
      else if (sub3(i)) continue;
      else sub1(i);
   }
}

int main() {
   ios_base::sync_with_stdio(false);

   cin.tie(nullptr);
#define TASK "GIFT11"
   freopen(TASK".inp", "r", stdin);
   freopen(TASK".out", "w", stdout);

   read_input();

   solve();

   return 0;
}
