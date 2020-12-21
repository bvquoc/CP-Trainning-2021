#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#include<climits>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<iomanip>
#include<functional>
#include<cstring>
typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> pii;
#define IONAME "SOCKS"
//#define E_DEBUG
//#define TIMECOMP

const long long md=1e9+7;
const int N=5e5+123;
int t,q;
int n,m;
int io[N];
std::vector<int> vv[N];
int qu[N],inqu[N],rr[N],xx[N],dad[N];
std::vector<int> leaf;

void sub1(){
    int cnt=0,res=0;
    for (int i=1;i<=n;i++) cnt+=io[i];
    if (cnt>=2) res=1;
    std::printf("%d\n",res);
    while (q--){
        int j;
        std::scanf("%d",&j);
        if (io[j]) {
            cnt--;
            io[j]=0;
        }
        else{
            cnt++;
            io[j]=1;
        }
        if (cnt>=2) res=1;
        std::printf("%d\n",res);
    }
}

void dfs(int u,int pre,int cnt,int fq){
    if (io[u]) cnt++;
    if ((inqu[u]) && (!io[u])) fq=1;
    if (vv[u].size()<=1) leaf.push_back(u);
    if (vv[u].size()<=1 && cnt>=2) rr[u]=1;
    if (vv[u].size()<=1 && fq) xx[u]=1; 
    for (auto v:vv[u]){
        if (v!=pre){
            dad[v]=u;
            dfs(v,u,cnt,fq);
        }
    }
}

bool cmp(int x,int y){
    if (rr[x]==rr[y]){
        if (xx[x]==xx[y]) return inqu[x]>inqu[y];
        return xx[x]<xx[y];
    }
    return rr[x]<rr[y];
}

int used[N];

void sub(){
    int res=0;
    for (int i=1;i<=n;i++){
        inqu[i]=q+12;
    }
    for (int i=1;i<=q;i++){
        std::scanf("%d",&qu[i]);
        if (inqu[qu[i]]==0) inqu[qu[i]]=i;
        else inqu[qu[i]]=std::min(inqu[qu[i]],i);
    }
    qu[0]=0;
    int j=0;
    int root=0;
    do {
        io[qu[j]]=1;
        for (int i=1;i<=n;i++){
            if (io[i]) {
                root=i;
                break;
            }
        }
        j++;
    } while (!root);
    dfs(root,root,0,0);
    std::sort(leaf.begin(),leaf.end(),cmp);
    while (rr[leaf.back()]==1){
        res++;
        int u=leaf.back();
        leaf.pop_back();
        while (!io[u])  {
            io[u]=1;
            u=dad[u];
        }
        if (leaf.size()==1) break;
        int v=leaf.back();
        leaf.pop_back();
        while (!io[v]){
            io[v]=1;
            v=dad[v];
        }
    }
    for (int i=0;i<j;i++) std::printf("%d\n",res);
    for (int i=j;i<=q;i++){
        if (io[qu[i]]) {
            std::printf("%d\n",res);
            continue;
        }
        res++;
        while ((!leaf.empty()) && io[leaf.back()]) leaf.pop_back();
        for (auto x:leaf){
            if (!io[x]){
                int tmp=x,e=0;
                while (!io[tmp]) {
                    if (qu[i]==tmp) {e=1; break;}
                    tmp=dad[tmp];
                }
                if (e){
                    int tmp=x;
                    while (!io[tmp]) {
                        io[tmp]=1;
                        tmp=dad[tmp];
                    }
                    while ((!leaf.empty()) && io[leaf.back()]) leaf.pop_back();
                    if (leaf.empty()) break;
                    int v=leaf.back();
                    while (!io[v]){
                        io[v]=1;
                        v=dad[v];
                    }
                    while ((!leaf.empty()) && io[leaf.back()]) leaf.pop_back();
                }
            }
        }
        std::printf("%d\n",res);
    }
}

void marota(){
    std::scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++){
        std::scanf("%d",&io[i]);
    }
    for (int i=1;i<n;i++){
        int u,v;
        std::scanf("%d%d",&u,&v);
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    int e=0;
    for (int i=1;i<=n;i++){
        e|=(vv[i].size()>2);
    }
    if (!e) sub1();
    else sub();
}
 
int main(){
    #ifdef TIMECOMP
    clock_t tStart = clock();
    #endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #if defined(IONAME)    
        if(fopen(IONAME".inp", "r") != nullptr){
            freopen(IONAME".INP","r",stdin);
            freopen(IONAME".OUT","w",stdout);
        }
    #endif
    marota();
    #ifdef TIMECOMP
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif
    return 0;
} 