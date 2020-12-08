#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=y;i>=x;i--)
#define ll long long
#define add push_back
#define ad push
#define fi first
#define se second
#define fast_read ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef struct pair<ll,ll> ii;
ll n,m,a[200010],x[200010],dem[25],st[25],ed[25],res,mod=1000003,ans,minn,cc[1000010];
vector<ll> nx;
bool ck;
void io(){
    freopen("mine.inp" , "r" , stdin);
    freopen("mine.out" , "w" , stdout);
}
void inp(){
    scanf("%lld%lld",&n,&m);
    fr(i,1,n*2) scanf("%lld",&a[i]);
}
void xuli(){
    fr(i,1,n) dem[i]=0;
    minn=0;
    fr(i,1,n) cc[i]=0;
    ck=false;
    fr(i,1,2*n){
        if(cc[x[i]]==0){
            if(minn<x[i]) minn=x[i];
            else return;
            cc[x[i]]++;
        }
    }
    fr(i,1,2*n){
        dem[x[i]]++;
        if(dem[x[i]]==1) st[x[i]]=a[i];
        else ed[x[i]]=a[i];
    }
    fr(i,1,n){
        if(dem[i]>2){
            return;
        }
    }
    ans=n*2;
    nx.clear();
    nx.add(0);
    fr(i,1,2*n){
        //cout<<nx.back()<<endl;
        if(nx.back()==x[i]) {
            nx.pop_back();
            ans-=2;
        }
        else nx.add(x[i]);
    }
    if(nx.size()-1==ans && ans!=0) return;
    fr(i,1,n){
        if((ed[i]-st[i])>m) return;
    }
    res++;
}
void backk(int i){
    fr(j,1,n){
        x[i]=j;
        if(i==2*n) xuli();
        else backk(i+1);
    }
}
void sub(){
    sort(a+1,a+n*2+1);
    backk(1);
    res=res%mod;
    printf("%lld",res);
}
int main (){
    io();
    inp();
    sub();
    return 0;
}
