// KHAz
#include <bits/stdc++.h>
#define maxn 100005
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define Task "oddcoin"
#define pii pair < int,int >
#define pil pair < int,pii >
using namespace std;
int a[18]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int q ,x,T , f[17][maxn] ,m , dd[maxn] ,p[maxn];
pii b[maxn],c[maxn] , d[maxn];
void sub1()
{
    a[16]=x;

    for(int i=0;i<=16;i++)
    {
        for(int j=1;j<=T;j++) f[i][j]=1e9;
    }
    for(int i=1;i<=16;i++)
    {
        for(int j=1;j<=T;j++)
        {
            int k=a[i],cnt=1;
            f[i][j]=f[i-1][j];
            while(k<=j&&k<a[i]*10)
            {
                f[i][j]=min(f[i-1][j-k]+cnt, f[i][j]);
                k+=a[i];
                cnt++;
            }
        }
    }
    cout << f[16][T] <<'\n';
}
void kt()
{
    for(int i=1;i<=14;i++)
    {
        for(int j=1;j<=10;j++)
        {
             if(a[i]*j>a[i+1]) break;
              b[++m]={a[i]*j,j};
              dd[a[i]*j]=1;
        }
    }
    dd[a[15]]=1;
    b[++m]={a[15],1};
  //  for(int i=13;i<=15;i++) b[++m]={a[i],1} , dd[a[i]]=1;
}
void sub2()
{
    a[16]=x;
    for(int i=1;i<=m;i++) d[i]=b[i];
    int m1=m;
    if(x>50000) d[++m1]={x,1};
    else
    {
        int cnt=1,kz=x;
        while(x<=50000)
        {
            d[++m1]={x,cnt};
           // cout << x << endl;
            if(dd[x]) break;
            cnt++;
            x+=kz;
        }
    }
    int k=0;
    sort(d+1,d+m1+1);
    for(int i=1;i<=m1;i++)
    {
        if(d[i].F!=d[i-1].F) c[++k]=d[i];
    }
    for(int i=1;i<=k;i++) p[i]=c[i].F;
    int res=0;
    while(T>0)
    {
        int xx=upper_bound(p+1,p+k+1,T)-p-1;
     //   cout << c[xx].F << endl;
        int kk=T/c[xx].F;
        res+=kk*c[xx].S;
        T=T%c[xx].F;
    }
   cout << res  <<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>q;
    kt();
    while(q--)
    {
        cin>>x>>T;
        if(x<=1e5&&T<=1e5) sub1();
       else sub2();
    }
    return 0;
}
