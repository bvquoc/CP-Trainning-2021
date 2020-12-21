#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1) +l;}
#define fi first
#define se second
#define pii pair<int,int>
#define ii pair<int,pii>
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x^(1ll<<i))


const int maxn=2e5+10,mod=1e9+7,N=2e5;
int n;
int a[maxn],b[maxn];
int SUB1=1;
int it[maxn];

void upd(int x){
    while(x>0){
        it[x]++;
        x-=(x&-x);
    }
}

int get(int x){
    int kq=0;
    while(x<=N){
        kq+=it[x];
        x+=(x&-x);
    }
    return kq;
}

main(){
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    forinc(i,1,n) cin>>a[i];
    forinc(i,1,n) cin>>b[i];

    forinc(i,1,n) if(a[i]!=b[i]) SUB1=0;

    if(SUB1){
        int ret=0;
        forinc(i,1,n){
            ret+=get(a[i]+1);
            upd(a[i]);
        }
        cout<<ret<<"\n";
    }else{
        if(n==1) cout<<0;
        else if(n==2) cout<<1;
        else if(n==3) cout<<9;
        else{
            int X=n*(n-1)%mod;
            X=X*6%mod;
            forinc(i,5,n) X=X*i%mod;
            cout<<X;
        }
    }

}
