#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,mt[100010][10],s[100010],ans=1e18,dp[100010][10];
typedef pair <long long ,long long >ii;
vector <ii> a[100010];
ii d[100010];
typedef pair <ii,ii> iii;
long long Min(long long a,long long b)
{
   if(a>b) return b;
   return a;
}
void dijsktra(long long u)
{
   priority_queue <iii,vector <iii>, greater <iii> >pq;
   for(int i=1;i<=n;i++)
   {
      for(int j=0;j<=k;j++)
      {
         dp[i][j]=1e18;
      }
   }
   dp[u][s[u]]=0;
   long long mask=0,cur=1;
   for(int i=1;i<=s[u];i++)
   {
      cur=1;
      cur=(cur<<mt[u][i]);
      mask+=cur;
   }
   pq.push(iii(ii(0,-s[u]),ii(u,mask)));

   while(!pq.empty())
   {
      long long du=pq.top().first.first,soluong=-pq.top().first.second,u=pq.top().second.first,curmask=pq.top().second.second;
      pq.pop();
      if(du>dp[u][soluong]) continue;
      if(u==n&&soluong>=l)
      {
         ans=Min(ans,du);
         continue;
      }
      for(int i=0;i<a[u].size();i++)
      {
         long long v=a[u][i].first;
         long long w=a[u][i].second;
         long long tam=curmask,cnt=soluong;
         for(int j=1;j<=s[v];j++)
         {
            long long gan=(1<<mt[v][j]);
            long long muon=tam;
            tam=tam|gan;
            if(tam>muon) cnt++;
         }
         if(dp[v][cnt]>dp[u][soluong]+w)
         {
            dp[v][cnt]=dp[u][soluong]+w;
            pq.push(iii(ii(dp[v][cnt],-cnt),ii(v,tam)));
         }
      }
   }
}
int main()
{
   //cout<<LONG_MAX;
   freopen("DHAKA.inp","r",stdin);
   freopen("DHAKA.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k>>l;
   for(int i=1;i<=n;i++)
   {
      int x;
      cin>>s[i];
      for(int j=1;j<=s[i];j++)
      {
         cin>>mt[i][j];
      }
   }
   for(int i=1;i<=m;i++)
   {
      long long u,v,w;
      cin>>u>>v>>w;
      a[u].push_back(ii(v,w));
      a[v].push_back(ii(u,w));
   }
   dijsktra(1);
   if(ans==1e18) cout<<"-1"<<endl;
   else cout<<ans<<endl;
   return 0;
}
