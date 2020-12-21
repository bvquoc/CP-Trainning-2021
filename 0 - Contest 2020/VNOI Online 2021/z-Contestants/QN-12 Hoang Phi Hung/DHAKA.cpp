#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
#define INF 1e18
#define LIMIT 100010

int n, m, k, l;
int t[LIMIT], c[LIMIT][6];

#define pairs pair<long long, int>
#define fi first
#define se second

vector<pairs> adj[LIMIT];
long long res;

#define sz(s) (int)s.size()

void online_judge(void)
{
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
}

void inp(void)
{
    cin>>n>>m>>k>>l;
    uf(i,1,n)
    {
        cin>>t[i];
        uf(j,1,t[i]) cin>>c[i][j];
    }
    uf(i,1,m)
    {
        int u, v; long long w;
        cin>>u>>v>>w;
        adj[u].push_back(pairs(w,v));
        adj[v].push_back(pairs(w,u));
    }
}

int x[15];
long long dst[15][15];
bool visit[LIMIT];

void gen_dist(int s)
{
    uf(i,1,n) dst[s][i] = INF;
    priority_queue<pairs> q;
    q.push(pairs(0,s));
    dst[s][s] = 0;
    while(!q.empty())
    {
        pairs top = q.top();
        q.pop();
        long long dist = -top.fi; int u = top.se;
        if(dist != dst[s][u]) continue;
        for(pairs child: adj[u])
        {
            int v = child.se; long long w = child.fi;
            if(dst[s][v] > dst[s][u] + w)
            {
                dst[s][v] = dst[s][u] + w;
                q.push(pairs(-dst[s][v],v));
            }
        }
    }
}

set<int> water_melon;

void travel(int u, int cnt, long long total_dist)
{
    if(u == n)
    {
        water_melon.clear();
        uf(i,1,cnt) uf(id,1,t[x[i]]) water_melon.insert(c[x[i]][id]);
        if(sz(water_melon) >= l) res = min(res,total_dist);
        return;
    }
    uf(v,1,n)
    {
        if(visit[v]) continue;
        visit[v] = true;
        x[cnt+1] = v;
        travel(v,cnt+1,total_dist+dst[u][v]);
        visit[v] = false;
    }

}

void subtask1(void)
{
    uf(u,1,n) gen_dist(u);
    visit[1] = true;
    x[1] = 1;
    res = INF;
    travel(1,1,0);
    if(res == INF) cout<<"-1";
    else cout<<res;
    exit(0);
}

long long d[5][LIMIT];

void dijkstra(int sign, int s)
{
    uf(i,1,n) d[sign][i] = INF;
    priority_queue<pairs> q;
    q.push(pairs(0,s));
    d[sign][s] = 0;
    while(!q.empty())
    {
        pairs top = q.top();
        q.pop();
        long long dist = -top.fi; int u = top.se;
        if(dist != d[sign][u]) continue;
        for(pairs child: adj[u])
        {
            int v = child.se; long long w = child.fi;
            if(d[sign][v] > d[sign][u] + w)
            {
                d[sign][v] = d[sign][u] + w;
                q.push(pairs(-d[sign][v],v));
            }
        }
    }
}

void subtask2(void)
{
    dijkstra(0,1);
    if(d[0][n] == INF) cout<<"-1";
    else cout<<d[0][n];
    exit(0);
}

void subtask3(void)
{
    dijkstra(1,1);
    dijkstra(2,n);
    res = INF;
    uf(i,1,n) if(t[i] > 0) res = min(res,d[1][i]+d[2][i]);
    if(res == INF) cout<<"-1";
    else cout<<res;
    exit(0);
}

#define p2(x) (1<<(x))
#define bit(x,i) ((x)&(1<<(i)))
#define turn(x,i) ((x)^(1<<(i)))

#define mulpair pair<pairs,int>

long long dp[LIMIT][35];

void toDhaka(int s)
{
    uf(i,1,n) uf(x,0,p2(k)-1) dp[i][x] = INF;
    priority_queue<mulpair> q;
    int mask = 0;
    uf(i,1,t[s]) mask = turn(mask,c[s][i]-1);
    dp[s][mask] = 0;
    q.push(mulpair(pairs(0,s),mask));
    while(!q.empty())
    {
        mulpair top = q.top();
        q.pop();
        long long dist = -top.fi.fi;
        int u = top.fi.se, mask = top.se;
        if(dist != dp[u][mask]) continue;
        for(pairs child: adj[u])
        {
            int v = child.se; long long w = child.fi;
            int new_mask = mask;
            uf(i,1,t[v])
            {
                if(bit(mask,c[v][i]-1)) continue;
                new_mask = turn(new_mask,c[v][i]-1);
            }
            if(dp[v][new_mask] > dp[u][mask] + w)
            {
                dp[v][new_mask] = dp[u][mask] + w;
                q.push(mulpair(pairs(-dp[v][new_mask],v),new_mask));
            }
        }
    }
}

void subtask4(void)
{
    toDhaka(1);
    res = INF;
    uf(mask,0,p2(k)-1)
    {
        int cnt = 0;
        uf(i,1,k) if(bit(mask,i-1)) cnt++;
        if(cnt < l) continue;
        res = min(res,dp[n][mask]);
    }
    if(res == INF) cout<<"-1";
    else cout<<res;
}

int main(void)
{
    fastread
    online_judge();
    inp();
    if(n <= 10) subtask1();
    if(l == 0) subtask2();
    if(k == 1) subtask3();
    subtask4();
    return 0;
}

/* Code by: gaconvuive */

