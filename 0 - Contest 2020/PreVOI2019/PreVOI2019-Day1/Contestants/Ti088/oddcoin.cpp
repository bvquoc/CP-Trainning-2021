#include <bits/stdc++.h>
using namespace std;
int f[1000001],i,j,x,m,q;
int a[16]={ 0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000 };
void sub1()
{
    int kq=round(2e9)+1;
    for(i=0;i<=m/x;i++) kq=min(kq,f[m-i*x]+i);
    cout<<kq<<'\n';
}
void sub2()
{
    int k=max(x,50000),kq=0;
    while(m>1000000 && m>=k) { m-=k; kq++; }
    if(x>50000)
        while(m>1000000) { m-=50000; kq++; }
    int mi=round(2e9)+1;
    for(i=0;i<=m/x;i++) mi=min(mi,f[m-i*x]+i);
    cout<<kq+mi<<'\n';
}
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    for(i=1;i<=1000000;i++) f[i]=round(2e9)+1;
    for(i=1;i<=15;i++)
        for(j=a[i];j<=1000000;j++)
            f[j]=min(f[j],f[j-a[i]]+1);
    cin>>q;
    while(q--)
    {
        cin>>x>>m;
        if(m<=1000000) sub1();
        else sub2();
    }
}
