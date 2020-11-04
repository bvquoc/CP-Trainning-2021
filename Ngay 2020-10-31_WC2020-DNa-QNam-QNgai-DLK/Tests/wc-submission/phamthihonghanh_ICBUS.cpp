#include<bits/stdc++.h>
using namespace  std;
typedef pair<long long,long long >h;
priority_queue<h,vector<h>,greater<h> > q;
long long res=1e16,truoc[201];
long long n,m,u,v,c,kq=0;
void hh(long long gt[],long long start,vector<h>a[])
{
    for(long long i=1;i<=n;i++)gt[i]=1e10;
    q.push(h(0,start));
    gt[start]=0;
    while(!q.empty())
    {
        long long d=q.top().first;
        long long u=q.top().second;
        q.pop();
        if(gt[u]!=d)continue;
        for(long long i=0;i<a[u].size();i++)
        {
             v=a[u][i].first;
              c=a[u][i].second;
              if(gt[v]>gt[u]+c)
              {

                  gt[v]=gt[u]+c;
                  q.push(h(gt[v],v));
              }
        }
    }
}
vector<h> a[20001];
long long gt[5001][5001],kt[5001][5001],s[5001],b[5001],ans[100001];
vector<h>e[5001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i]>>b[i];
  for(long long i=1;i<=m;i++)
  {
      cin>>u>>v;
      a[u].push_back(h(v,1));
      a[v].push_back(h(u,1));
  }
  //cout<<endl;
  for(int i=1;i<=n;i++)
   {hh(gt[i],i,a);
  for(int j=1;j<=n;j++)
    if(i!=j&&gt[i][j]<=b[i])
   {
    e[i].push_back(h(j,s[i]));
    kt[i][j]=1;
   }
  }
  for(int i=1;i<=n;i++)
    for(int j=0;j<a[i].size();j++)
        if(kt[i][a[i][j].first]==0)
  {
    e[i].push_back(h(a[i][j].first,s[i]));
    e[a[i][j].first].push_back(h(i,s[j]));
    kt[i][a[i][j].first]=1;
  }

    hh(ans,1,e);
    cout<<ans[n];


}
