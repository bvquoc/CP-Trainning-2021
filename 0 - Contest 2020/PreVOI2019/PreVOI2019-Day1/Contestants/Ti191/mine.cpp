#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define ll long long
#define ii pair<int,int>
#define ft first
#define sc second
#define mod 1000003
#define e5 200001
using namespace std;
int n,m;
int x[e5],t[e5],v[e5],r[e5];
long long result=0;
int y[e5];

void update()
{
     //rep(i,1,2*n) cout<<x[i]<<" ";cout<<endl;
     int nf=0;
     int maxn=0,minn=1e9;
     rep(i,1,2*n) v[i]=r[i]=0;
     int vv=0,rr=0;
     rep(i,1,2*n)
     {
          if(x[i]) nf++;else nf--;
          y[i]=nf;
     }
     //cout<<endl;
     rep(i,1,2*n) minn=min(minn,y[i]);
     if(minn!=0) return;

     rep(i,1,2*n)
     {
         if(x[i])
         {
              vv++;
              v[vv]=t[i];
         }
         if(!x[i])
         {
              rr++;
              r[rr]=t[i];
         }
     }

     if(vv!=n) return;
     if(rr!=n) return;
     rep(i,1,n) if(v[i]>=r[i]) return;
     rep(i,1,n) if(r[i]-v[i]>m) return;
     result++;
}

void TRY(int i)
{
     rep(bit,0,1)
     {
          x[i]=bit;
          if(i==2*n) update();
          else       TRY(i+1);
     }
}

void sub1()
{
    TRY(1);
     cout<<(result-1)%mod;
}

int main()
{
     freopen("mine.inp","r",stdin);
     freopen("mine.out","w",stdout);

     cin>>n>>m;
     rep(i,1,2*n) cin>>t[i];


     if(n<=10) sub1();
}
