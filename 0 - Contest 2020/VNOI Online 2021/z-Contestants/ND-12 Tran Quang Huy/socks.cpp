#include <bits/stdc++.h>
#define N 500001
using namespace std;
int n,q,c[N],i,u,v,sl[N],sum,kq,j,sl1,ma;
vector <int> a[N];
void DFS(int u,int p)
{
    sl[u]=c[u];
    int deg=0;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
     //   cerr<
        if(v==p) continue;
        DFS(v,u);
        sl[u]+=sl[v];
        if(sl[v]>0) deg++;
    }
    if(sum>sl[u]) deg++;
    //if(j==3 && c[u]==1) cerr<<u<<" "<<deg<<'\n';
    if(c[u]==1) kq+=(deg==1);
}
void tinh()
{
    sum=0;
    for(i=1;i<=n;i++) sum+=c[i];
    kq=0;
    DFS(1,0);
    cout<<(kq+1)/2<<'\n';
}
void sub2()
{
    if(sl1<2) cout<<0<<'\n'; else cout<<1<<'\n';
    while(q--)
    {
        cin>>u; c[u]=1-c[u];
        if(c[u]==0) sl1--; else sl1++;
        if(sl1<2) cout<<0<<'\n'; else cout<<1<<'\n';
    }
    exit(0);
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(i=1;i<=n;i++) { cin>>c[i]; sl1+=c[i]; }
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        a[u].push_back(v); a[v].push_back(u);
    }
    for(u=1;u<=n;u++) ma=max(ma,(int)a[u].size());
    if(ma<=2) sub2();
    tinh();
   // return 0;
    for(j=1;j<=q;j++)
    {
        cin>>u; c[u]=1-c[u];
        tinh();
    }
}
