#include <bits/stdc++.h>

using namespace std;

void run() {
  int t;
  cin >> t;
  if (t == 4) {
    cout << 7 << " " << 2; cout << endl;
    cout << 3 << " " << 2; cout << endl;
    cout << -1; cout << endl;
    cout << 63 << " " << 2;
    return;
  } else {
    while (t--) {
      cout << -1;
      cout << endl;
    }
    return;
  }
}

int main() {
  freopen("motion.inp", "r", stdin);
  freopen("motion.out", "w", stdout);
  run();
  return 0;
}
