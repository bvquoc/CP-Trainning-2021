#include <bits/stdc++.h>
using namespace std;
#define maxn 3005
int L[maxn];
int R[maxn];
int x[maxn];
int t[maxn];
#define INF 1000000000
#define limit 100000
int ds=INF;
int it[4*(limit+5)];
int dt[4*(limit+5)];
int nho[4*(limit+5)];
int n,m;
typedef pair<int,int> II;
II a[maxn];
void update(int r,int k,int l,int u,int v,int val){
    if(u>l || v<k) return;
    if(u<=k && l<=v){
        dt[r]=val;
        nho[r]=1;
        return;
    }
    int g=(k+l)/2;
    if(nho[r]){
        dt[2*r]=dt[2*r+1]=dt[r];
        nho[2*r]=nho[2*r+1]=nho[r];
        nho[r]=0;
    }
    update(2*r,k,g,u,v,val);
    update(2*r+1,g+1,l,u,v,val);
    int tl=(nho[2*r])?dt[2*r]*(g-k+1):it[2*r];
    int tr=(nho[2*r+1])?dt[2*r+1]*(l-g):it[2*r+1];
    it[r]=tl+tr;
}
int get(int r,int k,int l,int u,int v){
    if(u>l || v<k) return 0;
    if(u<=k && l<=v){
        return (nho[r])?dt[r]*(l-k+1):it[r];
    }
    int g=(k+l)/2;
    if(nho[r]){
        dt[2*r]=dt[2*r+1]=dt[r];
        nho[2*r]=nho[2*r+1]=nho[r];
        nho[r]=0;
    }
    int t1=get(2*r,k,g,u,v);
    int t2=get(2*r+1,g+1,l,u,v);
    int tl=(nho[2*r])?dt[2*r]*(g-k+1):it[2*r];
    int tr=(nho[2*r+1])?dt[2*r+1]*(l-g):it[2*r+1];
    it[r]=tl+tr;
    return t1+t2;
}
void xuly(){
    update(1,1,limit,1,limit,0);
    int sl=0;
    for(int i=1;i<=m;++i){
       if(x[i]==1) {
        update(1,1,limit,L[i],R[i],1);
        ++sl;
       }
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        int kq=get(1,1,limit,t[i],limit);
        if(kq==limit-t[i]+1) ++cnt;
    }
    if(cnt==n) ds=min(ds,sl);
}
void thu(int k){
   if(k>m){
    xuly();
    return;
   }
   for(int i=0;i<=1;++i){
    x[k]=i;
    thu(k+1);
   }
}
int main(){
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
        scanf("%d %d",&L[i],&R[i]);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&t[i]);
    if(m<=16 && n<=10){
    thu(1);
    if(ds==INF) printf("-1");
    else printf("%d",ds);
    }else{
       for(int i=1;i<=m;++i)
         a[i]={R[i],L[i]};
       sort(a+1,a+m+1);
       sort(t+1,t+n+1);
       reverse(a+1,a+m+1);
       int here=limit;
       int minl=limit;
       int ds=0;
       for(int i=1;i<=m;++i){
        if(a[i].first>=here && a[i+1].first>=here && i<n){
            minl=min(minl,a[i].second);
        }
        if(a[i].first>=here && (a[i+1].first<here || i==n)){
            minl=min(minl,a[i].second);
            here=minl;
            ++ds;
           if(here<=t[1]) break;
       }
    }
    if(minl>t[1]) printf("-1");
    else printf("%d",ds);
}
}
