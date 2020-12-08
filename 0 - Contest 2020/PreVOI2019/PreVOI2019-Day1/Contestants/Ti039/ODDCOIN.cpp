#include <bits/stdc++.h>
using namespace std;
#define tag "ODDCOIN"
#define maxn 10007
#define oo 1000000007LL
#define mid ((l+r)>>1)
#define meset(a,x) memset(a,x,sizeof(a))
#define loop(x) for(int LoOpEr=1;LoOpEr<=x;LoOpEr++)
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
#define runtime(stime) ((clock() - stime) / CLOCKS_PER_SEC * 1000)
#define checkfile(FiLeNaMe) { if(fopen(FiLeNaMe".inp","r")) freopen(FiLeNaMe".inp","r",stdin),freopen(FiLeNaMe".out","w",stdout); }
//// my data:
const vector<int> dong = {50000,30000,10000,5000,3000,1000,500,300,100,50,30,10,5,3,1};
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int calc(int x){
    int rep=0;

    for(int d: dong){
        if(x==0) break;
        rep+=x/d;
        x%=d;
    }
    return rep;
}

void solve(){
    int x,t;
    cin>>x>>t;

    int ans=calc(t);
    int dpt=t/x;
    for(int i=x;i<=t;i+=x){
        if(dpt>1e5 && calc(i)<=i/x) break;
        ans=min(ans,calc(t-i)+i/x);
    }

    cout<<ans<<"\n";
}

int main()
{
    checkfile(tag);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin>>test;

    while(test-->0) solve();

    return 0;
}
