#include <bits/stdc++.h>

using namespace std;
#define N 1000003
char _c; int _q;

int readint()
{
    _c=getchar();
    while (_c < '0' || _c > '9')
        _c = getchar();
    _q = 0;
    while (_c >= '0' && _c <= '9')
    {
        _q = 10 * _q + _c - '0';
        _c = getchar();
    }
    return _q;
}

int a[N], n, m;

void enter()
{
    n = readint(); m = readint();
    for (int i=1; i<=n; i++)
        a[i] = readint();
}
#define lint long long

void q1(int t, int l, int r, int k)
{
    if (t == 1)
    {
        for (int i=l; i<=r; i++)
            a[i] +=k;
    }
    else
    {
        vector<int> h(a, a+n+2);
        lint rr = 0;
        while (true)
        {
            int ma = N, mi = 0;
            int fd = 0;
            for (int i=1; i<=n; i++)
            {
                if (h[i] != 0)
                {
                    fd = 1;
                    ma = h[i]; mi = i;
                    for (int j=i; j<=n+1; j++)
                    {
                        if (h[j] == 0) break;
                        if (h[j] < ma)
                        {
                            ma = h[j];
                        }
                    }
                    rr += ma;
                    for (int j=i; j<=n+1; j++)
                    {
                        if (h[j] == 0) break;
                        h[j] -= ma;
                    }
                    break;
                }
            }
            if (!fd) break;
        }
        printf ("%d\n", rr);
    }
}

void driver()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    int t = readint();
    while (t--)
    {
        enter();
        for (int i=0,t,l,r,k; i<m; i++)
        {
            t = readint();
            l = readint();
            r = readint();
            if (t == 1)
            {
                k = readint();
            }
            q1(t,l,r,k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
