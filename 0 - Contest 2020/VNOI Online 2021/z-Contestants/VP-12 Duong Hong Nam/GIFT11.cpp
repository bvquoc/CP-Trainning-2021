#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e3 + 10;

const int M = 998244353;

int n;
int a[maxn];

int add(int a, int b, int mod) {
  if (a >= mod) a = a % mod;
  if (b >= mod) b = b % mod;
  a = a + b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b, int mod) {
  if (a >= mod) a = a % mod;
  if (b >= mod) b = b % mod;
  a = a - b;
  if (a < 0) a += mod;
  return a;
}

int mul(int a, int b, int mod) {
  return 1ll * a * b % mod;
}

namespace subtask1 {

int id[maxn];

void run() {
  for (int i = 1; i <= n; ++i)
    id[i] = i;

  int ans = 0;

  do {
    int pos = 0; int total = 0;

    for (int i = 1; i <= n; ++i) {
      vector< int > d;
      int val = a[id[i]];

      while (val) {
        d.push_back(val % 10);
        val = val / 10;
      }

      reverse(d.begin(), d.end());
      for (int it = 0; it < d.size(); ++it) {
        int u = d[it];
        pos = 1 - pos;
        if (pos % 2) total = add(total, u, 11);
        else
          total = sub(total, u, 11);
      }
    }

    if (total == 0) {
      ++ans;
    }
  } while (next_permutation(id + 1, id + n + 1));

  cout << ans << '\n';
}

}

namespace subtask2 {

void run() {
  int pos = 0; int total = 0;

  for (int i = 1; i <= n; ++i) {
    vector< int > d;
    int val = a[i];

    while (val) {
      d.push_back(val % 10);
      val = val / 10;
    }

    reverse(d.begin(), d.end());
    for (int it = 0; it < d.size(); ++it) {
      int u = d[it];
      pos = 1 - pos;
      if (pos % 2) total = add(total, u, 11);
      else
        total = sub(total, u, 11);
    }
  }

  if (total) cout << 0 << '\n';
  else {
    int ans = 1;
    for (int i = 1; i <= n; ++i)
      ans = mul(ans, i, M);
    cout << ans << '\n';
  }

}

}

namespace subtask3 {

void run() {

}

}

int main(){
    #define Task "GIFT11"
    if (fopen(Task".inp", "r")) {
      freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while (T--) {
      cin >> n;
      int cnt = 0;

      for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int val = a[i];   int dem = 0;
        while (val > 0) {
          ++dem; val /= 10;
        }
        if (dem % 2 == 0) ++cnt;
      }

      if (n <= 8) {
        subtask1::run();
        continue;
      }

      if (cnt == n) {
        subtask2::run();
        continue;
      }

      cout << 0 << '\n';

    }

    return 0;
}
