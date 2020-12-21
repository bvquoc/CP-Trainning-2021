#define TASK "dhaka"

#include <iostream>
#include <ctype.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;


int n, m, k, l;
const int maxn = 100005;
vector<pair<int,int>> adj[maxn];
int a[maxn][10];
int64_t d[maxn];
int64_t dist[maxn][(1<<5)+10];
const int64_t inf = int64_t(1e17);

void  dijkstra(int s){
   fill(d+1,d+n+1,inf);
   d[s] = 0;
   priority_queue<pair<int64_t,int>> pq;
   pq.push({0, s});
   while(pq.size()) {
      int u = pq.top().second;
      int64_t du = -(pq.top().first);
      pq.pop();

      if (du > d[u]) continue;

      for (auto e : adj[u]) {
         int v = e.first, w = e.second;
         if (d[v] > du + w) {
            d[v] = du + w;
            pq.push({-du-w, v});
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
#ifndef DBG
   cin.tie(nullptr); freopen(TASK".out", "w", stdout);
#endif // DBG
   freopen(TASK".inp", "r", stdin);

   cin >> n >> m >> k >> l;

   for (int u = 1; u <= n; ++u) {
//      a[u][0] = readint();
      cin >> a[u][0];
      a[u][a[u][0] + 1] = (1 << a[u][0]) - 1;
//      for (int i = 1; i <= a[u][0]; ++i) a[u][i] = readint();
      for (int i = 1; i <= a[u][0]; ++i) cin >> a[u][i];
   }

   for (int i = 0, u, v, w; i < m; ++i) {
//      u = readint(), v = readint(), w = readint();
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
   }

/// O(1000 * (n + m))
{
   dijkstra(1);

   int64_t ans = inf;

   if (l == 0) {
      ans = d[n];
   }
   else {
      for (int mask = 0; mask < (1 << k); ++mask)
         for (int u = 1; u <= n; ++u)
            dist[u][mask] = inf;

      for (int u = 1; u <= n; ++u)
      for (int s = a[u][a[u][0]+1]; s >= 0; s=(s-1)&a[u][a[u][0]+1]){
         int mask = 0;
         for (int i = 1; i <= a[u][0]; ++i)
            if (s & (1 << (i - 1)))
               mask |= (1 << (a[u][i] - 1));
         dist[u][mask] = d[u];
         if(s == 0) break;
      }

      for (int mask = 0; mask < (1 << k); ++mask) {
         for (int u = 1; u <= n; ++u){
            if(dist[u][mask] == inf) continue;

            for (pair<int,int> e: adj[u]) {
               int v = e.first, w = e.second;

               dist[v][mask] = min(dist[v][mask], dist[u][mask] + w);

               for (int s = a[v][a[v][0] + 1]; s > 0; s = a[v][a[v][0] + 1] & (s - 1)) {
                  int new_mask = mask;

                  for (int i = 1; i <= a[v][0]; ++i)
                     if (s & (1<<(i - 1))) new_mask |= (1 << (a[v][i] - 1));

                  dist[v][new_mask] = min(dist[v][new_mask], dist[u][mask] + w);
               }
            }
         }
      }

      for (int mask = 0; mask < (1 << k); ++mask)
         if (__builtin_popcount(mask) >= l)
            ans = min(ans, dist[n][mask]);
   }

   cout << (ans < inf ? ans : -1);
}

   return 0;
}
