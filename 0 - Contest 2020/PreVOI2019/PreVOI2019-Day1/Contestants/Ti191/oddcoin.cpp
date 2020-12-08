#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define e4 10001
#define e5 100001
#define inf 2000000001
using namespace std;
int q,n=16,m,temp;
int w[20],dp[e5];

void _int()
{
     w[1]=1;
     w[2]=3;
     w[3]=5;
     w[4]=10;
     w[5]=30;
     w[6]=50;
     w[7]=100;
     w[8]=300;
     w[9]=500;
     w[10]=1000;
     w[11]=3000;
     w[12]=5000;
     w[13]=10000;
     w[14]=30000;
     w[15]=50000;
}

int bs(int x)
{
     int lo=1,hi=n,ans=-1;
     while(lo<=hi)
     {
          int mid=(lo+hi)/2;
          if(w[mid]<=x)
          {
               lo=mid+1;
               ans=mid;
          }else hi=mid-1;
     }
     return w[ans];
}

void codulieu()
{
     while(m>=e5)
     {
          temp++;
          int ans=bs(m);
          m=m-ans;
     }
}

void _dp()
{
     rep(j,0,m) dp[j]=inf;dp[0]=0;

     rep(j,0,m) rep(i,1,n) if(j>=w[i])
     dp[j]=min(dp[j],dp[j-w[i]]+1);

     printf("%d\n",dp[m]+temp);
}



void solve()
{
     _int();
     scanf("%d%d",&w[n],&m);
     sort(w+1,w+1+n);
     temp=0;

     codulieu();//cout<<m<<endl;
     _dp();
}

int main()
{
     freopen("oddcoin.inp","r",stdin);
     freopen("oddcoin.out","w",stdout);

     scanf("%d",&q);
     while(q--) solve();
}
