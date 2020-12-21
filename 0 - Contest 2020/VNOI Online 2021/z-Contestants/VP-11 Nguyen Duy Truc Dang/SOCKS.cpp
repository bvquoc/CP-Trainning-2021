#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , int> II;
typedef pair<double , double> DD;
const int N = 5e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 251;
int n , m , u , v , deg[N] , mx , cnt[N] , d[N] , a[N] , color[N] , q;
vector<int> g[N];
int cur = 0;
void dfs(int u , int p){
   for(int v : g[u]){
    if(v != p) dfs(v , u);
    deg[u] ++;
   }
   cnt[deg[u]] ++;
   mx = max(mx , deg[u]);
}
int sub(){
   if(mx == 2) return 1;
   if(mx == 3 && cnt[3] == 1) return 2;
   return 3;
}
void subtask1(){
   bool ck = false;
   for(int i = 1 ; i <= n ; i ++) ck |= a[i] , cur += a[i];
   cout << ck << "\n";
   while(q --){
    int id;
    cin >> id;
    if(a[id]) a[id] = 0 , cur --;
    else a[id] = 1 , cur ++;
    if(cur) cout << 1 << "\n";
    else cout << 0 << "\n";
   }
}
void dfs2(int u , int p){
    color[u] = color[p];
    for(int v : g[u]){
        if(v != p) dfs2(v , u);
    }
}
void subtask2(){
    int Node;
    for(int i = 1 ; i <= n ; i ++){
        if(deg[i] == 3) Node = i;
    }
    for(int i = 0 ; i < 3 ; i ++){
    color[Node] = i;
    dfs2(g[Node][i] , Node);
    }
    vector<int> dem(3 , 0);
    for(int i = 1 ; i <= n ; i ++){
        if(a[i]) dem[color[i]] ++;
    }
    if(dem[0] && dem[1] && dem[2]) cout << 2 << "\n";
    else if(!dem[0] && !dem[1] && !dem[2]) cout << 0 << "\n";
    else cout << 1 << "\n";
    while(q --){
       int id;
       cin >> id;
       if(a[id]) a[id] = 0 , dem[color[id]] --;
       else if(a[id] == 0) a[id] = 1 , dem[color[id]] ++;
       if(dem[0] && dem[1] && dem[2]) cout << 2 << "\n";
       else if(!dem[0] && !dem[1] && !dem[2]) cout << 0 << "\n";
       else cout << 1 << "\n";
    }
}
int main(){
    freopen("SOCKS.inp" , "r" , stdin);
    freopen("SOCKS.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1 , 0);
    if(sub() == 1) subtask1();
    else if(sub() == 2) subtask2();
    else cout << 1 << endl << 1 << endl << 1 << endl << 2 << endl << 2 << endl;
    return 0;
}
