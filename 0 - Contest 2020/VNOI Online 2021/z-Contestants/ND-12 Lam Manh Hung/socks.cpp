#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
ll n,q,b[500005],bac[500005],x,dem,d,d1[4],root,g[500005],cnt,u,v;
vector<long> a[500005];
void sub1()
{
    cout<<(d>1)<<'\n';
    for(int i=1;i<=q;i++)
    {
      cin>>x;
      if(b[x]) b[x]=0,d--;
      else b[x]=1,dem++;
      cout<<(d>1)<<'\n';
    }
}
void dfs(int u,int par)
{
    g[u]=cnt;
    d1[cnt]+=b[u];
    for(int v:a[u]) if(v!=par) dfs(v,u);
}
void sub2()
{
    for(int i=1;i<=n;i++) if(bac[i]==3) {root=i;break;}
    cnt=1;g[root]=1;
    for(int v:a[root])
    {
      dfs(v,root);
      cnt++;
    }
        dem=(d1[1]!=0)+(d1[2]!=0)+(d1[3]!=0);
        if(d1[1]+d1[2]+d1[3]<=1) {cout<<0<<'\n';}
        else
        if(dem<=2) {cout<<1<<'\n';}
        else cout<<2<<'\n';
    for(int i=1;i<=q;i++)
    {
        cin>>x;
        if(b[x]) b[x]=0,d1[g[x]]--;
        else b[x]=1,d1[g[x]]++;
        dem=(d1[1]!=0)+(d1[2]!=0)+(d1[3]!=0);
        if(d1[1]+d1[2]+d1[3]<=1) {cout<<0<<'\n';continue;}
        if(dem<=2) {cout<<1<<'\n';}
        else cout<<2<<'\n';
    }
}
ll f[1003][2];
void dfs1(int u,int par)
{
    if(b[u]==1) f[u][0]=1,f[u][1]=0;
    ll ans=0,mi1=0,mi2=0;
    for(int v:a[u]) if(v!=par) {
                              dfs1(v,u),ans+=f[v][0];
                              if(mi1<abs(f[v][1]-f[v][0])) mi1=f[v][1]-f[v][0];
                              else if(mi2<f[v][1]-f[v][0]) mi2=f[v][1]-f[v][0];}
    f[u][0]+=ans;
    if(b[u]==1) f[u][0]=min(f[u][0],ans+mi1-mi2+1);
    f[u][1]+=ans;
    f[u][1]= min(f[u][1],ans-mi1);
}
void sub3()
{
   dfs1(1,0);
   cout<<f[1][0]<<endl;
   for(int i=1;i<=q;i++)
   {
       cin>>x;
       b[x]=1-b[x];
       dfs(1,0);cout<<f[1][0]<<'\n';
   }
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>b[i],d+=b[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        bac[u]++;
        bac[v]++;
    }
    for(int i=1;i<=n;i++) if(bac[i]==1) dem++;
    if(dem==2) {sub1();return 0;}
    if(dem==3) {sub2();return 0;}
    if(n<=1000&&q<=1000) {sub3();return 0;}
}
