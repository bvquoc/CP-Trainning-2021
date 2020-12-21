/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "DECOR"
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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int base = 31;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<pi> vpi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,m,k;
string s;
int a[maxn+5],sum[maxn+5],need_to_add[maxn+5];
int parent[maxn+5],Rank[maxn+5];
int vis_sub_3[maxn+5];
int dd[maxn+5];
int ccnt_have_light_sub_3;
vi Adj[maxn+5];
pi G[maxn+5];
void sub_1(){
    int L = INF,R = INF;
    int res = 0;
    INC(i,1,n){
       if(a[i]){
          int cnt = 0;
          int j = i;
          while(a[j] && j <= n){
             j++;
             cnt++;
          }
          if(cnt > res){
             res = cnt;
             L = i;
             R = j - 1;
          }
          i = j - 1;
       }
    }
    if(L == INF && R == INF){
        cout << -1;
        return;
    }
    cout << L << ' ' << R;
}
void sub_2(){
    INC(i,1,n){
        need_to_add[i] = need_to_add[i-1] + (a[i] == 0);
    }
    int L = INF,R = INF;
    int res = 0;
    INC(i,1,n){
        int left = i,right = n,pos = -1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(need_to_add[mid] - need_to_add[i-1] <= k){
                pos = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        if(pos != -1){
            if(pos - i + 1 > res){
                res = pos - i + 1;
                L = i;
                R = pos;
            }
        }
    }
    if(L == INF && R == INF){
        cout << -1;
        return;
    }
    cout << L << ' ' << R;
}
int Find(int u){
   if(parent[u] != u) parent[u] = Find(parent[u]);
   return parent[u];
}
void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(Rank[u] < Rank[v]){
        Rank[v] += Rank[u];
        parent[u] = v;
    }
    else{
        Rank[u] += Rank[v];
        parent[v] = u;
    }
}
void DFS_sub_3(int u){
    vis_sub_3[u] = 1;
    ccnt_have_light_sub_3 += a[u];
    for(int v : Adj[u]){
        if(vis_sub_3[v]) continue;
        DFS_sub_3(v);
    }
}
void sub_3(){
    INC(i,1,n){
        parent[i] = i;
        Rank[i] = 1;
    }
    INC(i,1,m){
        Union(G[i].fi,G[i].se);
    }
    INC(i,1,m){
        int u = G[i].fi;
        int v = G[i].se;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    set<int> Set;
    INC(i,1,n){
       if(Find(i) != i){
          Set.insert(Find(i));
       }
    }
    for(int u : Set){
        ccnt_have_light_sub_3 = 0;
        DFS_sub_3(u);
        dd[u] = ccnt_have_light_sub_3;
    }
    int res = 0,L = INF,R = INF;
    INC(i,1,n){
       set<int> T;
       int tmp_have_light = 0;
       INC(j,i,n){
           int v = Find(i);
           if(T.find(v) == T.end()){
              T.insert(Find(v));
              tmp_have_light += dd[v];
           }
           if(tmp_have_light + k >= j - i + 1){
              if(j - i + 1 > res){
                 res = j - i + 1;
                 L = i;
                 R = j;
              }
           }
           else break;
       }
    }
    if(L == INF && R == INF){
        cout << -1;
        return;
    }
    cout << L << ' ' << R;
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    INC(i,0,(int)(s.size())-1){
        a[i+1] = s[i] - '0';
        sum[i+1] = sum[i] + a[i+1];
    }
    INC(i,1,m){
        cin >> G[i].fi >> G[i].se;
    }
    if(m == 0 && k == 0) sub_1();
    else if(m == 0) sub_2();
    else if(n <= 5e5) sub_3();
}

