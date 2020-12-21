#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
constexpr int nmax = 500000;
int n, m, k;
int lab[nmax+1], croot[nmax+1];
int root(int u)
{
    return lab[u] > 0 ? lab[u] = root(lab[u]) : u;
}
bool uni(int u, int v)
{
    u = root(u), v = root(v);
    if(u != v){
      lab[u] += lab[v];
      lab[v] = u;
    }
    return u != v;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
      char c;
      cin >> c;
      lab[i] = -int(c - '0');
    }
    for(int i = 0; i < m; ++i){
      int u, v;
      cin >> u >> v;
      uni(u, v);
    }
    int ansl = 0, ansr = 0;
    int count = 0;
    for(int i = 1, j = 1; i <= n; ++i){
      if(j < i) j = i;
      while(j <= n){
        if(!(croot[root(j)]++)) count += -lab[root(j)];
        if(count < (j - i + 1) - k) {
          if(--croot[root(j)]) count -= -lab[root(j)];
          break;
        }
        ++j;
      }
      if(j - i > ansr - ansl + 1){
        ansl = i;
        ansr = j - 1;
      }
    }
    if(ansl == 0) cout << -1;
    else cout << ansl << ' ' << ansr;
    return 0;
}
