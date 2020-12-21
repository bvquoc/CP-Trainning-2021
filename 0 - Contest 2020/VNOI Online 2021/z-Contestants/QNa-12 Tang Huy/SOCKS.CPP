#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,color[N],deg[N];
vector<int>a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>color[i];
    }
    for (int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    bool ok=true;
    int dem=0;
    for (int i=1;i<=n;i++)
    {
        if (deg[i]>2) ok=false;
        if (color[i]) dem++;
    }
    if (ok)
    {
        if (dem>1) cout<<1<<'\n';
        else cout<<0<<'\n';
        while (q--)
        {
            int u;
            cin>>u;
            color[u]=color[u]^1;
            if (color[u]==1) dem++;
            else dem--;
            if (dem>1) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}
