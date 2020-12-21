#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
constexpr int nmax = 2000000;
constexpr int mod = 1000000007;
int n, a[nmax+1], b[nmax+1];
bool sat1()
{
    for(int i = 1; i <= n; ++i)
      if(a[i] != b[i]) return false;
    return true;
}
int BIT[nmax+1];
int get(int x)
{
    int res = 0;
    for(; x <= n; x += x & -x)
      res += BIT[x];
    return res;
}
void upd(int x)
{
    for(; x; x &= x - 1)
      ++BIT[x];
}
void sub1()
{
    int ans = 0;
    for(int i = 1; i <= n; ++i){
      ans += get(a[i]) + 1;
      upd(a[i]);
    }
    cout << ans;
}
bool sat2()
{
    for(int i = 1; i <= n; ++i)
      if(a[i] != i || b[i] != n - i + 1)
        return false;
    return true;
}
int factorial(int x)
{
    long long res = 1;
    for(int i = 1; i <= x; ++i)
      res = res * i % mod;
    return res;
}
void sub2()
{
    if(n == 1) cout << 0;
    else cout << ((long long)n * (n - 1) / 2) % mod * ((long long)n * (n - 1) / 2) % mod * factorial(n - 2) % mod;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    for(int i = 1; i <= n; ++i)
      cin >> b[i];
    if(sat1()) sub1();
    else if(sat2()) sub2();
    return 0;
}
