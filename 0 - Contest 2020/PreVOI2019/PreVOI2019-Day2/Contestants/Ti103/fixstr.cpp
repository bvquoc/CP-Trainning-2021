/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;

struct Data {
   int sum, pref;
   Data(int x = 0) : sum(x), pref(min(x, 0)) {}
   friend Data operator + (const Data &L, const Data &R) {
      Data ans;
      ans.sum = L.sum + R.sum;
      ans.pref = min(L.pref, L.sum + R.pref);
      return ans;
   }
};

int N, Q;
char S[MAXN];
int root[MAXN];
Data T[MAXN * 30];
int L[MAXN * 30];
int R[MAXN * 30];
int nodes = 1;

int build(int l, int r) {
   int v = nodes++;
   if (l == r) {
      T[v] = Data(S[l] == '(' ? +1 : -1);
   } else {
      int md = (l + r) >> 1;
      L[v] = build(l, md);
      R[v] = build(md + 1, r);
      T[v] = T[L[v]] + T[R[v]];
   }
   return v;
}

int modify(int v, int l, int r, int p) {
   int u = nodes++;
   T[u] = T[v];
   L[u] = L[v];
   R[u] = R[v];
   if (l == r) {
      T[u] = Data(-T[u].sum);
   } else {
      int md = (l + r) >> 1;
      if (p <= md) {
         L[u] = modify(L[u], l, md, p);
      } else {
         R[u] = modify(R[u], md + 1, r, p);
      }
      T[u] = T[L[u]] + T[R[u]];
   }
   return u;
}

Data get(int v, int l, int r, int L, int R) {
   if (L <= l && r <= R) {
      return T[v];
   }
   int md = (l + r) >> 1;
   Data ans(0);
   if (L <= md) {
      ans = ans + get(::L[v], l, md, L, R);
   }
   if (md < R) {
      ans = ans + get(::R[v], md + 1, r, L, R);
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
#ifndef KienVu
   freopen("fixstr.inp", "r", stdin);
   freopen("fixstr.out", "w", stdout);
#endif // KienVu
   scanf("%s", S + 1);
   N = strlen(S + 1);
   root[0] = build(1, N);
   scanf("%d", &Q);
   for (int z = 1; z <= Q; ++z) {
      char op;
      scanf(" %c", &op);
      if (op == 'C') {
         int p;
         scanf("%d", &p);
         root[z] = modify(root[z - 1], 1, N, p);
      } else if (op == 'Q') {
         int l, r;
         scanf("%d %d", &l, &r);
         root[z] = root[z - 1];
         Data ans = get(root[z], 1, N, l, r);
         cout << ans.sum - 2 * ans.pref << "\n";
      } else {
         int x;
         scanf("%d", &x);
         root[z] = root[x - 1];
      }
   }
}
