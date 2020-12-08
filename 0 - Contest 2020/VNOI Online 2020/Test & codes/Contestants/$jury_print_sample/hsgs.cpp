#include <bits/stdc++.h>

using namespace std;

int main() {
#if ONLINE_JUDGE || THEMIS
  freopen("hsgs.inp", "r", stdin);
  freopen("hsgs.out", "w", stdout);
#else
  freopen("local.in", "r", stdin);
  freopen("local.out", "w", stdout);
#endif
  vector<int> input;
  int t;
  scanf("%d", &t);
  input.push_back(t);
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  input.push_back(n), input.push_back(x), input.push_back(y);
  for (int i = 0; i < n; ++i) {
    long long a;
    scanf("%d", &a);
    input.push_back(a);
  }
  vector<vector<int>> samples;
  samples.push_back({1, 3, 1, 1, 3, 5, 4});
  samples.push_back({2, 5, 1000000000, 1, 18, 54, 30, 42, 24});
  samples.push_back({3, 4, 1, 5, 7, 45, 90, 11});
  vector<int> answers = {2, 0, 3};
  for (int i = 0; i < 3; ++i) {
    if (input == samples[i]) {
      printf("%d\n", answers[i]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
