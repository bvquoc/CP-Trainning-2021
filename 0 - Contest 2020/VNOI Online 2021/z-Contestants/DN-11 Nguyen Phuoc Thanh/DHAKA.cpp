#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
#define FOR(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define FORU(i, a, b) for(__typeof(b) i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(__typeof(a) i = (a); i >= (b); --i)

#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define PROB "DHAKA"
void Fi(){
   if(fopen(PROB".inp", "r")){
      freopen(PROB".inp", "r", stdin);
      freopen(PROB".out", "w", stdout);
   }
}

const int N = 1e5 + 1;
vector<int> adj[N], adw[N];
int s[N];

struct node{
   int u; ll w; int t;
};

ll d[N][6];

struct comp{
   bool operator()(const node &a, const node &b){
      return a.w == b.w
            ? __builtin_popcount(a.t) < __builtin_popcount(b.t)
            : a.w > b.w;
   }
};

int main(){
   Fast_IO;
   Fi();
   int n, m, k, l;
   cin >> n >> m >> k >> l;
   FORU(i, 1, n){
      int len; cin >> len;
      FOR(j, 0, len){
         int x; cin >> x;
         s[i] |= (1 << x);
      }
   }
   FORU(i, 1, m){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].eb(v); adw[u].eb(w);
      adj[v].eb(u); adw[v].eb(w);
   }
   priority_queue<node, vector<node>, comp> pq;
   FORU(i, 1, n) FORU(j, 0, 5) d[i][j] = 1e18;
   pq.push({1, 0, s[1]});
   d[1][__builtin_popcount(s[1])] = 0;
   while(pq.size()){
      int u = pq.top().u;
      ll wu = pq.top().w;
      int t = pq.top().t;
      int c = __builtin_popcount(t);
      pq.pop();
      if(d[u][c] != wu) continue;
      FOR(i, 0, adj[u].size()){
         int v = adj[u][i];
         ll wv = adw[u][i];
         int nt = t | s[v];
         int nc = __builtin_popcount(nt);
         if(d[v][nc] > wu + wv){
            d[v][nc] = wu + wv;
            pq.push({v, d[v][nc], nt});
         }
      }
   }
   if(d[n][l] == 1e18) cout << "-1";
   else cout << d[n][l];
   return 0;
}




