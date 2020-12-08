#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define ll long long
#define e5 100005
#define ii pair<int,int>
#define ft first
#define sc second
using namespace std;
int n,m,qq,q;
int a[e5],w[e5],d[e5],top;
int st[e5*4],t[e5*4];
ii query[e5];
void build(int id,int l,int r)
{
     if(l>r) return;
     if(l==r)
     {
          st[id]=a[l];
          return;
     }
     int mid=(l+r)/2;
     build(id*2,l,mid);
     build(id*2+1,mid+1,r);
     st[id]=max(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int u,int v,int val)
{
     if(t[id])
     {
          st[id]+=t[id];
          if(l!=r)
          {
               t[id*2]+=t[id];
               t[id*2+1]+=t[id];
          }
          t[id]=0;
     }

     if(l>v||r<u) return ;
     if(u<=l&&r<=v)
     {
          st[id]+=val;
          if(l!=r)
          {
               t[id*2]+=val;
               t[id*2+1]+=val;
          }
          t[id]=0;
          return ;
     }
     int mid=(l+r)/2;
     update(id*2,l,mid,u,v,val);
     update(id*2+1,mid+1,r,u,v,val);
     st[id]=max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
     if(t[id])
     {
          st[id]+=t[id];
          if(l!=r)
          {
               t[id*2]+=t[id];
               t[id*2+1]+=t[id];
          }
          t[id]=0;
     }

     if(l>v||r<u) return -1e9;
     if(u<=l&&r<=v) return st[id];
     int mid=(l+r)/2;
     return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int li[e5],ri[e5];
void construct()
{

     rep(i,0,4*m) st[i]=t[i]=0;

     top=0;d[top]=0;
     rep(i,1,m)
     {
          while(top>0&&a[d[top]]>=a[i]) --top;
          li[i]=d[top]+1;d[++top]=i;
     }

     top=0;d[top]=m+1;
     for(int i=m;i>=1;--i)
     {
          while(top>0&&a[d[top]]>=a[i]) --top;
          ri[i]=d[top]-1;d[++top]=i;
     }

     build(1,1,m);

     rep(i,1,m) query[i]={a[i],i};
     sort(query+1,query+1+m);

     int result=0;
     rep(qqq,1,m)
     {
          int i=query[qqq].sc;
          if(a[i]=get(1,1,m,i,i))
          {
              update(1,1,m,li[i],ri[i],-a[i]);
              result=result+a[i];
          }
     }
     cout<<result<<endl;
}

void solve()
{
     cin>>n>>qq;
     rep(i,1,n) cin>>w[i];

     int id,l,r,k;
     while(qq--)
     {
          cin>>id>>l>>r;
          if(id==1)
          {
               cin>>k;
               rep(i,l,r) w[i]=w[i]+k;
          }
          else

          if(id==2)
          {
               m=r-l+1;
               rep(i,l,r) a[i-l+1]=w[i];
               construct();
          }
     }
}

int main()
{
     freopen("contruct.inp","r",stdin);
     freopen("contruct.out","w",stdout);
     ios_base::sync_with_stdio(0);cin.tie(0);

     cin>>q;
     while(q--) solve();
}
