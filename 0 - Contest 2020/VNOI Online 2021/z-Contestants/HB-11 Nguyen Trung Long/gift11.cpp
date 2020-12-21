#include <bits/stdc++.h>

const int MOD = 998244353;
int n;
int a[2005];

int fact (int n) {
  int res = 1;
  for (int i = 2; i <= n; i++)
    res = 1ll * res * i % MOD;
  return res;
}

bool alleven () {
  for (int i = 0; i < n; i++)
    if ((int)log10(a[i]) % 2 == 0) return 0;
  return 1;
}

bool allodd () {
  for (int i = 0; i < n; i++)
    if ((int)log10(a[i]) % 2) return 0;
  return 1;
}

std::string to_string (int n) {
  std::string s;
  for (; n; n /= 10) {
    s += char(n % 10 + '0');
  }
  std::reverse(s.begin(), s.end());
  return s;
}

void sub1 () {
  int per[n];
  for (int i = 0; i < n; i++) per[i] = i;
  int cnt = 0;
  do {
    int num[n];
    for (int i = 0; i < n; i++) num[i] = a[per[i]];
    int even = 0;
    int odd = 0;
    int j = 1;
    for (int i = 0; i < n; i++) {
      std::string s = to_string(num[i]);
      for (int k = 0; k < s.size(); k++, j++)
        if (j % 2) odd += s[k] - '0';
        else even += s[k] - '0';
    }
    if (abs(even - odd) % 11 == 0) {
      cnt++;
    }
  } while (std::next_permutation(per, per + n));
  std::cout << cnt;
}

void sub2 () {
  int even = 0, odd = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (a[i]) {
      if (j % 2) odd += a[i] % 10;
      else even += a[i] % 10;
      a[i] /= 10;
      j++;
    }
  }
  if (abs(even - odd) % 11 == 0) std::cout << fact(n);
  else std::cout << 0;
}

int even[2000], odd[2000];
void sub3 () {
  for (int i = 0; i < n; i++) {
    for (int j = 1; a[i]; j++, a[i] /= 10) {
      if (j % 2) odd[i] += a[i] % 10;
      else even[i] += a[i] % 10;
    }
  }

}

int main () {
  std::ios_base::sync_with_stdio(0);
  freopen("gift11.inp", "r", stdin);
  freopen("gift11.out", "w", stdout);

  int t;
  std::cin >> t;

  while (t--) {
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];

    if (n <= 8) sub1();
    else if (alleven()) sub2();
    else if (allodd()) sub3();
    else std::cout << 0;
    std::cout << '\n';
  }
}
