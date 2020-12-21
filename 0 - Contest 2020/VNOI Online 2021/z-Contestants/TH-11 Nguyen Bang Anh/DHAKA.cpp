#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define oo 1000000000000000000
#define MAXN 100001
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) { cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define taskname "DHAKA"
#define pb push_back

struct nation{
    long long nation;
    long long w;
    long long nWatermelon;
    set<long long> luu;
};

struct cmp{
    bool operator() (nation a, nation b)
    {
        return a.w>b.w || (a.w==b.w && a.nWatermelon<=b.nWatermelon);
    }
};

long long m,n,k,l;
vector<long long> melon[MAXN];
vector<ii> neighs[MAXN];

void read()
{
    long long s,x,y,w;
    cin>>n>>m>>k>>l;
    FOR(i,1,n)
    {
        cin>>s;
        FOR(j,1,s)
        {
            cin>>x;
            melon[i].pb(x);
        }
    }
    FOR(i,1,m)
    {
        cin>>x>>y>>w;
        neighs[x].pb(ii(y,w));
        neighs[y].pb(ii(x,w));
    }
}

void init()
{

}

long long f[MAXN][11];

void Dijkstra(long long start, long long target)
{
    long long u,v,ts1,ts2;
    long long k1,k2;
    set<long long> DuaHauU,DuaHauV;
    priority_queue<nation, vector<nation>, cmp> pq;
    FOR(i,1,n)
    {
        FOR(j,0,k) f[i][j]=oo;
    }
    FOR(i,0,int(melon[start].size())) f[start][i]=0;
    FOR(i,0,int(melon[start].size())-1) DuaHauU.insert(melon[start][i]);

    pq.push({start, 0, melon[start].size(), DuaHauU});

    while(pq.size())
    {
        u=pq.top().nation;
        ts1=pq.top().w;
        k1=pq.top().nWatermelon;
        DuaHauU.clear();
        DuaHauU=pq.top().luu;
        cout<<"u:"<<u<<' '<<"k:"<<k1<<' '<<"ts:"<<ts1<<'\n';
        pq.pop();

        if(f[u][k1]!=ts1) continue;

        FOR(i,0,int(neighs[u].size())-1)
        {
            v=neighs[u][i].first;
            ts2=neighs[u][i].second;
            DuaHauV.clear();
            DuaHauV=DuaHauU;
            FOR(j,0,int(melon[v].size())-1) DuaHauV.insert(melon[v][j]);
            k2=min(int(DuaHauV.size()),int(l));
            cout<<v<<' '<<k2<<' '<<ts1+ts2<<' ';
            if(f[v][k2]>ts1+ts2)
            {
                //cout<<"REPLACE\n";
                FOR(j,0,k2) f[v][j]=min(f[v][j],ts1+ts2);
                f[v][k2]=ts1+ts2;
                pq.push({v, f[v][k2], k2, DuaHauV});
            }
            else cout<<'\n';
        }
    }
}

void solve()
{
    Dijkstra(1,n);
//    FOR(i,1,n)
//    {
//        FOR(j,0,k) cout<<f[i][j]<<' ';
//        cout<<'\n';
//    }
}

void write()
{
    if(f[n][l]!=oo)
        cout<<f[n][l];
    else cout<<-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    read();
    init();
    solve();
    write();
    return 0;
}
