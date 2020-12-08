#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <map>

#define task "ODDCOIN"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;

const int maxn = 1e5+1;
const int coin[16] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int q, x[51], t[51];
int f[maxn];
int c[17], n;

void solve(lli x, lli t)
{
    reset(c);
    bool kt = true;
    n = 0;
    for (int i = 1; i <= 15; i++)
    {
        if (kt && coin[i] > x)
        {
            c[++n] = x;
            kt = false;
        }
        c[++n] = coin[i];
    }
    if (kt)
        c[++n] = x;
    //Sub 1 + 2:
    if (t <= 1e5)
    {
        f[0] = 0;
        for (int i = 1; i <= t; i++)
        {
            f[i] = 1e8;
            for (int j = 1; j <= n; j++)
                if (i >= c[j])
                    f[i] = min(f[i], f[i - c[j]] + 1);
                else
                    break;
        }
        fo << f[t] << "\n";
    }
    else
    {
        f[0] = 0;
        for (int i = 1; i < maxn; i++)
        {
            f[i] = 1e8;
            for (int j = 1; j <= n; j++)
                if (i >= c[j])
                    f[i] = min(f[i], f[i - c[j]] + 1);
                else
                    break;
        }
        int cnt = 0;
        while (t > 1e5)
        {
            int mc = -1;
            for (int i = 1; i <= n; i++)
                if (t >= c[i])
                    mc = max(mc, c[i]);
                else
                    break;
            cnt++;
            t -= mc;
        }
        cnt += f[t];
        fo << cnt << "\n";
    }
}

int main()
{
    fi >> q;
    for (int i = 1; i <= q; i++)
        fi >> x[i] >> t[i];
    for (int i = 1; i <= q; i++)
        solve(x[i], t[i]);
}
