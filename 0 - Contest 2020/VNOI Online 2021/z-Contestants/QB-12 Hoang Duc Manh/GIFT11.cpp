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
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> pii;
#define IONAME "GIFT11"
//#define E_DEBUG
//#define TIMECOMP

const long long md=1e9+7;
int t;
int n,m;
int a[2222];

void sub1(){
    int hv[11];
    std::iota(hv+1,hv+n+1,1);
    ll res=0;
    do{
        int v[3]={0,0,0};
        int io=0;
        for (int i=n;i>=1;i--){
            int tmp=a[hv[i]];
            while (tmp){
                io=1-io;
                v[io]+=(tmp%10);
                tmp/=10;
            }
        }
        if (v[1]>v[0]) std::swap(v[1],v[0]);
        res+=((v[0]-v[1])%11==0);
    } while (std::next_permutation(hv+1,hv+n+1));
    std::cout<<res<<'\n';
}

void marota(){
    std::cin>>t;
    while (t--){
        std::cin>>n;
        for (int i=1;i<=n;i++) std::cin>>a[i];
        sub1();
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