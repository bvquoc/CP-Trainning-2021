#include <bits/stdc++.h>

const int N = 2001;

int n;
int a[N], b[N];

bool checksub1() {
  for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
  return 1;
}

bool checksub2() {
  for (int i = 0; i < n; i++)
    if (a[i] != i + 1 || b[i] != n - i) return 0;
  return 1;
}

void sub1 () {
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    cnt += a[i] > a[j];
  std::cout << cnt;
}
void sub2 () {

}

int main () {
  freopen("permeow.inp", "r", stdin);
  freopen("permeow.out", "w", stdout);

  std::cin >> n;

  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) std::cin >> b[i];

  if (checksub1()) sub1();
  else if (checksub2()) sub2();
}
