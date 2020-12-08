#include <bits/stdc++.h>

using namespace std;
int xs[10006],x[10006],s,ma,w,a[20],k,q;
void xuat()
    {
        if (s==w)
        for(int i=1;i<=16;i++)
            xs[i]=x[i];
    }
void tr(int v)
    {
        int j;
        for (j=0;j<=1;j++)
        if ((s+a[v]*j)<=w)
        {
            x[v]=j;
            s+=a[v]*x[v];
            if (v==1)xuat();
            else tr(v-1);
            s-=a[v]*x[v];
        }
    }
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    a[1]=1;
    a[2]=3;
    a[3]=5;
    a[4]=10;
    for(int i=5;i<=15;i++)
    a[i]=a[i-3]*10;
    cin>>q;
    while (q--)
    {
        cin>>k>>w;
        a[16]=k;
        sort(a+1,a+17);
        s=0;ma=0;
        memset(x,0,sizeof(x));
        tr(16);
        int d=0;
       for(int i=1;i<=16;i++)
           if (xs[i]==1)d++;
        cout<<d<<"\n";
    }
    return 0;
}
