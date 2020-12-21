						///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define II pair<int,pii>
#define Zo "DHAKA"
#define MOD 1000000007
#define maxn 100111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // kiem tra bit i
#define SET_ON(x, i) ((x) | MASK(i)) // bat bit thu i cua x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tat bit thu i cua x

using namespace std;
int n,m,k,l,ans=1e18,msk[maxn];
int d[maxn][MASK(5)];
vector<pii> ke[maxn];
void dijkstra(int s)
{
    priority_queue<II,vector<II>,greater<II>> Q;
    Q.push({0,{s,msk[s]}});
    d[s][msk[s]]=0;
    while(!Q.empty())
    {
        II t=Q.top();
        int u=t.S.F;
        int mask=t.S.S;
        Q.pop();
        for(pii g:ke[u])
        {
            int v=g.F;
            int new_mask=(mask|msk[v]);
            if(d[v][new_mask]>d[u][mask]+g.S)
            {
                d[v][new_mask]=d[u][mask]+g.S;
                Q.push({d[v][new_mask],{v,new_mask}});
            }
        }
    }
}
void nhap()
{
    mem(d,64);
    cin>>n>>m>>l>>k;
    for(int i=1;i<=n;i++)
    {
        int len;
        cin>>len;
        int sum=0;
        for(int j=1;j<=len;j++)
        {
            int x;
            cin>>x;
            x--;
            sum+=MASK(x);
        }
        msk[i]=sum;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ke[u].pb({v,w});
        ke[v].pb({u,w});
    }
    dijkstra(1);
    for(int mask=0;mask<MASK(l);mask++)
    {
        int g=__builtin_popcount(mask);
        if(g>=k)
        {
            ans=min(ans,d[n][mask]);
        }
    }
    if(ans==1e18)
    {
        cout<<-1;
    }
    else cout<<ans;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
