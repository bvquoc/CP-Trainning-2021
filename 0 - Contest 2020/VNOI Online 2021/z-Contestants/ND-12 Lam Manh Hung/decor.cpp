#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
ll n,m,k,b[500005],d[500005],u,v,dd[500005],dem[500005],m1,d1[2002];
char c;
vector<ll> a[500005];
void sub1()
{
    for(int i=1;i<=n;i++) d[i]=d[i-1]+(b[i]==0);
    int l=0;
    ll ans=0,vt;
    for(int i=1;i<=n;i++)
    {
        while(d[i]-d[l]>k) l++;
        if(ans<(i-l)) ans=i-l,vt=i;
    }
    if(ans==0) {cout<<-1;return;}
    cout<<vt-ans+1<<' '<<vt;
}

//==================================
void dfs(int u)
{
  dd[u]=m1;
  dem[m1]+=b[u];
  for(int v:a[u]) {if(dd[v]==0) dfs(v);}
}
long check(int l,int r)
{
    for(int i=1;i<=m1;i++) d1[i]=0;
    long ans=0;
    for(int i=l;i<=r;i++)
    {
        if(b[i]==0&&d1[dd[i]]<dem[dd[i]]) d1[dd[i]]++;
        else ans++;
    }
    return ans;
}
void sub2()
{
    m1=0;
    for(int i=1;i<=n;i++) if(dd[i]==0) m1++,dfs(i);
    long l=1;
    long ans=0,vt;
    for(int i=1;i<=n;i++)
    {
        while(l<=i&&check(l,i)>k) l++;
        if(ans<(i-l+1)) ans=i-l+1,vt=i;
    }
    if(ans==0) {cout<<-1;return;}
    cout<<vt-ans+1<<' '<<vt;
}
//===================================================

 void sub3()
 {

 }
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c=='1') b[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(m==0) {sub1();return 0;}
    if(n<=2000) {sub2();return 0;}
    sub3();
    return 0;
}
