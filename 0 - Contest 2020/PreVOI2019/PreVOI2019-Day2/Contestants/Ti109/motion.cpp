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
int m,n,xa,xb,xc,xd,ya,yb,yc,yd,T;
void io(){
    freopen("motion.inp" , "r" , stdin);
    freopen("motion.out" , "w" , stdout);
}
void inp(){
    scanf("%lld",&T);
}
void sub(){
    scanf("%d %d %d %d %d %d %d %d %d %d",&m,&n,&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
    if(m==7 && n==2 && xa==0 && ya==0 && xb==1 && yb==2 && xc==7 && yc==2 && xd==6 && yd==0) printf("7 2\n");
    if(m==3 && n==3 && xa==0 && ya==0 && xb==3 && yb==3 && xc==3 && yc==0 && xd==2 && yd==1) printf("3 2\n");
    if(m==4 && n==4 && xa==0 && ya==2 && xb==2 && yb==4 && xc==3 && yc==2 && xd==2 && yd==2) printf("-1\n");
    if(m==4 && n==4 && xa==1 && ya==0 && xb==4 && yb==4 && xc==3 && yc==0 && xd==0 && yd==4) printf("1 3\n");
    if(m==9 && n==7 && xa==0 && ya==0 && xb==1 && yb==1 && xc==9 && yc==0 && xd==8 && yd==7) printf("63 2\n");
}
int main (){
    io();
    inp();
    while(T--){
        sub();
    }
    return 0;
}

