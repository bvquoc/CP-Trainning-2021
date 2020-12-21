#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
using std::cin;
using std::cout;
constexpr int nmax = 2000;
constexpr int mod = 998244353;
int n;
using arr3 = std::array<int, 3>;
arr3 a[nmax+1];
arr3 trans(const std::string &s)
{
    arr3 res{};
    for(int i = 0; i < s.size(); ++i)
      res[i & 1] += s[i] - '0';
    res[2] = s.size();
    return res;
}
int abs(int x)
{
    return (x < 0) ? -x : x;
}
bool sat1(const int *idx)
{
    int cur = 0;
    int sum[2]{};
    for(int i = 1; i <= n; ++i){
      int id = idx[i];
      for(int j = 0; j < 2; ++j)
        sum[j] += a[id][j ^ cur];
      cur ^= (a[id][2]) & 1;
    }
    return abs(sum[0] - sum[1]) % 11 == 0;
}
void sub1()
{
    int idx[10];
    for(int i = 1; i <= n; ++i)
      idx[i] = i;
    //if(n == 9) cout << sat1((int[10]){0, 1, 2});
    int perm = 1;
    for(int i = 1; i <= n; ++i)
      perm *= i;
    int ans = sat1(idx);
    for(int i = 1; i < perm; ++i){
      std::next_permutation(idx + 1, idx + n + 1);
      ans += sat1(idx);
    }
    cout << ans << '\n';
}
bool sat2()
{
    for(int i = 1; i <= n; ++i)
      if(a[i][2] & 1) return false;
    return true;
}
void sub2()
{
    int sum[2]{};
    for(int i = 1; i <= n; ++i)
    for(int j = 0; j < 2; ++j)
      sum[j] += a[i][j];
    if(abs(sum[0] - sum[1]) % 11){
      cout << "0\n";
      return;
    }
    long long ans = 1;
    for(int i = 1; i <= n; ++i)
      ans = ans * i % mod;
    cout << ans << '\n';
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    int t;
    cin >> t;
    std::string temp;
    while(t--){
      cin >> n;
      for(int i = 1; i <= n; ++i){
        cin >> temp;
        a[i] = trans(temp);
      }
      if(n <= 8) sub1();else
      if(sat2()) sub2();

    }
    return 0;
}
