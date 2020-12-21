#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
#define TASK "DHAKA"
#define ll long long
typedef pair<ll,int>ii;
typedef pair<ii,int>pi;
#define F first
#define S second
int n,m,k,l;
vector<ii>adj[N];
int mask[N];
ll d[1<<5][N];
void inp()
{
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;++i)
    {
        int sz;
        cin>>sz;
        while(sz--)
        {
            int x;
            cin>>x;
            mask[i]|=(1<<(x-1));
        }
    }
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
}
void init()
{
    for(int x=0;x<(1<<k);++x)
        for(int i=1;i<=n;++i)
        d[x][i]=1e18;
}
bool minimize(ll &x,ll y)
{
    if(x<=y)return false;
    x=y;
    return true;
}
void djk_heap()
{
    init();
    d[mask[1]][1]=0;
    priority_queue<pi>q;
    q.push(pi(ii(0,1),mask[1]));
    while(q.size())
    {
        ll du=-q.top().F.F;
        int u=q.top().F.S;
        int Mask=q.top().S;
        q.pop();
        if(du>d[Mask][u])continue;
        for(auto v:adj[u])
        {
            int newMask=(Mask|mask[v.S]);
            if(minimize(d[newMask][v.S],du+v.F))
                q.push(pi(ii(-d[newMask][v.S],v.S),newMask));
        }
    }
    ll ans=1e18;
    for(int Mask=0;Mask<(1<<k);++Mask)
        if(__builtin_popcount(Mask)>=l)
            ans=min(ans,d[Mask][n]);
    cout<<((ans==1e18)?(-1):(ans));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    inp();
    djk_heap();
    return 0;
}
