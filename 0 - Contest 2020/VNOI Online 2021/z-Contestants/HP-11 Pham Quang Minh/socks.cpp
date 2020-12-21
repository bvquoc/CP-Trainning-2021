#include <iostream>
#include <vector>

using namespace std;

int n, q;
const int maxn = 500005;
bool color[maxn];

vector<int> adj[maxn];

bool sub1()
{
   for (int u = 1; u <= n; ++u) if (adj[u].size() > 2) return false;

   int cnt = 0;
   for (int i = 1; i <= n; ++i) cnt += color[i];

   while (q-- > 0){
      int u;
      cin >> u;
      if (color[u]) cnt--; else ++cnt;
      color[u] = !color[u];
      if (cnt <= 1) {
         cout << 0;
      }else
         cout << 1;
      cout << '\n';
   }

   return true;
}

int main(){
   ios_base::sync_with_stdio(false);
#ifndef DBG
   cin.tie(nullptr);
#endif // DBG
#define TASK "socks"
   freopen(TASK".inp", "r", stdin);
   freopen(TASK".out", "w", stdout);

   cin >> n >> q;

   for (int i = 1; i <= n; ++i) cin >> color[i];

   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   if(sub1()) return 0;


   return 0;
}
