#include <bits/stdc++.h>
using namespace std;
int n,m;
#define maxn 1505
#define maxm 5001
int cl[maxn][maxn];
int kc[maxn][maxn];
int f[maxn][maxn];
int L[maxm];
int u[maxm];
int v[maxm];
int col[maxn];
#define mod 998244353
#define INF 1000000000
typedef pair<int,int> II;
vector<II> gn[maxn];
set<II> s;
int pos=0;
int tp[maxn];
vector<II> g[maxn];
void Dij(int id){
   for(int i=1;i<=n;++i){
    cl[id][i]=0;
    kc[id][i]=INF;
   }
   s.clear();
   cl[id][id]=1;
   kc[id][id]=0;
   s.insert({kc[id][id],id});
   while(!s.empty()){
    int u=s.begin()->second;
    s.erase(s.begin());
    tp[++pos]=u;
    cl[id][u]=2;
    for(auto i:g[u]){
        int v=i.first;
        int L=i.second;
        if(cl[id][v]==0){
            cl[id][v]=1;
            kc[id][v]=kc[id][u]+L;
            s.insert({kc[id][v],v});
        }else if(cl[id][v]==1 && kc[id][v]>kc[id][u]+L){
            s.erase({kc[id][v],v});
            kc[id][v]=kc[id][u]+L;
            s.insert({kc[id][v],v});
        }
    }
   }
}
int main(){

    freopen("CAULUONG.inp","r",stdin);
    freopen("CAULUONG.out","w",stdout);
   int t;
   scanf("%d",&t);
   scanf("%d %d",&n,&m);
   for(int i=1;i<=m;++i){
     scanf("%d %d %d",&u[i],&v[i],&L[i]);
     g[u[i]].push_back({v[i],L[i]});
     gn[v[i]].push_back({u[i],L[i]});
   }
   for(int i=1;i<=n;++i){
    pos=0;
     Dij(i);
     f[i][i]=1;
     for(int k=1;k<=n;++k)
        col[k]=0;
     for(int k=2;k<=n;++k){
        int u=tp[k];
        if(col[u]==0){
        col[u]=1;
        for(auto &j:gn[u]){
            int v=j.first;
            int l=j.second;
            if(kc[i][v]+l==kc[i][u] && f[i][v]!=0) f[i][u]=(f[i][u]+f[i][v])%mod;
        }
     }
     }
   }
   for(int k=1;k<=m;++k){
    long long ds=0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j){
            if(kc[i][u[k]]+L[k]+kc[v[k]][j]==kc[i][j]){
                ds=(ds+1ll*f[i][u[k]]*f[v[k]][j]%mod)%mod;

        }
    }
   printf("%lld\n",ds);
   }
}
