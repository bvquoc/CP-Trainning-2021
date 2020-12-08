#include <bits/stdc++.h>

using namespace std;
int x,t,f[510001],q;
int a[20]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
void sub1()
{
    memset(f,-1,sizeof(f));
    f[0]=0;
    for (int i=1;i<=t;i++)
    {
        for (int j=15;j>=0;j--)
            if (i-a[j]>=0 && (f[i-a[j]]!=-1))
            {
                if (f[i]==-1) f[i]=f[i-a[j]]+1;
                else
                f[i]=min(f[i],f[i-a[j]]+1);
            }
    }
    cout<<f[t]<<"\n";
}
void sub2()
{
    int tt=(1<<16)-1;
int ans=2*1e9;
    for (int i=0;i<=tt;i++)
    {
        int tong=t;int sl=0;
        for (int j=15;j>=0;j--)
            if ((i & (1<<j))>0)
        {
           if (tong>=a[j])
            {
                int thuong=tong/a[j];
                sl+=thuong;
                tong-=thuong*a[j];
            }
        }
        if (tong==0) ans=min(ans,sl);
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
   cin>>q;
    while (q--)
    {
        cin>>x>>t;
        a[15]=x;
       if (t<=100000)            sub1();        else
            sub2();
    }
}
