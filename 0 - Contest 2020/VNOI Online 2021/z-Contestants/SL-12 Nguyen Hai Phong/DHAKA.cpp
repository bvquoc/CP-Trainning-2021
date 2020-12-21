///DHAKA
#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<vector>

#define Se second
#define Fi first

const int N = 100005;
const int M = 100005;
typedef std::pair<int, int> ii;
const int oo = 1000000009;
int numN, numM, K, L, head[N], link[2*M], t, d[2][N];
struct{int u, v, w;} e[2*M];
int p[N][6], adj[N];
bool ava[N];

///sub1

void Disjistra()
{
    std::priority_queue<ii, std::vector<ii>, std::greater<ii> > q;
    std::fill_n(d[1] + 1, numN, oo);
    d[1][1] = 0;
    q.push({0, 1});
    while(!q.empty())
    {
        int u = q.top().Se;
        q.pop();
        if(u == t)
            break;
        if(ava[u]) continue;
        ava[u] = 1;
        for(int i = head[u]; i; i = link[i])
        {
            int v = e[i].v, w = e[i].w;
            if(d[1][v] > d[1][u] + w)
            {
                d[1][v] = d[1][u] + w;
                q.push({d[1][v], v});
            }
        }
    }
}

void sub2()
{
    memset(ava, 0, sizeof ava);
    t = numN;
    Disjistra();
    if(d[1][numN] == oo) printf("-1");
    else printf("%d",d[1][numN]);
}

///

///subfull

int par[2][N];

void Disjistra_k(int S, int id)
{
    std::priority_queue<ii, std::vector<ii>, std::greater<ii> > q;
    std::fill_n(d[id] + 1, numN, oo);
    d[id][S] = 0;
    q.push({0, S});
    while(!q.empty())
    {
        int u = q.top().Se;
        q.pop();
        if(ava[u]) continue;
        ava[u] = 1;
        for(int i = head[u]; i; i = link[i])
        {
            int v = e[i].v, w = e[i].w;
            if(d[id][v] > d[id][u] + w)
            {
                d[id][v] = d[id][u] + w;
                par[id][v] = u;
                q.push({d[id][v], v});
            }
        }
    }
}

bool Check(int v)
{
    int u = par[1][v];
    bool ok[N];
    while(1)
    {
        for(int i = 1; i <= adj[u]; ++i) ok[p[u][i]] = 1;
        if(u == 1) break;
        u = par[1][u];
    }
    u = par[2][v];
    while(1)
    {
        for(int i = 1; i <= adj[u]; ++i) ok[p[u][i]] = 1;
        if(u == numN) break;
        u = par[2][u];
    }
    int cnt = 0;
    for(int i = 1; i <= K; ++i)
        if(ok[i]) ++cnt;
    if(cnt >= L) return 1;
    else return 0;
}

int ans = oo;

void subfull()
{
    memset(ava, 0, sizeof ava);
    memset(par, 0, sizeof par);
    Disjistra_k(1, 1);
    if(d[1][numN] == oo)
    {
        printf("-1");
        return;
    }
    memset(ava, 0, sizeof ava);
    Disjistra_k(numN, 2);
    for(int v = 2; v < numN; ++v)
        if(Check(v)) ans = std::min(ans, d[1][v] + d[2][v]);
    if(ans == oo) printf("-1");
    else printf("%d",ans);
}

///

int main()
{
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    scanf("%d%d%d%d",&numN,&numM,&K,&L);
    std::set<int> st;
    for(int i = 1; i <= numN; ++i)
    {
        scanf("%d",&adj[i]);
        for(int j = 1; j <= adj[i]; ++j)
        {
            int id; scanf("%d",&id);
            p[i][j] = id;
            st.insert(id);
        }
    }
    for(int i = 1; i <= numM; ++i)
    {
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        e[i] = {u, v, w};
        e[i + numM] = {v, u, w};
    }
    memset(head, 0, sizeof head);
    for(int i = 1; i <= 2* numM; ++i)
    {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
    if(st.size() < L)
    {
        printf("-1");
        return 0;
    }
    if(L == 0)
        sub2();
    else
        subfull();
    return 0;
}
