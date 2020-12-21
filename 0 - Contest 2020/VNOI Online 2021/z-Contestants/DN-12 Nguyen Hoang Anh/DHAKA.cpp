/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "DHAKA"
#define fi first
#define se second
#define ll long long
#define sz(v) (int)(v.size())
#define get_bit(x,i) (x >>(i-1)&1)
#define countbit_one(n) __builtin_popcountll(n)
#define INC(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 1e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 31;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<pi> vpi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N,M,K,L;
ll dp[maxn+5][35];
vi Fruit[maxn+5];
vpi Adj[maxn+5];
struct ii{
    int id;
    ll val;
    int bitmask;
};
struct cmp{
    bool operator () (ii A,ii B){
       return A.val > B.val;
    }
};
priority_queue<ii,vector<ii>,cmp> Heap;
void dijkstra(int s){
    INC(i,1,N){
       INC(state,0,(1<<K)-1){
           dp[i][state] = INF;
       }
    }
    while(Heap.size()) Heap.pop();
    if(Fruit[s].size()){
        int sta = 0;
        for(int u : Fruit[s]){
            sta |= (1 << (u-1));
        }
        dp[s][sta] = 0;
        Heap.push({s,0,sta});
    }
    else{
        dp[s][0] = 0;
        Heap.push({s,0,0});
    }
    while(Heap.size()){
        ii u = Heap.top();
        Heap.pop();
        if(dp[u.id][u.bitmask] < u.val) continue;
        for(pi v : Adj[u.id]){
            int next_state = u.bitmask;
            for(int vv : Fruit[v.fi]){
                next_state |= (1 << (vv-1));
            }
            if(dp[u.id][u.bitmask] + 1ll * v.se < dp[v.fi][next_state]){
                dp[v.fi][next_state] = dp[u.id][u.bitmask] + 1ll * v.se;
                Heap.push({v.fi,dp[v.fi][next_state],next_state});
            }
        }
    }
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    scanf("%d %d %d %d",&N,&M,&K,&L);
    INC(i,1,N){
        int x;
        scanf("%d",&x);
        while(x--){
            int y;
            scanf("%d",&y);
            Fruit[i].push_back(y);
        }
    }
    INC(i,1,M){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        Adj[u].push_back({v,w});
        Adj[v].push_back({u,w});
    }
    dijkstra(1);
    ll res = INF;
    INC(state,1,(1<<K)-1){
        if(countbit_one(state) >= L){
            res = min(res,dp[N][state]);
        }
    }
    if(res == INF) res = -1;
    printf("%lld",res);
}

