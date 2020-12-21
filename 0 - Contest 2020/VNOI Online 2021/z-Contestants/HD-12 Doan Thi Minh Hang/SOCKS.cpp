#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int tp[N], n, ques, deg[N], dep[N], pd[N], cl[N], be[N], en[N], type[N], branch[N], cnt[N];
vector <int > g[N];

int id = 0, slt = 0;
int s[N];

void dfs(int u)
{
    cl[u] = 1;
    tp[++slt] = u;
    be[u] = ++id;

    for(auto &v: g[u])
    {
        if(cl[v] == 0)
        {
            pd[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
    en[u] = id;
}
void calc(int &start, int &stop)
{
    for(int j = 1; j <= n; ++j)
    {
        if(type[j] == 1 && start == 0) start = j;
        if(type[j] == 1) stop = j;
    }
}

void sub1()
{
    printf("1\n");

    for(int i = 1; i <= ques; ++i)
    {
        int id;
        scanf("%d", &id);

        if(type[id] == 0) type[id] = 1;
        else type[id] = 0;

        printf("1\n");
    }
}

bool ischild(int u, int v)
{
    if(be[v] <= be[u] && en[u] <= en[v]) return true;
    return false;
}

int calc2(int sl)
{
    for(int i = 1; i <= sl; ++i)
        cnt[branch[i]] = 0;

    for(int i = 1; i <= n; ++i)
    {
        int u = tp[i];

        if(type[u] == 0) continue;

        for(int j = 1; j <= sl; ++j)
        {
            if(ischild(u, branch[j]))
            {
                cnt[branch[j]] = max(cnt[branch[j]], dep[u]);
                break;
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= sl; ++i)
        if(cnt[branch[i]] > 0) ans++;

    return ans;
}

int root = 0;

void sub2()
{
    id = 0;
    dfs(root);

    int sl = 0;
    for(auto &v: g[root])
    {
        branch[++sl] = v;
    }

    int ans = calc2(sl);

    printf("%d\n", (ans - 1)/2 + 1);

    for(int i = 1; i <= ques; ++i)
    {
        int id;
        scanf("%d", &id);

        if(type[id] == 0) type[id] = 1;
        else type[id] = 0;


        for(auto &v: g[root])
        {
            if(ischild(id, v))
            {
                if(type[id] == 0) --branch[v];
                if(branch[v] == 0)
                {
                    ans--;
                }

                if(type[id] == 1)
                {
                    if(branch[v] == 0) ++branch[v], ans++;
                }

                break;
            }
        }

        printf("%d\n", (ans - 1)/2 + 1);
    }
}

int calc3()
{
    for(int i = 1; i <= n; ++i) s[i] = 0;

    for(int i = n; i >= 1; --i)
    {
        int u = tp[i];
        int sl = 0;

        for(auto &v: g[u])
        {
            if(pd[v] == u)
            {
                if(type[v] == 1 && s[v] == 0) ++sl;
                if(s[v] > 0)
                {
                    s[u] += s[v];
                }
            }
        }

        if(sl >= 1) s[u] += (sl - 1)/2 + 1;
    }

    int sl = 0;
    for(auto &v: g[1])
    {
        if(s[v] >= 2) ++sl;
    }

    if(sl > 0) s[1] += (sl - 1)/2 + 1;
    return s[1];
}

void sub3()
{
    dfs(1);

    int ans = calc3();
    printf("%d\n", ans);

    for(int i = 1; i <= ques; ++i)
    {
        int id;
        scanf("%d", &id);

        if(type[id] == 0) type[id] = 1;
        else type[id] = 0;

        int res = calc3();
        printf("%d\n", res);
    }
}
#define ha "SOCKS"

int main()
{
    //freopen("task.inp","r",stdin);
    freopen(ha".INP","r",stdin);
    freopen(ha".OUT","w",stdout);

    scanf("%d %d", &n, &ques);

    for(int i = 1; i <= n; ++i) scanf("%d", &type[i]);

    int smax = 0, smax2 = 0;
    root = 0;

    for(int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);

        deg[u]++;
        deg[v]++;

        if(deg[u] > smax)
        {
            smax2 = smax;
            smax = deg[u];
            root = u;
        }
        else smax2 = max(smax2, deg[u]);
    }

    if(smax == 2) sub1();
    else if(smax >= 3 && smax2 <= 2) sub2();
    else sub3();
}
