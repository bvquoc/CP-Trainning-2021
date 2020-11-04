#include<bits/stdc++.h>
using namespace std;
long long i,j,a[10001],k,q,p,dp[10001][10001],ans,n,vti,vtj,truoc[100001],s,kq;
vector<long long >res;
int main()
{
    cin>>n>>k>>q>>p;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=k;i++)dp[i][1]=a[i],truoc[i]=i;
    for(i=k+1;i<=n;i++)
     for(j=1;j<=(q/p)+1;j++)
     {

     // dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i]);
     if(dp[i-1][j]>dp[i-1][j-1]+a[i])
     {
dp[i][j]=dp[i-1][j];
truoc[i]=i-1;
     }
     else dp[i][j]=dp[i-1][j-1]+a[i],truoc[i]=truoc[i-1];
      if(dp[i][j]>ans)
      {
          ans=dp[i][j];
      vti=i;
      }

     }

    //cout<<vti;

    i=vti;
      while(1)
      {
       if(truoc[i]==i){res.push_back(i);break;}
       else res.push_back(i);
       i=truoc[i];
      }
      s=q;
      sort(res.begin(),res.end(),greater<int>());
      for(i=0;i<res.size();i++)
      {
        kq+=a[res[i]]*min(s,p);
        s=s-min(s,p);
        if(s==0)break;
      }
      cout<<kq;






}
