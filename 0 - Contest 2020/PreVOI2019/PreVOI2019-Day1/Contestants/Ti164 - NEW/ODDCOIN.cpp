#include <bits/stdc++.h>

using namespace std;
int q;
vector<long long> money;
long long a[20];
long long f[1000001];
long long F(long long t)
{
    if(f[t]!=t+1) return f[t];
    long long res=t;
    for(int i=16;i>=1;i--)
        if(t-a[i]>=0)res=min(res,F(t-a[i]));
    return f[t]=res+1;
}
void process(long long x,long long t)
{
    long long res=0;
    long long ress=1e9;
    a[16]=x;
    sort(a+1,a+16+1);
    for(int i=1;i<=1e6;i++)
        f[i]=i+1;
    f[0]=0;
    f[1]=1;
    f[3]=1;
    f[5]=1;
    f[10]=1;
    f[30]=1;
    f[50]=1;
    f[100]=1;
    f[300]=1;
    f[500]=1;
    f[1000]=1;
    f[3000]=1;
    f[5000]=1;
    f[10000]=1;
    f[30000]=1;
    f[50000]=1;
    for(int i=1;i<=16;i++)
    {
        long long times=0;
        times=t/a[i];
        ress=min(ress,times+F(t-times*a[i]));
    }
    for(int i=1;i<=1e6;i++)
        f[i]=i+1;
     f[0]=0;
    f[1]=1;
    f[3]=1;
    f[5]=1;
    f[10]=1;
    f[30]=1;
    f[50]=1;
    f[100]=1;
    f[300]=1;
    f[500]=1;
    f[1000]=1;
    f[3000]=1;
    f[5000]=1;
    f[10000]=1;
    f[30000]=1;
    f[50000]=1;
    long long times=0;
    if(x>50000)
    {
         times=t/x;
        t-=times*x;
    }
    else
    {
        f[x]=1;
        if(t>50000)
        {
            times=t/50000;
            t-=times*50000;
        }
        //cout<<times<<'\n';
    }
    //cout<<t<<'\n';
    res+=times;
    cout<<min(ress,res+F(t))<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    cin>>q;
    for(int i=1;i<=1000000;i++)
        f[i]=i+1;
    f[0]=0;
    f[1]=1;
    f[3]=1;
    f[5]=1;
    f[10]=1;
    f[30]=1;
    f[50]=1;
    f[100]=1;
    f[300]=1;
    f[500]=1;
    f[1000]=1;
    f[3000]=1;
    f[5000]=1;
    f[10000]=1;
    f[30000]=1;
    f[50000]=1;
    a[0]=0;
    a[1]=1;
    a[2]=3;
    a[3]=5;
    a[4]=10;
    a[5]=30;
    a[6]=50;
    a[7]=100;
    a[8]=300;
    a[9]=500;
    a[10]=1000;
    a[11]=3000;
    a[12]=5000;
    a[13]=10000;
    a[14]=30000;
    a[15]=50000;
    for(int qq=1;qq<=q;qq++)
    {
        long long x,t;
        cin>>x>>t;
        process(x,t);
        //cout<<res<<'\n';
    }
    return 0;
}
