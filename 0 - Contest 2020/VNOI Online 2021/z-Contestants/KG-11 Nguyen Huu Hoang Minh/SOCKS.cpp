#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 500005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "SOCKS"
#define int long long

using namespace std;

typedef long double ld;

int n,m;
bool color[N];
vector<int> a[N];
int q,giao;
int d[N], h[4];
int trace[N];
bool is_li[N];
int par, red;
bool line_graph = false;
bool T_graph = false;

void reset_all()
{
    for(int i=1; i<=n; i++) trace[i] = d[i] = is_li[i] = 0;
}

void dfs(int u)
{
    for(auto v: a[u])
    {
        if (!d[v] && v!=par){
            d[v] = d[u]+1;
            trace[v] = u;
            dfs(v);
        }
    }
}

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> color[i];
        if (color[i]) red++;
    }
    for(int i=1; i<=n-1; i++){
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int bac1 = 0;
    int bac2 = 0;
    int bac3 = 0;
    for(int i=1; i<=n; i++) if (a[i].size()==1) bac1++; else if (a[i].size()==2) bac2++; else bac3++;
    if (bac1 == 2 && bac2 == n-2) line_graph = true;
    if (bac3 == 1 && bac1 == 3) T_graph = true;
}

void tr(int ST)
{
    int s = ST;
    while (s != -1)
    {
        is_li[s] = true;
        s = trace[s];
    }
}

void proc()
{
    reset_all();
    for(int i=1; i<=n; i++) if (color[i]) {par = i; break;}
    trace[par] = -1;
    dfs(par);
    int res = 0;
    for(int i=1; i<=n; i++) if (color[i] && !is_li[i] && i!=par) {
        tr(i);
        res++;
    }
    cout << res << '\n';
}

void Dfs(int u, int &way)
{
    for(auto v : a[u])
    {
        if (u == giao) way++;
        if (!d[v]){
            if (color[v]) h[way]++;
            d[v] = d[u]+1;
            Dfs(v,way);
        }
    }
}

void Tbrute()
{
    h[1] = h[2] = h[3] = 0;
    int way = 0;
    for(int i=1; i<=n; i++) {d[i] = 0; if (a[i].size()==3) giao = i;}
    d[giao] = 1;
    Dfs(giao,way);
    int ans = 0;
    for(int i=1; i<=way; i++) {ans += h[i];}
    if (ans==3)
    {
        cout << 2 << '\n';
    }
    if (ans==2) cout << 1 << '\n';
    if (ans==1) if (red >= 2) cout << 1 << '\n'; else cout << 0 << '\n';
}

void LoopT()
{
    while (m--)
    {
        int x;
        cin >> x;
        color[x] = 1 - color[x];
        if (color[x]==1) red++;
        if (color[x]==0) red--;
        Tbrute();
    }
}

void brute()
{
    if (red >= 2) cout << 1 << '\n';
    while (m--)
    {
        int x;
        cin >> x;
        if (color[x]==0) red++;
        else red--;
        if (red >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

signed main()
{
    readfile();
    if (line_graph) brute();
    else if (T_graph) {Tbrute();LoopT();}
    else proc();
    return 0;
}
