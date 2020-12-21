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
#define IONAME "COOLMAC"
//#define E_DEBUG
//#define TIMECOMP

const long long md=1e9+7;
const int N=111000,mx=1e5;
int t;
int n,m;
int x[N];

int ans(int lm){
    int bb=-1;
    for (int i=0;i<=lm;i++){
        bb=std::max(bb,x[i]);
    }
    if (bb==-1) return -1;
    int res=1;
    while (bb<mx) {
        res++;
        int tmp=-1;
        for (int i=lm+1;i<=bb;i++){
            tmp=std::max(tmp,x[i]);
        }
        if (tmp==-1) return -1;
        lm=bb;
        bb=std::max(bb,tmp);
    }
    return res;
}

void marota(){
    std::memset(x,-1,sizeof(x));
    std::cin>>m;
    for (int i=1;i<=m;i++){
        int a,b;
        std::cin>>a>>b;
        x[a]=std::max(x[a],b);
    }
    int limit=1e5+1;
    std::cin>>n;
    for (int i=1;i<=n;i++){
        int tmp;
        std::cin>>tmp;
        limit=std::min(limit,tmp);
    }
    std::cout<<ans(limit);
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