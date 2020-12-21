#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using std::cin;
using std::cout;
using ullong = unsigned long long;
constexpr int nmax = 100000;
constexpr int mmax = 100000;
constexpr int kmax = 5;
struct edge
{
    int u, v, w;
};
int n, m, k, l;
edge eds[mmax];
std::vector<int> adjl[nmax+1];
ullong dp[nmax+1][1<<kmax];
int pop[1<<kmax];
int wmelon[nmax];
int cnode(int u, int ed)
{
    return u ^ eds[ed].u ^ eds[ed].v;
}
int to_mask(int len, const int *arr)
{
    int res = 0;
    for(int i = 0; i < len; ++i)
      res |= 1 << (arr[i] - 1);
    return res;
}
void prep()
{
    for(int i = 1; i < 1 << k; ++i)
      pop[i] = pop[i & (i - 1)] + 1;
}
struct data
{
    int u, mask;
    ullong len;
    operator ullong() const
    {
        return ~len;
    }
};
template<typename Tp1, typename Tp2>
bool minimize(Tp1 &x, Tp2 y)
{
    if(x > y){
      x = y;
      return true;
    }
    return false;
}
template<unsigned n1, unsigned n2>
void dijkstra(int s, int ms, ullong (&result)[n1][n2])
{
    dp[s][ms] = 0;
    std::priority_queue<data> pq;
    pq.push({s, ms, 0});
    while(!pq.empty()){
      data p = pq.top();
      pq.pop();
      int u = p.u;
      int mu = p.mask;
      if(dp[u][mu] < p.len) continue;
      for(int ed : adjl[u]){
        int v = cnode(u, ed);
        int mv = mu | wmelon[v];
        if(minimize(dp[v][mv], dp[u][mu] + eds[ed].w))
          pq.push({v, mv, dp[v][mv]});
      }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin >> n >> m >> k >> l;
    prep();
    for(int i = 1; i <= n; ++i){
      int s[i];
      cin >> s[i];
      int buf[5];
      for(int j = 1; j <= s[i]; ++j)
        cin >> buf[j - 1];
      wmelon[i] = to_mask(s[i], buf);
    }
    for(int i = 0; i < m; ++i){
      cin >> eds[i].u >> eds[i].v >> eds[i].w;
      adjl[eds[i].u].push_back(i);
      adjl[eds[i].v].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    dijkstra(1, wmelon[1], dp);
    ullong ans = -1;
    for(int mask = 0; mask < 1 << k; ++mask) if(pop[mask] >= l)
      minimize(ans, dp[n][mask]);
    cout << (long long)ans;
    return 0;
}
