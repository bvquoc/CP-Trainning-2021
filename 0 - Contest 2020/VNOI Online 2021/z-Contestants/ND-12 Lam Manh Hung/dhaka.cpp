#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define ppi pair<pii,ll>
using namespace std;
ll n,m,k,h,s,x,y,u,v,f[100005][1<<5],w,tt,l;
const ll oo=1e18;
long b[100005];
vector<pii> a[100005];
void dij()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<k);j++) f[i][j]=oo;
    f[1][b[1]]=0;
    priority_queue<ppi,vector<ppi>,greater<ppi> > pq;
    pq.push({{0,b[1]},1});
    while(!pq.empty())
    {
        u=pq.top().S;
        w=pq.top().F.F;
        tt=pq.top().F.S;
        pq.pop();
        if(w>f[u][tt]) continue;
        if(u==n&& __builtin_popcount(tt)>=l) {cout<<w;return;}
        for(pii v:a[u])
        if(w+v.F<f[v.S][tt|b[v.S]]) f[v.S][tt^b[v.S]]=w+v.F,pq.push({{w+v.F,tt^b[v.S]},v.S});
    }
    cout<<-1;
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        cin>>s;b[i]=0;
        for(int j=1;j<=s;j++) cin>>x,x--,b[i]^=(1<<x);
    }
    for(int i=1;i<=m;i++) cin>>u>>v>>w,a[u].push_back({w,v}),a[v].push_back({w,u});
    dij();
    return 0;
}
