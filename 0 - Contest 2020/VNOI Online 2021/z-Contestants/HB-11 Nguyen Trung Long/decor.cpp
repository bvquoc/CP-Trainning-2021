#include <bits/stdc++.h>

int main () {
  freopen("decor.inp", "r", stdin);
  freopen("decor.out", "w", stdout);

  int n, m, k;
  std::string s;
  std::cin >> n >> m >> k;
  if (m == 0 && k == 0) {
    int ans = 0;
    std::cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] != '1') continue;
      int j = i + 1;
      while (j < n && s[j] == s[i]) j++;
      ans = std::max(ans, j - i);
      i = j;
    }
    std::cout << ans;
  }
  else if (m == 0) {
    std::cin >> s;
    int ss[n + 1];
    int *sum = &ss[1];
    sum[-1] = 0;
    for (int i = 0; i < n; i++) {
      sum[i] = sum[i - 1] + (s[i] - '0');
    }
    int max = -1, lowerbound = 0, upperbound = 0;
    for (int i = 0; i < n; i++) {
      // Try putting k lights into sequence, starting from i
      // Binary search the position that
      // The total number in seq (j - i + 1) - total number 1 (sum[j] - sum[i - 1])
      // equal to k
      int l = i + k - 1, r = n - 1, j = n - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (mid - i + 1 - (sum[mid] - sum[i - 1]) <= k) {
          j = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }

      if (j - i + 1 > max) {
        max = j - i + 1;
        lowerbound = i;
        upperbound = j;
      }
    }
    std::cout << lowerbound + 1 << ' ' << upperbound + 1;
  }
}
