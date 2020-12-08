#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000005;

int n, m;
int cha[MaxN], hang[MaxN], color[MaxN];
int dd[128];

int find(int u)
{
    if (u != cha[u])
    {
        cha[u] = find(cha[u]);
    }
    return cha[u];
}

bool Join(int u, int v, int c)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        color[u] = c;
        return false;
    }
    if (hang[u] == hang[v])
    {
        hang[u]++;
    }
    if (hang[u] < hang[v])
    {
        cha[u] = v;
        color[v] = c;
    }
    else
    {
        cha[v] = u;
        color[u] = c;
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    cin >> n;
    int k = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        dd[i] = 0;
    }
    int type;
    char x, y;
    while (n--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            k++;
            cha[k] = k;
            hang[k] = 0;
            color[k] = x;
            if (dd[x] == 0)
            {
                dd[x] = k;
            }
            else
            {
                Join(dd[x], k, x);
                dd[x] = find(dd[x]);
            }
        }
        else
        {
            cin >> x >> y;
            if (y == x)
            {
                continue;
            }
            if (dd[x] == 0)
            {
                continue;
            }
            if (dd[y] == 0)
            {
                dd[y] = dd[x];
                color[dd[x]] = y;
                dd[x] = 0;
                continue;
            }
            Join(dd[y], dd[x], y);
            dd[y] = find(dd[y]);
            dd[x] = 0;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << char(color[find(i)]);
    }
    
    return 0;
}