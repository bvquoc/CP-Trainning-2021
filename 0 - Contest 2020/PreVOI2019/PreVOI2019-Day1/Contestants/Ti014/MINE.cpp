#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "MINE"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))

const int M=1000003,
          N=500010;

int n,m;
int a[N];
int g[N],h[N];
int f[2222][2222];

int pw(int a,int i){
    int b=1;
    for(;i;i>>=1,a=a*a%M) if(i&1) b=b*a%M;
    return b;
}

int C(int n,int k){
    if(n<k) return 0;
    return g[n]*h[n-k]%M*h[k]%M;
}

int W(int i,int j,int n){
    if(i>j) return W(j,i,n);
    int x=(n+j-i)/2;
    return C(n,x);
}

int calc(int i,int n){
    if(i>n) return 0;
    return (n-i)&1 ? 0 : (W(i,0,n)-W(i,-2,n)+M)%M;
}

int dfs(int l,int r){
    if(l>r) return 1;
    if(r-l==1) return a[r]-a[l]<=m;
    int &ret=f[l][r]; if(ret>-1) return ret; ret=0;
    forinc(i,l+1,r){
        if(a[i]-a[l]>m) break;
        if((r-i)&1) continue;
        ret=(ret+dfs(l+1,i-1)*dfs(i+1,r)%M)%M;
    }
    return ret;
}

main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    fasty;

    forinc(i,0,5e5) g[i]=i?g[i-1]*i%M:1;
    fordec(i,5e5,0) h[i]=i<5e5?h[i+1]*(i+1)%M:pw(g[i],M-2);

    cin>>n>>m;
    forinc(i,1,n+n) cin>>a[i];

    if(m==1000000){
        cout<<calc(0,n+n)<<"\n";
    } else{
        reset(f,-1);
        cout<<dfs(1,n+n);
    }
}

