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
#define IONAME "DECOR"
//#define E_DEBUG
//#define TIMECOMP

struct edge{
    int u,v;
} e[555000];

const long long md=1e9+7;
int t;
int n,m,k;
std::string s;

void sub2(){
    int l=0,r=-1;
    int cnt0=0;
    int cnt1=0;
    int lx=0;
    for (int i=0;i<n;i++){
        cnt0+=(s[i]=='0');
        cnt1+=(s[i]=='1');
        while (cnt0>k){
            cnt0-=(s[lx]=='0');
            cnt1-=(s[lx]=='1');
            lx++;
        }
        if (i-lx>r-l) {
            r=i;
            l=lx;
        }
    }
    if (r-l+1==0) std::cout<<-1<<'\n';
    else std::cout<<l+1<<" "<<r+1;
}

void sub(){

}

void marota(){
    std::cin>>n>>m>>k;
    std::cin>>s;
    if (m==0) sub2();
    else {
        for (int i=1;i<=m;i++){
            std::cin>>e[i].u>>e[i].v;
        }
        std::cout<<1<<" "<<n;
    }
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