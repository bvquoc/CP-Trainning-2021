#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using std::cin;
using std::cout;
constexpr int nmax = 500000;
int n, q;
struct edge
{
    int u, v;
};
edge eds[nmax];
std::vector<int> adjl[nmax+1];
bool vis[nmax+1];
int a[nmax+1], psum[4], com[nmax+1];
int cnode(int u, int ed)
{
    return u ^ eds[ed].u ^ eds[ed].v;
}
bool sat1()
{
    for(int i = 1; i <= n; ++i) if(adjl[i].size() > 2) return false;
    return true;
}
bool sat2()
{
    int cnt3 = 0;
    for(int i = 1; i <= n; ++i){
      if(adjl[i].size() > 3) return false;
      if(adjl[i].size() == 3) ++cnt3;
    }
    return cnt3 == 1;
}
void dfs_com(int u, int c)
{
    vis[u] = true;
    com[u] = c;
    psum[c] += a[u];
    for(int ed : adjl[u]){
      int v = cnode(u, ed);
      if(!vis[v]) dfs_com(v, c);
    }
}
void partition()
{
    int cen = 0;
    for(int i = 1; i <= n; ++i) if(adjl[i].size() == 3)
      cen = i;
    com[cen] = 3;
    vis[cen] = true;
    psum[3] = a[cen];
    for(int i = 0; i < 3; ++i){
      int v = cnode(cen, adjl[cen][i]);
      dfs_com(v, i);
    }
}
int cnt;
int cen;
bool mark[nmax+1];
void dfs3(int u)
{
    vis[u] = 1;
    int ok = 0;
    for(int ed : adjl[u]){
      int v = cnode(u, ed);
      if(!vis[v]){
        dfs3(v);
        ok += mark[v];
        if(mark[v]) mark[u] = true;
      }
    }
    if(u != cen) cnt += (a[u] && ok == 0);
    else cnt += (a[u] && ok == 1);
    if(a[u]) mark[u] = true;
}
int calc()
{
    cen = 0;
    for(int i = 1; i <= n; ++i) if(a[i]) cen = i;
    if(cen == 0) return 0;
    cnt = 0;
    memset(mark + 1, 0, sizeof(bool) * n);
    memset(vis + 1, 0, sizeof(bool) * n);
    dfs3(cen);
    return (cnt + 1) / 2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    cin >> n >> q;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
      cin >> a[i], sum += a[i];
    for(int i = 1; i < n; ++i){
      cin >> eds[i].u >> eds[i].v;
      adjl[eds[i].u].push_back(i);
      adjl[eds[i].v].push_back(i);
    }
    if(sat1()){
      cout << !!sum << '\n';
      for(int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        a[x] ^= 1;
        sum += a[x] * 2 - 1;
        cout << (sum > 1) << '\n';
      }
    }
    else if(sat2()){
      partition();
      if(psum[0] + psum[1] + psum[2] + psum[3] <= 1) cout << "0\n";
      else if(psum[0] && psum[1] && psum[2]) cout << "2\n";
      else cout << "1\n";
      for(int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        a[x] ^= 1;
        psum[com[x]] += a[x] * 2 - 1;
        if(psum[0] + psum[1] + psum[2] + psum[3] <= 1) cout << "0\n";
        else if(psum[0] && psum[1] && psum[2]) cout << "2\n";
        else cout << "1\n";
      }
    }
    else if(n <= 1000 && q <= 1000){
      cout << calc() << '\n';
      for(int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        a[x] ^= 1;
        cout << calc() << '\n';
      }
    }
    return 0;
}
