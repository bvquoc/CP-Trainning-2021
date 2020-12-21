//TaiEm(Nguyen Duc Huy) IT_18-21 
//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <bitset>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> i3;

#define taskname "COOLMAC"
#define FOR(i,j,n) for(int i=j; i<=n; i++)
#define FOD(i,j,n) for(int i=j; i>=n; i--)
#define fi first
#define se second
#define REP(i,j,n) for(int i=j; i<n; i++)
#define LL long long
#define LD long double

const int maxN=1e5+12;
const LL oo=1e18+11;

struct ds {
	int d,c;
};

bool xet(const ds x , const ds y) {
	return x.c<y.c;
}

bool xet2(const ds x , const ds y) {
	return ((x.d>y.d) && x.c==y.c);
}

//////////////////////////////////////////////

int M,N;
ds A[maxN];
bool C[maxN];
int S[maxN];

//////////////////////////////////////////////

void xuli(){
    int k=M;
    int dem=1;
    S[M]=1;
    C[M]=1;
    FOD(i,M-1,1){
        if(A[k].d<=A[i].c){
            if (A[k].d>A[i].d) dem++;
            C[i]=1;
        }
        S[i]=dem;
    }
}

void enter(){
    scanf("%d",&M);
    FOR(i,1,M){
        scanf("%d%d",&A[i].d,&A[i].c);
    }
    sort(A+1,A+1+M,xet);
    sort(A+1,A+1+M,xet2);
    if (A[M].c!=100000){
        cout << -1;
        return;
    }
    scanf("%d",&N);
    int mn=1000000;
    FOR(i,1,N){
        int cur;
        scanf("%d",&cur);
        if (mn>cur) mn=cur;
    }
    xuli();
    int res=1000000;
    FOR(i,1,M){
        if ((C[i]) && (mn>=A[i].d)){
            if (res>S[i]) res=S[i];
        }
    }
    if (res==1000000) cout << -1;
    else cout << res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #else
        // online submission
    #endif
    // main program here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    enter();
    return 0;
}