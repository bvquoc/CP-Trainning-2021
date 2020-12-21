#include <bits/stdc++.h>
#define ft first
#define sc second

using namespace std;
typedef pair <int, int > II;
int const mod = 998244353;

int const N = 5005;

int n, m;
int64_t bit[N];

vector <II > g[N];
int e[N], cl[N], kc[N], d[N][N];
set <II > s;
set <int > box[N];
int64_t in[N];

void update(int u, int delta)
{
    while(u <= n)
    {
        bit[u] = (bit[u] + delta) % mod;
        u += u & (-u);
    }
}

int64_t get(int u)
{
    int64_t res = 0;

    while(u > 0)
    {
        res = (res + bit[u]) % mod;
        u -= u&(-u);
    }

    return res;
}

void sub2()
{
    for(int i = 1; i <= m; ++i)
    {
        for(int j = i; j <= m; ++j)
        {
            update(i, 1);
            update(j + 1, -1);
        }
    }

    for(int i = 1; i <= m; ++i)
    {
        int64_t ans = get(i);
        printf("%I64d\n", ans);
    }
}


void dij(int xp)
{
    for(int i = 1; i <= n; ++i) cl[i] = 0, kc[i] = 0, box[i].clear();

    cl[xp] = 1;
    kc[xp] = 0;

    s.insert({kc[xp], xp});
    //box[xp].insert({xp, 0});

    while(!s.empty())
    {
        II x = (*s.begin());
        int u = x.sc;
        s.erase(x);
        cl[u] = 2;

        for(auto &tmp: g[u])
        {
            int v = tmp.ft;
            int id = tmp.sc;
            int l = e[id];

            if(cl[v] == 0)
            {
                cl[v] = 1;
                kc[v] = kc[u] + l;
                s.insert({kc[v], v});
                box[v].insert(box[u].begin(), box[u].end());

                //int sz = box[u].size();
                box[v].insert(id);
            }
            else if(cl[v] == 1 && kc[v] > kc[u] + l)
            {
                s.erase({kc[v], v});
                kc[v] = kc[u] + l;
                s.insert({kc[v], v});
                box[v].clear();
                box[v].insert(box[u].begin(), box[u].end());

                //int sz = box[u].size();
                box[v].insert(id);
            }
            else if(cl[v] == 1 && kc[v] == kc[u] + l)
            {
                box[v].insert(box[u].begin(), box[u].end());
                //int sz = box[u].size();
                box[v].insert(id);
            }
        }
    }
}

void sub3()
{
    for(int i = 1; i <= n; ++i)
    {
        //cerr << "i" << i << endl;
        dij(i);

        for(int j = 1; j <= n; ++j)
        {
            if(i == j) continue;
            if(cl[j] == 0) continue;

           // cerr << j << ":" << endl;
            for(auto &id: box[j])
            {
                //int id = tmp.ft;
                //int l = tmp.sc;

                in[id] = (in[id] + 1) % mod;
            }

            //cerr << endl;
        }

        //cerr << endl << endl;
    }

    for(int i = 1; i <= m; ++i)
        printf("%I64d\n", in[i]);
}

#define ha "CAULUONG"

int main()
{
    //freopen("task.inp","r",stdin);
    freopen(ha".INP","r",stdin);
    freopen(ha".OUT","w",stdout);

    int type;
    scanf("%d", &type);

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        d[u][v]++;
        g[u].push_back({v, i});
        e[i] = w;
    }

    if(type == 2) sub2();
    else sub3();
}
