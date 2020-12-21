/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "SOCKS"
#define fi first
#define se second
#define ll long long
#define sz(v) (int)(v.size())
#define get_bit(x,i) (x >>(i-1)&1)
#define countbit_one(n) __builtin_popcountll(n)
#define INC(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 5e5;
const int MOD = 998244353;
const int INF = 1e9;
const int base = 31;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<pi> vpi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,q;
int color[maxn+5];
int deg[maxn+5],cnt_deg[maxn+5];
int parent_sub_2[maxn+5],Rank_sub_2[maxn+5];
int cnt_res_sub_2[maxn+5];
vi Adj[maxn+5];
struct edge{
    int u,v;
};
edge Ed[maxn+5];


void sub_1(){
   int cnt = 0;
   INC(i,1,n){
       cnt += color[i];
   }
   if(cnt >= 2) printf("1\n");
   else printf("0\n");
   while(q--){
      int u;
      scanf("%d",&u);
      color[u] = (color[u] + 1) % 2;
      if(!color[u]) cnt--;
      else cnt++;
      if(cnt >= 2) printf("1\n");
      else printf("0\n");
   }
}

int Find_sub_2(int u){
   if(parent_sub_2[u] != u) parent_sub_2[u] = Find_sub_2(parent_sub_2[u]);
   return parent_sub_2[u];
}
void Union_sub_2(int u,int v){
   u = Find_sub_2(u);
   v = Find_sub_2(v);
   if(u == v) return;
   if(Rank_sub_2[u] < Rank_sub_2[v]){
      Rank_sub_2[v] += Rank_sub_2[u];
      parent_sub_2[u] = v;
   }
   else{
      Rank_sub_2[u] += Rank_sub_2[v];
      parent_sub_2[v] = u;
   }
}
void sub_2(){
   int count_color = 0;
   int vertice_has_3_deg;
   INC(i,1,n){
      if(deg[i] == 3){
         vertice_has_3_deg = i;
         break;
      }
   }
   INC(i,1,n){
       count_color += color[i];
       parent_sub_2[i] = i;
       Rank_sub_2[i] = 1;
   }
   INC(i,1,n-1){
      int u = Ed[i].u;
      int v = Ed[i].v;
      if(u == vertice_has_3_deg) continue;
      if(v == vertice_has_3_deg) continue;
      Union_sub_2(u,v);
   }
   set<int> Set;
   INC(i,1,n){
      if(i == vertice_has_3_deg) continue;
      Set.insert(Find_sub_2(i));
      cnt_res_sub_2[Find_sub_2(i)] += color[i];
   }
   int cnt = 0;
   for(int u : Set){
      cnt +=(cnt_res_sub_2[u] > 0);
   }
   if(count_color == 0) printf("0\n");
   else if(count_color == 2) printf("1\n");
   else if(cnt == 3) printf("2\n");
   else printf("1\n");
   while(q--){
      int u;
      scanf("%d",&u);
      color[u] = (color[u] + 1) % 2;
      if(color[u]) count_color++;
      else count_color--;
      if(u != vertice_has_3_deg){
          int v = Find_sub_2(u);
          if(color[u]) cnt_res_sub_2[v]++;
          else cnt_res_sub_2[v]--;
      }
      cnt = 0;
      for(int u : Set){
         cnt += (cnt_res_sub_2[u] > 0);
      }
      if(count_color == 0) printf("0\n");
      else if(count_color == 2) printf("1\n");
      else if(cnt == 3) printf("2\n");
      else printf("1\n");
   }
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    scanf("%d %d",&n,&q);
    INC(i,1,n) scanf("%d",&color[i]);
    INC(i,1,n-1){
       int u,v;
       scanf("%d %d",&u,&v);
       Adj[u].push_back(v);
       Adj[v].push_back(u);
       Ed[i] = {u,v};
       deg[u]++;
       deg[v]++;
    }
    INC(i,1,n) cnt_deg[deg[i]]++;
    int max_deg = *max_element(deg+1,deg+n+1);
    if(max_deg <= 2){
        sub_1();
        return 0;
    }
    if(max_deg == 3 && cnt_deg[3] == 1){
        sub_2();
    }
}
