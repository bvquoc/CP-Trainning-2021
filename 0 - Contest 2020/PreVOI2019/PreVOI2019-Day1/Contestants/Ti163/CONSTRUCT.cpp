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
#define oo 100006
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
int n,m;
int a[oo];
struct tdz
{
    int t,L,R,x;
}q[oo];
int l[oo],r[oo];
void ReadInPut()
{
    n=read();m=read();
    F(i,1,n)a[i]=read();
    F(i,1,m)
    {
        q[i].t=read();
        q[i].L=read();
        q[i].R=read();
        if(q[i].t==1)q[i].x=read();
    }
}
int ok[oo],cur;
void sub1()
{
    F(i,1,m)
    {
        if(q[i].t==1){
            int L=q[i].L,R=q[i].R,x=q[i].x;
            for(int j=L;j<=R;j++)a[j]+=x;
        }
        else{
            cur++;
            int ans=0;
            int L=q[i].L,R=q[i].R;
            l[L]=L-1;
            for(int j=L+1;j<=R;j++)
            {
                int k=j-1;
                l[j]=k;
                while(k>=L&&a[k]>=a[j])
                {
                    l[j]=l[k];
                    if(a[j]==a[k])ok[j]=cur;
                    k=l[k];
                }
            }
            r[R]=R+1;
            for(int j=R-1;j>=L;j--)
            {
                int k=j+1;
                r[j]=k;
                while(k<=R&&a[k]>=a[j])
                {
                    r[j]=r[k];
                    k=r[k];
                }
            }
            for(int j=L;j<=R;j++)
            {
                if(ok[j]==cur)continue;
               // cout<<j<<" "<<l[j]<<" "<<r[j]<<'\n';
                int tmp=a[l[j]];
                int tmp1=a[r[j]];
                if(l[j]<L)tmp=0;
                if(r[j]>R)tmp1=0;
                ans+=a[j]-max(tmp,tmp1);
            }
            cout<<ans<<'\n';
        }
    }
}
void Solve()
{
    sub1();
}
main()
{
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    int sotest=1;
    cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
