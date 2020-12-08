#include <bits/stdc++.h>
using namespace std;
#define tag "CONSTRUCT"
#define maxn 100007
#define oo 1000000007LL
#define mid ((l+r)>>1)
#define meset(a,x) memset(a,x,sizeof(a))
#define loop(x) for(int LoOpEr=1;LoOpEr<=x;LoOpEr++)
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
#define runtime(stime) ((clock() - stime) / CLOCKS_PER_SEC * 1000)
#define checkfile(FiLeNaMe) { if(fopen(FiLeNaMe".inp","r")) freopen(FiLeNaMe".inp","r",stdin),freopen(FiLeNaMe".out","w",stdout); }
//// my data:
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int n,m;
int a[maxn];
int b[maxn];
int up[maxn];
int L[maxn],R[maxn];

void enter(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}


///SUBONE:
int64_t brute(int l,int r){

    for(int i=l;i<=r;i++){
        b[i-l+1]=a[i];
    }

    int sz=r-l+1;
    b[0]=b[sz+1]=0;
    for(int i=1;i<=sz;i++)
        for(L[i]=i-1;L[i]>=1 && b[i]<b[L[i]];L[i]=L[L[i]]);

    for(int i=sz;i>=1;i--)
        for(R[i]=i+1;R[i]<=n && b[i]<=b[R[i]];R[i]=R[R[i]]);

    int64_t rep=0;
    for(int i=1;i<=sz;i++){
        rep+=b[i]-max(b[L[i]],b[R[i]]);
    }

    return rep;
}

void sub1(){
    auto resetup = [&](){
        for(int i=0;i<=n+1;i++) up[i]=0;
    };

    resetup();
    int type,l,r,x;
    for(int ques=0;ques<m;ques++){
        cin>>type;

        if(type==1){
            cin>>l>>r>>x;
            up[l]+=x;
            up[r+1]-=x;
        }else{
            cin>>l>>r;
            for(int i=1;i<=n;i++){
                up[i]+=up[i-1];
                a[i]+=up[i];
            }
            resetup();
            cout<<brute(l,r)<<"\n";
        }
    }
}

///SOLVE:
void solve(){
    enter();
    sub1();
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
