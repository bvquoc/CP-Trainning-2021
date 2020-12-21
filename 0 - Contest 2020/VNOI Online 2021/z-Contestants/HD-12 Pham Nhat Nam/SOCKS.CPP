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
//////////////////////////
void debug(vector<int> a)
{
    for (auto & v : a)
        cerr<<v<<" ";
    cerr<<"\n";
}
//////////////////////////

int a[500005];
int cl[500005];
int deg[500005];
int mark[500005];
vector<int> g[500005];

int n,q,id = 0;

bool checkSub(int id)
{
    if (id == 1)
    {
        return *max_element(deg+1,deg+n+1) <= 2;
    }

    if (id == 2)
    {
        int pos = 0;
        for (int i = 1; i <= n; ++i)
            if (deg[i] == 3)
                pos = i;
        for (int i = 1; i <= n; ++i)
            if (i != pos)
                if (deg[i] > 2)
                    return false;
        return true;
    }

    return false;
}

void sub1()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += a[i];
    while (q -- )
    {
        int x;
        scanf("%d",&x);

        if (a[x] == 0)
            cnt++,a[x] = 1;
        else
            cnt--,a[x] = 0;

        if (cnt == 0)
            putchar('0');
        else
            putchar('1');
        putchar('\n');
    }
}

void dfs(int u,int root)
{
    cl[u] = root;
    for (auto & v : g[u])
        if (cl[v] == 0)
            dfs(v,root);
}

void sub2()
{
    int root = 0;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 3)
            root = i;

    int ton = 0;
    cl[root] = root;
    for (auto & v : g[root])
        dfs(v,v);

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        mark[cl[i]]++,ton += a[i];

    for (int i = 1; i <= n; ++i)
        if (i != root)
            cnt += mark[i]%2;

    bool onRoot = false;
    if (mark[root]%2)
        onRoot = true;

    while (q -- )
    {
        int x;
        scanf("%d",&x);

        mark[cl[x]]++;
        if (a[x])
            ton--;
        else
            ton++;
        a[x]=  1-a[x];

        if (cl[x] != root)
        {
            if (mark[cl[x]]%2 == 0)
                cnt--;
            else
                cnt++;
        }

        if (cl[x] == root)
        {
            if (mark[root]%2)
                onRoot = true;
            else
                onRoot = false;
        }

        if (ton <= 1)
            putchar('0');
        else
        {
            if (cnt == 0)
            {
                if (onRoot)
                    putchar('1');
                else
                    putchar('0');
            }
            else
                printf("%d",(cnt-1)/2+1);
        }
        putchar('\n');
    }
}

void buff()
{
    sub1();
}

//////////////////////////
main()
{
#define file "SOCKS."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d %d",&n,&q);

    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);

    for (int i = 1; i < n; ++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].pb(v),g[v].pb(u);
        deg[u]++,deg[v]++;
    }

    if (checkSub(1))
        sub1();
    else if (checkSub(2))
        sub2();
    else
        buff();
}

