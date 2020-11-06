#include<bits/stdc++.h>
using namespace std;
long long n,truoc[1005],f[1005][1005],c[1005][1005],res,s[1001][1001];
vector<long long >a[1005];
void bfs()
{
    queue<long long >q;
    q.push(n+n+1);
    while(!q.empty())
    {
       int  u=q.front();q.pop();
        for(int i=0;i<a[u].size();i++)
        {
          int   v=a[u][i];
            if(truoc[v]==0&&f[u][v]<c[u][v])
            {
               truoc[v]=u;
               q.push(v);
               if(v==n+n+2)return;
            }
        }
    }
}
bool timduongdu()
{
 for(int i=1;i<=n+n+2;i++)truoc[i]=0;
 truoc[n+n+1]=-1;
    bfs();
  return truoc[n+n+2];
}
void tangluong()
{
   long long  v=n+n+2,luong=1e18;
    while(v!=n+n+1)
    {
        int u=truoc[v];
        luong=min(luong,c[u][v]-f[u][v]);
        v=u;
    }
    v=n+n+2;
    while(v!=n+n+1)
    {
        int u=truoc[v];
        f[u][v]+=luong;
        f[v][u]-=luong;
        v=u;
    }
    res+=luong;
    return;
}

bool kiemtra(long long mid)
{
    long long i,j;
    res=0;
    for(i=1;i<=n;i++)c[n+n+1][i]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(s[i][j]>=mid)c[i][n+j]=1;else c[i][n+j]=0;
    for(i=1;i<=n;i++)c[n+i][n+n+2]=1;
    for(i=1;i<=n+n+2;i++)
        for(j=1;j<=n+n+2;j++)f[i][j]=0;
for(int i=1;i<=10000;i++)
    if(timduongdu())tangluong();else break;
    if(res == n)return true;
    return false;
}
long long i,j,maxx,l,r,mid,ans=-1;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cin>>s[i][j];
            a[i].push_back(j+n);
            a[j+n].push_back(i);
            maxx=max(maxx,s[i][j]);
        }
  for(i=1;i<=n;i++)
  {
      a[n+n+1].push_back(i);
      a[n+n+2].push_back(n+i);
      a[i].push_back(n+n+1);
      a[n+i].push_back(n+n+2);
  }
  l=1;r=maxx;
    while(l<=r)
    {
        mid=(l+r+1)/2;
        if(kiemtra(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans;
    //cout<<kiemtra(1)<<" "<<res;

}
