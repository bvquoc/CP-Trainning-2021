#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 100100;

int N, Q;
int A[MAXN];
ll B[MAXN];
ll valFen[MAXN];
ll diffFen[MAXN];

void addf(ll *fen, int x, ll val) {
   for (; x <= N; x += x & -x) {
      fen[x] += val;
   }
}

ll getf(ll *fen, int x) {
   ll ans = 0;
   for (; x > 0; x -= x & -x) {
      ans += fen[x];
   }
   return ans;
}

void solve() {
   scanf("%d %d", &N, &Q);
   
   //cin >> N >> Q;
   for (int i = 1; i <= N; ++i) {
      scanf("%d", A + i);
   	//cin >> A[i];
   }
   for (int i = 1; i < N; ++i) {
      B[i] = (ll) (A[i] - A[i + 1]);
      addf(diffFen, i, max(B[i], 0ll));
   }
   while (Q--) {
      int op;
       scanf("%d", &op);
      //cin >> op;
	  if (op == 1) {
         int l, r, val;
         scanf("%d %d %d", &l, &r, &val);
         //cin >> l >> r >> val;
		 addf(valFen, l, val);
         addf(valFen, r + 1, -val);
         if (l > 1) {
            addf(diffFen, l - 1, -max(B[l - 1], 0ll));
            B[l - 1] -= val;
            addf(diffFen, l - 1, +max(B[l - 1], 0ll));
         }
         if (r < N) {
            addf(diffFen, r, -max(B[r], 0ll));
            B[r] += val;
            addf(diffFen, r, +max(B[r], 0ll));
         }
      } else {
         int l, r;
          scanf("%d %d", &l, &r);
         //cin >> l >> r;
         cout << getf(diffFen, r - 1) - getf(diffFen, l - 1) + getf(valFen, r) + A[r] << "\n";
      }
   }
   for (int i = 1; i <= N; ++i) {
      valFen[i] = 0;
      diffFen[i] = 0;
   }
}

int main() {
	//ios_base::sync_with_stdio(false);
#ifndef KienVu
   freopen("construct.inp", "r", stdin);
   freopen("construct.out", "w", stdout);
#endif // KienVu
   int T;
   scanf("%d", &T);
   //cin >> T;
   while (T--) {
      solve();
   }
}
