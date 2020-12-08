#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define mod 1000000007
#define oo 2006
#define INF 0x3f3f3f3f
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll base=1e6+3;
int f[oo][oo][2];
int n,m;
int a[oo];
int sl[400005];
void ReadInPut()
{
    n=read();m=read();
    n*=2;
    F(i,1,n)a[i]=read();
}
int tinh(int i,int j,int k)
{
    if(k==1&&abs(a[i]-a[j])>m)return 0;
    if(i>=j)return 0;
    if(i==j-1)return k;
    if(f[i][j][k]!=-1)return f[i][j][k];
    int res=0;
    if(k==1)
    {
        f[i][j][k]=tinh(i+1,j-1,0);
        if(a[i+1]>=a[j-1]-m)f[i][j][k]+=tinh(i+1,j-1,1);
        if(f[i][j][k]>=base)f[i][j][k]-=base;
        return f[i][j][k];
    }
    F(t,i+1,j-1)
    {
        if(a[t]>a[i]+m)break;
        int sum=tinh(t+1,j,0);
        if(a[t]>=a[j]-m)sum+=tinh(t+1,j,1);
        if(sum>=base)sum-=base;
        res+=tinh(i,t,1)*(sum);
        res%=base;
    }
    f[i][j][k]=res;
    return res;
}
void sub1()
{
    reset(f,-1);
    int sum=tinh(1,n,0);
    if(a[1]>=a[n]-m)sum+=tinh(1,n,1);
    if(sum>=base)sum-=base;
    cout<<sum;
}
int p[400005];
void snt()
{
    p[1]=1;
    int t=sqrt(400005);
    F(i,2,t)
    {
        if(p[i])continue;
        p[i]=i;
        int j=i*i;
        while(j<400005)
        {
            p[j]=i;
            j+=i;
        }
    }
    F(i,t-1,400005)
    {
        if(p[i]==0)p[i]=i;
    }
}
int tach(int i,int val)
{
    while(i>1)
    {
        int t=p[i];
        while(i%t==0)
        {
            sl[t]+=val;
            i/=t;
        }
    }
}
void sub2()
{
    snt();
    int k=n/2;
    for(int i=2;i<=n;i++)tach(i,1);
    for(int i=2;i<=k;i++)tach(i,-1);
    for(int i=2;i<=n-k;i++)tach(i,-1);
    tach(k+1,-1);
    int ans=1;
    F(i,2,n)
    {
        int t=sl[i];
        for(int j=1;j<=t;j++)ans=(ans*i)%base;
    }
    cout<<ans;
}
void Solve()
{
    if(n<=400)sub1();
    else sub2();
}
main()
{
    freopen("MINE.INP","r",stdin);
    freopen("MINE.OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
