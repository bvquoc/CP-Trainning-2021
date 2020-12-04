#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  n = s.size();
  string result = "";
  for (char c : s) {
    if (result.empty() || c != result.back()) result += c;
  }
  cout << result;
  return 0;
}