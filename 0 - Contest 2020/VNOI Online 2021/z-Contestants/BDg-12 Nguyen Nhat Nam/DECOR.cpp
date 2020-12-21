#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK "DECOR"

char ch;
template<class T> void readNum(T&q) 
{
    q = 0;
    ch = getchar();
    while (ch>'9' || ch <'0') 
        ch = getchar();
    while (ch >= '0' && ch<= '9') 
    {
        q = 10 * q + ch - '0';
        ch = getchar();
    }
}

const int N = 500002;
int n, m, k;
char s[N], sz;

void readString() 
{
    while (ch > '9' || ch < '0') 
        ch = getchar();
    for (int i=1; i<=n; ++i) 
    {
        s[i] = ch;
        ch = getchar();
    }
    s[n + 1] = 0;
}

struct DSU 
{
    vector<int> f;
    vector<int> c;

    DSU () {}

    DSU (int n) 
    {
        f.resize(n + 1);
        c.resize(n + 1);
        for (int i=1; i<=n; ++i) 
        {
            f[i] = -1;
            c[i] = s[i] == '1';
        }
    }

    int root (int u) 
    {
        if (f[u] < 0 ) 
            return u;
        return f[u] = root(f[u]);
    }

    bool mergetree (int u, int v) 
    {
        if (u == v) 
            return false;
        u = root(u);
        v = root(v);
        if (u == v) 
            return false;
        if (f[u] > f[v]) 
            swap(u, v);
        f[u] += f[v];
        f[v] = u;
        c[u] += c[v];
        c[v] = 0;
        return true;        
    }
} dsu;

void enter()
{
    readNum(n);
    readNum(m);
    readNum(k);
    readString();
    dsu = DSU(n);
    for(int i=1,u,v; i<=m; ++i) 
    {
        readNum(u);
        readNum(v);
        dsu.mergetree(u, v);
    }
}

pii sub1() 
{
    int bb=-1, bl=-1, br=-1;
    for (int i=1,j=0,z=0; i<=n; ++i) 
    {
        while ((j < n)) 
        {
            if (s[j + 1] == '1') 
                ++j;
            else 
            {
                if (z < k) 
                {
                    ++z;
                    ++j;
                }
                else 
                {
                    break;
                }
            }
        }
        if (j - i + 1 > bb) 
        {
            bb = j - i + 1;
            bl = i; br = j;
        }
        if (s[i] == '0') 
            --z;
    }
    return {bl, br};
}

pii sub3() 
{
    int abest = -1, al = -1, ar = -1;
    DSU backup = dsu;

    for (int b=1, e; b<=n; ++b) 
    {
        bool good = true;
        int left = k;
        for (e=b; e<=n && good; ++e) 
        {
            if (dsu.c[dsu.root(e)]) 
            {
                dsu.c[dsu.root(e)]--;
            }
            else
            {
                if (left) 
                {
                    --left;
                }
                else 
                {
                    break;
                }
            }
        }
        if (e > b) 
        {
            if (e - b > abest) 
            {
                abest = e - b;
                al = b;
                ar = e - 1;
            }
        }
        dsu = backup;
    }
    return {al, ar};
}

void driver()
{
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    enter();
    pii r;
    if (m == 0) 
        r = sub1();
    else 
        r = sub3();
    if (r.first == -1) 
        cout << -1;
    else cout << r.first << ' ' << r.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
