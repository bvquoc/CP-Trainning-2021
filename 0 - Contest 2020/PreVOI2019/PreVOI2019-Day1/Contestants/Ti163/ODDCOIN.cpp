#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define oo 1000006
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
ll base=1e9+7;
int f[50000005];
int a[20],N,x,t;
void ReadInPut()
{
    x=read();t=read();
}
void Solve()
{
    int ans=t;
    for(int i=0;i<=t/x;i++)
    {
        MIN(ans,i+f[t-x*i]);
    }
    cout<<ans<<'\n';
}
main()
{
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    int sotest=1;
    cin>>sotest;
    a[1]=1;a[2]=3;a[3]=5;
    int j=1,t=4;
    for(int z=1;z<5;z++)
    {
        a[t]=a[j]*10;
        a[t+1]=a[j+1]*10;
        a[t+2]=a[j+2]*10;
        t+=3;j+=3;
    }
    N=t-1;
    j=1;
    for(int i=1;i<=50000000;i++)
    {
        while(j<N&&a[j]<=i&&a[j+1]<=i)
        {
            j++;
        }
        f[i]=1+f[i-a[j]];
    }
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
