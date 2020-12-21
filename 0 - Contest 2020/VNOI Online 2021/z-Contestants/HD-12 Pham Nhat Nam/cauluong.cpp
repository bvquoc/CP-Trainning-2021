#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
const ll inf = 1e18 + 18;
const int oo = 1e9 + 9;
const int max6 = 1e6 + 6;
const int modx = 1e9 + 7;
const int mody = 997;
const int base = 137;
const int mod = 998244353;
//////////////////////////
void debug(vector<int> a)
{
    for (auto & v : a)
        cerr<<v<<" ";
    cerr<<"\n";
}
//////////////////////////
typedef pair<int,int> ii;

ii f[1505][1505];

array<int,3> e[5005];
vector<ii> g[1505];

int n,m,t;

void dij(int xp)
{
    ++id;
    cl[xp] = id;
    f[xp][xp] = 0;
    s.insert({0,xp});

    while (!s.empty())
    {
        ii pe = *s.begin();
        s.erase(pe);

        int u = pe.y;
        for (auto & it : g[u])
        {
            int v = it.x;
            int c = it.y;

            if (cl[v] == 0)
            {
                cl[v] = 1;
                f[xp][v] = {f[xp][u].x+c,f[xp][u].y};
                s.insert({f[xp][v].x,v});
            }
            else
            {
                // cl[v] = 1
                if (f[xp][v].x > f[xp][u].x+c)
                {
                    s.erase({f[xp][v].x,v});
                    f[xp][v] = {f[xp][u].x+c,f[xp][u].y};
                    s.insert({f[xp][v].x,v});
                }
                else if (f[xp][v].x == f[xp][u].x+c)
                    f[xp][v].y = (f[xp][v].y+f[xp][u].y)%mod;
            }
        }
    }
}

void sub1()
{

}

void buff()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = f[j][i] = {oo,0};

    for (int i = 1; i <= n; ++i)
        f[i][i] = {0,1};
    for (int i = 1; i <= m; ++i)
    {
        int u = e[i][1];
        int v = e[i][2];
        int c = e[i][0];

        if (c < f[u][v].x)
            f[u][v] = {c,1};
        else if (c == f[u][v].x)
            f[u][v].y++;

    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != k && k != j)
                    {
                    int cost = f[i][k].x+f[k][j].x;
                    int way = 1ll*f[i][k].y*f[k][j].y%mod;

                    if (f[i][j].x > cost)
                        f[i][j] = {cost,way};
                    else if (f[i][j].x == cost)
                        f[i][j].y = (f[i][j].y+way)%mod;
                }

    for (int asdf = 1; asdf <= m; ++asdf)
    {
        int u = e[asdf][1];
        int v = e[asdf][2];
        int c = e[asdf][0];

        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                int cost = f[i][j].x;
                int cur = f[i][u].x+f[v][j].x+c;
                int way = 1ll*f[i][u].y*f[v][j].y%mod;
                if (cur == cost)
                    res = (res+way)%mod;
            }

        printf("%d\n",res);
    }
}

//////////////////////////
main()
{
#define file "cauluong."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d",&t);
    scanf("%d %d",&n,&m);

    for (int i = 1; i <= m; ++i)
    {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        g[u].pb({v,c}),g[v].pb({u,c});
        e[i] = {c,u,v};
    }

    if (t == 2)
        sub1();
    else
        buff();
}


