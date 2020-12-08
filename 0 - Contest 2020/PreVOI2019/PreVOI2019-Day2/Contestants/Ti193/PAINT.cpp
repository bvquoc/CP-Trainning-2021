#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define io ios_base::sync_with_stdio(), cin.tie(0), cout.tie(0)

using namespace std;

const int maxn = 2e6 + 7;

int fa[maxn], q, n = 0, cnt = 0, col[maxn], cur_root[30] = {};

int root(int u)
{
    if (fa[u] < 0) return u;
    return fa[u] = root(fa[u]);
}

void read(char &c)
{
    c = getchar();
    while (c > 'z' || c < 'a') c = getchar();
}

void enter()
{
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    scanf("%d",&q);
    cnt = q + 1;
    bool small = (q > 10000);

    if (small)
    {
        while (q--)
        {
            char cx, cy;
            int x, y, t;
            scanf("%d",&t);
            if (t == 1) read(cx), x = (int)(cx - 'a'), ++n, col[n] = x; else
            {
                read(cx), read(cy);
                x = (int)(cx - 'a'), y = (int)(cy - 'a');
                for (int i = 1; i <= n; ++i)
                    if (col[i] == x) col[i] = y;
            }
        }
        for (int i = 1; i <= n; ++i)
            putchar((char)(col[i] + 'a'));
    }else
    {
        memset(col, 0, sizeof col);
        while (q--)
        {
            char cx, cy;
            int x, y, t;
            scanf("%d",&t);
            if (t == 1)
            {
                read(cx), x = (int)(cx - 'a'), ++n;
                if (!cur_root[x]) cur_root[x] = ++cnt, fa[cnt] = -1, col[cnt] = x;
                fa[n] = cur_root[x];
            }else
            {
                read(cx), read(cy);
                x = (int)(cx - 'a'), y = (int)(cy - 'a');
                if (x != y && cur_root[x])
                {
                    if (!cur_root[y]) cur_root[y] = ++cnt, col[cnt] = y, fa[cnt] = -1;
                    col[cur_root[x]] = y, fa[cur_root[x]] = cur_root[y], cur_root[x] = 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
             putchar((char)(col[root(i)] + 'a'));
    }
}

int main()
{
    enter();
}
