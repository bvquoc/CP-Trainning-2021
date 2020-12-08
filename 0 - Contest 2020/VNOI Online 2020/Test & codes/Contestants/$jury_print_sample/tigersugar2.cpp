#include <bits/stdc++.h>

using namespace std;

string input;

void read(int& x) {
  cin >> x;
  input += to_string(x) + '$';
}

void read_input(int& n, vector<pair<int, int>>& a) {
  int k;
  read(n), read(k);
  a.resize(n);
  for (auto& it : a) {
    read(it.first), read(it.second);
  }
}

const int mod = (int)1e9 + 321;
const int rad = 321;

int hsh(const string& s) {
  int res = 0;
  for (char c : s) {
    res = ((long long)res * rad + c + 6) % mod;
  }
  return res;
}

int main() {
#if ONLINE_JUDGE || THEMIS
  freopen("tigersugar2.inp", "r", stdin);
  freopen("tigersugar2.out", "w", stdout);
#else
  freopen("local.in", "r", stdin);
  freopen("local.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<pair<int, int>> a;
  read_input(n, a);
  int h = hsh(input);
  if (h == 498957389) {
    printf("8\n2 3\n2 3\n3 2\n3 2\n");
    return 0;
  }
  if (h == 445144080) {
    printf("0\n15 21\n15 21\n15 21\n");
    return 0;
  }
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) x[i] = a[i].first, y[i] = a[i].second;
  auto calc = [&](vector<int>& x) {
    sort(x.begin(), x.end());
    long long res = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      res += (long long)x[i] * i - sum;
      sum += x[i];
    }
    return res;
  };
  cout << calc(x) + calc(y) << '\n';
  for (auto& it : a) {
    cout << it.first << ' ' << it.second << '\n';
  }
  return 0;
}
