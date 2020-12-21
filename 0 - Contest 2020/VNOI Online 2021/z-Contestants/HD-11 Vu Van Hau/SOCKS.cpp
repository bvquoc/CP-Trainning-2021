#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int cl[maxn];
int dad[maxn];
int depth[maxn];
int s[maxn];
int dchild[maxn];
int ddad[maxn];
vector<int> g[maxn];
int f[maxn][int(log2(maxn))+5];
int a[maxn];
void DFS(int u){
   cl[u]=1;
   for(auto &v:g[u]){
    if(cl[v]==0){
        dad[v]=u;
        depth[v]=depth[u]+1;
        DFS(v);
    }
   }
}
int LCA(int u,int v){
   if(depth[u]<depth[v]) swap(u,v);
   while(depth[u]>depth[v]){
    int k=int(log2(depth[u]-depth[v]));
    u=f[u][k];
   }
   if(u==v) return u;
   int m=int(log2(depth[u]))+1;
   for(int k=m;k>=0;--k){
    if(f[u][k]!=f[v][k]){
        u=f[u][k];
        v=f[v][k];
    }
   }
   u=f[u][0];
   return u;
}
int main(){
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1);
    for(int i=1;i<=n;++i)
        f[i][0]=dad[i];
    int m=int(log2(n))+1;
    for(int j=1;j<=m;++j)
        for(int i=1;i<=n;++i)
        f[i][j]=f[f[i][j-1]][j-1];

    for(int i=1;i<=n;++i){
        ddad[i]=n;
        dchild[i]=n;
    }

    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j){
        if(a[i]==a[j] && a[i]==1 && i!=j){
            int k=LCA(i,j);
            if(i==k){
               if(dchild[i]==n) dchild[i]=0;
               if(ddad[i]==n) ddad[i]=0;
               if(ddad[j]==n) ddad[j]=0;
               if(dchild[j]==n) dchild[j]=0;
                ++dchild[i];
                ++ddad[j];
            }
            if(j==k){
                 if(dchild[i]==n) dchild[i]=0;
               if(ddad[i]==n) ddad[i]=0;
               if(ddad[j]==n) ddad[j]=0;
               if(dchild[j]==n) dchild[j]=0;
                ++dchild[j];
                ++ddad[i];
            }
        }
    }
    int ds=0;
    for(int i=1;i<=n;++i){
        if(a[i]==1){
        if(dchild[i]==0 || ddad[i]==0) ++ds;
        }}
    printf("%d\n",(ds+1)/2);
    for(int k=1;k<=q;++k){
        int id;
        scanf("%d",&id);
        a[id]=1-a[id];
        for(int i=1;i<=n;++i){
        ddad[i]=n;
        dchild[i]=n;
    }

    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j){
        if(a[i]==a[j] && a[i]==1 && i!=j){
            int k=LCA(i,j);
            if(i==k){
               if(dchild[i]==n) dchild[i]=0;
               if(ddad[i]==n) ddad[i]=0;
               if(ddad[j]==n) ddad[j]=0;
               if(dchild[j]==n) dchild[j]=0;
                ++dchild[i];
                ++ddad[j];
            }
            if(j==k){
               if(dchild[i]==n) dchild[i]=0;
               if(ddad[i]==n) ddad[i]=0;
               if(ddad[j]==n) ddad[j]=0;
               if(dchild[j]==n) dchild[j]=0;
                ++dchild[j];
                ++ddad[i];
            }
        }
    }
    int ds=0;
    for(int i=1;i<=n;++i){
        if(a[i]==1){
        if(dchild[i]==0 || ddad[i]==0) ++ds;
        }}
     printf("%d\n",(ds+1)/2);
    }


}
