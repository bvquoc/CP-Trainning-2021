#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int n;
int a[200009];
int b[200009];
int ok[200009];
int ok1[200009];
//int d[200009];
int dp[200009];
int mang[200009];
int sub1()
{
    int kq=0;
    int tam=0;
    for (int i=1;i<=n;i++)
    {
        int u=ok[i];
        kq=(kq+u-i)%MOD;
       // cout<<kq<<endl;
        for (int j=u;j>=i+1;j--)
        {
            a[j]=a[j-1];
            ok[a[j]]=j;
        }
    }
    return kq;
}
int sub2()
{
    dp[0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            dp[i]=(dp[i]+(dp[i-1]+j-1)%MOD)%MOD;
        }
       // cout<<dp[i]<<endl;
    }
    return dp[n];
}
int xuli(int k)
{
    if (k==n)
    {
        return 1LL;
    }
    int j=k;
    int u=mang[j];
    int cur=((u-1)*dp[n-j])%MOD;
    cur=(cur+xuli(k+1))%MOD;
    return cur;
}
int sub3()
{
    for (int i=1;i<=n;i++)
    {
        mang[i]=a[i];
    }
    int res=xuli(1);
    for (int i=1;i<=n;i++)
    {
        mang[i]=b[i];
    }
    int res1=xuli(1);
    return (res1-res+MOD*MOD)%MOD;
}
main()
{
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ok[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        ok1[b[i]]=i;
    }
    int kt=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=b[i])
        {
            kt=1;
            break;
        }
    }
    int kt1=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=i)
        {
            kt1=1;
            break;
        }
        if (b[i]!=n-i+1)
        {
            kt1=1;
            break;
        }
    }
    if (kt==0)
    {
      //  cout<<0;
        cout<<sub1()<<endl;
        return 0;
    }
    if (kt1==0)
    {
        cout<<sub2()<<endl;
        return 0;
    }
    int q=sub2();
    //cout<<q<<endl;
    int kq=sub3();
    swap(a,b);
    swap(ok,ok1);
    int z=sub1();
    kq=(kq+z)%MOD;
    cout<<kq<<endl;
    return 0;
}
