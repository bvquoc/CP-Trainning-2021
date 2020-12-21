#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
#define LIMIT 100001
#define MAX 100000
#define INF 1e9

int m, n, temp = INF;

struct CoolMac {
    int L, R, cnt;
};

CoolMac c[LIMIT], p[LIMIT];

void online_judge(void)
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
}

void inp(void)
{
    cin>>m;
    uf(i,1,m) cin>>c[i].L>>c[i].R;
    cin>>n;
    uf(i,1,n)
    {
        int t; cin>>t;
        temp = min(temp,t);
    }
}

int d[4001][4001];
vector<int> adj[4001], st, ed;

#define pairs pair<int,int>

void dijkstra(int s)
{
    uf(i,1,m) d[s][i] = INF;
    priority_queue<pairs> q;
    q.push(pairs(-1,s));
    d[s][s] = 1;
    while(!q.empty())
    {
        pairs top = q.top();
        q.pop();
        int dist = -top.first, u = top.second;
        if(d[s][u] != dist) continue;
        for(int v: adj[u])
        {
            if(d[s][v] > d[s][u] + 1)
            {
                d[s][v] = d[s][u] + 1;
                q.push(pairs(-d[s][v],v));
            }
        }
    }
}

void subtask1(void)
{
    uf(i,1,m) uf(j,1,m)
    {
        if(c[j].L <= c[i].R and c[j].R > c[i].R) adj[i].push_back(j);
        if(c[j].L == c[i].R + 1) adj[i].push_back(j);
    }
    uf(i,1,m)
    {
        if(c[i].L <= temp) st.push_back(i);
        if(c[i].R >= MAX) ed.push_back(i);
    }
    if((int)ed.size() == 0) { cout<<"-1"; return; }
    for(int u: st) dijkstra(u);
    int res = INF;
    for(int u: st) for(int v: ed) res = min(res,d[u][v]);
    if(res == INF) cout<<"-1";
    else cout<<res;
}

bool cmp(CoolMac x, CoolMac y) {
    if(x.L == y.L) return (x.R < y.R);
    return (x.L < y.L);
}

void subtask2(void)
{
    sort(c+1,c+m+1,cmp);
    int id = 1;
    p[1].L = c[1].L; p[1].R = c[1].R; p[1].cnt = 1;
    uf(i,2,m)
    {
        if((c[i].L <= p[id].R and c[i].R >= p[id].R) or (c[i].L == p[id].R + 1))
        {
            p[id].R = c[i].R;
            p[id].cnt++;
        }
        else
        {
            if(c[i].L > p[id].R+1)
            {
                id++;
                p[id].L = c[i].L;
                p[id].R = c[i].R;
                p[id].cnt = 1;
            }
        }
    }
    int res = INF;
    uf(i,1,id) if(p[i].L <= temp and p[i].R >= MAX) res = min(res,p[i].cnt);
    if(res == INF) cout<<"-1";
    else cout<<res;
}

int main(void)
{
    fastread
    online_judge();
    inp();
    if(m <= 3000) subtask1();
    else subtask2();
    return 0;
}

/* Code by: gaconvuive */

