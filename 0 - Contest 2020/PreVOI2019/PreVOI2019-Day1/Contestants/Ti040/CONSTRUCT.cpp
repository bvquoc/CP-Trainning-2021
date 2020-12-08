#include <bits/stdc++.h>

template < typename T > inline void read(T &x)
{
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
}

template < typename T > inline void writep(T x)
{
    if (x > 9)
        writep(x / 10);
    putchar(x % 10 + 48);
}

template < typename T > inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    writep(x);
    putchar('\n');
}

using namespace std;
#define taskname "CONSTRUCT"
typedef int64_t ll;

int T, n, m;
ll a[100005];
ll c[100005];

ll F(int l, int r, ll val)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[l] - val;
    ll mina = 1e18;
    for (int i = l; i <= r; i++)
        mina = min(mina, a[i]);
    ll tmp = mina - val;
    val += mina - val;
    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (a[i] != mina)
            cnt++;
        else
        {
            tmp += F(i - cnt, i - 1, val);
            cnt = 0;
        }
    if (cnt > 0)
        tmp += F(r - cnt + 1, r, val);
    return tmp;
}

int main()
{
    if (fopen (taskname".inp", "r"))
    {
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    }
    read(T);
    while (T --> 0)
    {
        read(n); read(m);
        for (int i = 1; i <= n; i++)
            read(a[i]);
        int id, L, R, k;
        while (m --> 0)
        {
            read(id);
            read(L); read(R);
            if (id == 1)
            {
                read(k);
                c[L] += k;
                c[R + 1] -= k;
            }
            else
            {
                if (L == R)
                {
                    write(0);
                    continue;
                }
                ll cur = 0;
                for (int i = 1; i <= n; i++)
                {
                    cur += c[i];
                    c[i] = 0;
                    a[i] += cur;
                }
                write(F(L, R, 0));
            }
        }
    }
}
