#include <iostream>
#include <fstream>
#include <string.h>

#define task "PAINT"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;
typedef pair<int, int> II;

const int maxn = 1e6+1;

int n, s;
char x, y;
int root[maxn], root_color[256];
char color[maxn];

int get_root(int u)
{
    if (root[u] == 0)
        return u;
    root[u] = get_root(root[u]);
    return root[u];
}

int main()
{
    fi >> n;
    //Sub 1:
    if (n <= 1e4)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            fi >> s >> x;
            if (s == 1)
                color[++cnt] = x;
            else
            {
                fi >> y;
                for (int i = 1; i <= cnt; i++)
                    if (color[i] == x)
                        color[i] = y;
            }
        }
        for (int i = 1; i <= cnt; i++)
            fo << color[i];
    }
    else
    //Sub 2:
    {
        int cnt = 0;
        int p, q;
        reset(root);
        reset(root_color);
        for (int i = 1; i <= n; i++)
        {
            fi >> s >> x;
            if (s == 1)
            {
                ++cnt;
                if (root_color[x] == 0)
                {
                    root_color[x] = cnt;
                    color[cnt] = x;
                }
                else
                    root[cnt] = root_color[x];
            }
            else
            {
                fi >> y;
                if (x == y)
                    continue;
                if (root_color[x] == 0)
                    continue;
                if (root_color[y] == 0)
                {
                    root_color[y] = root_color[x];
                    color[root_color[y]] = y;
                }
                else
                    root[root_color[x]] = root_color[y];
                root_color[x] = 0;
            }
        }
        for (int i = 1; i <= cnt; i++)
            fo << color[get_root(i)];
    }
}
