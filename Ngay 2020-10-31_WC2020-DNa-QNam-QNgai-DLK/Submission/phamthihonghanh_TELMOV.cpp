#include<bits/stdc++.h>
using namespace  std;
typedef pair<long long,long long >h;
priority_queue<h,vector<h>,greater<h> > q;
vector<h> a[20001];
long long gt[20001],res=1e16,truoc[201];
long long n,m,u,v,c,kq=0;
void hh()
{
    for(long long i=1;i<=n;i++)gt[i]=1e10;
    q.push(h(0,1));
    gt[1]=0;
    truoc[1]=1;
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
long long p,l,k;
int main()
{
    cin>>n>>m>>p>>l>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        a[u].push_back(h(v,c));
        a[v].push_back(h(u,c));
    }
    hh();cout<<gt[n];
}
