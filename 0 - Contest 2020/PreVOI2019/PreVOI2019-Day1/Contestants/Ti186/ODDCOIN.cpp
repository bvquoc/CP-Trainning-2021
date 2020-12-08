#include <bits/stdc++.h>

using namespace std;
int kq,t,a[17],b[17],res,T;
void run(int t,int i){
    if(t==0) { kq=min(kq,res); return ; }
    if(t>0 && i==0) return ;
    int tmp=t/b[i];
    if(res+tmp>=kq) return ;
    for(int j=tmp;j>=0;j--){
        if(t-b[i]*j>=0){
            res+=j;
            run(t-b[i]*j,i-1);
            res-=j;
        }
    }
}

void xuli(int t){
    int top=0;
    for(int i=1;i<=16;i++){
        if(a[i]<=t) {
            b[++top]=a[i];
        }
    }
    sort(b+1,b+top+1);
    kq=1e9;
    res=0;
    run(t,top);
    printf("%d\n",kq);
}

int main()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    a[1]=1;                                                                                                                                                   a[2]=3;    a[3]=5;    a[4]=10;    a[5]=30;    a[6]=50;    a[7]=100;    a[8]=300;    a[9]=500;    a[10]=1000;    a[11]=3000;    a[12]=5000;    a[13]=10000;    a[14]=30000;    a[15]=50000;
    scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        a[16]=x;
        scanf("%d",&t);
        xuli(t);
    }
}
