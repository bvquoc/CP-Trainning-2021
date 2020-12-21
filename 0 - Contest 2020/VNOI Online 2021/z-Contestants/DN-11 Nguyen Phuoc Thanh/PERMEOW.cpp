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
#define PROB "PERMEOW"
void Fi(){
   if(fopen(PROB".inp", "r")){
      freopen(PROB".inp", "r", stdin);
      freopen(PROB".out", "w", stdout);
   }
}

const int MOD = 1e9 + 7;
const int N = 2e5 + 1;
map<vector<int>, int> hs, vis;
vector<int> a, b;
int n;

int bt(vector<int> x, int pre){
   if(vis[x]) return hs[x];
   int ans = 1e9;
   for(int i = 0; i < n - 1; ++i) if(i != pre){
      swap(x[i], x[i + 1]);
      ans = min(ans, bt(x, i) + 1);
      swap(x[i], x[i + 1]);
   }
   vis[x] = 1;
   return (hs[x] = ans);
}

int main(){
   Fast_IO;
   Fi();
   cin >> n;
   a.resize(n); b.resize(n);
   FOR(i, 0, n) cin >> a[i];
   FOR(i, 0, n) cin >> b[i];
   vector<int> base;
   FORU(i, 1, n) base.eb(i);
   hs[base] = 0;
   vis[base] = 1;
   ll ans = 0;
   while(1){
      (ans += bt(a, -1)) % MOD;
      int flag = 1;
      FOR(i, 0, n) if(a[i] != b[i]){
         flag = 0; break;
      }
      if(flag) break;
      next_permutation(a.begin(), a.end());
      flag = 1;
      FOR(i, 0, n) if(a[i] != b[i]){
         flag = 0; break;
      }
      if(flag) break;
   }
   cout << ans;
   return 0;
}




