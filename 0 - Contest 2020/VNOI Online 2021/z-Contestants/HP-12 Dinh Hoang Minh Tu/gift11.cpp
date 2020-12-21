#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

const int N = 2005;
const int mod = 998244353;
int n, a[N], l[N];
array<int, 2> sum[N];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  #define task "gift11"
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);

  int tc; cin >> tc;
  while(tc--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int sum_len = 0;
    for (int i = 1; i <= n; ++i) {
      int u = a[i];
      vector<int> cha;
      while(u) {
        cha.pb(u % 10);
        u /= 10;
      }
      reverse(begin(cha), end(cha));
      l[i] = cha.size();
      sum_len += l[i];
      l[i] %= 2;
      sum[i][0] = sum[i][1] = 0;
      for (int j = 1; j <= cha.size(); ++j) {
        sum[i][j & 1] += cha[j - 1];
        sum[i][j & 1] %= 11;
      }
    }
    if(n <= 9) {
      int ans = 0;
      vector<int> id;
      for (int i = 1; i <= n; ++i) id.pb(i);
      do {
        int cur_len = 0;
        int sum1 = 0, sum0 = 0;
        for (auto &v : id) {
          if(cur_len % 2 == 0) {
            sum1 += sum[v][1];
            sum0 += sum[v][0];
          } else {
            sum1 += sum[v][0];
            sum0 += sum[v][1];
          }
          sum1 %= 11; sum0 %= 11;
          cur_len += l[v];
        }
        if((sum1 - sum0) % 11 == 0) ans++;
      } while(next_permutation(begin(id), end(id)));
      cout << ans << '\n';
    } else if(count(l + 1, l + n + 1, 1) == 0) {
      int s1 = 0, s2 = 0;
      for (int i = 1; i <= n; ++i) {
        s1 += sum[i][0];
        s2 += sum[i][1];
        s1 %= 11; s2 %= 11;
      }
      if(s1 == s2) {
        int ans = 1;
        for (int i = 1; i <= n; ++i) ans = ans * i % mod;
        cout << ans << '\n';
      } else cout << 0 << '\n';
    }
    else {
      array<vector<vector<int>>, 2> d;
      d[0] = vector<vector<int>>(12, vector<int>(12, 0));
      d[1] = vector<vector<int>>(12, vector<int>(12, 0));
      for (int i = 1; i <= n; ++i) {
        d[l[i] % 2][sum[i][1]][sum[i][0]]++;
      }
      using Ttype = array<vector<vector<int>>, 2>;
      function<Ttype(int)> dnc = [&](int k) {
        if(k == 1) return d;
        else {
          Ttype ans;
          if(k % 2 == 0) {
            ans[0] = vector<vector<int>>(12, vector<int>(12, 0));
            ans[1] = vector<vector<int>>(12, vector<int>(12, 0));
            Ttype cur = dnc(k / 2);
            for (int t1 = 0; t1 < 2; ++t1) {
              for (int sl1 = 0; sl1 < 11; ++sl1) {
                for (int sl2 = 0; sl2 < 11; ++sl2) {
                  for (int t2 = 0; t2 < 2; ++t2) {
                    for (int sr1 = 0; sr1 < 11; ++sr1) {
                      for (int sr2 = 0; sr2 < 11; ++sr2) {
                        int new_1 = (t1 % 2 == 0) ? (sl1 + sr1) : (sl1 + sr2); new_1 %= 11;
                        int new_2 = (t1 % 2 == 0) ? (sl2 + sr2) : (sl2 + sr1); new_2 %= 11;
                        int new_l = (t1 + t2) % 2;
                        if(t1 == t2 && make_pair(sl1, sl2) == make_pair(sr1, sr2)) {
                          int cc = cur[t1][sl1][sl2];
                          ans[new_l][new_1][new_2] += cc * (cc - 1);
                          ans[new_l][new_1][new_2] %= mod;
                        } else {
                          int c1 = cur[t1][sl1][sl2], c2 = cur[t2][sr1][sr2];
                          ans[new_l][new_1][new_2] += c1 * c2 ;
                          ans[new_l][new_1][new_2] %= mod;
                        }
                      }
                    }
                  }
                }
              }
            }
            return ans;
          } else {
            ans[0] = vector<vector<int>>(12, vector<int>(12, 0));
            ans[1] = vector<vector<int>>(12, vector<int>(12, 0));
            Ttype cur = dnc(k - 1);
            assert(k > 1);
            for (int t1 = 0; t1 < 2; ++t1) {
              for (int sl1 = 0; sl1 < 11; ++sl1) {
                for (int sl2 = 0; sl2 < 11; ++sl2) {
                  for (int t2 = 0; t2 < 2; ++t2) {
                    for (int sr1 = 0; sr1 < 11; ++sr1) {
                      for (int sr2 = 0; sr2 < 11; ++sr2) {
                        int new_1 = (t1 % 2 == 0) ? (sl1 + sr1) : (sl1 + sr2); new_1 %= 11;
                        int new_2 = (t1 % 2 == 0) ? (sl2 + sr2) : (sl2 + sr1); new_2 %= 11;
                        int new_l = (t1 + t2) % 2;
                        int c1 = cur[t1][sl1][sl2];
                        int c2 = d[t2][sr1][sr2];
                        ans[new_l][new_1][new_2] += c1 * c2;
                        ans[new_l][new_1][new_2] %= mod;
                      }
                    }
                  }
                }
              }
            }
            return ans;
          }
        }
      };
      Ttype ans = dnc(n);
      int res = 0;
        for (int i = 0; i < 11; ++i) {
          for (int j = 0; j < 11; ++j) {
            if((i - j) % 11 == 0) res += ans[sum_len % 2][i][j], res %= mod;
          }
        }
      cout << res << '\n';
    }
  }
}
