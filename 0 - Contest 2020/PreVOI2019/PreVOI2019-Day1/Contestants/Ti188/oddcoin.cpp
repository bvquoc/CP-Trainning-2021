#include <bits/stdc++.h>

using namespace std;

int Q,a[17],n;

int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    scanf("%d",&Q);
    a[1]=1; a[2]=3; a[3]=5; a[4]=10; a[5]=30; a[6]=50;
    a[7]=100; a[8]=300; a[9]=500; a[10]=1000; a[11]=3000;
    a[12]=5000; a[13]=10000; a[14]=30000; a[15]=50000;
    while (Q--)
    {
        int x,T; scanf("%d%d",&x,&T);
        int P=T;
        int kq=1e9; int tong=0; a[16]=x; n=16;
        while (T>0 && n>=1)
        {
            int tg=T/a[n]; tong+=tg;
            T-=tg*a[n]; n--;
        }
        kq=min(kq,tong); tong=0; n=15;
        while (P>0)
        {
            int tg=P/a[n]; tong+=tg;
            P-=tg*a[n]; n--;
        }
        cout<<min(kq,tong)<<"\n";
    }
}
