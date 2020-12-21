#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define f first
#define s second
#define nmax 100005
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> pii;
set<ii> S;
set<pii> S1;
vector<ii> dske[nmax];
vector<int> a[nmax];
int kc[nmax];
ii kc1[nmax];
bool avail[nmax], wtm[nmax];
int n, m, l, k;
int watermelon(int u)
{
    int res = 0;
    For(x, 0, a[u].size()-1)
    {
        int v = a[u][x];
        if(wtm[v] == 0)
        {
            res ++;
            wtm[v] = 1;
        }
    }
    return res;
}
void dijkstra(int s)
{
    memset(kc, 0, sizeof kc);
    kc[s] = 0;
    avail[s] = 1;
    S.insert(ii(s, kc[s]));
    while(!S.empty())
    {
        ii tg = *S.begin();
        S.erase(tg);
        int u = tg.f;
        For(x, 0, dske[u].size()- 1)
        {
            int v = dske[u][x].f;
            int w = dske[u][x].s;
            if(avail[v] == 0)
            {
                avail[v] = 1;
                kc[v] = kc[u] + w;
                S.insert(ii(v, kc[v]));
            }
            else if(kc[v] > kc[u] + w)
            {
                S.erase(ii(v, kc[v]));
                kc[v] = kc[u] + w;
                S.insert(ii(v, kc[v]));
            }
        }
    }
    cout<<kc[n];

}
void dijkstra1(int s)
{
    memset(kc1, 0, sizeof kc1);
    memset(avail, 0, sizeof avail);
    kc1[s] = ii(0, 0);
    avail[s] = 1;
    S1.insert(pii(kc1[s], s));
    while(!S1.empty())
    {
        pii tg = *S1.begin();
        S1.erase(tg);
        int u = tg.s;
        For(x, 0, dske[u].size() - 1)
        {
            int v = dske[u][x].f;
            int w = dske[u][x].s;
            int wt = watermelon(v);
            if(avail[v] == 0)
            {
                avail[v] = 1;
                kc1[v].f = kc1[u].f + w;
                kc1[v].s = kc1[u].s + wt;
                S1.insert(pii(kc1[v], v));
            }
            else if(kc1[v].f >= kc1[u].f + w && wt >= kc1[v].s)
            {
                S1.erase(pii(kc1[v], v));
                kc1[v].f = kc1[u].f + w;
                kc1[v].s = kc1[u].s + wt;
                S1.insert(pii(kc1[v], v));
            }
        }
    }
    if(kc1[n].s >= l)
        cout<<kc1[n].f;
    else
        cout<<-1;

}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w", stdout);
    cin >> n >> m >> k >> l;
    For(i, 1, n)
    {
        int s, t;
        cin >> s;
        For(j, 1, s)
        {
            cin >> t;
            a[i].pb(t);
        }
    }
    For(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dske[u].pb(ii(v, w));
        dske[v].pb(ii(u, w));
    }
    memset(avail, 0, sizeof avail);
    if(l == 0 || k == 1)
        dijkstra(1);
    else
        dijkstra(1);
}
