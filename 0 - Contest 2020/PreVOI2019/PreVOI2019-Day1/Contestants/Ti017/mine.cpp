#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=4e5+5;
const int base=1e6+3;
template <typename T> re(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
int n,m;
int a[mn];
int f[mn];
int t2[mn];
int mo(int sl,int x)
{
    if(sl==0)return 1;
    if(sl==1)return x;
    int tmp=mo(sl/2,x);
    tmp=(tmp*tmp)%base;
    if(sl%2==1)tmp=(tmp*x)%base;
    return tmp;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    re(n);re(m);
    for(int i=1;i<=2*n;i++)re(a[i]);
    if(n<=2000)
    {
        f[0]=1;t2[0]=1;t2[2]=1;t2[4]=2;
    for(int i=6;i<=2*n;i++)
        if(i%2==0)
    {
        for(int j=i-1;j>=1;j--)
        if((i-j+1)%2==0)
        {
            int sl=(i-j-1);
            t2[i]=(t2[i]+(t2[j-1]*t2[sl]))%base;
        }
    }
    for(int i=2;i<=2*n;i++)
    {
        for(int j=i-1;j>0;j--)
        if((i-j+1)%2==0&&a[i]-m<=a[j])
        {
            int sl=(i-j-1);
            f[i]=(f[i]+f[j-1]*t2[sl])%base;
        }
    }
    cout<<f[2*n];
    }
    else
    {
        int res=1ll;
        for(int i=n+2;i<=2*n;i++)res=(res*i)%base;
        int res1=1ll;
        for(int i=2;i<=n;i++)res1=(res1*i)%base;
        res1=mo(base-2,res1);
        cout<<(res*res1)%base;
    }
    return 0;
}
