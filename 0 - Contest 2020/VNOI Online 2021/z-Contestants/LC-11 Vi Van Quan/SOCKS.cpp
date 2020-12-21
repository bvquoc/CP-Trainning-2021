///WizardAP
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define Nothing "SOCKS"
#define pb push_back
using namespace std;
int a[500005],deg[500005];
vector<int> adj[500005];
int n,q;
namespace sub1
{
    void solve()
    {
        int pp=0;
        for (int i=1;i<=n;i++)
            pp+=a[i];
        cin>>q;
         cout<<(pp >1 ? 1 :0)<<"\n";
        while(q--)
        {
            int x;
            cin>>x;
            if (a[x]==1) pp--;
            else pp++;
            a[x]=1-a[x];
            if (pp>1) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
}

signed main()
{
    FastIO;
    freopen(Nothing".inp","r",stdin);
    freopen(Nothing".out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[v]++;
        deg[u]++;
    }
    bool s1=true;
    for (int i=1;i<=n;i++)
         if (deg[i]>2)
         {
             s1=false;
         }
    if (s1) sub1::solve();
    return 0;
}
