#include<bits/stdc++.h>
#define l first
#define r second
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,nhanh[4],colo[N*5],k,d[5*N],q,t,vt,change;
vector <int> a[5*N];
void dfs(int k,int u,int pre)
{
    nhanh[k]+=colo[u];
    d[u]=k;
    for (int v:a[u])
    {
        if (v==pre) continue;
        dfs(k,v,u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>colo[i],t+=colo[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int check=0;
    for (int i=1;i<=n;i++) if (a[i].size()>2) ++check,vt=i;
    if (check==0)
    {
        for (int i=1;i<=q;i++)
        {
            cin>>change;
            if (colo[change]==0) {++t;colo[change]=1;}
            else {--t;colo[change]=0;}
            if (t>1) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
    if (check==1)
    {
        int k=0;
        for (int x:a[vt])
        {
            ++k;
            dfs(k,x,vt);
        }
        for (int i=1;i<=q;i++)
        {
            cin>>change;
            if (colo[change]==0) colo[change]=1,++nhanh[d[change]];
            else colo[change]=0,--nhanh[d[change]];
            if (nhanh[1]!=0 && nhanh[2]!=0 && nhanh[3]!=0) cout<<2<<"\n";
            else if (nhanh[1]+nhanh[2]+nhanh[3]>2) cout<<0<<"\n";
            else cout<<1<<"\n";
        }
    }
}
