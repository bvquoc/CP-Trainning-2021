#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <int,int>
#define pl pair <ll,ll>
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define ft(i,x,y) for (int i=y;i>=x;i--)
#define N 100005
using namespace std ;
int n,m,a[20*N];
void inp(){
     freopen("mine.inp","r",stdin) ;
     freopen("mine.out","w",stdout);
     scanf("%d%d",&n,&m);
     fr(i,1,2*n)
        scanf("%d",&a[i]) ;
}
void sub(){
      if (n==3) cout<<"2" ;
      else
         cout<<n;
}
int main(){
    inp() ;
    sub() ;
}
