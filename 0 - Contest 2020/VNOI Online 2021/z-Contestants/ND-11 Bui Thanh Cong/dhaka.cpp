#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, pair<long,long> >
#define x first
#define y second
using namespace std;
const ll oo=1000000000000000;
const long o=1e5+5;
long n,m,k,l,d[o]; ll f[o][1<<5];
vector<long>ke[o],cp[o];
priority_queue< pii,vector<pii>,greater<pii> >q;
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>l;
    for(long i=1;i<=n;i++)
    {
        long sl; cin>>sl;
        d[i]=0;
        for(long j=1;j<=sl;j++)
        {
            long dh; cin>>dh;
            d[i]|=(1<<(dh-1));
        }
    }
    for(long i=1;i<=m;i++)
    {
        long u,v,w; cin>>u>>v>>w;
        ke[u].push_back(v);
        cp[u].push_back(w);
        ke[v].push_back(u);
        cp[v].push_back(w);
    }
    for(long i=1;i<=n;i++)
    for(long j=0;j<(1<<k);j++)
        f[i][j]=oo;
    f[1][0]=0;
    q.push({0,{1,0}});
    while(!q.empty())
    {
        long u=q.top().y.x,tt=q.top().y.y;
        q.pop();
        for(long i=0;i<ke[u].size();i++)
        {
            long v=ke[u][i],w=cp[u][i];
            if(f[v][tt]>f[u][tt]+w)
            {
                f[v][tt]=f[u][tt]+w;
                q.push({f[v][tt],{v,tt}});
            }
        }
        long ttm=tt|d[u];
        if(f[u][ttm]>f[u][tt])
        {
            f[u][ttm]=f[u][tt];
            q.push({f[u][ttm],{u,ttm}});
        }
    }
    ll kq=oo;
    for(long i=0;i<(1<<k);i++)
        if(__builtin_popcount(i)>=l)kq=min(kq,f[n][i]);
    if(kq==oo)kq=-1;
    cout<<kq;
    return 0;
}
