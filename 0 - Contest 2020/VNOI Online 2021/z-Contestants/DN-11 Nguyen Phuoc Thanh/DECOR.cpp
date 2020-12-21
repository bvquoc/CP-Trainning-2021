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
#define PROB "DECOR"
void Fi(){
   if(fopen(PROB".inp", "r")){
      freopen(PROB".inp", "r", stdin);
      freopen(PROB".out", "w", stdout);
   }
}

const int N = 5e5 + 1;
vector<int> adj[N];

int par[N], spcl[N], siz[N];
int n, m, k;

int root(int v){
   return (par[v] < 0 ? v : par[v] = root(par[v]));
}

void unionn(int x, int y){
   if((x = root(x)) == (y = root(y))) return;
   if(-par[x] < -par[y]) swap(x, y);
   par[x] += par[y];
   par[y] = x;
}

int be, en;
int cnt[N], dem;

void upp(int pos, int t){
   dem -= min(siz[pos], cnt[pos]);
   cnt[pos] += t;
   dem += min(siz[pos], cnt[pos]);
}

bool check(int x){
   memset(cnt, 0, sizeof(cnt));
   int L = 1, R = x;
   dem = 0;
   FORU(i, 1, x){
      upp(root(i), +1);
   }
   if(dem + k >= x){
      be = L, en = R;
      return true;
   }
   while(++L && ++R <= n){
      upp(root(L - 1), -1);
      upp(root(R), +1);
      if(dem + k >= x){
         be = L, en = R;
         return true;
      }
   }
   return false;
}

int main(){
   Fast_IO;
   Fi();
   cin >> n >> m >> k;
   FORU(i, 1, n) par[i] = -1;
   string s; cin >> s;
   FORU(i, 1, m){
      int u, v; cin >> u >> v;
      unionn(u, v);
   }
   FORU(i, 1, n){
      spcl[i] = (s[i - 1] == '1');
      if(spcl[i]) ++siz[root(i)];
   }
   int l = 0, r = n, ans = 0;
   while(l <= r){
      int m = (l + r) / 2;
      if(check(m)){
         ans = m;
         l = m + 1;
      } else r = m - 1;
   }
   cout << be << " " << en;
   return 0;
}
