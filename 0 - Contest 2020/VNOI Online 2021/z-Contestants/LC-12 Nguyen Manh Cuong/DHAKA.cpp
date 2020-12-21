#include <bits/stdc++.h>
#define Killian "DHAKA"
#define endl "\n"
#define long long long
#define pii pair <int,long>
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD=1000000007;
const int base=26;
const int arraysize=100005;

int T,n,m,k,l;
int mask[100005];
struct data
{
    int u,g;
    long w;
    bool operator < (const data &B) const
    {
        return w > B.w;
    };
};
priority_queue <data> pq;
long d[100005][35];
vector <pii> ke[100005];
long res=1e18;

void Dijkstra ()
{
    for (int i=1; i<=n; i++)
        for (int j=0; j<(1<<k); j++)
            d[i][j]=1e18;
    pq.push({1,mask[1],0});
    d[1][mask[1]]=0;
    while (pq.empty()==0)
    {
        int u=pq.top().u;
        int w=pq.top().w,g=pq.top().g;
        pq.pop();
        if (w!=d[u][g])
            continue;
        for (auto t: ke[u])
        {
            int v=t.first;
            long c=t.second;
            if (d[v][g|mask[v]]>w+c)
            {
                d[v][g|mask[v]]=w+c;
                pq.push({v,g|mask[v],w+c});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>n>>m>>k>>l;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        while (k--)
        {
            int x;
            cin>>x;
            x--;
            mask[i]+=(1<<x);
        }
    }
    for (int i=1; i<=m; i++)
    {
        int u,v;
        long c;
        cin>>u>>v>>c;
        ke[u].push_back({v,c});
        ke[v].push_back({u,c});
    }
    Dijkstra();
    for (int i=1; i<(1<<k); i++)
        if (bitcount(i)>=l)
            res=min(res,d[n][i]);
    if (res==1e18)
        res=-1;
    cout<<res;
}
