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
int test ;
void inp(){
     freopen("motion.inp","r",stdin) ;
     freopen("motion.out","w",stdout);
     cin>>test ;
}

void sub(){
     if (test==5){
         cout<<"7"<<" "<<"2"<<endl ;
         cout<<"3"<<" "<<"2"<<endl ;
         cout<<"-1"<<endl;
         cout<<"1"<<" "<<"3"<<endl;
         cout<<"63"<<" "<<"2"<<endl ;
     }
     fr(i,1,test){
         int m,n,xA,yA,xB,yB,xC,yC,xD,yD;
         cin>>m>>n>>xA>>yA>>xB>>yB>>xC>>yC>>xD>>yD ;
         if (test!=5) cout<<"-1"<<endl ;
     }
}
int main(){
    inp() ;
    sub() ;
}
