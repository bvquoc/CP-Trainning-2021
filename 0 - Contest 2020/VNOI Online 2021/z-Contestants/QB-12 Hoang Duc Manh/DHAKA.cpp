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
#define IONAME "DHAKA"
//#define E_DEBUG
//#define TIMECOMP

struct way{
    int v,w;
};

struct best{
    int u,io;
    ll w;
};

const long long md=1e9+7;
const int N=1e5+123;
int n,m,k,l;
int melon[N],io[N];
ll d[N];
std::set<int> ss[N];
std::vector<int> iot[N];
std::vector<way> vv[N];

bool cmp(best x,best y){
    if (x.io==y.io) return x.w>y.w;
    return x.io<y.io;
}

std::priority_queue<best,std::vector<best>,std::function<bool(best,best) > >  pq (cmp); 

int pc(int x){
    return __builtin_popcount(x);
}

void merge(way v,int u){
    for (auto x:iot[u]){
        int tt=x|melon[v.v];
        int tmp=pc(tt);
        if (io[v.v]<tmp){
            io[v.v]=tmp;
            iot[v.v].clear();
            ss[v.v].clear();
            iot[v.v].push_back(tt);  
            ss[v.v].insert(tt);
        }  
        else if (io[v.v]==tmp){
            if (ss[v.v].find(tt)==ss[v.v].end()){
                ss[v.v].insert(tt);
                iot[v.v].push_back(tt);
            }
        }
    }
}

void dijkstra(){
    for (int i=1;i<=n;i++) {
        d[i]=1e18+123;
    }
    d[1]=0; 
    pq.push({1,io[1],0});
    while (!pq.empty()){
        int u=pq.top().u;
        int iou=pq.top().io;
        ll du=pq.top().w;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto v:vv[u]){
            if (d[v.v]>d[u]+v.w){
                d[v.v]=d[u]+v.w;
                pq.push({v.v,io[v.v],d[v.v]});
            }  
        }
    }
}

void sub2(){
    dijkstra();
    std::cout<<d[n];
}

int vst[N];
ll res=1e18+132;

void dfs(int u,int passed,int x,ll dd,ll sdd){
    vst[u]=1;
    passed|=(u==n);
    x|=melon[u];
    if (passed && pc(x)>=l) {
        res=std::min(res,dd+sdd);
        vst[u]=0;
        return;
    }
    for (auto v:vv[u]){
        if (!vst[v.v]){
            dfs(v.v,passed,x,dd+v.w,sdd+passed*(v.w));
        }
    }
    vst[u]=0;
}

void sub1(){
    dfs(1,0,0,0,0);
    std::cout<<res;
}

void marota(){
    std::cin>>n>>m>>k>>l;
    int xx=0;
    for (int i=1;i<=n;i++){
        int sz;
        std::cin>>sz;
        for (int j=1;j<=sz;j++){
            int type;
            std::cin>>type;
            melon[i]|=1<<type;
        }
    }
    for (int i=1;i<=n;i++) {
        xx|=melon[i];
    }
    if (pc(xx)<l) {std::cout<<-1; return;}
    for (int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        vv[u].push_back({v,w});
        vv[v].push_back({u,w});
    }
    if (l==0) sub2();
    else sub1();
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