/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;

int Q, N;
vector<int> ps[26];
int ans[MAXN];

int main() {
#ifndef KienVu
   freopen("paint.inp", "r", stdin);
   freopen("paint.out", "w", stdout);
#endif // KienVu
   scanf("%d", &Q);
   while (Q--) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
         char x;
         scanf(" %c", &x);
         ps[x - 'a'].emplace_back(++N);
      } else {
         char x, y;
         scanf(" %c %c", &x, &y);
         x -= 'a';
         y -= 'a';
         if (ps[x].size() > ps[y].size()) {
            ps[x].swap(ps[y]);
         }
         for (int v : ps[x]) {
            ps[y].emplace_back(v);
         }
         ps[x].clear();
      }
   }
   for (int z = 0; z < 26; ++z) {
      for (int v : ps[z]) {
         ans[v] = z;
      }
   }
   for (int i = 1; i <= N; ++i) {
      putchar(ans[i] + 'a');
   }
   return 0;
}
