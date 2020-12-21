#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
#define LIMIT 500001

int n, query, root;
int col[LIMIT], deg[LIMIT];
vector<int> adj[LIMIT];

bool sub1, sub2;

void online_judge(void)
{
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
}

void inp(void)
{
    cin>>n>>query;
    uf(i,1,n) cin>>col[i];
    uf(i,1,n-1)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
}

void subtask1(void)
{
    int cnt_red = 0;
    uf(i,1,n) cnt_red += (col[i] == 1);
    if(cnt_red >= 2) cout<<"1\n";
    else cout<<"0\n";
    while(query--)
    {
        int t; cin>>t;
        if(col[t] == 1) col[t] = 0, cnt_red--;
        else col[t] = 1, cnt_red++;
        if(cnt_red >= 2) cout<<"1\n";
        else cout<<"0\n";
    }
}

int d[LIMIT], team[5];

void divide(int u, int par, int flag)
{
    d[u] = flag;
    for(int v: adj[u])
    {
        if(v == par) continue;
        divide(v,u,flag);
    }
}

void subtask2(void)
{
    int flag = 0, cnt, cnt_red = 0;
    for(int v: adj[root]) divide(v,root,++flag);
    uf(i,1,n)
    {
        if(col[i] == 1) team[d[i]]++;
        cnt_red += (col[i] == 1);
    }
    cnt = 0;
    uf(i,1,3) cnt += (team[i] > 0);
    if(cnt == 1)
    {
        if(cnt_red >= 2) cout<<"1\n";
        else cout<<"0\n";
    }
    if(cnt == 2) cout<<"1\n";
    if(cnt == 3) cout<<"2\n";
    while(query--)
    {
        int t; cin>>t;
        if(col[t] == 1)
        {
            col[t] = 0;
            cnt_red--;
            team[d[t]]--;
        }
        else
        {
            col[t] = 1;
            cnt_red++;
            team[d[t]]++;
        }
        cnt = 0;
        uf(i,1,3) cnt += (team[i] > 0);
        if(cnt == 1)
        {
            if(cnt_red >= 2) cout<<"1\n";
            else cout<<"0\n";
        }
        if(cnt == 2) cout<<"1\n";
        if(cnt == 3) cout<<"2\n";
    }
}

int trace[LIMIT], leaf[LIMIT];
bool vis[LIMIT];

void DFS(int u, int par)
{
    for(int v: adj[u])
    {
        if(v == par) continue;
        trace[v] = u;
        DFS(v,u);
    }
}

void subtask3(void)
{
    int cnt = 0, res = 0;
    uf(i,1,n) if(deg[i] == 1) leaf[++cnt] = i;
    trace[1] = 0;
    DFS(1,1);
    uf(i,1,cnt)
    {
        if(leaf[i] == 1) continue;
        int cur = leaf[i];
        bool good_trip = false;
        while(cur != 0)
        {
            if(col[cur] == 1 and !vis[cur]) good_trip = true;
            vis[cur] = true;
            cur = trace[cur];
        }
        if(good_trip) res++;
    }
    cout<<(res+1)/2<<"\n";
    while(query--)
    {
        int t; cin>>t;
        if(col[t] == 1) col[t] = 0;
        else col[t] = 1;
        uf(i,1,n) vis[i] = false;
        uf(i,1,cnt)
        {
            if(leaf[i] == 1) continue;
            int cur = leaf[i];
            bool good_trip = false;
            while(cur != 0)
            {
                if(col[cur] == 1 and !vis[cur]) good_trip = true;
                vis[cur] = true;
                cur = trace[cur];
            }
            if(good_trip) res++;
        }
        cout<<(res+1)/2<<"\n";
    }
}

int main(void)
{
    fastread
    online_judge();
    inp();
    bool sub1 = true, sub2 = false;
    uf(i,1,n)
    {
        if(deg[i] > 2) sub1 = false;
        if(deg[i] > 3) sub2 = false;
        if(deg[i] == 3)
        {
            if(sub2) sub2 = false;
            if(!sub2 and root == 0)
            {
                sub2 = true;
                root = i;
            }
        }

    }
    if(sub1) subtask1();
    else
    {
        if(sub2) subtask2();
        else subtask3();
    }
    return 0;
}

/* Code by: gaconvuive */

