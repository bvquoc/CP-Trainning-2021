#include <bits/stdc++.h>
#define task "PERMEOW"
#define REP(i,a,b) for(int i = a; i<=b;++i)

using namespace std;

int Sub2(){
    int ans = 0;
    REP(i,1,n-1) ans+=i;
    cout<<ans;
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    bool IsSub1 = true;
    bool IsSub2 = true;
    REP(i,1,n){
        cin>>A[i];
        if (A[i] != i) IsSub1 = false;
    }
    REP(i,1,n){}
        cin>>B[i];
        if (B[i] != i) IsSub1 = false;
        if (B[i] != n - i+1) IsSub2 = false;
    }
    if (IsSub1){
        cout<<"0";
        return 0;
    }
    if (IsSub2){
        Sub2();
        return 0;
    }
    else cout<<"0";
}
