//DinoFromMar
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "CONSTRUCT"
#define maxn 200005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> a[maxn];
int dd[maxn];
map<int, int> kt[maxn], d[maxn];
int cnt = 0;
int num[maxn], low[maxn];
int ans, res = 1e9;
int bri = 0;
int par[maxn];
int ANS = 0;
pii f[maxn];

void DFS(int u)
{
    dd[u] = 1;
    num[u] = low[u] = ++cnt;
    for(int v : a[u])
        if(!dd[v])
        {
///        kt[u][v] -- , kt[v][u] --;
            par[v] = u;
            DFS(v);
            if(low[v] > num[u] && kt[u][v] < 2)
            {
                bri++;
                if(f[u].F < f[v].F+1)
                {
                    f[u].F = f[v].F + 1;
//                if(f[u].S < f[v].S +1)f[u].S = f[v].S + 1;
                }
                else if(f[u].S < f[v].F + 1)
                    f[u].S = f[v].F + 1;
            }
            else
            {
                if(f[u].F < f[v].F)
                {
                    f[u].F = f[v].F ;
//                if(f[u].S < f[v].S +1)f[u].S = f[v].S + 1;
                }
                else if(f[u].S < f[v].F )
                    f[u].S = f[v].F ;
            }
//        cout << low[v] << " " << num[u] << "\n";
            low[u] = min(low[u],low[v]);
        }
        else if(par[u]!=v)
        {
///            kt[u][v] -- , kt[v][u] --;
            low[u] = min(low[u], num[v]);
        }
///        cerr << u << " " << f[u].F << " " << f[u].S << "\n";
    ANS = max(ANS, f[u].F + f[u].S);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
        ++d[v][u],++d[u][v];
        kt[v][u] = kt[u][v] = d[u][v];
    }
    if(n > 50)
    {
        for(int k = 1; k <= n; k++)
            if(!dd[k])
                DFS(k);
        cout << ANS;
        return 0;
    }
///            cerr << bri << "\n";
    for(int k = 1; k <= n; k++)
        if(!dd[k])
            DFS(k);
    ans = bri;
    for(int i = 1; i <= n; i++)
        for(int j = i ; j <= n; j++)
        {
            memset(low, 0,sizeof(low));
            memset(num, 0, sizeof(num));
            cnt = 0;
            bri = 0;
            memset(dd, 0,sizeof(dd));
            for(int k  = 1; k <= n; k++)
                for(int l = k; l <= n; l++)
                    kt[k][l] = kt[l][k] = d[l][k] = d[k][l];
            ++kt[i][j],++ kt[j][i];
            a[i].PB(j);
            a[j].PB(i);
            for(int k = 1; k <= n; k++)
                if(!dd[k])
                    DFS(k);
///            cerr << bri << "\n";
            res = min(bri, res);
            int k = a[i].size(), l = a[j].size();
            a[i].pop_back();
            a[j].pop_back();
        }
    cout << ans - res;
    return 0;
}

