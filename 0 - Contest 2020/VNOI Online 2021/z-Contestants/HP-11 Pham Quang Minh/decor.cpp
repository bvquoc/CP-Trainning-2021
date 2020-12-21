#define TASK "decor"

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int maxm = 500005;

int n, m, k;
string s;
vector<int> adj[maxm];

//int sum[maxm];
int num1[maxm], p[maxm], need_inc[maxm];

int find_set(int v) {
   return p[v] < 0 ? v : p[v] = find_set(p[v]);
}
void union_sets(int u, int v) {
   u = find_set(u), v = find_set(v);
//   assert(u >= 0 && v >= 0);
   if (u == v) return;
   if (p[u] > p[v]) swap(u, v);
   p[u] += p[v];
   p[v] = u;
   num1[u] += num1[v];
}
inline int& get_num1(int v) {
   return num1[find_set(v)];
}

void sub1() {
   int ans = 0, start = 0;

   for (int l = 0; l < n; ++l){
      int nr = 0;
      for (int r = l; r < n; ++r) {
         int p_r = find_set(r);

         if (get_num1(p_r) > 0) {
            ++nr;
            --get_num1(p_r);
            ++need_inc[p_r];
         }

         if (nr >= r - l + 1 - k){
            if (ans < r-l+1) ans = r-l+1, start=l;
         }
      }
      for (int r=l; r<n; ++r) {
         int p_r = find_set(r);
         if (need_inc[p_r] > 0) {
            get_num1(p_r) += need_inc[p_r];
            need_inc[p_r] = 0;
         }
      }
   }

   if (ans > 0)
      cout << start + 1<< ' ' << start + ans;
   else cout << -1;
}

int main() {
   ios_base::sync_with_stdio(false);
#ifndef DBG
   cin.tie(nullptr); freopen(TASK".out", "w", stdout);
#endif // DBG
   freopen(TASK".inp", "r", stdin);

   cin >> n >> m >> k;
   cin >> s;
//
//   sum[0] = 0;
//   for (int i = 0; i < n; ++i)
//      sum[i + 1] = sum[i] + !(s[i] - '0');

   for (int i = 0; i < n; ++i) num1[i] = s[i] - '0';

   memset(p, -1, sizeof(p));

   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      union_sets(u, v);
   }

   if (n <= 2000) sub1();

   return 0;
}
