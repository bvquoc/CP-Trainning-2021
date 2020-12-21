#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
#define tii tuple<ll,int,int>
#define bp __builtin_popcount
#define nmax 100010

using namespace std;
int getbit(int x,int y)
{
    return (x>>y)&1;
}
int getoff(int x,int y)
{
    return x^(1<<y);
}
int n,m,l,k,a[nmax];
ll f[nmax][40];
vector<pii> vt[nmax];
void dijkstra()
{
    priority_queue<tii,vector<tii>,greater<tii> > q;
    for (int u=1;u<=n;u++)
        for (int mask=0;mask<(1<<5);mask++) f[u][mask]=1e15;

    q.emplace(0,1,a[1]); f[1][a[1]]=0;
    q.emplace(0,1,0); f[1][a[1]]=0;
    while (!q.empty())
    {
        ll dd; int u,mask,maskm; tie(dd,u,mask)=q.top(); q.pop();
        for (int e=0;e<(int)vt[u].size();e++)
        {
            int v=vt[u][e].se; int w=vt[u][e].fi;
            maskm=(mask|a[v]);
            if (f[v][maskm]>dd+w)
            {
                f[v][maskm]=dd+w;
                q.emplace(dd+w,v,maskm);
            }
            if (f[v][mask]>dd+w)
            {
                f[v][mask]=dd+w;
                q.emplace(dd+w,v,mask);
            }
        }
    }

    ll res=1e15;
    for (int mask=0;mask<(1<<5);mask++)
        if (bp(mask)>=l) res=min(res,f[n][mask]);
    if (res==1e15) cout<<-1;
    else cout<<res;
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m>>l>>k;
    for (int i=1;i<=n;i++)
    {
        int sl,mask=0; cin>>sl;
        while (sl--)
        {
            int x; cin>>x;
            mask=getoff(mask,x-1);
        }
        a[i]=mask;
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        vt[u].pb(w,v); vt[v].pb(w,u);
    }

    dijkstra();
    return 0;
}
