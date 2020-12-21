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
#define IONAME "PERMEOW"
//#define E_DEBUG
//#define TIMECOMP

const long long md=1e9+7;
const int N=222000;
int t;
int n,m;
int a[N],b[N];

void sub1(){
    int cnt=0;
    for (int k=1;k<=n;k++){
        for (int i=k;i<=n;i++){
            if (k==a[i]){
                int j=i;
                while (a[j]!=j){
                    cnt++;
                    std::swap(a[j],a[j-1]);
                    j--;
                }
            }
        }
    }
    std::cout<<cnt;
}

void marota(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>a[i];
    }    
    for (int i=1;i<=n;i++){
        std::cin>>b[i];
    }
    sub1();
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