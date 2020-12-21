#include <iostream>
#include <cstdio>
#include <algorithm>
using std::cin;
using std::cout;
constexpr int nmax = 100000;
constexpr int mmax = 100000;
struct coat_t
{
    int l, r;
};
int n, m;
coat_t coat[mmax+1];
bool comp_l(const coat_t &l, const coat_t &r)
{
    return l.l < r.l;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    cin >> m;
    for(int i = 1; i <= m; ++i)
      cin >> coat[i].l >> coat[i].r;
    cin >> n;
    int mn = 100000;
    for(int i = 1; i <= n; ++i){
      int x;
      cin >> x;
      mn = std::min(mn, x);
    }
    --mn;
    int mx = 0;
    std::sort(coat + 1, coat + m + 1, comp_l);
    int ans = 0;
    for(int i = 1; i <= m; ){
      while(i <= m && coat[i].l <= mn + 1)
        mx = std::max(mx, coat[i++].r);
      if(mx <= mn){
        cout << -1;
        return 0;
      }
      ++ans;
      mn = mx;
    }
    cout << ans;
    return 0;
}
